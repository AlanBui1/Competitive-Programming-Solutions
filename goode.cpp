#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

int n, m, l, ans, fail;

struct segTree{
    int L, R, lazy, val;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R=right;
    s.lazy = 0;
    if (left == right){
        s.val = 1;
        return;
    }
    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
    s.val = cl.val+cr.val;
}

void lazyPush(int curNode){
    int L=s.L, R=s.R;

    if (s.lazy <= 0) return;

    s.val = (R-L+1) - s.val;

    if (L==R){
        s.lazy = 0;
        return;
    }

    cl.lazy += s.lazy;
    cr.lazy += s.lazy;
    cl.lazy %= 2;
    cr.lazy %= 2;
    s.lazy = 0;
}

void update(int curNode, int UL, int UR){
    int L=s.L, R=s.R;

    if (s.lazy > 0) lazyPush(curNode);

    if (L> UR || R < UL){
        return;
    }

    else if (UL <= L && R <= UR){
        s.lazy ++;
        s.lazy %= 2;
        lazyPush(curNode);
        return;
    }

    update(curNode*2, UL, UR);
    update(curNode*2+1, UL, UR);
    s.val = cl.val+cr.val;
}

void query(int curNode){
    int L=s.L, R=s.R;

    if (ans != -1) return;    
    lazyPush(curNode*2); lazyPush(curNode*2+1);

    if (cl.val + fail > l){
        query(curNode*2);
    }

    else if (cl.val + fail == l){
        if (cl.L == cl.R){
            ans = cl.L;
            fail ++;
            return;
        }

        else{
            query(curNode*2);
            query(curNode*2+1);
        }
    }

    else{
        fail += cl.val; 

        if (cr.L == cr.R && fail + cr.val == l){
            ans = cr.L;
            return;
        }
        query(curNode*2+1);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
   
    cin >> n >> m >> l;
    buildTree(1, 0, n-1);
    int a, b;

    while (m--){
        cin >> a >> b;
        a--; b--;
        update(1, a, b);

        fail = 0;
        ans = -1;

        lazyPush(1);

        if (seg[1].val < l){
            cout << "AC?\n";
        }

        else{
            query(1);
            cout << ans+1 << "\n";
        }

    }

}