#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>>f;
vector<int>a;

void bai3(int hourmax){
    int d[hourmax+1], sum = 0;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= hourmax; i++){
        for (int j = 1; j <= f.size(); j++){
            if (f[j].first == i){
                if (d[i] == 0){
                    d[i] = j;
                }
                else {
                    if (f[j].second > f[d[i]].second){
                        a.push_back(d[i]);
                        d[i] = j;
                    }
                    else a.push_back(j);
                }
            }
        }
    }
    for (int i = 1; i <= hourmax; i++){
        if (d[i] != 0){
            cout << d[i] << "\n";
            sum += f[d[i]].second;
        }
    }
    for (auto &v : a){
        cout << v << "\n";
    }
    cout << sum;
}

int main(){
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    int n, hourmax = 0;
    cin >> n;
    f.push_back({0, 0});
    for (int i = 0; i < n; i++){
        int hh, val;
        cin >> hh >> val;
        f.push_back({hh, val});
        if (hh > hourmax) hourmax = hh;
    }
    bai3(hourmax);
    return 0;
}