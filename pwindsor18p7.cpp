#include <bits/stdc++.h>
using namespace std;

vector <string> lis;


bool compare(string s1, string s2){
    string S = s1+s2, T = s2+s1;
    for (int i=0; i<S.size(); i++){
        if (S[i] < T[i]){
            return false;
        }
        if (T[i] < S[i]){
            return true;
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n; i++){
        string s; cin >> s;
        lis.push_back(s);
    }

    sort(lis.begin(), lis.end(), compare);

    for (string s : lis){
        cout << s;
    }
    cout << "\n";

}