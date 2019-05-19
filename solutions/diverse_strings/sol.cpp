// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        vector<int> h(27);
        string s;
        cin>>s;
        for (char c : s) h[c-'a'+1]++;
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(h[i+1] > 1) {
                cnt = 2; // any # > 1 works
                break;
            }
            if(h[i] == 0 && h[i+1] == 1) cnt++;
        }
        cout << (cnt==1?"Yes":"No") << endl;
    }
}
