#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 5e5+5;

int parent[MAXSZ], ans[MAXSZ];
bool used[MAXSZ];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    parent[a] = parent[b];
}

vector <int> arr;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
    }

    int n, m; cin >> n >> m;

    for (int i=0; i<n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    used[0] = 1;
    ans[0] = arr[0];
    unionsets(0, 1);

    for (int i=1; i<n; i++){
        int want = m-ans[i-1];
        auto op = lower_bound(arr.begin(), arr.end(), want);
        int ind = op-arr.begin();

        if (used[ind]){
            int nxt = find(ind);
            if (nxt >= n){
                cout << "-1\n";
                return 0;
            }
            used[nxt] = 1;
            ans[i] = arr[nxt];
            unionsets(nxt, nxt+1);
        }

        else{
            used[ind] = 1;
            unionsets(ind, ind+1);
            ans[i] = arr[ind];
        }
    }

    for (int i=0; i<n-1; i++){
        if (ans[i]+ans[i+1]< m){
            cout << "-1\n";
            return 0;
        }
    }

    for (int i=0; i<n-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << "\n";


}