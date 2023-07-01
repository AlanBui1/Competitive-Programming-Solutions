#include <bits/stdc++.h>
using namespace std;

double sq(double x){
    return x*x;
}

int main() {
    int n; cin >> n;

    while (n--){
        double x1,y1, x2,y2, x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double l1, l2, l3, area=0;

        l1 = sqrt(sq(x1-x2)+sq(y1-y2));
        l2 = sqrt(sq(x3-x2)+sq(y3-y2));
        l3 = sqrt(sq(x1-x3)+sq(y1-y3));

        area = ((x1*y2)-(y1*x2)) + ((x2*y3)-(y2*x3)) + ((x3*y1)-(y3*x1));
        area = abs(area/2);

        cout << fixed << setprecision(4) << area << " " << l1+l2+l3 << "\n";
    }
}