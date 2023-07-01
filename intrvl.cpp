#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

struct query{
    int val, ind, type, I;
};

bool compare(query x, query y){
    if (x.ind != y.ind){
        return x.ind < y.ind;
    }

    return x.type < y.type;
}

vector <query> Qs;
int ans[MAXSZ];


int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;

        query Q; Q.ind = a; Q.val = 1; Q.type = 0;

        Qs.push_back(Q);

        Q.ind = b+1; Q.val = -1; Q.type = 0;

        Qs.push_back(Q);
    }

    for (int i=0; i<q; i++){
        int x; cin >> x;
        query Q;
        Q.ind = x; Q.type = 1; Q.I = i;
        Qs.push_back(Q);
    }

    sort(Qs.begin(), Qs.end(), compare);

    int sz = Qs.size(), cur =0;

    for (int i=0; i<sz; i++){
        if (Qs[i].type){
            ans[Qs[i].I] = cur;
        }

        else{
            cur += Qs[i].val;
        }
    }

    for (int i=0; i<q; i++){
        cout << ans[i] << "\n";
    }
}