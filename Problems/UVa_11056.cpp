#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cctype>

using namespace std;

void to_upper(string &s){
    for(int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
}

struct driver{
    string name;
    string uname;
    uint16_t namelen;
    uint16_t minutes, seconds, miliseconds;
    driver(string input){
        char _name[20];
        sscanf(input.c_str(), "%s : %d min %d sec %d ms", &_name, &minutes, &seconds, &miliseconds);
        uname = name = string(_name);
        to_upper(uname);
    }
    bool operator< (driver other){
        if(minutes == other.minutes)
            if(seconds == other.seconds)
                if(miliseconds == other.miliseconds)
                    return uname < other.uname;
                else
                    return miliseconds < other.miliseconds;
            else
                return seconds < other.seconds;
        else
            return minutes < other.minutes;
    }
};

int main(){
    int n;
    while(cin >> n){
        string dummy;
        vector<driver> drivers;
        cin.ignore();
        for(int i = 0; i < n; i++){
            getline(cin, dummy);
            drivers.push_back(driver(dummy));
        }
        sort(drivers.begin(), drivers.end());
        int i;
        int row = 1;
        for(i = 0; i < drivers.size()-1; i+=2){
            cout << "Row " << row << '\n' << drivers[i].name << '\n' << drivers[i+1].name << '\n';
            row++;
        }
        if((row-1)*2 < drivers.size())
            cout << "Row " << row << '\n' << drivers[drivers.size()-1].name << '\n';
        cout << endl;
    }
    return 0;
}
