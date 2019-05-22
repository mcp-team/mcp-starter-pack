#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define fr(x) for (int i = 0; i < x; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<ll, ii> lii;
vi parent, weight;
vector<lii> E;

int find_node(int i) {
    if (parent[i] != i) return parent[i] = find_node(parent[i]);
    return parent[i];
}

bool connected(int i, int j) {
    return find_node(i) == find_node(j);
}

void union_nodes(int i, int j) {
    int pi = find_node(i), pj = find_node(j);
    if (pi == pj) return;

    if (weight[pi] > weight[pj]) {
        parent[pj] = pi;
        weight[pi] += weight[pj];
    }
    else {
        parent[pi] = pj;
        weight[pj] += weight[pi];
    }
}

int main() {
    int n, m, x, y;
    ll w;
    cin >> n >> m;
    parent.assign(n, 0); weight.assign(n, 1);
    fr(n) parent[i] = i;
    
    fr(n) {
        cin >> w;
        E.pb(lii(w, ii(i,i)));   
    }
    sort(E.begin(),E.end());
    ll minW = E[0].fst; int minE = E[0].snd.fst;
    for (int i = 1; i < n; i++) {
        E[i].fst += minW;
        E[i].snd.snd = minE;
    }
    fr(m) {
        cin >> x >> y >> w;
        x--; y--;
        E.pb(lii(w, ii(x,y)));
    }
    sort(E.begin(),E.end());
    ll ans = 0;
    for (auto p : E) {
        x = p.snd.fst; y = p.snd.snd;
        w = p.fst;
        if (connected(x,y)) continue;
        ans += w;
        union_nodes(x,y);
    }
    cout << ans << endl;
    return 0;
}
