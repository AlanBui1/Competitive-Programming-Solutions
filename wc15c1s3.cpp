#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define inf INT_MAX
#define f first
#define s second

int main() {
    ll n, m, left;
    scan(n);
    scan(m);
    scan(left);
    ll houses[n];
    ll dist1[n];
    ll dist2[n];

    for (int i=0; i<n; i++){
        scan(houses[i]);
        dist1[i] = inf;
        dist2[i] = inf;
    }
    dist1[0] =0;
    dist2[1] =0;

    vector <pair<ll, ll>> graph[n];
    ll node1, node2, weight;
    for (int i=0; i<m; i++){
        scan(node1);
        scan(node2);
        scan(weight);
        graph[node2-1].push_back({node1-1, weight});
    }

    priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> > pq; 
    pq.push({0, 0});
    ll node;
    ll nxtNode, nxtDist;

    // for (int i=0; i<n; i++){
    //     for (pair<ll, ll> info : graph[i]){
    //         cout << info.f << " " << info.s << "\n";
    //     }
    // }
    while (!pq.empty()){
        node = pq.top().s;
        pq.pop();
        for (pair<ll, ll> nxt : graph[node]){
            nxtNode = nxt.f;
            nxtDist = nxt.s;
            if (dist1[node]+nxtDist < dist1[nxtNode]){
                dist1[nxtNode] = dist1[node]+nxtDist;
                pq.push({dist1[nxtNode], nxtNode});
            }
        }
    }

    pq.push({0, 1});

    while (!pq.empty()){
        node = pq.top().s;
        pq.pop();
        for (pair<ll, ll> nxt : graph[node]){
            nxtNode = nxt.f;
            nxtDist = nxt.s;
            if (dist2[node]+nxtDist < dist2[nxtNode]){
                dist2[nxtNode] = dist2[node]+nxtDist;
                pq.push({dist2[nxtNode], nxtNode});
            }
        }
    }
    vector<pair<ll,ll>> dif;
    for (int i=0; i<n; i++){
        dif.push_back({dist1[i]-dist2[i], i});
    }
    sort(dif.rbegin(), dif.rend());
    ll curTown=0, added=0;
    while (left>0 && dif[curTown].f >0){
        if (houses[dif[curTown].s]==0){
            curTown++;
        }
        
        else{
            left--;
            houses[dif[curTown].s]--;
            added+=dist2[dif[curTown].s];
        }
    }
    for (int i=0; i<n; i++){
        if (houses[i] >0){
            added += (houses[i]*dist1[i]);
        
            if (dist1[i]==inf){
                added = inf;
                break;
            }
        }
    }
    if (added == inf){
        cout << -1 << "\n";
    }
    else{
        cout << added << "\n";
    }
}