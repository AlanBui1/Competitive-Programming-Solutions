#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

set<int> heights[MAXSZ];
bool vis[MAXSZ];
int arr[MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i=1; i<=N; i++){
        cin >> arr[i];
        heights[arr[i]].insert(i);
    }

    int ans = 0;

    for (int i=1; i<=N; i++){
        if (vis[i]) continue;
        ans++;

        int curInd = i;

        while (curInd <= N){
            //cout << curInd << "\n";
            auto it = heights[arr[curInd] - 1].lower_bound(curInd);
            if (it == heights[arr[curInd] - 1].end()) break;
            int nxtInd = *it;

            vis[nxtInd] = 1;
            heights[arr[curInd] - 1].erase(it);
            curInd = nxtInd;
        }
    }

    cout << ans << "\n";
}