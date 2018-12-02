#include <iostream>
#include <math.h>

using namespace std;

#define EPS 1e-4

double deg_to_rad(int deg){
    return deg * M_PI/180.0;
}


void simulate(double a, double b, double v, double A, double s){
    double l = v*s/2; // Length of travel; Formulas v^2 = v0^2 - 2as; a = v0/t; a - decceleration; s - length of travel; v = 0; v0 - initial velocity
    double H, V;

    double xl = l * cos(A); // Length of travel on x axis
    double yl = l * sin(A); // Length of travel on y axix
    if(xl <= EPS)
        H = 0;
    else
        H = xl / (a/2.0);
    if(yl <= EPS)
        V = 0;
    else
        V = yl / (b/2.0);

    if(H <= 1.0-EPS){
        H = 0;
    }else if(H < 2.0-EPS){
        H = 1;
    }else{
      //  cout << H << endl;
        H = (int)((H-1)/2) + 1;
    }

    if(V <= 1.0-EPS){
        V = 0;
    }else if(V < 2.0-EPS){
        V = 1;
    }else{
     //   cout << V << endl;
        V = (int)((V-1)/2) + 1;
    }

    cout << H << ' ' << V << endl;
}

int main(){
    int a, b, v, A_deg, s;
    while(1){
        cin >> a >> b >> v >> A_deg >> s;
        if(a == 0 && b == 0 && v == 0 && A_deg == 0 && s == 0)
            break;
        double A = deg_to_rad(A_deg);
        simulate(a, b, v, A, s);
    }
}
