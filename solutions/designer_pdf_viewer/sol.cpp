// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int h[26];
int main(){
    for(int i=0;i<26;i++) cin>>h[i];
    string s;
    cin>>s;
    int mx = 0;
    for(auto c: s){
        mx = max(mx, h[c-'a']);
    }
    cout << mx * s.size() << endl;
}
