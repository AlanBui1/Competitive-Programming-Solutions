#include <bits/stdc++.h>
using namespace std;

int main(){
  int n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;
  if (n1 == 8|| n1==9){
    if (n4 == 8|| n4==9){
      if (n2==n3){
        cout << "ignore\n";
        }
      else{
        cout << "answer\n";
      }
    }
    else{
      cout << "answer\n";
    }

  }
  else{
    cout << "answer\n";
  }
}