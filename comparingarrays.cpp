#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int MAXSZ = 5e5+5;
const int MOD = 1e9+7;
const int MOD2 = 1e9+21;
const int BASE = 113;
const int BASE2 = 131;

int arr[MAXSZ], powers[MAXSZ], powers2[MAXSZ];
int n, q;

struct node{
    int L, R, val, val2;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.val = arr[left]*powers[n-left];
        s.val %= MOD;
        s.val2 = arr[left]*powers2[n-left];
        s.val2 %= MOD2;
        return;
    }

    int mid = (left+right)/2;

    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    s.val = (cl.val+cr.val)%MOD;
    s.val2 = (cl.val2+cr.val2)%MOD2;
}

void update(int curNode, int idx, int newVal){
    int L = s.L, R = s.R;

    if (idx > R || idx < L){
        return;
    }

    if (idx == L && L == R){
        s.val = newVal*powers[n-L];
        s.val %= MOD;
        s.val2 = newVal*powers2[n-L];
        s.val2 %= MOD2;
        return;
    }
    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);

    s.val = (cl.val+cr.val)%MOD;
    s.val2 = (cl.val2+cr.val2)%MOD2;
}

int query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL) return 0;

    if (QL <= L && R <= QR) return s.val;

    return (query(curNode*2, QL, QR) + query(curNode*2+1, QL, QR))%MOD;
}

int query2(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL) return 0;

    if (QL <= L && R <= QR) return s.val2;

    return (query2(curNode*2, QL, QR) + query2(curNode*2+1, QL, QR))%MOD2;
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    powers[0] = 1;
    powers2[0] = 1;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        powers[i] = powers[i-1]*BASE;
        powers[i] %= MOD;
        powers2[i] = powers2[i-1]*BASE2;
        powers2[i] %= MOD2;
    }

    buildTree(1, 1, n);

    int oper, l1, l2, r1, r2, v, ind;

    while (q--){
        cin >> oper;

        if (oper == 1){
            cin >> l1 >> r1 >> l2 >> r2;

            int sum1 = query(1, l1, r1), sum2 = query(1, l2, r2);
            int sum3 = query2(1, l1, r1), sum4 = query2(1, l2, r2);

            if (l1 > l2){
                sum1 *= powers[l1-l2];
                sum1 %= MOD;
                sum3 *= powers2[l1-l2];
                sum3 %= MOD2;
            }
            else if (l2 > l1){
                sum2 *= powers[l2-l1];
                sum2 %= MOD;
                sum4 *= powers2[l2-l1];
                sum4 %= MOD2;
            }

            if (sum1 == sum2 && sum3 == sum4){
                cout << "1\n";
            }
            else cout << "0\n";
            //cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 <<  "\n";

        }
        else{
            cin >> ind >> v;
            update(1, ind, v);
        }
    }

}