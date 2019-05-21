// Written by: wyattwismer

#include <bits/stdc++.h>
#define BIG 1000000007
#define ll long long int
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> f;
    for (char c: s) f[c]++;
    auto good = [&](){
        bool res = true;
        for (char c: "ACTG") res &= (f[c] <= n/4);
        return res;
    };
    if (good()){
        cout << 0 << endl;
        return 0;
    }
    int l,r;
    l = r = -1;
    int mn = BIG;
    while (true){
        bool done = false;
        while(!good()) {
            if(r+1>=n){
                done = true;
                break;
            }
            f[s[++r]]--;
        }
        if (done) break;
        while(good()){
            int sz = r-l;
            mn = min(mn, sz);
            f[s[++l]]++;
        }
    }
    cout << mn << endl;
}

