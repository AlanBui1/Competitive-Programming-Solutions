#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int lis[81]= {192, 442, 692, 942, 1192, 1442, 1692, 1942, 2192, 2442, 2692, 2942, 3192, 3442, 3692, 3942, 4192, 4442, 4692, 4942, 5192, 5442, 5692, 5942, 6192, 6442, 6692, 6942, 7192, 7442, 7692, 7942, 8192, 8442, 8692, 8942, 9192, 9442, 9692, 9942, 10192, 10442, 10692, 10942, 11192, 11442, 11692, 11942, 12192, 12442, 12692, 12942, 13192, 13442, 13692, 13942, 14192, 14442, 14692, 14942, 15192, 15442, 15692, 15942, 16192, 16442, 16692, 16942, 17192, 17442, 17692, 17942, 18192, 18442, 18692, 18942, 19192, 19442, 19692, 19942, 20192};
  int start;
  for (int t = 0; t<n; t++){
    cin >> start;
    for (int i=0; i<81; i++){
      if (lis[i] > start){
        cout << lis[i] << endl;
        break;
      }
    }

  }


}