#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXSZ = 1e6+5;
const int inf = 1e9;

vector <int> graph[MAXSZ];
int hat[MAXSZ], dist1[MAXSZ], dist2[MAXSZ], ans1[MAXSZ], ans2[MAXSZ], freq[MAXSZ];

pair<int, int> best1[MAXSZ], best2[MAXSZ], sbest1[MAXSZ], sbest2[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<MAXSZ; i++){
        dist1[i] = inf;
        dist2[i] = inf;
        ans1[i] = inf;
        ans2[i] = inf;
        best1[i] = {inf, inf};
        best2[i] = {inf, inf};
        sbest1[i] = {inf, inf};
        sbest2[i] = {inf, inf};
    }
    bool works = 0;
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> hat[i];
        freq[hat[i]]++;
        if (freq[hat[i]] > 1){
            works = 1;
        }
    }

    if (!works){
        cout << "-1\n";
        return 0;
    }

    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue <int> q;
    q.push(1);

    dist1[1] = 0;
    dist2[n] = 0;

    while (!q.empty()){
        int curNode = q.front();
        q.pop();

        for (int nxtNode : graph[curNode]){
            if (dist1[nxtNode] > dist1[curNode] + 1){
                q.push(nxtNode);
                dist1[nxtNode] = dist1[curNode]+1;
            }
        }
    }

    q.push(n);

    while (!q.empty()){
        int curNode = q.front();
        q.pop();

        for (int nxtNode : graph[curNode]){
            if (dist2[nxtNode] > dist2[curNode]+1){
                q.push(nxtNode);
                dist2[nxtNode] = dist2[curNode]+1;
            }
        }
    }

    int ans = inf;

    for (int i=1; i<=n; i++){
        if (dist1[i] <= best1[hat[i]].f){
            sbest1[hat[i]].f = best1[hat[i]].f;
            best1[hat[i]] = {dist1[i], i};
        }
        else if (dist1[i] <= sbest1[hat[i]].f){
            sbest1[hat[i]].f = dist1[i];
        }
        if (dist2[i] <= best2[hat[i]].f){
            sbest2[hat[i]].f = best2[hat[i]].f;
            best2[hat[i]] = {dist2[i], i};
        }
        else if (dist2[i] <= sbest2[hat[i]].f){
            sbest2[hat[i]].f = dist2[i];
        }
    }

    for (int i=1; i<=n; i++){

        if (best1[i].s != best2[i].s){
            ans = min(ans, best1[i].f+best2[i].f);
        }
        else{
            //ans = min(ans, best1[i].f+best2[i].f);
            ans= min(ans, min(best1[i].f+sbest2[i].f, sbest1[i].f+best2[i].f));
        }
    }

    if (ans >= inf){
        cout << "-1\n";
    }
    else cout << ans << "\n";

   

}