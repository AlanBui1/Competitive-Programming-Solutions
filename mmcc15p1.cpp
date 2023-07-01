#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5e5+5;
#define f first
#define s second

int parent[MAXSZ], siz[MAXSZ], cnt=-1;

vector <pair <int, int>> nodeHist;
vector <pair <int, int>> sizeHist;
vector <pair <int, int>> repHist;

int find(int u){
    if (parent[u] == u) return u;
    return find(parent[u]);
}

void Init(int N){

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        siz[i]=1;
    }

}

void AddEdge(int U, int V){
    int u = find(U), v = find(V);


    if (u != v){
        if (siz[u] < siz[v]){
            swap(u, v);
        }
        nodeHist.push_back({u, v});
        sizeHist.push_back({siz[u], siz[v]});
        repHist.push_back({parent[u], parent[v]});
        parent[v] = u;
        siz[u] += siz[v];
    }
    else{
        nodeHist.push_back({u, v});
        sizeHist.push_back({siz[u], siz[v]});
        repHist.push_back({parent[u], parent[v]});
    }

    cnt++;
}

void RemoveLastEdge(){
    int a = nodeHist[cnt].f, b = nodeHist[cnt].s;
    
    parent[a] = repHist[cnt].f; parent[b] = repHist[cnt].s;
    siz[a] = sizeHist[cnt].f; siz[b] = sizeHist[cnt].s;

    nodeHist.erase(nodeHist.end());
    sizeHist.erase(sizeHist.end());
    repHist.erase(repHist.end());

    cnt--;
}

int GetSize(int u){
    return siz[find(u)];
}

int main() {

}