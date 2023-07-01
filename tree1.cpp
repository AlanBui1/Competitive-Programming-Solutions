#include <bits/stdc++.h>
using namespace std;

const int nax = 10;

int parent[10], grid[10][10];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);
    if (a != b){
        parent[b] = a;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<10; i++){
        parent[i] = i;
    }

    for (int i=1; i<=4; i++){
        for (int k=1; k<=4; k++){
            cin >> grid[i][k];
        }
    }

    int n=0;

    for (int i=1; i<=4; i++){
        for (int k=i+1; k<=4; k++){
            if (grid[i][k]){
                if (find(i) == find(k)){
                    cout << "No\n";
                    return 0;
                }
                unionsets(i, k);
                n++;
            }
        }
    }

    if (n == 3){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";

}