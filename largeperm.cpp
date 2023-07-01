#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5+5;

int n;

int want(int i){
    return n-i+1;
}

int inds[nax], arr[nax];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int k, todo=0; cin >> k;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        inds[arr[i]] = i;
        if (inds[arr[i]] != want(i)){
            todo++;
        }
    }

    int highest = n;

    while (k--){
        if (!todo) break;

        for (; highest > 0; highest--){
            if (inds[highest] != want(highest)){
                //cout << highest << " " << want(highest) << "\n";
                int x = highest, y = want(highest);
                //swap(arr[inds[x]], arr[inds[arr[y]]]);
                swap(arr[inds[x]], arr[y]);
                swap(inds[arr[inds[x]]], inds[arr[y]]);

                todo--;
                break;
            }
        }
    }


    for (int i=1; i<n; i++){
        cout << arr[i] << " ";
    }cout << arr[n] << "\n";
}