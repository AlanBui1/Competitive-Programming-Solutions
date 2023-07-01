#include <bits/stdc++.h>
using namespace std;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int nax = (1<<20) + 5;

int arr[nax], n,N, m, wins[nax];

struct node{
    int L, R, val, id, depth;
}seg[nax*4];

void pushUp(int curNode){
    if (cl.val > cr.val){
        s.val = cl.val;
        s.id = cl.id;
        wins[cl.id] = s.depth;
        wins[cr.id] = cr.depth;

    }
    else{
        s.val = cr.val;
        s.id = cr.id;
        wins[cr.id] = s.depth;
        wins[cl.id] = cl.depth;
        
    }
}

void buildTree(int curNode, int left, int right, int dep){
    s.L = left; s.R= right;
    s.depth = dep;
    if (left == right){
        s.val = arr[left];
        s.id = left; 
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid, dep-1);
        buildTree(curNode*2+1, mid+1, right, dep-1);
        
        pushUp(curNode);
    }
}

void update(int curNode, int idx, int newVal){
    int L= s.L, R=s.R;

    if (L > idx ||R<idx) return;

    if (L==R && L==idx){
        s.val = newVal;
        s.id = L; 
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);
    pushUp(curNode);
    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> m;
    n = 1 << N;
    for (int i=0;i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1, N);

    char oper;
    int x, y;

    while (m--){
        cin >> oper;
        if (oper == 'W'){
            cout << seg[1].id+1 << "\n";
        }
        else if (oper == 'R'){
            cin >> x >> y; x--;
            wins[x] = 0;
            update(1, x, y);
        }
        else{
            cin >> x;
            cout << wins[x-1] << "\n";
        }
        
    }



    
}