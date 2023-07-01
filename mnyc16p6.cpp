#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;
#define ll long long

ll bit[nax];
unordered_map <string, int> vals;
unordered_map <string, int> location;

int convert(string word){
    ll val=0;
    for (char c : word){
        val += c-'a'+1;
    }
    return val;
}

void update(int r, int v){
    for (; r <= nax; r+= r&-r){
        bit[r] += v;
    }
}

ll query(int L, int R){
    ll s=0;
    if (L>R) swap(L, R);
    L--;
    for (; L > 0; L -= L&-L){
        s-=bit[L];
    }
    for (; R > 0; R -= R&-R){
        s+=bit[R];
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int numrocks=0;
    int q; cin >> q;

    char oper;
    int x, y, r;
    string name;
    string rname;

    while (q--){
        cin >> oper;

        if (oper == 'A'){
            cin >> name;
            if (location[name] != 0){
                cout << "Can't add " << name << "\n";
            }
            else{
                vals[name] = convert(name); 
                numrocks++;
                update(numrocks, vals[name]);
                location[name] = numrocks;
            }
        }

        else if (oper == 'N'){
            cout << numrocks << "\n";
        }

        else if (oper == 'R'){
            cin >> name >> rname;
            vals[rname] = convert(rname);
            update(location[name], -vals[name]);
            update(location[name], vals[rname]);
            location[rname] = location[name];
            location[name] = 0; 
        }

        else if (oper == 'M'){
            cin >> name >> rname;
            cout << query(location[name], location[rname]) << "\n";
        }

        else{
            cin >> name >> rname;
            update(location[name], -vals[name]+vals[rname]);
            update(location[rname], -vals[rname]+vals[name]);
            int re = location[name];
            location[name] = location[rname];
            location[rname] = re;
        }
    }


}