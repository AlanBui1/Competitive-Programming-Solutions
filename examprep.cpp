#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6+5;
#define ll long long
ll parent[nax], SIZE[nax], resource[nax];

ll find(int i){
return i == parent[i] ? i:parent[i]=find(parent[i]);
}

void unionsets(int a, int b){

a=find(a); b=find(b);

if (a!=b){

if (SIZE[a] < SIZE[b]){

swap(a, b);

}
parent[b]=a;
SIZE[a]+=SIZE[b];
resource[a]+=resource[b];
}

}

int main(){
cin.sync_with_stdio(0); cin.tie(0);

ll n, q; cin >> n >> q;
ll oper, a, b;

for (int i=0; i<n; i++){
parent[i] = i;
SIZE[i]=1;
cin >> resource[i+1];
}
parent[n] = n;
SIZE[n] = 1;


while (q--){

cin >> oper; 

if (oper == 1){

cin >> a >> b;
unionsets(a, b);

}

else if (oper == 2){

cin >> a;
cout << SIZE[find(a)] << "\n";

}

else{

cin >> a;
cout << resource[find(a)] << "\n";

}

}


}