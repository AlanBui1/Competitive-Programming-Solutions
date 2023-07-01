#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, cost, value, typeo, budget;

  cin >> t;
  cin >> n;

  vector <tuple<int, int>> items[t];

  for (int i=0; i<n; i++){
    cin >> cost >> value >> typeo;
    items[typeo-1].push_back(make_tuple(cost, value));
  }
  cin >> budget;
  int vals[budget+1];
  
  for (int i=0; i<= budget; i++){
    vals[i] = 0;
  }

  for (int i=0; i<t; i++){    
    for (int k=budget; k>0; k--){
      for (int j=0; j<items[i].size(); j++){
        if (k >= get<0>(items[i][j])){ 
          vals[k] = max(vals[k], vals[k-get<0>(items[i][j])]+get<1>(items[i][j]));
        } 
      }
    }
  }
  cout << vals[budget];
}