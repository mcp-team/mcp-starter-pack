// Written by: wyattwismer

#include<bits/stdc++.h>
using namespace std;

int n,h,mn;
int main(){
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        h += (c=='+'?1:-1);
        mn = min(mn,h);
    };
    cout << -mn + h << endl;
}
