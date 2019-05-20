// Written by: wyattwismer

#include <bits/stdc++.h>
#define N 100005
#define MOD 1000000007
#define ll long long int
using namespace std;

ll bp(ll a, ll b){
    if (b==0) return 1;
    ll res = bp(a,b/2);
    return (((res*res)%MOD)*(b&1?a:1)) % MOD;
}

ll par[N], sz[N];
ll find(ll x){ return par[x] = (x == par[x]?x:find(par[x])); }
void un(ll u, ll v){
    u = find(u); v = find(v);
    if (u == v) return;
    if (sz[v] > sz[u]) swap(u,v);
    par[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
}

int main(){
    for(ll i=0;i<N;i++) par[i] = i, sz[i] = 1;
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        if(!w) un(u,v);
    }
    ll res = bp(n,k);
    for(ll i=0;i<n;i++) if(sz[i])
        res = (res + MOD - bp(sz[i],k)) % MOD;
    cout << res << endl;
}
