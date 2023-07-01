#include <bits/stdc++.h>
using namespace std;
const int nax = 1005;
#define f first
#define s second

int n, m;
char grid[nax][nax];
int visited[nax][nax];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        string line; cin >> line;
        int cnt=0;
        for (char c: line){
            grid[i][cnt] = c;
            cnt++;
        }
    }

    int cur = 1, traps = 0;

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            if (visited[i][k] != 0){
                continue;
            }

            traps ++;
            cur++;

            queue <pair <int, int>> q;
            q.push({i, k});
            pair <int, int> node;
            int x, y;
            while (!q.empty()){
                node = q.front(); q.pop();

                x = node.f; y = node.s;
              

                if (visited[x][y] !=0 && visited[x][y] != cur){
                    traps--;
                    break;
                }

                if (visited[x][y] == cur){
                    break;
                }

                visited[x][y] = cur;

                if (grid[x][y] == 'S'){
                    if (x+1 >= n){
                        traps --;
                        break;
                    }
                    q.push({x+1, y});
                }
                else if (grid[x][y] == 'N'){
                    if (x-1 < 0){
                        traps --;
                        break;
                    }
                    q.push({x-1, y});
                }
                else if (grid[x][y] == 'E'){
                    if (y+1 >= m){
                        traps--;
                        break;
                    }
                    q.push({x, y+1});
                }
                else{
                    if (y-1 < 0){
                        traps--;
                        break;
                    }
                    q.push({x, y-1});
                }
            }
        }
    }


    cout << traps << "\n";
}