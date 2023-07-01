#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define f first
#define s second

const int MAXSZ = 1e6+5;

unordered_map <int, int> conv;

struct node{
    int L, R, maxVal;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L = left;
    seg[curNode].R = right;
    if (left == right){
        return;
    }
    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
}

void update(int curNode, int idx, int newVal){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (L == R && L == idx){
        seg[curNode].maxVal = max(seg[curNode].maxVal, newVal);
        return;
    }
    if (L > idx || R < idx) return;

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);

    seg[curNode].maxVal = max(seg[curNode*2].maxVal, seg[curNode*2+1].maxVal);
}

int query(int curNode, int QL, int QR){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (L > QR || R < QL) return 0;
    if (QL <= L && R <= QR) return seg[curNode].maxVal;
    return max(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

struct info{
    int op, a, ind, q;
};

bool compare(info x, info y){
    if (x.a == y.a){
        return x.op > y.op;
    }
    return x.a < y.a;
}

int dp[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    vector <pii> alpaca(N+1);
    vector <info> queries;

    for (int i=1; i<=N; i++){
        cin >> alpaca[i].f >> alpaca[i].s;
    }

    sort(alpaca.begin() ,alpaca.end());
    int cnt = 0;
    vector <int> nums;
    for (pii al : alpaca){
        if (al.f == 0) continue;
        cnt++;

        queries.push_back({0, al.f, cnt, al.f - al.s});
        queries.push_back({1, al.f+al.s, cnt, al.f});

        nums.push_back(al.f - al.s);
        nums.push_back(al.f);
    }

    sort(nums.begin(), nums.end());
    cnt = 1;
    conv[nums[0]]= cnt;
    for (int i=1; i<nums.size(); i++){
        if (nums[i] != nums[i-1]){
            cnt++;
            conv[nums[i]] = cnt;
        }
    }

    sort(queries.begin(), queries.end(), compare);
    buildTree(1, 0, MAXSZ-1);
    for (info I : queries){
        I.q = conv[I.q];
        if (I.op == 0){
            if (I.q > 0) dp[I.ind] = 1 + query(1, 0, I.q);
            else{
                dp[I.ind] = 1;
            }
        }
        else{
            if (I.q > 0) update(1, I.q, dp[I.ind]);
        }
        //cout << I.ind << " " << dp[I.ind] << "\n";
        //cout << I.op << " " << I.a << " " << I.ind << " " << I.q << " " <<dp[I.ind] << "\n";
    }

    int ans = 0;
    for (int i=1; i<=N; i++){
        //cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

}