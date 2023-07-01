#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int G, P, plane, ans;
set <int> gates;
bool cantdock=false;

int main() {
    scan(G);
    scan(P);
    for (int i=1; i<=G; i++){
        gates.insert(i);
    }

    while (P--){
        scan(plane);
        if (cantdock) continue;

        if (ans < G){
            // cout  <<" BEFORE1\n";
            // auto y = prev(gates.upper_bound(50000));
            // cout << *y << " YYYY\n";
            auto left = prev(gates.upper_bound(plane));
            int x = *left;
            auto found = gates.find(x);
            
            if (x > plane){
                cantdock=true;
                continue;
            }
            else if (found == gates.end()){
                cantdock=true;
                continue;
            }
            // cout << *left <<" BEFORE2\n";
            gates.erase(left);
            //cout << "AFTER\n";
            ans++;
        }

        else{
            auto left = gates.lower_bound(plane);
            if (*left <= plane){
                ans++;
            }
        }

    }
    cout << ans << "\n";
}