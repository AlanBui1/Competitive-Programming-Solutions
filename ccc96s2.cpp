#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int len){
    bool flag = false;
  
    for (int i=0; i<len; i++){
        if (!flag && arr[i] == 0){
            continue;
        }
        cout << arr[i];
        flag = true;
       
    }
    if (flag) cout << "\n";
 
}

void solve(int arr[], int len, string s){
    string newS;
    while (len > 2){
        print(arr, len);

        int toSubtract = arr[len-1];

        if (arr[len-2] >= toSubtract){
            arr[len-2] -= toSubtract;
        }

        else{
            arr[len-2] += 10;
            arr[len-2] -= toSubtract;
            arr[len-3] --;
        }

        for (int i=len-2; i>0; i--){
            if (arr[i] < 0){
                arr[i] += 10;
                arr[i-1]--;
            }
        }

        newS = "";
        bool flag = 0;
        for (int i=0; i<len-1; i++){
            if (!flag && arr[i] == 0){
                continue;
            }
            flag = 1;
            newS += to_string(arr[i]);
        }
        len = newS.length();

        for (int i=0; i<len; i++){
            arr[i] = newS[i]-'0';
        }
    }

    print(arr, len);

    if (len == 1){
        cout << "The number " << s << " is not divisible by 11.\n";
    }

    else if (arr[0] == arr[1]){
        cout << "The number " << s << " is divisible by 11.\n";
    }
    else{
        cout << "The number " << s << " is not divisible by 11.\n";
    }

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    while (n--){
        string s; cin >> s;
        int len = s.length();

        int arr[len];
        bool flag;
        for (int i=0; i<len; i++){
            arr[i] = s[i]-'0';
        }

        solve(arr, len, s);
        if (n>0){
            cout << "\n";
        }
    }
}