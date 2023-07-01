#include <bits/stdc++.h>
using namespace std;
const int nax=1005;

int matrix[nax][nax];
vector <int> connections[nax];
bool visited[nax];
int parent[nax];

int find(int a){
    return a==parent[a] ? a: parent[a]=find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        parent[b] = a;
    }
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            cin >> matrix[i][k];
        }
    }

    for (int i=0; i<nax; i++) parent[i] = i;

    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            if (matrix[i][k]){
                unionsets(i, k);
            }
        }
    }

    for (int i=0; i<n; i++){
        connections[find(i)].push_back(i);
    }
   
    for (int i=0; i<n; i++){
        if (visited[i]) continue;
        visited[i] = true;
        bool flag=true;
        sort(connections[i].begin(), connections[i].end());
        for (int k : connections[find(i)]){
            visited[k] = true;
            cout << k+1 << " ";
            flag = false;
        }
        if (!flag) cout << "\n";
    }
}