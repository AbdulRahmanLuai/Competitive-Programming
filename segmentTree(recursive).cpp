#include <bits/stdc++.h>
#include <iostream>  
using namespace std;  
#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
const ll MOD = 998244353;
const ll INF = 1e9;
const ll N = 2e5 + 100;
ll seg[4*N];
ll a[N];
ll defaultVal = 0;


ll combine(ll a, ll b){
    return a + b;
}

void build(int id, int start, int end){
    
    if (start == end){
        seg[id] = (ll) a[start];
        return; 
    }
    int mid = (start + end)/2;

    build(id*2, start, mid);
    build(id*2 + 1, mid + 1, end);

    seg[id] = combine(seg[id*2], seg[id*2 + 1]);
}

ll query(int id, int nodeLeft, int nodeRight, int queryLeft, int queryRight){

    if (queryLeft > nodeRight || queryRight < nodeLeft){
        return defaultVal;
    }
    if (nodeLeft >= queryLeft && nodeRight <= queryRight){
        return seg[id];
    }

    int mid = (nodeLeft + nodeRight)/2;

    ll answerLeft = query(2*id, nodeLeft, mid, queryLeft, queryRight);
    ll answerRight = query(2*id + 1, mid + 1, nodeRight, queryLeft, queryRight);

    return combine(answerLeft, answerRight);
}

void update(int id, int nodeLeft, int nodeRight, int index, int newVal){

    if (nodeLeft == nodeRight){
        seg[id] = newVal;
        return;
    }

    int mid = (nodeLeft + nodeRight)/2;
    if (index <= mid){
        update(id*2, nodeLeft, mid, index, newVal);
    }
    else{
        update(id*2 + 1, mid + 1, nodeRight, index, newVal);
    }
    seg[id] = combine(seg[id*2], seg[id*2 + 1]);
}




void solve(){

    int n, q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];

    build(1, 1, n);

    while(q--){
        int type, i, j; cin >> type >> i >> j;
        if (type == 1){
            update(1, 1, n, i, j);
        }
        else{
            cout << query(1, 1, n, i, j) << endl;
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
