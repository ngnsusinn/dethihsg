#include<bits/stdc++.h>

using namespace std;

vector<string>w;

void remove_ship(int i, int j){
    w[i][j] = '0';
    if (i + 1 < w.size() && w[i+1][j] == 'x')
        remove_ship(i+1, j);
    if (i - 1 >= 0 && w[i-1][j] == 'x')
        remove_ship(i-1, j);
    if (j + 1 < w[i].size() && w[i][j+1] == 'x')
        remove_ship(i, j+1);
    if (j - 1 >= 0 && w[i][j-1] == 'x')
        remove_ship(i, j-1);
}

int count_ship(){
    int ships = 0;
    for (int i = 0; i < w.size(); i++){
        for (int j = 0; j < w[i].size(); j++){
            if (w[i][j] == 'x'){
                ships++;
                remove_ship(i, j);
            }
        }
    }
    return ships;
}

int main(){
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    string s;
    while (cin >> s) w.push_back(s);
    cout << count_ship();
    return 0;
}