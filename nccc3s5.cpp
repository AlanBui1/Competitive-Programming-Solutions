#include <bits/stdc++.h>
using namespace std;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define ll __int64_t
const int MAXSZ=2e6+5;

struct segTree{
    ll cost, cnt;
    ll addLazy;
    int L, R;
    bool setLazy;
}seg[MAXSZ*5];

struct buyamtq{
    ll moneyleft, bought;
};

struct buylowq{
    ll conesleft, bought;
};

struct buyhighq{
    ll conesleft, bought;
};

void buildTree(ll curNode, ll left, ll right){
    s.cost = 0; s.cnt = 0; s.addLazy = 0; s.setLazy = 0;
    s.L = left; s.R = right;

    if (left != right){
        ll mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}

void reset(ll curNode){
    s.cost = 0; s.cnt = 0; s.addLazy = 0; s.setLazy = 0;
}

void pushUp(ll curNode){
    s.cost = cl.cost+cr.cost;
    s.cnt = cl.cnt+cr.cnt;
}

void lazyPush(ll curNode){
    if (s.addLazy == 0 && s.setLazy == 0) return;

    ll L= s.L, R=s.R;
    if (s.setLazy){
        reset(curNode);
        if (L != R){
            cl.setLazy = 1;
            cr.setLazy = 1;
        }
        
    }

    else if (s.addLazy > 0){
        s.cost += ((L+R)*(R-L+1)*s.addLazy)/2;
        s.cnt +=  (R-L+1)*s.addLazy;
        if (L != R){
            if (cl.setLazy){
                lazyPush(curNode*2);
            }
            if (cr.setLazy){
                lazyPush(curNode*2+1);
            }
            cl.addLazy += s.addLazy;
            cr.addLazy += s.addLazy;
          
        }
        s.addLazy = 0;
    }
}

void addRange(ll curNode, ll UL, ll UR, ll val){
    ll L=s.L, R = s.R;

    if (s.addLazy >0 || s.setLazy) lazyPush(curNode); 

    if (L > UR || R < UL){
        return;
    }

    else if (UL <= L && R <= UR){
        s.addLazy += val;
        lazyPush(curNode);
        return;
    }

    addRange(curNode*2, UL, UR, val);
    addRange(curNode*2+1, UL, UR, val);
    pushUp(curNode);

}

buyamtq buyamt(ll curNode, buyamtq cur){
    ll L=s.L, R=s.R;

    lazyPush(curNode); lazyPush(curNode*2); lazyPush(curNode*2+1);

    if (cur.moneyleft < L || cur.moneyleft <= 0){
        return cur;
    }

    if (L == R){
        ll canbuy = min(s.cnt,cur.moneyleft/L);
        cur.bought += canbuy;
        s.cnt -= canbuy;
        s.cost = L*s.cnt;
      
        return cur; 
    }

    buyamtq ans;

    if (cur.moneyleft >= cl.cost){
        cur.moneyleft -= cl.cost;
        cur.bought += cl.cnt;
        cl.setLazy = 1;
        lazyPush(curNode*2);
        ans =  buyamt(curNode*2+1, cur);
    }

    else{
        ans =  buyamt(curNode*2, cur);
    }
    
    pushUp(curNode);
    return ans;
    
}

buylowq buylow(ll curNode, buylowq cur){
    ll L = s.L, R=s.R;

    if (cur.conesleft == 0){
        return cur;
    }

    if (L==R){
        ll canbuy = min(s.cnt, cur.conesleft);
        cur.bought += L*canbuy;
        s.cnt -= canbuy;
        s.cost = s.cnt*L;
        return cur;
    }

    lazyPush(curNode); lazyPush(curNode*2); lazyPush(curNode*2+1);

    buylowq ans;

    if (cl.cnt <= cur.conesleft){
        cur.conesleft -= cl.cnt;
        cur.bought += cl.cost;
        cl.setLazy = 1;
        lazyPush(curNode*2);
        ans = buylow(curNode*2+1, cur);
    }
    else{
        ans = buylow(curNode*2, cur);
    }

    pushUp(curNode);
    return ans;
}

buyhighq buyhigh(ll curNode, buyhighq cur){
    ll L = s.L, R=s.R;

    if (cur.conesleft == 0){
        return cur;
    }

    if (L == R){
        ll canbuy = min(s.cnt, cur.conesleft);
        cur.bought += L*canbuy;
        s.cnt -= canbuy;
        s.cost = s.cnt*L;
        return cur;
    }

    buyhighq ans;

    lazyPush(curNode); lazyPush(curNode*2); lazyPush(curNode*2+1);

    if (cr.cnt <= cur.conesleft){
        cur.conesleft -= cr.cnt;
        cur.bought += cr.cost;
        cr.setLazy = 1;
        lazyPush(curNode*2+1);
        ans = buyhigh(curNode*2, cur);
    }
    else{
        ans = buyhigh(curNode*2+1, cur);
    }

    pushUp(curNode);
    return ans;
}

ll cost(ll curNode, ll lim){
    ll L=s.L, R=s.R;

    lazyPush(curNode); lazyPush(curNode*2); lazyPush(curNode*2+1);

    if (L == R){
        return L;
    }

    if (cl.cnt < lim){
        return cost(curNode*2+1, lim-cl.cnt);
    }

    return cost(curNode*2, lim);
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    ll n;
    cin >> n;

    buildTree(1, 1, MAXSZ-1);

    string oper;
    ll k, p, a, b, q;

    for (int i=0; i<n; i++){
        cin >> oper;

        if (oper == "ADD"){
            cin >> k >> p;
            addRange(1, p, p, k);
        }

        else if (oper == "ADDRANGE"){
            cin >> a >> b;
            addRange(1, a, b, 1);
        }

        else if (oper == "BUYAMT"){
            cin >> q;
            lazyPush(1);
            if (seg[1].cnt == 0){
                cout << 0 << "\n";
            }
            else if (q >= seg[1].cost){
                cout << seg[1].cnt << "\n";
                seg[1].setLazy = 1;
                lazyPush(1);
            }
            else{
                buyamtq start;
                start.bought = 0;
                start.moneyleft = q;
                cout << buyamt(1, start).bought << "\n";
            }
        }

        else if (oper == "NUMCONES"){
            lazyPush(1);lazyPush(2);lazyPush(3);
            cout << seg[1].cnt << "\n";
            
        }

        else if (oper == "TOTALCOST"){
            lazyPush(1);
            cout << seg[1].cost << "\n";
            
        }

        else if (oper == "BUYLOW"){
            cin >> q;
            lazyPush(1);

            if (seg[1].cnt < q){
                cout << seg[1].cost << "\n";
            }

            else{
                buylowq star; star.bought = 0; star.conesleft = q;
                cout << buylow(1, star).bought << "\n";
            }
        }

        else if (oper == "BUYHIGH"){
            cin >> q;
            lazyPush(1);

            if (seg[1].cnt < q){
                cout << seg[1].cost << "\n";
            }
            else{
                buyhighq sta; sta.bought = 0; sta.conesleft = q;
                cout << buyhigh(1, sta).bought << "\n";
            }
        }

        else if (oper == "COST"){
            cin >> q;
            lazyPush(1);
            if (q > seg[1].cnt){
                cout << -1 << "\n";
            }
            else{
                cout << cost(1, q) << "\n";
            }
        }
    }


}