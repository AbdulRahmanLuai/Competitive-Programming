#include <bits/stdc++.h>
#include <iostream>  
using namespace std;  
#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
const ll MOD = 998244353;
const ll INF = 1e9;
const ll N = 2e5 + 100;
ll tree[4*N];
ll a[N];
int n;
ll defaultVal = 0;
ll initialVal = 0;
int leavesCnt = 0;

ll combine(ll a, ll b){
    return a + b;
}

void build(){
    int log = 32 -  __builtin_clz(n-1);
    leavesCnt = 1 << log;
    int indx = 1 << log;
    for (int i=0; i<n; i++){
        tree[indx++] = a[i];
    }
    for (int i= indx - n - 1; i>=1; i--){
        tree[i] = combine(tree[i*2], tree[i * 2 + 1]);
    }
}
void update(int i, int v){

    int pointer = i + leavesCnt;
    tree[pointer] = v;
    pointer /= 2;
    while(pointer){
        tree[pointer] = combine(tree[pointer * 2], tree[pointer * 2 + 1]);
        pointer /= 2;
    }
}

ll query(int a, int b) {
    a += leavesCnt; b += leavesCnt;
    ll s = initialVal;
    while (a <= b) {
        if (a%2 == 1) s = combine(s, tree[a++]);
        if (b%2 == 0) s = combine(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s; 
}




void solve(){

    int q; cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i];

    build();

    while (q--){
        int type; cin >> type;

        if (type == 1){

            int k, u; cin >> k >> u;
            k--;
            update(k, u);
        }
        else{
            int a, b; cin >> a >> b;
            a--; b--;
            cout << query(a, b) << endl;

        }
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
