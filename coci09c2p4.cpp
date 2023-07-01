#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define f first
#define s second

const int MAXSZ = 505;
const int inf = 1e9;

char grid[MAXSZ][MAXSZ];

int n, m;
vector <pii> trees;
pii start, dest; pii moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dist[MAXSZ][MAXSZ], best[MAXSZ][MAXSZ];

void bfs(pii t){
    int x = t.f, y = t.s;

    dist[x][y] = 0;

    queue <pair <int, pii>> q;

    q.push({0, t});

    while (!q.empty()){
        auto node = q.front(); q.pop();

        x = node.s.f; y = node.s.s;
        int curDist = node.f;

        for (pii mov : moves){
            x += mov.f; y += mov.s;

            if (1 <= x && x <= n && 1 <= y && y <= m){
                if (dist[x][y] > curDist+1){
                    dist[x][y] = curDist+1;
                    q.push({curDist+1, {x, y}});
                }
            }

            x -= mov.f; y -= mov.s;
        }
    }
}

int main(){

    cin.sync_with_stdio(0); cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int k=1; k<=m; k++){
            cin >> grid[i][k];

            if (grid[i][k] == '+'){
                trees.push_back({i, k});
            }

            if (grid[i][k] == 'J') dest = {i, k};
            if (grid[i][k] == 'V') start = {i, k};

            dist[i][k] = inf;
        }
    }

    for (pii tree : trees){
        bfs(tree);
    }

    queue <pair <int, pii>> q;

    best[start.f][start.s] = dist[start.f][start.s];

    q.push({best[start.f][start.s], start});

    while (!q.empty()){
        auto node = q.front(); q.pop();

        int curBest = node.f, x = node.s.f, y = node.s.s;

        for (pii mov : moves){
            x += mov.f; y += mov.s;
            int nxtBest = min(curBest, dist[x][y]);
            if (best[x][y] < nxtBest){
                best[x][y] = nxtBest;
                q.push({nxtBest, {x, y}});
            }

            x -= mov.f; y -= mov.s;
        }
    }

    cout << best[dest.f][dest.s] << "\n";

}