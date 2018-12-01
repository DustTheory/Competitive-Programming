#include <iostream>
#include <math.h>

using namespace std;

double deg_to_rad(int deg){
    return deg * 180/M_PI;
}


void simulate(double a, double b, double v, double A, double s){

    double d = v/s; // Usporenje
    double posx = a/2, posy = b/2; // Pocetna pozicija centar

    while(1){
        // Find where it's going to hit
        // Calculate speed and time at that position
        // Repeat
    }

}

int main(){
    int a, b, v, A_deg, s;
    cin >> a >> b >> v >> A_deg >> s;
    double A = A_deg;
}
