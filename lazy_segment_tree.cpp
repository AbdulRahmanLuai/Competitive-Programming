#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll INF = 1e18;
const ll N = 2e5 + 100;

ll n, q;
ll a[N];
ll seg[4 * N];
ll lazy[4 * N];
ll defaultValue = 0;

ll combine(ll a, ll b) {
    return a + b;
}

void build(ll id, ll leftNode, ll rightNode) {
    if (leftNode == rightNode) {
        seg[id] = a[leftNode];
        return;
    }
    ll mid = (leftNode + rightNode) >> 1;
    build(id * 2, leftNode, mid);
    build(id * 2 + 1, mid + 1, rightNode);

    seg[id] = combine(seg[id * 2], seg[id * 2 + 1]);
}

void push(ll id, ll leftNode, ll rightNode) {
    if (lazy[id] != 0) {
        seg[id] += lazy[id] * (rightNode - leftNode + 1); // make sure this is correct for different problems. 

        if (leftNode != rightNode) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void updateRange(ll id, ll leftNode, ll rightNode, ll updateLeft, ll updateRight, ll value) {
    push(id, leftNode, rightNode);

    if (updateRight < leftNode || updateLeft > rightNode) {
        return;
    }
    if (leftNode >= updateLeft && rightNode <= updateRight) {
        
        lazy[id] += value; 
        push(id, leftNode, rightNode);
        return;
    }

    ll mid = (leftNode + rightNode) >> 1;
    updateRange(id * 2, leftNode, mid, updateLeft, updateRight, value);
    updateRange(id * 2 + 1, mid + 1, rightNode, updateLeft, updateRight, value);

    seg[id] = combine(seg[id * 2], seg[id * 2 + 1]);
}

ll query(ll id, ll leftNode, ll rightNode, ll queryLeft, ll queryRight) {
    push(id, leftNode, rightNode);

    if (queryRight < leftNode || queryLeft > rightNode) {
        return defaultValue;
    }
    if (leftNode >= queryLeft && rightNode <= queryRight) {
        return seg[id];
    }

    ll mid = (leftNode + rightNode) >> 1;
    ll leftAnswer = query(id * 2, leftNode, mid, queryLeft, queryRight);
    ll rightAnswer = query(id * 2 + 1, mid + 1, rightNode, queryLeft, queryRight);

    return combine(leftAnswer, rightAnswer);
}

void solve() {
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1, 1, n);

    while(q--){
        int t; cin >> t;
        if (t == 1){
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
