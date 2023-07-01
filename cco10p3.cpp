#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MAXSZ=1e6+5;

int bit[MAXSZ], id[MAXSZ];


struct query{
    char op;
    int x, r, k;
};

unordered_map <int, int> conv;
unordered_map <int, int> reverseID; //conv id to rating
vector <int> nums;
vector <query> ops; 

void update(int i, int v){
    for(; i< MAXSZ; i+= i &-i){
        bit[i] += v;
    }
}

int sum(int i){
    int s =0;

    for (; i>0; i-= i&-i){
        s += bit[i];
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    char oper;
    int x, r;
    cin >> n;
    for (int i=0; i<n; i++){
        query newQ;
        cin >> oper;
        newQ.op = oper;

        if (oper == 'Q'){
            cin >> x;
            newQ.k =x;   
        }
        else{
            cin >> x >> r;
            newQ.x = x;
            newQ.r = r;
            nums.push_back(r);
        }

        ops.push_back(newQ);
    }

    sort(nums.begin(), nums.end());

    int cnt=1;

    conv[nums[0]] = cnt;
    for (int i=1; i<nums.size(); i++){
        if (nums[i] != nums[i-1]){
            cnt++;
            conv[nums[i]] = cnt;
        }
    }

    int num=0;
    for (query Q : ops){
        if (Q.op == 'N'){
            id[conv[Q.r]] = Q.x;
            reverseID[Q.x] = conv[Q.r];
            update(conv[Q.r], 1);
            num++;
        }

        else if (Q.op == 'M'){

            update(reverseID[Q.x], -1);

            reverseID[Q.x] = conv[Q.r];
            id[conv[Q.r]] = Q.x;

            update(conv[Q.r], 1);
            
        }

        else{
            int L=1, R=MAXSZ-1;
            int ans=-1;

            while (L <= R){
                int mid = (L+R)/2;
           
                int S = sum(mid);
          
                if (num-S+1 == Q.k){
                    if (id[mid] != 0) ans =  mid;
                    
                    R = mid-1;
                }

                else if (num-S+1 < Q.k){
                    R= mid-1;
                }
                else{
                    L=mid+1;
                }
            }
            cout << id[ans] << "\n";
        }
    }

}