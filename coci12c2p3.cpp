#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    priority_queue <int, vector <int>, greater<int>> pq;

    cin >> N;
    for (int i=0; i<N; i++){
        int x; cin >> x;

        pq.push(x);
    }

    int moves = 0, cnt = 1;

    while (cnt < N){
        int top = pq.top(); pq.pop();

        if (top + cnt <= N){
            cnt += top +1;
            moves += top;
        }
        else{
            moves += N - cnt;
            break;
        }
    }

    cout << moves << "\n";
}