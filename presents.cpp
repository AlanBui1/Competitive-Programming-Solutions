#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 2e5+5;

int parent[MAXSZ];
int findSet(int a){
    return parent[a] == a ? a : parent[a] = findSet(parent[a]);
}
void unionsets(int a, int b){
    a = findSet(a); b = findSet(b);

    parent[a] = b;
}

int32_t main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector <int> ppl(N);
    for (int i=0; i<N; i++){
        cin >> ppl[i];
    }
    sort(ppl.begin(), ppl.end());

    int P; cin >> P;
    vector <int> presents(P);
    for (int i=0;i<P; i++){
        cin >> presents[i];
        parent[i] = i;
    }
    sort(presents.begin(), presents.end());
    int ans =0;
    bool flag = 0;

    for (int i=0; i<N; i++){
        auto it = upper_bound(presents.begin(), presents.end(), ppl[i]);
        it--;
        int ind = findSet(it - presents.begin());
        //cout << "IND: " << findSet(ind) << "\n";

        if ( ind < 0 || presents[ind] > ppl[i] || (flag && ind == 0)){
            cout << "-1\n";
            return 0;
        }

        ans += abs(ppl[i] - presents[findSet(ind)]);

        if (ind > 0)unionsets(ind, ind - 1);
        else flag = 1;
    }
    cout << ans << "\n";

}