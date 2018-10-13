#include <iostream>
#include <map>
#include <utility>

using namespace std;

string l =
"`1234567890-=\
qwertyuiop[]\\\
asdfghjkl;'\
zxcvbnm,./";
string r =
"`123qjlmfp/[]\
456.orsuyb;=\\\
789aehtdck-\
0zx,inwvg'";
string L =
"~!@#$%^&*()_+\
QWERTYUIOP{}|\
ASDFGHJKL:\"\
ZXCVBNM<>?";
string R =
"~!@#QJLMFP?{}\
$%^>ORSUYB:+|\
&*(AEHTDCK_\
)ZX<INWVG\"";

string qwerty = l + L;
string dvorak = r + R;
void UVa_11278(){
    while(1){
        string a;
        getline(cin, a);
        if(cin.eof())
            break;
        for(int i = 0; i < a.length(); i++){
            int t = dvorak.find(a[i]);
            if(t > 255)
                cout << a[i];
            else
                cout << qwerty[t];
        }
        cout << endl;
    }
}
int main(){
    UVa_11278();
}
