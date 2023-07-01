#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

struct test{
    int f, e, ind, pts;
};

vector <test> lis;

bool compare(test x, test y){
    if (x.f != y.f){
        return x.f < y.f;
    }
    return x.e < y.e;
}

int diff[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int b, ans; cin >> b;

    for (int i=0; i<b; i++){
        int f, e, p; cin >> f >> e >> p;

        test T;
        T.f = f; T.e = e; T.pts = p;
        ans += p;

        lis.push_back(T);
    }

    sort(lis.begin(), lis.end(), compare);

    int t, F; cin >> t;

    for (int i=0; i<b; i++){
        lis[i].ind = i+1;
    }

    for (int i=0; i<t; i++){
        cin >> F;

        int smallest = 2e9, highest = -1;
        int lo = 0, hi = b-1;
        while (lo <= hi){
            int mid = (lo+hi)/2;

            if (lis[mid].f <= F && F <= lis[mid].e){
                smallest = min(smallest, mid);
                hi = mid-1;
            }

            else if (lis[mid].f >= F){
                hi = mid-1;
            }

            else{
                lo = mid+1;
            }
        }

        lo = 0; hi = b-1;
        while (lo <= hi){
            int mid = (lo+hi)/2;

            if (lis[mid].f <= F && F <= lis[mid].e){
                highest = max(highest, mid);
                lo = mid+1;
            }

            else if (lis[mid].f >= F){
                hi = mid-1;
            }

            else {
                lo = mid+1;
            }
        }

        if (smallest != 2e9 && highest != -1){
            diff[smallest+1]++;
            diff[highest+2]--;
        }
    }

    for (int i=1; i<=b; i++){
        diff[i] += diff[i-1];
        if (diff[i] > 0){
            ans -= lis[i-1].pts;
        }
        //cout << diff[i] << " ";
    }
    // << "\n";
    cout << ans << "\n";
}