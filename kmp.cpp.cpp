#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp_preproces(string &str){
    vector<int> reset_table (str.length());
    fill(reset_table.begin(), reset_table.end(), -1);
    int j = -1;
    for(int i = 0; i < str.length(); i=i){
        for(j = j; j >= 0 && str[i] != str[j]; j = reset_table[j])
            continue;
        j++;
        i++;
        reset_table[i] = j;
    }
    return reset_table;
}

int kmp_find(string &to_read, string &to_find){
    vector<int> reset_table = kmp_preproces(to_find);
    for(int i = 0; i < to_read.size(); i++){
        int len = 0;
        int mem = i;
        for(int j = 0; j < to_find.size(); j++){
            if(to_read[i] == to_find[j]){
                len++;
                i++;
            }else{
                i = mem + 1 + reset_table[j];
                break;
            }
        }
        if(len == to_find.size())
            return mem;
    }
    return -1;
}

int main()
{
    string to_read, to_find;
    cin >> to_read >> to_find;
    cout << kmp_find(to_read, to_find) << endl;
    return 0;
}
