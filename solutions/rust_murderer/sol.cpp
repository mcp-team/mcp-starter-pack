// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<set<int>> g(n);
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;v--;
            g[u].insert(v);
            g[v].insert(u);
        }
        int s;
        cin>>s;
        s--;
        vector<int> dist(n);
        queue<int> q;
        q.push(s);
        set<int> unseen;
        for(int i=0; i<n; i++) if(i!=s) unseen.insert(i);

        while (!unseen.empty()){
            int x = q.front();
            q.pop();
            vector<int> chk(unseen.begin(), unseen.end());
            for (int y: chk){
                if (g[x].find(y) == g[x].end()){
                    unseen.erase(y);
                    q.push(y);
                    dist[y] = dist[x] + 1;
                }
            }
        }
        for(int i=0; i<n; i++) if(i != s)
            cout << dist[i] << " ";
        cout << endl;
    }
}


