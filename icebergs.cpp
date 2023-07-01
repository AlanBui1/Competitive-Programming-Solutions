#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5005;
#define f first
#define s second

int psa[MAXSZ][MAXSZ];
bool visited[MAXSZ][MAXSZ];

bool good(int curX, int curY, int l, int w, int r, int c){
    if (curX+l > r+1 || curY+w > c+1) return true;
    return psa[curX+l-1][curY+w-1]+psa[curX-1][curY-1]-psa[curX-1][curY+w-1]-psa[curX+l-1][curY-1];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int l, r, w, c;

    cin >> r >> c;
    cin >> l >> w;

    string line;
    for (int i=1; i<=r; i++){
        cin >> line;

        for (int k=0; k<c; k++){
            if (line[k] == '#'){
                psa[i][k+1] ++;
            }

            psa[i][k+1] += psa[i-1][k+1]+psa[i][k]-psa[i-1][k];
        }
    }

    queue <pair <pair <int, int>, int>> q;

    int ans = -1;

    q.push({{1, 1}, 0});

    pair <pair <int, int>, int> stuff;
    int curX, curY, curDist;

    while (!q.empty()){
        stuff = q.front(); q.pop();

        curX = stuff.f.f; curY = stuff.f.s; curDist = stuff.s;
        
        if (visited[curX][curY]) continue;

        visited[curX][curY] = true;

        if (good(curX, curY, l, w, r, c)) continue;

        if (curX == r-l+1 && curY == c-w+1){
            ans = curDist;
            break;
        }

        if (curX+1 <= r){
            q.push({{curX+1, curY}, curDist+1});
        }
        if (curY+1 <= c){
            q.push({{curX, curY+1}, curDist+1});
        }
        if (curX-1 >=1){
            q.push({{curX-1, curY}, curDist+1});
        }
        if (curY-1 >= 1){
            q.push({{curX, curY-1}, curDist+1});
        }
    }

    cout << ans << "\n";
}