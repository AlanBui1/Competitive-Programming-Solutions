#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=25e4+5;

int n, m, a, b;
string nums;

struct segTree{
    int L, R;
    int vals[10];
    int lazy;
}seg[MAXSZ*4];

void lazyPush(int curNode){
    int L=seg[curNode].L, R=seg[curNode].R;

    int newArr[10];
    for (int i=0; i<10; i++){
        newArr[i] = seg[curNode].vals[(i-seg[curNode].lazy +10)%10];
    }
    for (int i=0; i<10; i++) seg[curNode].vals[i] = newArr[i];

    if (L==R){
        seg[curNode].lazy=0;
        return;
    }

    seg[curNode*2].lazy += seg[curNode].lazy;
    seg[curNode*2].lazy %= 10;
    seg[curNode*2+1].lazy+=seg[curNode].lazy;
    seg[curNode*2+1].lazy %=10;
    seg[curNode].lazy=0;
}

void buildTree(int curNode, int left, int right){
    seg[curNode].L=left; seg[curNode].R=right;
    seg[curNode].lazy=0;

    //if its a leaf
    if (left==right){
        seg[curNode].vals[nums[left]-'0'] = 1;
    }

    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        for (int i=0; i<10; i++){
            seg[curNode].vals[i] = seg[curNode*2].vals[i]+seg[curNode*2+1].vals[i];
        }
    }
}

int sumQuery(int curNode, int QL, int QR){
    int L=seg[curNode].L, R=seg[curNode].R;
    lazyPush(curNode);
    if (L>QR || R<QL) return 0;

    if (QL<=L && R<= QR) {
        int s=0;
        for (int i=0; i<10; i++){
            s += i*seg[curNode].vals[i];
        }
        return s;
    }

    return sumQuery(curNode*2, QL, QR) + sumQuery(curNode*2+1, QL, QR);
}

void update(int curNode, int UL, int UR){
    int L=seg[curNode].L, R=seg[curNode].R;

    lazyPush(curNode);

    if (L>UR || R<UL) return;

    //if its completely in range
    if (UL<=L && R<=UR){
        seg[curNode].lazy++;
        // seg[curNode].lazy%=10;
        lazyPush(curNode);
        return;
    }

    //partially in range
    update(curNode*2, UL, UR);
    update(curNode*2+1, UL, UR);
    
    for (int i=0; i<10; i++){
        seg[curNode].vals[i] = seg[curNode*2].vals[i]+seg[curNode*2+1].vals[i];
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> nums;
    buildTree(1, 0, n-1);
    while (m--){
        cin >> a >> b;
        a--; b--;
        cout << sumQuery(1, a, b) << "\n";
        update(1, a, b);
    }
}