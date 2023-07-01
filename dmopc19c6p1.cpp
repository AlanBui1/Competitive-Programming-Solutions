#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double slope, yint;

    bool undef = 0;
    if (x1 == x2){
        undef = 1;
    }

    else{
        slope = (y1-y2)/(x1-x2);
        yint = y1 - (slope*x1);
    }

    if (x3 == x4){
        if (undef){
            if (x1 == x3){
                cout << "coincident\n";
            }
            else{
                cout << "parallel\n";
            }
        }
        else{
            double Y = slope*x3 + yint;
            cout << fixed << setprecision(6) << x3 << " " << Y << "\n";
        }
    }

    else{
        double slope2 = (y3-y4)/(x3-x4);
        double B = y3 - (slope2*x3);
        if (undef){
            double Y = slope2*x1+ B;
            cout << fixed << setprecision(6) << x1 << " " << Y << "\n";
        }

        else{
            if (((y1-y2)*(x3-x4)) == ((y3-y4)*(x1-x2))){
                if (abs(y1 - (((y1-y2)/(x1-x2))*x1) - B) < 0.0001){
                    cout << "coincident\n";
                }
                else{
                    cout << "parallel\n";
                }
            }
            else{
                double X = ((B-yint)/(slope-slope2));
                double Y = slope*X + yint;
                cout << fixed << setprecision(6) << X << " " << Y << "\n";
            }
        }

    }
}