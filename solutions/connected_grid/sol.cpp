// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
int dfs(int x){
    if(x < 0 || x >= n*m) return 0;
    if (!a[x]) return 0;
    a[x] = 0;
    int res = 1;
    vector<int> il, jl;
    il = jl = {0};
    if (x/m > 0) il.push_back(-m);
    if (x/m < n-1) il.push_back(m);
    if (x%m > 0) jl.push_back(-1);
    if (x%m < m-1) jl.push_back(1);
    for (int id: il)
        for (int jd: jl)
            res += dfs(x + id + jd);
    return res;
}

int main(){
    cin>>n>>m;
    a.resize(n*m);
    for(int i=0;i<n*m;i++) cin>>a[i];
    int mx = 0;
    for(int i=0;i<n*m;i++) mx = max(mx, dfs(i));
    cout << mx << endl;
}
