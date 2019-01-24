#include <iostream>
#include <complex>
#include <tgmath.h>
#include <vector>

using namespace std;

long double dis(complex<long double> a, complex<long double> b){
    return sqrtl((a.real() - b.real())*(a.real() - b.real()) + (a.imag() - b.imag())*(a.imag() - b.imag()));

}

long double dis(long double x1, long double y1, long double x2, long double y2){
    return sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

pair<complex<long double>, complex<long double>> calc_circles(complex<long double> a, complex<long double> b, long double r){
    long double x1 = a.real(), y1 = a.imag(), x2 = b.real(), y2 = b.imag();
   

    // Calculate midpoint
    long double x3 = (x1+x2)/2.0, y3 = (y1+y2)/2.0;
  
    if(x1+x2 == 0)
        x3 = 0;

    if(y1+y2 == 0)
        y3 = 0;

    long double midpoint = dis(x1, y1, x2, y2)/2.0;

    // Distance between the midpoint and the center of a circle
    long double d = sqrt(r*r - midpoint*midpoint);

    long double p1, p2, q1, q2, alpha, deltax, deltay;

    if(x1 == x2){
        deltax = d;
        deltay = 0;
    }else if(y1 == y2){
        deltay = d;
        deltax = 0;
    }else{
        // line p : goes trough our 2 given points; y = p1*x + p2
        p1 = (x2-x1)/(y2-y1);
        p2 = y3 - p1*x3;

        // line q: perpandicular to line p; y = q1*x + q2; q1 = -1/p1
        q1 = -1/p1;
        q2 = y3 - q1*x3;

        // p1 is also the tg of the angle the line p creates with the x axis
        // reverse that shit
        alpha = atan(q1);
        
        // Split the line segment of length d starting from midpoint into x and y components
        deltax = cos(alpha)*d;
        deltay = sin(alpha)*d;
    }
//    cout << midpoint << endl;
    // Finally generate the points
    complex<long double> point1(x3+deltax, y3+deltay);
    complex<long double> point2(x3-deltax, y3-deltay);

    return pair<complex<long double>, complex<long double>>(point1, point2); 
}

int m;


int max_mosquitoes(complex<long double> mosquitoes[40], vector<complex<long double>> &circles, long double r){
    int maxi = 0;
    for(auto &circle : circles){
        int cnt = 0;
  //      cout << "CIRCLE: " << circle.real() << ' ' << circle.imag() << endl;
        for(int i = 0; i < m; i++){
            if(dis(circle, mosquitoes[i]) <= r){
//                cout << mosquitoes[i].real() << ' ' << mosquitoes[i].imag() << endl;
                cnt++;
            }
        }    
        maxi = max(cnt, maxi);
    }
    return maxi;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        long double d;
        cin >> m >> d;
        //d += 0.0001;
        long double x, y;
        long double r = d/2;
        complex<long double> mosquitoes[40];
        vector<complex<long double>> circles;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            mosquitoes[i] = complex<long double>(x, y);
            circles.push_back(mosquitoes[i]);
        }
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                long double dist = dis(mosquitoes[i], mosquitoes[j]); 
               //cout << dist << endl;
                if(dist == 0)
                    continue;
                if(dist <= d){
                    pair<complex<long double>, complex<long double>> centers = calc_circles(mosquitoes[i], mosquitoes[j], r);      
                    circles.push_back(centers.first);
                    circles.push_back(centers.second);
       //           cout << "##################" << endl;
       //           cout << mosquitoes[i].real() << ' ' << mosquitoes[i].imag() << ' ' << mosquitoes[j].real() << ' ' << mosquitoes[j].imag() << endl;
       //           cout << centers.first.real() << ' ' << centers.first.imag() << ' ' << centers.second.real() << ' ' << centers.second.imag() << endl;
       //           cout << "##################" << endl;
                }//else if(dist == d){
                 //   circles.push_back(complex<long double>((mosquitoes[i].real()+mosquitoes[j].real())/2.0, 
                //                                        (mosquitoes[i].imag()+mosquitoes[j].imag())/2.0));
              //  }
            }
        }
        cout << max_mosquitoes(mosquitoes, circles, r) << endl;
    }
    return 0;
}
