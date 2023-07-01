#include <bits/stdc++.h>
using namespace std;

void primeRange(int lowerbound, int upperbound){
  if (lowerbound == 1){
    lowerbound++;
  }
  int limit = floor(sqrt(upperbound))+1;
  vector<int>prime;
  bool check[limit+1];
  memset(check, false, limit+1);

  for (int i=2; i<=limit; i++){
    if (!check[i]){
      prime.push_back(i);
      for (int j=i; j<= limit; j+=i){
        check[j] = true;
      }
    }
  }

  int numele = upperbound-lowerbound+1;
  bool mark[numele+1];
  memset(mark, false, numele+1);

  for (int i=0; i<prime.size(); i++){
    int loLim  = floor(lowerbound/prime[i])*prime[i];
    if (loLim < lowerbound){
      loLim += prime[i];
    }
 
    if (loLim == lowerbound){
      loLim += prime[i];
    }

    if (loLim == prime[i]){
      loLim += prime[i];
    }

    for (int j=loLim; j<=upperbound; j+=prime[i]){
      mark[j-lowerbound] = true;
    }
  }
  int start = lowerbound;
  if (start <= 2){
    start=3;
    cout << 2 << "\n";
  }
  for (int i=start; i<=upperbound; i++){
    if (! mark[i-lowerbound]){
      if (i%2 != 0){
        cout << i << "\n";
      }
    }
  }


}

int main(){
  int n, m;
  cin >> n >> m;
  primeRange(n, m);
}