#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1e6+5;
ll redPSA[MAXSZ], bluePSA[MAXSZ], greenPSA[MAXSZ];

int main() {
    cin.sync_with_stdio(0);cin.tie(0);

    ll n; cin >> n;

    string lights; cin >> lights;
    ll totRed=0, totGreen=0, totBlue=0;

    for (int i=0; i<n; i++){
        redPSA[i+1] += (lights[i]=='R');
        bluePSA[i+1] += (lights[i]=='B');
        greenPSA[i+1] += (lights[i]=='G');
    }

    
    string ls, rs;

    cin >> ls;

    string lights2; cin >> lights2;

    for (int i=0; i<n; i++){
        
        redPSA[i+1] += redPSA[i]+(lights2[i]=='R')-(lights[i] == lights2[i] and lights[i]=='R');
        bluePSA[i+1] += bluePSA[i]+(lights2[i]=='B')-(lights[i] == lights2[i] and lights[i]=='B');
        greenPSA[i+1] += greenPSA[i]+(lights2[i]=='G')-(lights[i] == lights2[i] and lights[i] == 'G');

        totRed += lights[i] == 'R' and lights2[i] == 'R';
        totBlue += lights[i] == 'B' and lights2[i] == 'B';
        totGreen+= lights[i] == 'G' and lights2[i] == 'G';

        
        
    }

    cin >> rs;
    ll ans =0;
    for (int i=0; i<n; i++){
        char L = ls[i], R=rs[i];

        if (L != R){

            if ((L=='R' and R == 'B') or (L=='B' and R=='R')){
                ans += greenPSA[n];
                
            }

            else if((L=='R' and R=='G') or (L=='G' and R=='R')){
                ans += bluePSA[n];
            }

            else{
                ans += redPSA[n];
            }

        }

        else{
            if (L=='R'){
                ans += n-redPSA[n]-totBlue-totGreen;
            }
            else if (L=='G'){
                ans += n-greenPSA[n]-totRed-totBlue;
            }
            else{
                ans += n-bluePSA[n]-totGreen-totRed;
            }
        }
    }

    cout << ans << "\n";

}