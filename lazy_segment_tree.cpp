#include <bits/stdc++.h>
#include <iostream>  
using namespace std;  
#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
 
const ll MOD = 998244353;
const ll INF = 1e9;
const ll N = 2e5 + 100;
int a[N];
ll seg[4*N];
ll lazy[4*N];
ll defaultValue = 0;

ll combine(ll a, ll b){
    return a + b;
}

void build(int id, int leftNode, int rightNode){
    if (leftNode == rightNode){
        seg[id] = a[leftNode];
        return;
    }
    int mid = (leftNode + rightNode) >> 1;
    build(id*2, leftNode, mid);
    build(id*2 + 1, mid + 1, rightNode);

    seg[id] = combine(seg[id*2], seg[id*2 + 1]);
}

void updateRange(int id, int leftNode, int rightNode, int updateLeft, int updateRight, int value){
    if (updateRight < leftNode || updateLeft > rightNode){
        return;
    }
    if (leftNode >= updateLeft && rightNode <= updateRight){
        lazy[id] += value;
        return;
    }
    int mid = (leftNode + rightNode) >> 1;
    updateRange(2*id, leftNode, mid, updateLeft, updateRight, value);
    updateRange(2*id + 1, mid + 1, rightNode, updateLeft, updateRight, value);
}

ll query(int id, int leftNode, int rightNode, int queryLeft, int queryRight){

    if (leftNode > queryRight || rightNode < queryLeft){
        return defaultValue;
    }
    if (leftNode >= queryLeft && rightNode <= queryRight){
        return seg[id] + lazy[id] * (rightNode - leftNode + 1);
    }
    
    int mid = (leftNode + rightNode) >> 1;
    lazy[id*2] += lazy[id];
    lazy[id*2 + 1] += lazy[id];
    
    ll leftAnswer = query(id*2, leftNode, mid, queryLeft, queryRight);
    ll rightAnswer = query(id * 2 + 1, mid + 1, rightNode, queryLeft, queryRight);
    seg[id] = combine(leftAnswer, rightAnswer);
    lazy[id] = 0;
    return seg[id];
}




void solve(){
    int n, q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1, 1, n);

    while(q--){
        int type; cin >> type;

        if(type == 1){
            int l, r, u; cin >> l >> r >> u;
            updateRange(1, 1, n, l, r, u);
        }
        else{
            int k; cin >> k;
            cout << query(1, 1, n, k, k) << endl;
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
