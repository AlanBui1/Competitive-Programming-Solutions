#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=50005;
int freq[26][MAXSZ];

string query(int L1, int R1, int L2, int R2){

    for (int i=0; i<26; i++){
        if (freq[i][R1] - freq[i][L1-1] != freq[i][R2] - freq[i][L2-1]) return "NE";
    }

    return "DA";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    for (int i=0; i<s.size(); i++){
        for (int k=0; k<26; k++){
            freq[k][i+1] = freq[k][i] + (s[i]-'a' == k);
        }
    }

    int q; cin >> q;

    int a, b, c, d;

    while (q--){
        cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << "\n";
    }

}