#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

vector<string> blank_coordinate_system(int &x, int &y);

void generate_graph(string &s, int &high, int &low){
    int x = s.length();
    int y = fabs(high)+fabs(low);
    std::vector<string> cs = blank_coordinate_system(x, y);
    std::vector<int> lastchar;

    for(int i = 0; i < y; i++)
        lastchar.push_back(0);
    lastchar[y] = x+2;

    int pos = fabs(low);

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'R'){
            pos++;
            cs[y-pos][i+2] = '/';
            lastchar[y-pos] = i+2;
        }
        else if(s[i] == 'F'){
            cs[y-pos][i+2] = '\\';
            lastchar[y-pos] = i+2;
            pos--;
        }else{
             cs[y-pos-1][i+2] = '_';
             lastchar[y-pos-1] = i+2;
        }
    }

    for(int i = 0; i < cs.size(); i++){
        for(int j = 0; j < cs[i].size() && j <= lastchar[i]; j++){
            cout << cs[i][j];
        }        
        cout << endl;
    }
}

vector<string> blank_coordinate_system(int &x, int &y){
    vector<string> cs;
    for(int i = 0; i < y; i++){
        string tmp = "|";
        for(int i = 0; i <= x; i++)
            tmp += " ";
        cs.push_back(tmp);
    }
    string tmp = "+-";
    for(int i = 0; i <= x; i++)
        tmp += "-";
    cs.push_back(tmp);
    return cs;
}

void UVa_10800(){
    int test_cases;
    cin >> test_cases;
    for(int tc = 0; tc < test_cases; tc++){
        string s;
        cin >> s;
        int height = 0;
        int low = 0, high = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R')
                height++;
            else if(s[i] == 'F')
                height--;
            else if(s[i] == 'C' && height == high)
                high++;
            if(height > high)
                high = height;
            if(height < low)
                low = height;
        }
        cout << "Case #" << tc+1 << ":" << endl;
        generate_graph(s, high, low);
        cout << endl;
  }
}




int main(){
    ios_base::sync_with_stdio(false);
    UVa_10800();
    return 0;
}
