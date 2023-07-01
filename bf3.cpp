#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long num){
  if (num <= 1){
    return false;
  }
  if (num <= 3){
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0){
    return false;
  }
  for (long long i=5; i*i<num; i+=6){
    if (num%i == 0 || num%(i+2)==0){
      return false;
    }
  }
  return true;

}

int main() {
  long long n;
  cin >> n;
  if (isPrime(n)){
    cout << n << "\n";
  }
  else if(n<=2){
    cout << 2 << "\n";
  }
  else{
    if (n%2 == 0){
      n++;
    }
    while (true){
      if (isPrime(n)){
        cout << n << "\n";
        break;
      }
      n+=2;
    }

  }
}