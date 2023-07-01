#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

int arr[MAXSZ];
bool bad[MAXSZ];

unordered_map <int, int> freq, used;
unordered_map <int, vector <int>> inds;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, num; cin >> n;

    bool flag = 0;

    for (int i=0; i<n*2; i++){
        cin >> arr[i];
        freq[arr[i]]++;
        inds[arr[i]].push_back(i);
        if (freq[arr[i]] >= n){
            flag = 1;
            num = arr[i];
        }
    }

    if (flag){
        cout << 2*n - freq[num] << "\n";

        for (int i : inds[num]){
            bad[i] = 1;
        }
        int cur = 0;

        for (int i=0; i<2*n; i++){
            if (!bad[i]){
                cout << i+1 << " " << inds[num][cur]+1 << "\n";
                cur++;
            }
        }

        for (int i=cur; i<freq[num]; i+=2){
            cout << inds[num][i]+1 << " " << inds[num][i+1]+1 << "\n";
        }
    }

    else{
        cout << n << "\n";
        priority_queue <pair<int, int>> pq;

        for (pair <int, int> i : freq){
            pq.push({i.second, i.first});
        }

        while (!pq.empty()){
            pair <int, int> T = pq.top(); pq.pop();
            pair <int, int> S = pq.top(); pq.pop();

            //cout << T.first << " " << T.second << " "  << S.first << " " << S.second << "\n";

            if (T.first == 0){
                break;
            }
            cout << inds[T.second][used[T.second]]+1 << " " << inds[S.second][used[S.second]]+1 << "\n";

            used[T.second]++; used[S.second]++;

            pq.push({T.first-1, T.second});
            pq.push({S.first-1, S.second});

        }
    }



}