#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

int N, Q, P[MAXSZ], comps = 0, cycleNum[MAXSZ], R[MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i=1; i<=N; i++){
        cin >> P[i];
        R[P[i]] = i;
    }

    int curCycle = 1;

    for (int i=1; i<=N; i++){
        if (!cycleNum[i]){
            curCycle++;
            for (int cur = i; !cycleNum[cur]; cur = P[cur]){
                cycleNum[cur] = curCycle;
            }
        }
    }

    while (Q--){
        int leng; cin >> leng;
        set <int> query, used;
        for (int i=0; i<leng; i++){
            int x; cin >> x;
            query.insert(x);
            used.insert(cycleNum[x]);
        }

        int ans = curCycle - used.size();

        for (int i : query){
            if (query.count(R[i]) == 0){
                ans++;
            }
        }

        cout << ans-1 << "\n";
    }

}