#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum status{misspelling, unknown, correct, incorrect};

bool rule2(string &a, string &b){
    if(a.length() != b.length())
        return false;

    bool found = false;
    for(int i = 0; i < a.length(); i++)
        if(found && a[i] != b[i])
            return false;
        else if(a[i] != b[i])
            found = true;

    return found;
}

bool rule3(string &a, string &b){
    if(a.length() != b.length())
        return false;
    for(int i = 0; i < a.length()-1; i++){
        if(a[i] != b[i]){
            swap(a[i], a[i+1]);
            if(a == b){
                swap(a[i], a[i+1]);
                return true;
            }
            swap(a[i], a[i+1]);
        }
    }
    return a == b;
}


bool rule1_1(string &a, string &b){
    if(a.length() >= b.length())
        return false;
    if(a == b.substr(0, a.length()) && a.length()+1 == b.length())
        return true;
    if(a == b.substr(1, a.length()) && a.length()+1 == b.length())
        return true;
    int split = -1;
    for(int i = 0; i < a.size(); i++){
    //    cout << a[i] << ' ' << b[i] << endl;
        if(a[i] != b[i] && split == -1){
            split = i;
            break;
        }else if(a[i] != b[i]){
            return false;
        }
    }
   // cout << split << endl;
    if(split == -1)
        return false;
    //cout << a.substr(0, split)+b[split]+a.substr(split, a.length() - split) << endl;
    return a.substr(0, split)+b[split]+a.substr(split, a.length() - split) == b;
}

bool rule1_2(string &a, string &b){
    if(a.length() <= b.length())
        return false;
    return rule1_1(b, a);
}

int main(){
    vector<string> dict;
    int dict_size, n_words;
    cin >> dict_size;

    for(int i = 0; i < dict_size; i++){
        string dummy;
        cin >> dummy;
        dict.push_back(dummy);
    }

    cin >> n_words;
    vector<string> words;
    for(int i = 0; i < n_words; i++){
        string dummy;
        cin >> dummy;
        bool found = false;
        for(int j = 0; j < dict_size; j++){
           if(dummy == dict[j]){
                cout << dummy << " is correct" << endl;
                found = true;
                break;
            }
        }
        if(!found)
            for(int j = 0; j < dict_size; j++){
                if(rule1_1(dummy, dict[j]) || rule1_2(dummy, dict[j]) || rule2(dummy, dict[j]) || rule3(dummy, dict[j])){
                    cout << dummy << " is a misspelling of " << dict[j] << endl;
                    found = true;
                    break;
                }
            }
        if(!found)
            cout << dummy << " is unknown" << endl;
    }
}
