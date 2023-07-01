#include <bits/stdc++.h>
using namespace std;

string needle, haystack;
long long powers[200005];
const long long MOD = 44654641650887;
int nlen;

long long createhash(string s){
  long long hashval = 0;
  for (int i=0; i<s.size(); i++){
    hashval += (powers[nlen-i-1]*(s[i]-'a')) % MOD;
    hashval = hashval % MOD;
  }
  return hashval;

}
unordered_set <long long> rollHashValue;

int main() {
  cin >> needle >> haystack;
  powers[0] = 1;
  for (int i=1; i<200005; i++){
    powers[i] = (powers[i-1]*37) % MOD;
  }
  int hlen = haystack.size();
  nlen = needle.size();

  int nFreq[26];

  memset(nFreq,0,sizeof(nFreq));

  for (char c : needle){
    nFreq[c-'a'] ++;
  }

  int hFreq[26];
  memset(hFreq,0,sizeof(hFreq));

  for (int i=0; i<nlen; i++){
    hFreq[haystack[i]-'a'] ++;
  }

  bool found=true;
  for (int i=0; i<26; i++){
    if (hFreq[i] != nFreq[i]){
      found = false;
      break;
    }

  }
  long long startval = createhash(haystack.substr(0, nlen));
  if (found) {
    rollHashValue.insert(startval);
  }

  for (int ind=nlen; ind<hlen; ind++){
    hFreq[haystack[ind]-'a']++;
    hFreq[haystack[ind-nlen]-'a']--;

    startval -= ((haystack[ind-nlen]-'a')*powers[nlen-1]) % MOD;
    startval = (startval+MOD)% MOD;
    startval = (startval*37)%MOD;
    startval += haystack[ind]-'a';
    startval %= MOD;
    found=true;
    for (int i=0; i<26; i++){
      if (hFreq[i] != nFreq[i]){
        found = false;
        break;
    }

  }
    if (found){
      rollHashValue.insert(startval);
    }

  

  }
  cout << rollHashValue.size() << endl;
  
}