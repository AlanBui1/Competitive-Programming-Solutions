#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
#define f first
#define s second

const int MAXSZ = 2e4+5;

int parent[MAXSZ], siz[MAXSZ], cnt;
bool used[MAXSZ];

vector <pii> edges;
vector <int> in;

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);
    if (a!= b){
        if (siz[a] < siz[b]){
            swap(a, b);
        }
    }

    parent[b] = a;
    siz[a] += siz[b];
}

int connected(){
    int n = cnt;

    for (pii E : edges){
        if (find(E.f) != find(E.s)){
            unionsets(E.f, E.s);
            n--;
        }
        else{
            return -1;
        }
    }
    return n;
}

void solve(){

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    int comps = connected();

    if (comps != 1 || edges.size() != cnt-1){
        cout << "INVALID\n";
        return;
    }

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
    }

    for (pii E : edges){
        parent[E.s] = E.f;
    }

    for (int i : in){
        if (parent[i] == i){
            cout <<i << "\n";
            return;
        }
    }

}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int x, y;

    while (1){
        cin >> x >> y;

        if (x == -1 && y == -1){
            return 0;
        }

        if (x == 0 && y == 0){
            solve();
            for (int i : in){
                used[i] = 0;
            }
            in.clear();
            edges.clear();
            cnt = 0;
            continue;
        }
        bool flag = 0;
        for (pii E : edges){
            if (E.f == x && E.s == y){
                flag = 1;
                break;
            }
        }
        if (!flag) edges.push_back({x, y});
        if (!used[x]){
            used[x] = 1;
            cnt++;
            in.push_back(x);
        }
        if (!used[y]){
            used[y] = 1;
            cnt++;
            in.push_back(y);
        }
    }



}