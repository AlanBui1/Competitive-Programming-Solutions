#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e5+5;
const int MA = 1e6;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const ll inf = 0;

struct node{
    int L, R;
    ll SUM, SUF, PREF, SEG;
}seg[MA];

ll arr[MAXSZ];

void pushUp(int curNode){
    s.SUM = cl.SUM+cr.SUM;
    s.PREF = max(cl.PREF, (cl.SUM+cr.PREF));
    s.SUF = max(cr.SUF, cr.SUM+cl.SUF);
    s.SEG =  max(cl.SEG, max(cr.SEG, cl.SUF+cr.PREF));
}

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.SUF = arr[left];
        s.PREF = arr[left];
        s.SEG = arr[left];
        s.SUM = arr[left];
        return;
    }
    int mid = (left+right)/2;

    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
    pushUp(curNode);
    
}

// void update(int curNode, int idx, int newVal){
//     int L = s.L, R = s.R;

//     if (L == R && L == idx){
//         s.SUF = newVal;
//         s.PREF = newVal;
//         s.SEG = newVal;
//         s.SUM = newVal;
//         return;
//     }

//     buildTree(curNode*2, idx, newVal);
//     buildTree(curNode*2+1, idx, newVal);
//     pushUp(curNode);
// }

node query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (QL <= L && R <= QR){
        return s;
    }
    else if (L > QR || R < QL){
        node N;
        N.SUF = -inf; N.PREF = -inf; N.SUM = -inf; N.SEG = -inf;
        return N;
    }

    node lhs = query(curNode*2, QL, QR);
    node rhs = query(curNode*2+1, QL, QR);
    node ret;

    ret.SUM = lhs.SUM+rhs.SUM;
    ret.PREF = max(lhs.PREF, lhs.SUM+rhs.PREF);
    ret.SUF = max(rhs.SUF, rhs.SUM+lhs.SUF);
    ret.SEG = max(lhs.SEG, max(rhs.SEG, lhs.SUF+rhs.PREF));
    return ret;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    } 
    buildTree(1, 0, 2*n-1);

    ll ans = 0;

    for (int i=0; i<n; i++){
        ans = max(ans, query(1, i, i-1+k).SEG);   
    }
    
    cout << ans << "\n";
    
}