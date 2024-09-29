#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MOD = 998244353;

int add(int a, int b){
    return (a % MOD + b % MOD) % MOD;
}
int subtract(int a, int b){
    return (a % MOD - b%MOD + MOD) % MOD;
}
int multiply(int a, int b){
    return (1LL * a % MOD * b % MOD) % MOD;
}
int power(int a, int b){

    if (b == 0) return 1;

    int temp = power(a, b/2);

    temp = multiply(temp, temp);

    if (b&1) temp = multiply(temp, a);

    return temp;
}

int inv(int a){
    return power(a, MOD - 2);
}

int divide(int a, int b){
    return multiply(a, inv(b));
}


int main() {
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("outputs.txt", "wt", stdout);
    #endif
    

    return 0;
}
