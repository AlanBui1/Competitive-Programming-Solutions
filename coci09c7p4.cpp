#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define f first
#define s second
#define int long long

int parent[MAXSZ], siz[MAXSZ];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    if (siz[a] > siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
}

vector <pair <int, int>> as, bs, cs;
vector <pair <int, pair <int, int>>> graph;

int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i; siz[i] = 1;
    }

    int n; cin >> n;
    int x, y, z;
    for (int i=0; i<n; i++){
        cin >> x>> y>> z;
        as.push_back({x, i});
        bs.push_back({y, i});
        cs.push_back({z, i});
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());

    for (int i=1; i<as.size(); i++){
        graph.push_back({abs(as[i].f-as[i-1].f), {as[i-1].s, as[i].s}});
    }
    for (int i=1; i<bs.size(); i++){
        graph.push_back({abs(bs[i].f-bs[i-1].f), {bs[i-1].s, bs[i].s}});
    }
    for (int i=1; i<cs.size(); i++){
        graph.push_back({abs(cs[i].f-cs[i-1].f), {cs[i-1].s, cs[i].s}});
    }

    sort(graph.begin(), graph.end());

    int mstCost = 0;
    n--;
    for (auto possible : graph){
        int dist = possible.f, A = possible.s.f, B = possible.s.s;
        if (!n){
            cout << mstCost << "\n";
            return 0;
        }
        A = find(A); B = find(B);
        if (A != B){
            n--;
            unionsets(A, B);
            mstCost += dist;
        }
        
    }
    



}