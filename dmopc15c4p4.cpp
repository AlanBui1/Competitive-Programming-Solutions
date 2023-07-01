#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 1e5+5;
int n, k, q, a, b, x, y;
int arr[MAXSZ], prefix[MAXSZ];
vector <int> freq[2005];

bool bsearch(int want, int x, int y){
    int left=0, right=freq[want].size()-1, mid;
    while (left <= right){
        mid = (left+right)/2;
        if (x <= freq[want][mid] && freq[want][mid] <= y){
            return true;
        }
        else if (x>freq[want][mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> q;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
        freq[arr[i]+1000].push_back(i);
    } 

    while (q--){
        cin >> a >> b >> x >> y;
        a+=1000; b+=1000;

        if (prefix[y] - prefix[x-1] > k && bsearch(a, x, y) && bsearch(b, x, y)){
            
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
}