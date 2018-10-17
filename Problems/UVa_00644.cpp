#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prefix(string a, string b){
    if(a.length() > b.length())
        return false;
    for(int i = 0; i < a.length(); i++)
        if(a[i] != b[i])
            return false;
    return true;
}

bool solve(vector<string> &vec){

    sort(vec.begin(), vec.end(), [](string &a, string &b){
        return a.length() < b.length();
    });

    for(int i = 0; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            if(vec[j].length() > vec[i].length()){
                if(is_prefix(vec[i], vec[j])){
                    return false;
                }
            }
            if(vec[i] == vec[j])
                return false;
        }
    }
    return true;
}

int main(){
    vector<string> group;
    string a;
    int i = 1;
    while(cin >> a){
        if(a == "9"){
            if(solve(group))
                cout << "Set " << i << " is immediately decodable" << endl;
            else
                cout << "Set " << i << " is not immediately decodable" << endl;
            i++;
            group.clear();
        }else{
            group.push_back(a);
        }
    }
}
