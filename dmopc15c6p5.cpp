#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=3e6+5;

ll arr[MAXSZ];
queue <ll> Q;
deque <ll> maxQ, minQ;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    ll p1=0, p2=0, ans = 0;

    Q.push(arr[0]);
    maxQ.push_back(arr[0]); minQ.push_back(arr[0]);

    while (p1 < n && p2 < n){
        if (maxQ.front()-minQ.front() <= k){
            ans += (p2-p1+1);
            p2++;

            if (p2 >= n) break;
            while (!maxQ.empty() && maxQ.back() < arr[p2]){
                maxQ.pop_back();
            }
            maxQ.push_back(arr[p2]);

            while (!minQ.empty() && minQ.back() > arr[p2]){
                minQ.pop_back();
            }
            minQ.push_back(arr[p2]);

            Q.push(arr[p2]);
        }

        else{
            p1++;

            if (Q.front() == minQ.front()){
                minQ.pop_front();
            }
            if (Q.front() == maxQ.front()){
                maxQ.pop_front();
            }
            Q.pop();
        }
    }

    cout << ans << "\n";

}