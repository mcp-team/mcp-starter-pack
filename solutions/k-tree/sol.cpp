#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define fr(i,x) for (int i = 0; i < int(x); i++)
#define frab(i,a,b) for (int i = int(a); i < int(b); i++)
#define sz(x) ((int) (x).size())
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int memo[2][105];
int n, k, d;
int solve(int val, bool ok) {
    if (val < 0) return 0;
    if (val == 0)
        return ok ? 1 : 0;
    if (memo[ok][val] > -1) return memo[ok][val];
    ll ans = 0;
    
    frab(i,1,k+1) 
        ans = (ans + solve(val-i, ok || (i >= d))) % MOD;
    return memo[ok][val] = ans;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k >> d;
    memset(memo, -1, 2*105*sizeof(int));
    cout << solve(n,false) << endl;
    return 0;
}
