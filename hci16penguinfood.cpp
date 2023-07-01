#include <bits/stdc++.h>
using namespace std;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int MAXSZ=1e6+5;
int arr[MAXSZ];
struct segTree{
    int L, R, SUM, PREF, SEG, SUF;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.SEG = arr[left];
        s.SUM = arr[left];
        s.PREF = arr[left];
        s.SUF = arr[left];
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left ,mid);
    buildTree(curNode*2+1, mid+1, right);

    s.SUM = cl.SUM + cr.SUM;
    s.PREF = max(cl.PREF, cl.SUM+cr.PREF);
    s.SUF = max(cr.SUF, cr.SUM+cl.SUF);
    s.SEG = max(max(cl.SEG, cr.SEG), cl.SUF+cr.PREF);
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;

    if (L > idx || R < idx) return;

    else if (L==R && L==idx){
        s.SEG = newVal;
        s.SUM = newVal;
        s.PREF =newVal;
        s.SUF = newVal;
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);

    s.SUM = cl.SUM + cr.SUM;
    s.PREF = max(cl.PREF, cl.SUM+cr.PREF);
    s.SUF = max(cr.SUF, cr.SUM+cl.SUF);
    s.SEG = max(max(cl.SEG, cr.SEG), cl.SUF+cr.PREF);
}

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    cout << max(0, seg[1].SEG) << "\n";

    cin >> m;
    int x, y;
    while (m--){
        cin >> x >> y;
        update(1, x, y);
        cout << max(0,seg[1].SEG) << "\n";
    }


    return 0;
}