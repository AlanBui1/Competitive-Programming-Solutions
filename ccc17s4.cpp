#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5+5;

struct edge{
    int a, b, weight, orig; //orig = 0 -> original plan
};

bool compare(edge x, edge y){
    if (x.weight == y.weight){
        return x.orig < y.orig;
    }
    return x.weight < y.weight;
}

int parent[nax], N, M, D;

int findSet(int a){
    return a == parent[a] ? a : parent[a] = findSet(parent[a]);
}

void unionsets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if (a != b){
        parent[b] = a;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<nax; i++){
        parent[i] = i;
    }

    cin >> N >> M >> D;
    vector <edge> graph(M);

    for (int i=0; i<M; i++){
        cin >> graph[i].a >> graph[i].b >> graph[i].weight;
        if (i >= N-1){
            graph[i].orig = 1;
        }
    }
    sort(graph.begin(), graph.end(), compare);

    int num = 0, cnt = 0;
    edge last;

    for (edge E : graph){
        cnt++;
        if (findSet(E.a) == findSet(E.b)){
            continue;
        }
        unionsets(E.a, E.b);
        num += E.orig;
        last = E;
        last.a = cnt-1;
    }

    if (last.orig == 1 && last.weight <= D){
        for (int i=0; i<nax; i++){
            parent[i] = i;
        }
        for (int i=0; i<last.a; i++){
            edge E = graph[i];
            if (findSet(E.a) == findSet(E.b)){
                continue;
            }
            if (E.orig == 0 || E.weight < last.weight) unionsets(E.a, E.b);
        }

        for (int i=last.a+1; i<graph.size(); i++){
            edge E = graph[i];
            if (findSet(E.a) == findSet(E.b)){
                continue;
            }
            if (E.weight <= D && E.orig == 0){
                num--;
                break;
            }
        }
    }

    cout << num << "\n";

}