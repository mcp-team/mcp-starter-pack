// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

#define BIG 100005
#define WIDTH 20

int par[BIG*2][WIDTH];

void insert(int x, int p){
    par[x][0] = p;
    for(int i=1;i<WIDTH;i++)
        par[x][i] = par[par[x][i-1]][i-1];
}

int kth(int x, int k){
    for(int i=0;k;i++,k>>=1) if(k&1)
        x = par[x][i];
    return x;
}

int main(){
    int T, n, Q, t, x, y, k;
    cin>>T;
    while(T--){
        for(int i=0;i<2*BIG;i++) for(int j=0;j<WIDTH;j++) par[i][j] = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            insert(x,y);
        }
        cin>>Q;
        while(Q--){
            cin>>t;
            if(t==0){
                cin>>y>>x;
                insert(x,y);
            } else if (t==1){
                cin>>x;
                for(int j=0;j<WIDTH;j++) par[x][j]=0;
            }else{
                cin>>x>>k;
                cout << kth(x,k) << endl;
            }
        }
    }
}
