#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXSZ = 8e3+5;
const int MAXN = 1e3+5;
const int inf = 2e9;

int arr[MAXSZ][MAXSZ], n, T;
ll rconv[MAXSZ*8];
vector <int> nums;
unordered_map <ll, ll> conv;

struct rect{
    int x1, y1, x2, y2, tint;
}rects[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> T;

    for (int i=0; i<n; i++){
        int x1, y1, x2, y2, t; cin >> y1 >> x1 >> y2 >> x2 >> t;
        x1++;y1++;

        nums.push_back(x1);
        nums.push_back(y1);
        nums.push_back(x2);
        nums.push_back(y2);
        nums.push_back(x1+1);
        nums.push_back(x2+1);
        nums.push_back(y1+1);
        nums.push_back(y2+1);

        rects[i].x1 = x1;
        rects[i].x2 = x2;
        rects[i].y1 = y1;
        rects[i].y2 = y2;
        rects[i].tint = t;
    }

    sort(nums.begin(), nums.end());

    conv[nums[0]] = 1;
    rconv[1] = nums[0];

    ll cnt = 2;

    for (int i=1; i<nums.size(); i++){
        if (nums[i] != nums[i-1]){
            conv[nums[i]] = cnt;
            rconv[cnt] = nums[i];
            cnt++;
        }
    }

    for (int i=0; i<n; i++){
        int x1 = conv[rects[i].x1], y1 = conv[rects[i].y1], x2 = conv[rects[i].x2], y2 = conv[rects[i].y2], t = rects[i].tint;

        arr[x1][y1]+=t;
        arr[x1][y2+1] -=t;
        arr[x2+1][y1] -=t;
        arr[x2+1][y2+1] += t;
    }

    ll ans = 0;
    for (int i=1; i<MAXSZ; i++){
        for (int k=1; k<MAXSZ; k++){
            arr[i][k] = min(arr[i][k] + arr[i-1][k] + arr[i][k-1] - arr[i-1][k-1], inf);
            if (arr[i][k] < 0) arr[i][k] = inf;

            if (arr[i][k] >= T){
                ans+= (rconv[i+1] - rconv[i]) * (rconv[k+1] - rconv[k]);
                //cout << arr[i][k] << " " << rconv[i] << "  " << rconv[i+1] << " " << rconv[k] << " " << rconv[k+1] << "\n";;
            }
        }
        //cout << "\n";
    }

    cout << ans << "\n";

}