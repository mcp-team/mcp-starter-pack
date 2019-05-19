// Written by: wyattwismer

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    for(char c : s) {
        char res = c;
        if (c >= 'a' && c <= 'z')
            res = ((c-'a')+k)%26 + 'a';
        else if (c >= 'A' && c <= 'Z')
            res = ((c-'A')+k)%26 + 'A';
        cout << res;
    }
    cout << endl;
}
