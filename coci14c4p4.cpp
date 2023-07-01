#include <bits/stdc++.h>
using namespace std;

double n, x, flow[1005][1005], amt[1005], want[1005];
bool super[1005][1005], t;
int a, b;

vector <pair <int, double>> graph[1005];

double sq(double y){
    return y*y;
}

void dfs(int curNode, int prevNode, double curFlow){
    amt[curNode] = curFlow;
   // cout << curNode << " " << curFlow << "\n";

    for (pair <int, double> pid : graph[curNode]){
        int nxtNode = pid.first, perc = pid.second;
        //cout << nxtNode << " " << perc << "\n";

        if (nxtNode == prevNode) continue;
        dfs(nxtNode, curNode, super[curNode][nxtNode] ? sq(curFlow*perc/100) : curFlow*perc/100);
    }
}

bool works(){
    bool flag = 1;
    for (int i=1; i<=n; i++){
        //cout << amt[i] << " ";
        if (want[i] > amt[i]) return false;
    }//cout << "\n";
    return flag;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<n; i++){
        cin >> a >> b >> x >> t;
        super[a][b] = t; super[b][a] = t;

        graph[a].push_back({b, x});
        graph[b].push_back({a, x});
    }

    for (int i=1; i<=n; i++){
        cin >> want[i];
    }

    double lo = 0, hi = 2e9, best = 2e9;

    while (hi - lo >= 0.0001){
        double mid = (lo+hi)/2;

        dfs(1, 1, mid);

        if (works()){
            //cout << mid << "\n";
            hi = mid - 0.0001;
            best = min(best, mid);
        }

        else{
            lo = mid+0.0001;
        }
    }

    cout << best << "\n";

}