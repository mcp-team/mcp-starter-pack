// Written by: wyattwismer

#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define M 11

int T,a,b,n,cnt;
int p[N];
int ps[M][N];
int main(){
    for(int i=2;i<N;i++)
        if(p[i] == 0) for(int j=i; j<N; j+=i) p[j]++;
    for(int i=0;i<M;i++)
        for(int j=1;j<N;j++) ps[i][j] = ps[i][j-1] + (p[j]==i);
    cin>>T;
    while(T--){
        cin>>a>>b>>n;
        cout << ps[n][b] - ps[n][a-1] << endl;
    }
}
