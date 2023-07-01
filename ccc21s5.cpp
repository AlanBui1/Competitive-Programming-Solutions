#include <bits/stdc++.h>

using namespace std;
const int MAXSZ=150005;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

ll gcd(ll a, ll b){
    if (a == -1) return b;
    if (b == -1) return a;
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

struct node{
    ll L, R, GCD;
}seg[MAXSZ*4];

struct req{
    ll QL, QR, val;
};

vector <req> qs;
int n, m, x, y, z;
ll arr[MAXSZ], diff[17][MAXSZ];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R =right;
    if (left == right){
        s.GCD = arr[left];
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode << 1, left, mid);
        buildTree(curNode << 1 | 1, mid+1, right);
        s.GCD = gcd(cl.GCD, cr.GCD);
    }
}

ll query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL) return -1;
    if (QL <= L && R <= QR) return s.GCD;
    return gcd(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<MAXSZ; i++) arr[i] = 1;

    for (int i=0; i<m; i++){
        cin >> x >> y >> z;
        req temp; temp.QL = x-1; temp.QR = y-1; temp.val = z;
        diff[z][x-1]++; diff[z][y]--;
        qs.push_back(temp);
    }

    for (int i=0; i<n; i++){
        for (int k=0; k<17; k++){
            diff[k][i] += diff[k][i-1];
            if (diff[k][i] > 0){
                arr[i] = lcm(arr[i], k);
            }
        }
    }

    bool flag = 0;

    buildTree(1, 0, n-1);

    for (req Q : qs){
        if (query(1, Q.QL, Q.QR) != Q.val){
            flag = 1;
            break;
        }
    }
    for (int i : arr){
        if (i > 1000000000) flag = 1;
    }

    if (flag){
        cout << "Impossible\n";
    }
    else{
        for (int i=0; i<n-1; i++){
            cout << arr[i] << " ";
        }
        cout << arr[n-1] << "\n";
    }

    return 0;
}