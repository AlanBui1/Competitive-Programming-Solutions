#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6+5;

int arr[nax];

queue <int> Q;
deque <int> minDeque, maxDeque;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m, c; cin >> n >> m >> c;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    Q.push(arr[0]);
    minDeque.push_back(arr[0]);
    maxDeque.push_back(arr[0]);

    for (int i=1; i<m; i++){
        Q.push(arr[i]);

        while (!minDeque.empty() && minDeque.back() > arr[i]){
            minDeque.pop_back();
        }
        minDeque.push_back(arr[i]);

        while (!maxDeque.empty() && maxDeque.back() < arr[i]){
            maxDeque.pop_back();
        }
        maxDeque.push_back(arr[i]);
    }
    bool flag=0;
    for (int i=0; i<=n-m; i++){
        if (maxDeque.front() - minDeque.front() <= c){
            cout << i+1 << "\n";
            flag = 1;
        }
        if (minDeque.front() == Q.front()){
            minDeque.pop_front();
        }
        if (maxDeque.front() == Q.front()){
            maxDeque.pop_front();
        }
        Q.pop();

        while (!minDeque.empty() && minDeque.back() > arr[i+m]){
            minDeque.pop_back();
        }
        minDeque.push_back(arr[i+m]);

        while (!maxDeque.empty() && maxDeque.back() < arr[i+m]){
            maxDeque.pop_back();
        }
        maxDeque.push_back(arr[i+m]);
        Q.push(arr[i+m]);
    }
    if (!flag){
        cout << "NONE\n";
    }

}