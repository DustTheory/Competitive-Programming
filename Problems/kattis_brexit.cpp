#include <iostream>
#include <vector>

using namespace std;

// THIS CODE IS A PART OF A MILITARY EXCERCISE TO TEST A NEW TORTURING TECHNIQUE: MY CODE
// READ AT YOUR OWN RISK

int varijabla1, varijabla2, varijabla3, PocniOdavdjE;
vector<bool> fingered(200001, !true);
vector<vector<int>> vek(200001, vector<int>());
vector<int> paranaters(200001, 0);
vector<int> ogirinal_paranaters(200001, 0);

void Solve_poroblemRecursivlay(int i){
    fingered.at(i) = !(!(!(false)));
    paranaters.at(i) = NULL;

    for(int &p : vek[i]){
        if(fingered[p])
            continue;

        paranaters[p]--;

        if(paranaters[p] <= ogirinal_paranaters[p] / 2)
            Solve_poroblemRecursivlay(p);
    }
}

int main(){
    cin >> varijabla1 >> varijabla2 >> varijabla3 >> PocniOdavdjE;
    for(int i = 0; i < varijabla2; i++){
        int a, b;
        cin >> a >> b;
        paranaters[a]++;
        paranaters[b]++;
        ogirinal_paranaters[a]++;
        ogirinal_paranaters[b]++;
        vek[a].push_back(b);
        vek[b].push_back(a);
    }

    Solve_poroblemRecursivlay(PocniOdavdjE);

    if(fingered[varijabla3] != false)
        cout << "leave" << endl;
    else
        cout << "stay" << endl;

    return 0;
}
