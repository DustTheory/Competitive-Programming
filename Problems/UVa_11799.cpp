#define __USE_MINGW_ANSI_STDIO 1 //or gcc prog.c -std=c99 -D__USE_MINGW_ANSI_STDIO
#include <iostream>
#include <inttypes.h>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    uint8_t tc;
    scanf("%" SCNu8, &tc);
    for(uint8_t t = 0; t < tc; t++){
        uint8_t s;
        short a, m = 0;
        scanf("%" SCNu8, &s);
        for(uint8_t i = 0; i < s; i++){
            cin >> a;
            if(a > m)
                m = a;
        }
        printf("Case %u: %u\n", t+1, m);
    }
}
