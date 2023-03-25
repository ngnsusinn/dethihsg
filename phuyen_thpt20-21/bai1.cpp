#include<bits/stdc++.h>

using namespace std;

vector<int>primes;

bool isprime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= sqrt(n); i+=6){
        if (n % i == 0 || n % (i+2) == 0){
            return false;
        }
    }
    return true;
}

void output(int first, int finish){
    for (int i = first; i < finish; i++){
        cout << primes[i] << "\n";
    }
}

void process(int n){
    for (int i = 1; i <= 9; i++){
        if (isprime(i)){
            primes.push_back(i);
        }
    }
    int first = 0, finish = primes.size();
    if (n == 1){
        output(first, finish);
        return;
    };
    n--;
    int gen[] = {1, 2, 3, 5, 7, 9};
    int ngen = sizeof(gen)/sizeof(int);
    while(n--){
        for (int i = first; i < finish; i++){
            for (int j = 0; j < ngen; j++){
                if (isprime(primes[i]*10 + gen[j])){
                    primes.push_back(primes[i]*10 + gen[j]);
                }
            }
        }
        first = finish;
        finish = primes.size();
    }
    output(first, finish);
}

int main(){
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);
    int n;
    cin >> n;
    process(n);
}