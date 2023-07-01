#include <bits/stdc++.h>
using namespace std;

#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int nax = 5e5+5;

int arr[nax];
struct Node{
    int L, R;
    unordered_map <int, int> freq;
}seg[nax*4];

void buildTree(int curNode, int left, int right){
    
    s.L = left; s.R = right;
    if (left == right){
        s.freq[0] = 1;
    }

    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.freq[0] = cl.freq[0]+cr.freq[0];
    }

}

void pushUp(int curNode, int val, int inc){
    s.freq[val] += inc;
    if (s.freq[val] == 0) s.freq.erase(val);
}

void update(int curNode, int idx, int inc){
    int L = s.L, R = s.R;
    if (L > idx || R < idx) return;

    else if (L == R && R == idx){
        s.freq.erase(arr[idx]);
        s.freq[arr[idx]+inc]=1;
    }

    else{

        update(curNode*2, idx, inc);
        update(curNode*2+1, idx, inc);

        pushUp(curNode, arr[idx], -1);
        pushUp(curNode, arr[idx]+inc, 1);
    }
}

int query(int curNode, int QL, int QR, int want){
    int L = s.L, R = s.R;
    if (L > QR || R  < QL || s.freq[want] == 0) return 0;

    if (QL <= L && R <= QR){
        return s.freq[want];
    } 
    
    return query(curNode*2, QL, QR, want)+query(curNode*2+1, QL, QR, want);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    buildTree(1, 0, n-1);

    int oper, c, x, l, r;

    while (q--){
        cin >> oper;
        if (oper == 1){
            cin >> x;
            x--;
            update(1, x, 1);
            arr[x]++;
        }
        else if (oper == 2){
            cin >> x;
            x--;
            update(1, x, -1);
            arr[x]--;
        }

        else{
            cin >> l >> r >> c;
            cout << query(1, l-1, r-1, c) << "\n";
        }

    }

}