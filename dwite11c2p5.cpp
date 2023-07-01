#include <bits/stdc++.h>
using namespace std;
const int nax =4e5+5;

int parent[nax], siz[nax];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b= find(b);

    if (a!= b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }
}

unordered_map <string, int> conv;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    for (int _ = 0; _ < 5; _++){
        conv.clear();
        int n, cnt =0; cin >> n;
        for (int i=0; i<nax; i++){
            siz[i] = 1;
            parent[i] = i;
        }

        while (n--){

            char oper; cin >> oper;
            string s1, s2; cin >> s1 >> s2;

            if (conv[s1] == 0){
                cnt++;
                conv[s1] = cnt;
            }

            if (conv[s2] == 0){
                cnt++;
                conv[s2] = cnt;
            }

            if (oper == 'q'){
                if (find(conv[s1]) == find(conv[s2])){
                    cout << "connected\n";
                }
                else{
                    cout << "not connected\n";
                }
            }

            else{
                unionsets(conv[s1], conv[s2]);
            }
        }
    }
}