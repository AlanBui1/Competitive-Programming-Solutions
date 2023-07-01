#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define s second
#define f first
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pair<int, int>> graph[n];

    int t;
    cin >> t;

    ll node1, node2, weight;
    for (int i=0; i<t; i++){
        cin >> node1 >> node2 >> weight;
        graph[node1-1].push_back({node2-1, weight});
        graph[node2-1].push_back({node1-1, weight});
    }

    int k;
    cin >> k;
    int city, pencilcost;
    vector <tuple<int, int>> costs;
    for (int i=0; i<k; i++){
        cin >> city >> pencilcost;
        costs.push_back(make_tuple(city-1, pencilcost));
    }

    ll dest;
    cin >> dest;
    dest --;

    priority_queue <tuple<ll, ll>> pq;
    int dist[n];
    for (int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }
    dist[dest] = 0;

    pq.push(make_tuple(0, dest));

    while (! pq.empty()){
        int node = get<1>(pq.top());
        pq.pop();
        for(tuple nxt : graph[node]){
            int nxtDist = get<1>(nxt);
            int nxtNode = get<0>(nxt);

            if (dist[node]+nxtDist < dist[nxtNode]){
                dist[nxtNode] = dist[node]+nxtDist;
                pq.push(make_tuple(dist[nxtNode], nxtNode));
            }
        }
    }
    int ans = INT_MAX;

    // for (int i=0; i<k; i++){
    //     cout << get<1>(costs[i]) << " " << dist[get<0>(costs[i])] << nl;
    // }
    // for(int i=0; i<k; i++){
    //     get<1>(costs[i]) += dist[get<0>(costs[i])];
    // }
    for (int i=0; i<k; i++){
        ans = min(ans, dist[get<0>(costs[i])]+get<1>(costs[i]));
    }
    cout << ans << nl;
    // for (int i=0; i<n; i++){
    //     cout << get<1>(costs[i]) << nl;
    // }
}