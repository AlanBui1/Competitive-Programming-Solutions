#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=405;

int room[MAXSZ][MAXSZ];
int r, c, ans;
 
string S;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> r>> c;

    for (int i=1; i<=r; i++){
        cin >> S;
        int cnt=1;
        for (char s : S){
            room[i][cnt] = room[i][cnt-1];
            if (s == 'X'){
                room[i][cnt]++;
            }
            // cout << room[i][cnt] << " ";
            cnt++;
            
        }
        // cout <<"\n";
    }
    int p1, p2, x, y;

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            p1 = k;
            p2 = k;

            if (room[i][p2] - room[i][p1-1] == 0){
                x = 1; y=1;
                while (p1 <= c && p2 <=c){
                    if (room[i][p2] - room[i][p1-1] == 0){
                        x = p2-p1+1;

                        for (int j=i; j<= r; j++){
                            if (room[j][p2] - room[j][p1-1] == 0){
                                y = j-i+1;
                                ans = max(ans, (x+y)*2);
                            }
                            else{
                                break;
                            }
                        }
                    }
                    else{
                        break;
                    }
                    p2++;
                }
                
            }
            else{
                x = 0; y = 0;
            }
            
            ans = max(ans, (x*2)+(y*2));
        }
    }

    cout << max(0, ans-1) << "\n";
}