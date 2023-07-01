#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define inf INT_MAX

const int MAXSZ=2e6+5;
int n, k, oper, l, r, h;

struct segTree{
    int L, R, buildLazy, remLazy;
    // int setLazy;
    int val;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L = left; seg[curNode].R = right;
    seg[curNode].buildLazy=-1; 
    seg[curNode].remLazy=inf;
    seg[curNode].val =0;
    // seg[curNode].setLazy = 0;

    if (left!=right){
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}
void setPush(int curNode, int newVal){
    int L=s.L, R=s.R;
    
    s.buildLazy = newVal; s.remLazy = newVal;
}

void lazyPush(int curNode){
    int L=s.L, R=s.R;
    
    if (L==R){
        
        
        if (s.buildLazy >= 0) s.val = max(s.val, s.buildLazy);
        if (s.remLazy < inf) s.val = min(s.val, s.remLazy);
        
        // cout << "11: " << seg[11].val << " " << seg[11].buildLazy << " " << seg[11].remLazy << "\n";
        s.buildLazy = -1;
        s.remLazy = inf;

        return;
    }

    else{
        int change;
        if (s.buildLazy >= 0 && s.remLazy < inf) change=3;
        else if (s.buildLazy >= 0) change=1;
        else if (s.remLazy < inf) change = 2;

        if (change == 3){
            if (cl.buildLazy == -1 && cl.remLazy == inf){
                cl.buildLazy = s.buildLazy;
                cl.remLazy = s.remLazy;
            }
            else if (cl.buildLazy != -1 && cl.remLazy != inf){
                if (s.buildLazy >= cl.buildLazy && s.buildLazy >= cl.remLazy){
                    setPush(curNode*2, s.buildLazy);
                }
                else if (s.remLazy <= cl.remLazy && s.remLazy <= cl.buildLazy){
                    setPush(curNode*2, s.remLazy);
                }
                else{
                    // lazyPush(curNode*2);
                    cl.buildLazy = max(cl.buildLazy, s.buildLazy);
                    cl.remLazy= min(s.remLazy, cl.remLazy);
                }
            }
            else if (cl.buildLazy >= 0){
                if (cl.buildLazy <= s.buildLazy){
                    cl.buildLazy = s.buildLazy;
                    cl.remLazy = s.remLazy;
                } 
                else if (cl.buildLazy >= s.remLazy){
                    
                    setPush(curNode*2, s.remLazy);
                }
                else{
                    cl.buildLazy = max(cl.buildLazy, s.buildLazy);
                    cl.remLazy = s.remLazy;
                }
            }

            else if (cl.remLazy < inf){
                if (cl.remLazy >= s.remLazy){
                    cl.remLazy = s.remLazy;
                    cl.buildLazy = s.buildLazy;
                }
                else if (cl.remLazy <= s.buildLazy){
                    
                    setPush(curNode*2, s.buildLazy);
                }
                else{
                    cl.remLazy = min(cl.remLazy, s.remLazy);
                    cl.buildLazy = s.buildLazy;
                }
            }

            if (cr.buildLazy == -1 && cr.remLazy == inf){
                cr.buildLazy = s.buildLazy;
                cr.remLazy = s.remLazy;
            }

            else if (cr.buildLazy != -1 && cr.remLazy != inf){
                if (s.buildLazy >= cr.buildLazy && s.buildLazy >= cr.remLazy){
                    setPush(curNode*2+1, s.buildLazy);
                }
                else if (s.remLazy <= cr.remLazy && s.remLazy <= cr.buildLazy){
                    setPush(curNode*2+1, s.remLazy);
                }
                else{
                    // lazyPush(curNode*2+1);
                    cr.buildLazy = max(cr.buildLazy, s.buildLazy);
                    cr.remLazy= min(s.remLazy, cr.remLazy);
                }
            }

            else if (cr.buildLazy >= 0){
                if (cr.buildLazy <= s.buildLazy){
                    cr.buildLazy = s.buildLazy;
                    cr.remLazy = s.remLazy;
                }
                else if (cr.buildLazy >= s.remLazy){
                    
                    setPush(curNode*2+1, s.remLazy);
                }
                else {
                    cr.buildLazy = max(cr.buildLazy, s.buildLazy);
                    cr.remLazy = s.remLazy;
                }
            }

            else if (cr.remLazy < inf){
                if (cr.remLazy >= s.remLazy){ 
                    cr.remLazy = s.remLazy;
                    cr.buildLazy = s.buildLazy;
                }
                else if (cr.remLazy <= s.buildLazy){
                    
                    setPush(curNode*2+1, s.buildLazy);
                }
                else{
                    cr.remLazy = min(cr.remLazy, s.remLazy);
                    cr.buildLazy = s.buildLazy;
                }
            }

            s.buildLazy = -1; 
            s.remLazy = inf;    
        }

        else if (change == 1){ //building phase

            if (cl.buildLazy == -1 && cl.remLazy == inf){
                cl.buildLazy = s.buildLazy;
                //lazyPush(curNode);
            }

            else if (cl.buildLazy != -1 && cl.remLazy != inf){
                if (s.buildLazy >= cl.buildLazy && s.buildLazy >= cl.remLazy){
                    setPush(curNode*2, s.buildLazy);
                }
                else cl.buildLazy = max(cl.buildLazy, s.buildLazy);
                //lazyPush(curNode);
            }

            else if (cl.buildLazy >= 0){
                cl.buildLazy = max(cl.buildLazy, s.buildLazy);
                // lazyPush(curNode);
            }

            else if (cl.remLazy < inf){
                if (s.buildLazy >= cl.remLazy){
                     
                    setPush(curNode*2, s.buildLazy);
                }
                else{
                    // lazyPush(curNode*2);
                    
                    cl.buildLazy = max(s.buildLazy,cl.buildLazy);
                }
            }

            if (cr.buildLazy == -1 && cr.remLazy == inf){
                cr.buildLazy = s.buildLazy;
                //lazyPush(curNode);
            }

            else if (cr.buildLazy != -1 && cr.remLazy != inf){
                if (s.buildLazy >= cr.buildLazy && s.buildLazy >= cr.remLazy){
                    setPush(curNode*2+1, s.buildLazy);
                }
                else cr.buildLazy = max(cr.buildLazy, s.buildLazy);
                //lazyPush(curNode);
            }

            else if (cr.buildLazy >= 0){
                cr.buildLazy = max(cr.buildLazy, s.buildLazy);
                // lazyPush(curNode);
            }

            else if (cr.remLazy < inf){

                if (s.buildLazy >= cr.remLazy){
                   
                    setPush(curNode*2+1, s.buildLazy);
                }
                else{
                    
                    // lazyPush(curNode*2+1);
                    // cout << "111: " << seg[11].val << " " << seg[11].buildLazy << " " << seg[11].remLazy << "\n";
                    cr.buildLazy = max(s.buildLazy,cr.buildLazy);
                    // cout << "111: " << seg[11].val << " " << seg[11].buildLazy << " " << seg[11].remLazy << "\n";
                    
                }
            }

            s.buildLazy = -1;

        }

        else{ //removing phase
            if (cl.buildLazy == -1 && cl.remLazy == inf){
                cl.remLazy = s.remLazy;
                //lazyPush(curNode);
            }

            else if (cl.buildLazy != -1 && cl.remLazy != inf){
                if (s.remLazy <= cl.buildLazy && s.remLazy <= cl.remLazy){
                    setPush(curNode*2, s.remLazy);
                }
                else cl.remLazy = min(cl.remLazy, s.remLazy);
                //lazyPush(curNode);
            }
            
            else if (cl.remLazy < inf){
                cl.remLazy = min(s.remLazy, cl.remLazy);
                // lazyPush(curNode);
            }

            else if (cl.buildLazy >= 0){
                if (s.remLazy <= cl.buildLazy){
                    
                    setPush(curNode*2, s.remLazy);
                }
                else{
                    // lazyPush(curNode*2);
                    cl.remLazy = min(s.remLazy,cl.remLazy);
                }
            }

            if (cr.buildLazy == -1 && cr.remLazy == inf){
                cr.remLazy = s.remLazy;
                //lazyPush(curNode);
            }
            else if (cr.buildLazy != -1 && cr.remLazy != inf){
                if (s.remLazy <= cr.buildLazy && s.remLazy <= cr.remLazy){
                    setPush(curNode*2+1, s.remLazy);
                }
                else cr.remLazy = min(cr.remLazy, s.remLazy);
                //lazyPush(curNode);
            }
            else if (cr.remLazy < inf){
                cr.remLazy = min(s.remLazy, cr.remLazy);
                // lazyPush(curNode);
            }

            else if (cr.buildLazy >= 0){

                if (s.remLazy <= cr.buildLazy){
                    
                    setPush(curNode*2+1, s.remLazy);
                }
                else{
                    // lazyPush(curNode*2+1);
                    
                    cr.remLazy = min(s.remLazy,cr.remLazy);
                    
                }
                // lazyPush(curNode);
            }
            s.remLazy = inf;

        }

    }
    
}

void changePhase(int curNode, int UL, int UR, int height, int change){
    int L=s.L, R=s.R;

    if (s.buildLazy >= 0 || s.remLazy < inf) lazyPush(curNode);
    
    if (L>UR || R<UL) return;
    
    if (UL <= L && R <= UR){
        
        if (change == 1){ //building phase

            if (s.buildLazy == -1 && s.remLazy == inf){
                s.buildLazy = height;
                // lazyPush(curNode);
                return;
            }

            else if (s.buildLazy != -1 && s.remLazy != inf){
                if (height >= s.buildLazy && height >= s.remLazy){
                    setPush(curNode, height);
                }
                else s.buildLazy = max(s.buildLazy, height);
                //lazyPush(curNode);
            }

            

            else if (s.buildLazy >= 0){
                s.buildLazy = max(s.buildLazy, height);
                // lazyPush(curNode);
                return;
            }

            else if (s.remLazy < inf){
  
                if (height >= s.remLazy){
                    setPush(curNode, height);
                }

                else{
                    // lazyPush(curNode);
               
                    s.buildLazy = max(s.buildLazy, height);

                }
                return;
            }

        }

        else{ //removing phase
            if (s.buildLazy == -1 && s.remLazy == inf){
                s.remLazy = height;
                // lazyPush(curNode);
                return;
            }

            else if (s.buildLazy != -1 && s.remLazy != inf){
                if (height <= s.buildLazy && height <= s.remLazy){
                    setPush(curNode, height);
                }
                else s.remLazy = min(s.remLazy, height);
                //lazyPush(curNode);
            }

            else if (s.remLazy < inf){
                s.remLazy = min(s.remLazy, height);
                // lazyPush(curNode);
                return;
            }

            else if (s.buildLazy >= 0){

                if (height <= s.buildLazy){
                    setPush(curNode, height);
                }
                else{
                    // lazyPush(curNode);

                    s.remLazy = min(s.remLazy, height);
                }
                // lazyPush(curNode);
                return;
            }

        }
    }
    
    changePhase(curNode*2, UL, UR, height, change);
    changePhase(curNode*2+1, UL, UR, height, change);
}

void fullPush(int curNode){
    int L=s.L, R=s.R;

    // if (s.buildLazy >= 0 || s.remLazy < inf) 
    lazyPush(curNode);

    if (L==R){
        // if (s.val == -1) cout << 0 << "\n";
        cout << s.val << "\n";
        return;
    }

    fullPush(curNode*2); fullPush(curNode*2+1);
}

int main() {
    scan(n); scan(k);
    buildTree(1, 0, n-1);

    while (k--){
        scan(oper); scan(l); scan(r); scan(h);
        changePhase(1, l, r, h, oper);
        

    }

    fullPush(1);
    // cout << "11: " << seg[24].val << " " << seg[24].buildLazy << " " << seg[24].remLazy << "\n";

}