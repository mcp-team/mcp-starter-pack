// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,s;
        cin>>n>>m;
        vector<vector<int>> gra(n);
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;v--;
            gra[u].push_back(v);
            gra[v].push_back(u);
        }
        cin>>s; s--;
        queue<int> q;
        q.push(s);
        vector<int> d(n,-1);
        d[s] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto nxt: gra[x]){
                if(d[nxt] != -1) continue;
                d[nxt] = d[x] + 6;
                q.push(nxt);
            }
        }
        for(int i=0; i<n; i++) if (i != s)
            cout << d[i] << " ";
        cout << endl;
    }
}
