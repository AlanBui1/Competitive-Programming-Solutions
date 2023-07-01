#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define ll __int128_t

struct segTree{
    int L, R;
    bitset<1005> freq;
}seg[MAXSZ*4];

int arr[MAXSZ];
unordered_map <int, int> conv;
int nums[1005];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.freq[conv[arr[left]]] = 1;
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.freq = cl.freq | cr.freq;
    }
}

void update(int curNode, int idx, int newVal, int oldVal){
    int L=s.L, R=s.R;

    if (L > idx || R < idx) return;

    if (L==R && L==idx){
        s.freq[oldVal] = 0;
        s.freq[newVal] = 1;
    }

    else{
        update(curNode*2, idx, newVal, oldVal);
        update(curNode*2+1, idx, newVal, oldVal);
        s.freq = cl.freq|cr.freq;
    }

}

bitset<1005> query(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    if (L > QR || R < QL) return 0;

    else if (QL <= L && R <= QR){
        return s.freq;
    }
    return query(curNode*2, QL, QR) | query(curNode*2+1, QL, QR);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    int newval=1;
    
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (conv[arr[i]] == 0){
            conv[arr[i]] = newval;
            newval++;
        }
        nums[conv[arr[i]]] ++;
        
    }

    buildTree(1, 0, n-1);

    int oper, l, r;
    while (q--){
        cin >> oper >> l >> r;
        int old = conv[arr[l-1]];

        if (oper == 1){
            nums[conv[arr[l-1]]]--;
            if (conv[r] == 0){
                if (nums[conv[arr[l-1]]] == 0){
                    conv[r] = conv[arr[l-1]];
                    conv[arr[l-1]] = 0;
                }
                else{
                    conv[r] = newval;
                    newval++;
                }
            }
            nums[conv[r]]++; arr[l-1] = r;

            update(1, l-1, conv[r], old);
        }
        else{
            cout << query(1, l-1, r-1).count() << "\n";
        }
    }

}