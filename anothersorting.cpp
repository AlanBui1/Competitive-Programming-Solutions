#include <bits/stdc++.h>
using namespace std;

vector <int> lis;

bool compare(int x, int y){
    if (x%10 != y%10){
        return x%10 < y%10;
    }
    return x > y;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++){
        int x; cin >> x;

        lis.push_back(x);
    }

    sort(lis.begin(), lis.end(), compare);

    for (int i=0; i<n-1; i++) cout << lis[i] << " ";
    cout << lis[n-1] << "\n";
}