#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const int MAXSZ = 45;
const int inf = 1e18;

int h[MAXSZ], g[MAXSZ];

struct LS{
    int score, height;
};

vector <LS> leftSide;
vector <ll> rightSide[MAXSZ];

signed main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans =0; cin >> n >> k;

    for (int i=0; i<n; i++){
        cin >> h[i] >> g[i];
    }
    h[44] = inf;

    for (int mask=0; mask<(1 << (n/2)); mask++){
        int highestBit = -1, prev = 0, works = 1, money = 0;

        for (int i=0; i<n/2; i++){
            if (mask & (1 << i)){
                highestBit = max(highestBit, i);
                if (h[i] < prev){
                    works = 0;
                    break;
                }

                else{
                    money += g[i];
                    prev = h[i];
                }
            }
        }

        if (works){
            if (highestBit == -1) highestBit = 43;
            LS stuff; stuff.score = money; stuff.height = h[highestBit];
            leftSide.push_back(stuff);
        }
    }

    for (int mask = 0; mask < (1 << (n - (n/2))); mask++){
        int firstBit = 44, prev = 0, works = 1, money = 0;

        for (int i=0; i<n-(n/2); i++){
            if (mask & (1 << i)){
                firstBit = min(firstBit, i + (n/2));
                if (h[i+(n/2)] < prev){
                    works =0;
                    break;
                }

                else{
                    money += g[i+(n/2)];
                    prev = h[i+(n/2)];
                }
            }

        }

        if (works){
            //cout << mask << " " << money << "\n";
            rightSide[firstBit].push_back(money);
        }
    }

    for (int i=0; i<MAXSZ; i++){
        sort(rightSide[i].begin(), rightSide[i].end());
    }
    //cout << "#########\n";
    for (LS thing : leftSide){
        for (int i=0; i<MAXSZ; i++){
            if (h[i] >= thing.height){
                int lo = 0, hi = rightSide[i].size()-1, best = inf;

                while (lo <= hi){
                    int mid = (lo+hi)/2;

                    if (rightSide[i][mid] + thing.score >= k){
                        best = min(best, mid);
                        hi = mid-1;
                    }
                    else{
                        lo = mid+1;
                    }
                }

                if (best < inf) ans += rightSide[i].size() - best;

            
            }
        }
        //cout << thing.score << " " << thing.height << "\n";
    }



    cout << ans << "\n";
    //cout << leftSide.size();
}

/*

15 50
15 36
3 8
33 42
5 4
45 43
28 33
5 44
8 48
32 29
36 6
11 21
28 24
17 7
46 32
16 2

*/