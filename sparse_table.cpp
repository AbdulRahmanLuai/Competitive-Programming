#include <bits/stdc++.h>
#include <iostream>  
using namespace std;  
#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
const ll MOD = 998244353;
const ll INF = 1e9;
const ll N = 2e5 + 100;
const int LOG = 17;
int SPARSE[N][LOG];

int query(int l, int r){
    int log = 32 - __builtin_clz(r - l + 1) - 1;
    return min(SPARSE[l][log], SPARSE[r - (1<<log) + 1][log]);
}

void build_sparse_table(vector<int> &a, int log){

    for (int j = 0; j<= log; j++){
        for (int i=0; i + (1 << j) - 1 < (int) a.size(); i++){
            if (!j){
                SPARSE[i][j] = a[i];
            }
            else{
                SPARSE[i][j] = min(SPARSE[i][j-1], SPARSE[i + (1 << (j-1))][j-1]);
            }
        }
    }

}


void solve(){

    int n; cin >> n;
    vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];

    int log = 32 - __builtin_clz(n) - 1;
    build_sparse_table(a, log);
    
   
    int q; cin >> q; 
    while(q--){
        int a, b; cin >> a >> b;
        cout << query(a, b) << endl;
    }
}



int main() {
    fastIO
 
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("outputs.txt", "wt", stdout);
    #endif
 
    ll T = 1;
    // cin >> T;
    while (T--) solve();
    
    
    return 0;
} 
