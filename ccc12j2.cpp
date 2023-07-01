#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2, n3, n4;
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    
    if (n1<n2 && n2<n3 && n3<n4){
        cout << "Fish Rising\n";
    }
    else if (n1>n2 && n2>n3 && n3>n4){
        cout << "Fish Diving\n";
    }
    else if (n1==n2 && n2==n3 && n3==n4){
        cout << "Fish At Constant Depth\n";
    }
    else{
        cout << "No Fish\n";
    }
    
    return 0;
}