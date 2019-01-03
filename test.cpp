#include "biginteger.h"

int main(){
    BigInteger a, b;
    while(cin >> a >> b){
        BigInteger i;
        BigInteger result;
        result = 0;
        for(i = 1; i <= a; i++){
            result += i*b.pow(i);
        }
        cout << result << endl;
    }
}
