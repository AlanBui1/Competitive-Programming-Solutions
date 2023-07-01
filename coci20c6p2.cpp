#include <bits/stdc++.h>
using namespace std;
const int nax = 1005;
const long long inf=1e16;

unordered_map <string, int> conv;
vector <pair <int, int>> graph[nax];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    int cnt = 0;

    string a, b; int d;

    for (int i=0; i<m; i++){
        cin >> a >> b >> d;
        if (conv[a] == 0){
            cnt++; conv[a] = cnt;
        }
        if (conv[b] == 0){
            cnt++; conv[b] = cnt;
        }

        graph[conv[a]].push_back({conv[b], d});
    }

    int q; cin >>q;
    
    while (q--){
        string start, dest; cin >> start >> dest;
        int s = conv[start], e = conv[dest];

        priority_queue<pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;

        pair <long long, long long> node;
        long long curNode, curDist;

        pq.push({0, s});

        long long dist[nax];
        for (int i=0; i<nax; i++) dist[i] = inf;

        dist[s] = 0;

        while (!pq.empty()){
            node = pq.top(); pq.pop();
            curNode = node.second; 
            curDist = node.first;

            for (pair <long long, long long> nxt : graph[curNode]){
                if (dist[nxt.first] > curDist+nxt.second){
                    dist[nxt.first] = curDist+nxt.second;
                    pq.push({dist[nxt.first], nxt.first});
                }
            }
        }

        if (dist[e] == inf){
            cout << "Roger\n";
        }
        else{
            cout << dist[e] << "\n";
        }


    }

}