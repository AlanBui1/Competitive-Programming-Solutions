#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXSZ = 1e6+5;
const ll BASE = 31;
const ll MOD = 1e9+7;
const ll BASE2 = 41;
const ll MOD2 = 44654641650887;

string T, S;
ll powers[MAXSZ], powers2[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> S >> T;

    ll len1 = S.length(), len2 = T.length();

    powers[0] = 1; powers2[0] = 1;

    for (int i=1; i<=len2; i++){
        powers[i] = (powers[i-1]*BASE)%MOD;
        powers2[i] = (powers2[i-1]*BASE2)%MOD2;
        
    } 

    ll HASH = 0, hashval=0;
    ll HASH2 = 0, hashval2 = 0;

    for (int i=0; i<len2; i++){
        HASH += (T[i]-'a'+1)*powers[len2-i-1];
        HASH %= MOD;
        HASH2 += (T[i]-'a'+1)*powers2[len2-i-1];
        HASH2 %= MOD2;

        hashval += (S[i]-'a'+1)*powers[len2-i-1];
        hashval %= MOD;
        hashval2 += (S[i]-'a'+1)*powers2[len2-i-1];
        hashval2 %= MOD2;
    }


    if (HASH == hashval && hashval2 == HASH2){
        cout << "0\n";
        return 0;
    }
    //cout << HASH << "\n";
    for (int i=1; i<len1-len2+1; i++){
        hashval -= powers[len2-1]*(S[i-1]-'a'+1);
        hashval = (hashval+MOD)%MOD;
        hashval *= BASE;
        hashval %= MOD;
        hashval += S[i-1+len2]-'a'+1;
        hashval %= MOD;
        
        hashval2 -= powers2[len2-1]*(S[i-1]-'a'+1);
        hashval2 = (hashval2+MOD2)%MOD2;
        hashval2 *= BASE2;
        hashval2 %= MOD2;
        hashval2 += S[i-1+len2]-'a'+1;
        hashval2 %= MOD2;

        if (hashval2 == HASH2){
            cout << i << "\n";
            return 0;
        }
    }
    //cout << hashval << "\n";
    cout << "-1\n";


}