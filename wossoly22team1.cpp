#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double area( double a, double b, double c){
    double s = a+b+c;
    s /= 2;
    return sqrt(s*(s - a)*(s - b)*(s - c));
}


int main(){
    double x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double s1 = dist(x1, y1, x2, y2), s2 = dist(x1, y1, x3, y3), s3 = dist(x2, y2, x3, y3);

    cout << area(s1, s2, s3) << "\n";
}