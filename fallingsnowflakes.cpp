#include <bits/stdc++.h>
using namespace std;

const int MAXSZ=5005;
const int MAXQ = 1e5+5;

int bit[MAXSZ][MAXSZ];
int ans[MAXQ];

void update(int r, int c, int upd){
    for (int i=r; i<MAXSZ; i+=(i&-i)){
        for (int k=c; k<MAXSZ; k+=(k&-k)){
            bit[i][k] += upd;
        }
    }
}

int sum(int x, int y){
    int s=0;
    for (int i=x; i>0; i-=(i&-i)){
        for (int k=y; k>0; k-=(k&-k)){
            s += bit[i][k];
        }
    }
    return s;
}

int query(int x1, int y1, int x2, int y2){
    return sum(x2,y2) - sum(x2, y1-1)- sum(x1-1, y2) + sum(x1-1, y1-1);
}

struct stuff{
    char op; //R, C, V, U
    int r, c, a, b, d, t, change, I;
};

vector <stuff> qs;

bool compare(stuff x, stuff y){
    if (x.t != y.t){
        return x.t < y.t;
    }

    if (x.op == 'U') return 1;
    else return 0;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;

    for (int i=0; i<m; i++){
        int r, c, l, d; cin >> r >> c >> l >> d;
        stuff temp;
        temp.r=r; temp.c=c;
        temp.op = 'U';
        temp.change = 1;
        temp.t = l;
        qs.push_back(temp);

        stuff temp2;
        temp2.r=r; temp2.c=c;
        temp2.op = 'U';
        temp2.t = d;
        temp2.change = -1;
        qs.push_back(temp2);
    }

    for (int i=0; i<q; i++){
        char oper; cin >> oper;
        stuff temp;

        temp.op = oper; temp.I = i;
        if (oper == 'R' || oper == 'C'){
            int a, b, t; cin >> a >> b >> t;
            temp.a = a; temp.b = b; temp.t = t;
            qs.push_back(temp);
        }
        else{
            int a, b, c, d, t; cin >> a >> b >> c >> d >> t;
            temp.a = a; temp.b = b; temp.c = c; temp.d = d; temp.t = t;
            qs.push_back(temp);
        }
    }

    sort(qs.begin(), qs.end(), compare);


    for (stuff Q : qs){
        //cout << Q.op << " " << Q.t << "\n";
        if (Q.op == 'U'){
            update(Q.r+1, Q.c+1, Q.change);
        }
        else if (Q.op == 'R'){
            //cout << query(Q.a, 0, Q.b, n) << "\n";
            ans[Q.I] = query(Q.a+1, 1, Q.b+1, n);
        }
        else if (Q.op == 'C'){
            ans[Q.I] = query(1, Q.a+1, n, Q.b+1);
            //cout << query(0, Q.a, n, Q.b) << "\n";
        }
        else{
            ans[Q.I] = query(Q.a+1, 1, Q.b+1, n) + query(1, Q.c+1, n, Q.d+1) - query(Q.a+1, Q.c+1, Q.b+1, Q.d+1);
            //cout << query(Q.a, 0, Q.b, n) + query(0, Q.c, n, Q.d) - query(Q.c, Q.a, Q.d, Q.b) << "\n";
        }
    }

    for (int i=0; i<q; i++) cout << ans[i] << "\n";
}