#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
int parent[MAXSZ];
vector <int> id;
vector <pair <int, int>> edges;
unordered_map<int, int> cid;


int n, m;

int find(int a){
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        parent[b] = a;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n>> m;
    int a, b;
    
    for (int i=0; i<m; i++){
        
        cin >> a >> b;
        edges.push_back({a, b});
        id.push_back(a);
        id.push_back(b);
    }
    sort(id.begin(), id.end());
    int cnt=1;

    for (int i=0; i<id.size(); i++){

        if (id[i] != id[i-1]){
            cid[id[i]] = cnt;
            cnt++;
        }
        parent[i] = i;
    }
   
    for (int i=0; i<m; i++){
        a = edges[i].first; b = edges[i].second;
        a = cid[a]; b = cid[b];
      
        if (find(a) == find(b)){
        
            continue;

        } 
        n--;
        unionsets(a, b);

    }
    cout << n << "\n";
}