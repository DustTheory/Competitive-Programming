#include <iostream>
#include <sstream>

using namespace std;

int digits[10];

void add_digits(int n){
    //cout << n << endl;
    while(n > 0){
        digits[n % 10]++;
        n /= 10;
    }
}

int main(){
    int T;
    cin >> T;

    cin.ignore();

    while(T--){
        for(int i = 0; i < 10; i++)
            digits[i] = 0;

        string line;
        getline(cin, line);
        cout << line << endl;
        getline(cin, line);
        cout << line << endl;

        stringstream ss;
        ss << line;

        int addresses;
        ss >> addresses;

        while(addresses > 0){
            ss.str("");
            getline(cin, line);
            ss << line;
            cout << ss.str();

            if(line[0] == '+'){
                char bl;
                ss >> bl;

                int l, r, ir;
                ss >> l >> r >> ir;
                for(int i = l; i <= r; i+=ir){
                    addresses--;
                    add_digits(i);
                }
            }else{
                int m;
                ss >> m;
                cout << ss.str() << endl;
                add_digits(m);
                addresses--;
            }
        }

        int num_of_digits = 0;
        for(int i = 0; i < 10; i++){
            cout << "Make " << digits[i] << " digit " << i << endl;
            num_of_digits += digits[i];
        }

        if(num_of_digits == 1)
            cout << "In total 1 digit" << endl;
        else
            cout << "In total " << num_of_digits << " digits" << endl;
    }

    return 0;
}
