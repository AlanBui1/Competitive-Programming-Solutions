#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=105;
#define f first
#define s second
const int inf=1e9;

pair <int, string> people[MAXSZ];
int dp[25][MAXSZ];
int best[MAXSZ];

int maxQuery(int QL, int QR){
    int MAX=-1;

    for (int i=QL; i<=QR; i++){
        MAX = max(MAX, people[i].f);
    }

    return MAX;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int k; cin >> k;
    int n; cin >> n;

    for (int i=1; i<=n; i++){
        cin >> people[i].s >> people[i].f;
    }

    dp[1][1] = people[1].f;


    for (int i=1; i<=n; i++) best[i]=inf;
    best[1] = dp[1][1];


    for (int i=2; i<=n; i++){
        for (int j=1; j<=k; j++){
            if (j>i) break;

            dp[j][i] = maxQuery(i-j+1, i) + best[i-j];
            best[i] = min(best[i], dp[j][i]);
        }
    }

    cout << "Total Time: " << best[n] << "\n";



    int ind=n;
    vector <int> ans;
    while (ind >0){
        for (int i=k; i>0; i--){
            if (best[ind] == dp[i][ind]){
                ans.push_back(i);
                ind -= i;
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    int cur=1;
    for (int i=0; i<=ans.size(); i++){
        for (int j=1; j<ans[i]; j++){
            
            cout << people[cur].s << " ";
            cur++;
        }
        cout << people[cur].s;
        cur++;
        if (i != ans.size()) cout << "\n";
    }

}