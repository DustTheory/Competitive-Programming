#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void UVa_10800(){
    int test_cases;
    cin >> test_cases;
    for(int tc = 0; tc < test_cases; tc++){
        string s;
        cin >> s;
        int height = 0;
        vector<pair<int, char> > output;
        int max_height = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R')
                height++;
            else if(s[i] == 'F')
                height--;
            if(height > max_height)
                max_height = height;
            output.push_back(pair<int, char>(height, s[i]));
        }
        vector<string> out;
        string y_axis = "+";
        for(int i = 0; i < max_height; i++)
            y_axis += '|';
        out.push_back(y_axis);

        for(int i = 0; i < output.size(); i++){
            string tmp = "-";
            for(int j = 0; j < max_height; j++)
                tmp += " ";
            switch(output[i].second){
                case 'R':
                    tmp[output[i].first] = '/';
                    break;
                case 'F':
                    tmp[output[i].first+1] = '\\';
                    break;
                default:
                    tmp[output[i].first+1] = '_';
                    break;
            }
          //  cout << tmp << endl;
            out.push_back(tmp);
        }
        string blank = "";
        for(int k = 0; k < out.size()+1; k++)
            blank+= " ";
        vector<string > outtrans(out[0].size(), blank);
        for (size_t i = 0; i < out.size(); ++i)
            for (size_t j = 0; j < out[0].size(); ++j)
                outtrans[j][i] = out[i][j];
        cout << "Case #" << tc+1 << ":" << endl;
        for(int i = outtrans.size()-1; i >= 0 ; i--){
            for(int j = 0; j < outtrans[i].size(); j++){
                cout << outtrans[i][j];
            }
            cout << endl;
        }
    }
}

int main(){
    UVa_10800();
    return 0;
}
