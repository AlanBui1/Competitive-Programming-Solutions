#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

unordered_map <string, int> conv;

int cur = 0;

vector <pair <int, int>> sameGroup, diffGroup;

int parent[MAXSZ], siz[MAXSZ];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}
void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a != b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a]+=siz[b];
    }
}

void setIn(string name){
    if (conv[name]== 0){
        cur++;
        conv[name] = cur;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    int x, y; cin >> x;
    for (int i=0; i<x; i++){
        string a, b; cin >> a >> b;
        setIn(a); setIn(b);
        sameGroup.push_back({conv[a], conv[b]});
    }

    cin >> y;

    for (int i=0; i<y; i++){
        string c, d; cin >> c >> d;
        setIn(c); setIn(d);
        diffGroup.push_back({conv[c], conv[d]});
    }

    int g; cin >> g;
    for (int i=0; i<g; i++){
        string n1, n2, n3; cin >> n1 >> n2 >> n3;
        setIn(n1); setIn(n2); setIn(n3);
        unionsets(conv[n1], conv[n2]); unionsets(conv[n2], conv[n3]); unionsets(conv[n1], conv[n3]);
    }

    int ans = 0;


    for (pair <int, int> mustHave : sameGroup){
        if (find(mustHave.first) != find(mustHave.second)){
            ans++;
            //cout << mustHave.first << " " << mustHave.second << "\n";
        }
    }
    for (pair <int, int> diff : diffGroup){
        if (find(diff.first) == find(diff.second)){
            ans++;
        }
    }
    cout << ans << "\n";
}