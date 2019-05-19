// Written by: wyattwismer

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<ll>> gra;
vector<ll> seen;
ll dfs(ll x){
    if(seen[x]) return 0;
    seen[x] = 1;
    ll res = 1;
    for(auto nxt: gra[x])
        res += dfs(nxt);
    return res;
}

int main(){
    ll T;
    cin>>T;
    while(T--){
        ll n,m,cl,cr;
        cin>>n>>m>>cl>>cr;
        gra.clear();
        gra.assign(n,{});
        while(m--){
            ll u,v;
            cin>>u>>v;
            u--;v--;
            gra[u].push_back(v);
            gra[v].push_back(u);
        }
        if(cl<=cr){
            cout << cl * n << endl;
            continue;
        }
        seen.clear();
        seen.assign(n,0);
        ll res = 0;
        for(ll i=0;i<n;i++) if(!seen[i]){
            ll cnt = dfs(i);
            res += (cnt-1) * cr + cl;
        }
        cout << res << endl;
    }
}
