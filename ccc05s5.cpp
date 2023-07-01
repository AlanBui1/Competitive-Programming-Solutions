#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+1;
int t;
vector <int> scores;
int bit[MAXSZ];
int orig[MAXSZ];
unordered_map <int, int> translate;

int sum(int L, int R){
    int s = 0;
    for (; R> 0; R -= (R&-R)){

        s += bit[R];
    }
    return s;
}

void update(int r){
    for (int i=r; i <= t; i+= (i&-i)){
        bit[i]++;
 
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (int i=0; i<t; i++){
        int score; cin >> score;
        orig[i] = score;
        scores.push_back(score);
        
    }
    sort(scores.begin(), scores.end());

    int e=0, c=1;

    while (e < scores.size()){

        if (e > 0){
            if (scores[e] == scores[e-1]){
                e++;
                continue;
            }
        }
        translate[scores[e]] = c;
        e++;
        c++;
    }

    double tot = 0;
    for (int i=0; i<t; i++){
        int cscore = translate[orig[i]];
        tot += 1+ (sum(0, t)-sum(0, cscore));

        update(cscore);
    }
    cout << fixed << setprecision(2) << tot/t << "\n";
}