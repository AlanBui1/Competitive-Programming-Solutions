#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define f first
#define s second
const int nax= 1e5+5;
const ll inf = 1e18;

vector <pair <int, ll>> graph[nax];
vector <int> classes[nax], studentIn[nax];
int arr[nax];
ll dist[nax];
ll n, c, K;

vector <pair <ll, ll>> makeGraph(int stud){
    vector <pair <ll, ll>> s;
    for (int clas : studentIn[stud]){
        for (int newstudent : classes[clas]){
            s.push_back({newstudent, abs(arr[newstudent]-arr[stud])+K});
        }
    }
    return s;
}

int main() {
    
    scan(n); scan(c); scan(K);

    for (int i=1; i<=n; i++){
        scan(arr[i]);
    }

    int num, x;

    for (int i=1; i<=n; i++){
        scan(num);
        while (num--){
            scan(x);
            // for (int stud : classes[x]){
            //     graph[stud].push_back({i, abs(arr[i]-arr[stud])+K});
            //     graph[i].push_back({stud, abs(arr[i]-arr[stud])+K});
            // }
            classes[x].push_back(i);
            studentIn[i].push_back(x);
        }
    }

    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>> > pq;

    pq.push({0, 1});

    pair <ll, ll> node; ll curNode, curDist;

    for (int i=2; i<nax; i++) dist[i] = inf;
    dist[1] = 0;

    while (!pq.empty()){
        node = pq.top(); pq.pop();
        curNode = node.s; curDist = node.f;

        if (dist[curNode] < curDist) continue;

        for (pair <int, int> nxt : makeGraph(curNode)){

            if (dist[nxt.f] > curDist + nxt.s){
                dist[nxt.f] = curDist + nxt.s;
                pq.push({dist[nxt.f], nxt.f});
            }
        }
    }

    for (int i=1; i<=n; i++){
        if (dist[i] == inf) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}