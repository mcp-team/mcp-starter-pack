#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define fr(i,x) for (int i = 0; i < int(x); i++)
#define frab(i,a,b) for (int i = int(a); i < int(b); i++)
#define sz(x) ((int) (x).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int init_clrs[101];
int clr_cost[101][101];

ll dp[101][101][101];
int n, m, k;

const ll INF = 0xffffffffffffff; 
ll solve(ll cur, ll alt, ll prev) {
    if (cur == n) {
        if (alt == k) return 0;
        else return INF;
    }
    if (alt > k) return INF;
    if (dp[cur][alt][prev]) return dp[cur][alt][prev];
    ll ans = INF;
    if (init_clrs[cur]) 
        return dp[cur][alt][prev] = solve(cur+1,alt + (prev != init_clrs[cur]),init_clrs[cur]);
    ans = INF;
    fr(j,m) {
        ans = min(ans, clr_cost[cur][j] + solve(cur+1,alt + (prev != j+1), j+1));
    }
    return dp[cur][alt][prev] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    fr(i,n) cin >> init_clrs[i];
    fr(i,n) fr(j,m) cin >> clr_cost[i][j];

    ll ans = solve(0,0,0);
    if (ans >= INF) {
        ll alt = 1;
        frab(i,1,n) {
            alt = init_clrs[i] == 0 ? INF : (
                    init_clrs[i] == init_clrs[i-1] ? alt : alt + 1);
        }
        alt = alt == k ? 0 : -1;
        cout << alt << endl;
    }
    else
        cout << ans << endl;

    return 0;
}
