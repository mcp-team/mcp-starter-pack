#include <bits/stdc++.h>

#define long long int;
#define pb push_back
#define fst first
#define snd second
#define DEBUGA(a, b) cout << "[ "; for (auto _x = (a); _x != (b); _x++) cout << *_x << " "; cout << "]"<< endl
#define DEBUG(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string>_it(_ss); err(_it, args); };cout << endl
#define fr(i,x) for (int i = 0; i < int(x); i++)
#define frab(i,a,b) for (int i = int(a); i < int(b); i++)
#define sz(x) ((int) (x).size())
void run();
int main() {
    std::ios::sync_with_stdio(false);
    run();
    return 0;
}

using namespace std;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "; ";
    err(++it, args...);
}


typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1000000000;
vector<vii> G;
vii EdgeList;
void run() {
    int n, m, u, v;
    cin >> n >> m;
    G.assign(n, vii());
    fr(i,m) {
        cin >> u >> v;
        u--; v--;
        EdgeList.pb(ii(u,v));
        G[u].pb(ii(v,INF));
        G[v].pb(ii(u,INF));
    }

    queue<int>q; q.push(0);
    vi color(n, INF); color[0] = 0;
    bool ok = true;
    while (!q.empty() & ok) {
        int u = q.front(); q.pop();
        for (int j = 0; j < sz(G[u]); j++) {
            ii v = G[u][j];
            if (color[v.fst] == INF) {
                color[v.fst] = 1 - color[u];
                q.push(v.fst);
            }
            else if (color[v.fst] == color[u]) {
                ok = false; break;
            }
        }
    }

    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (auto &[x, y] : EdgeList) {
            if (color[x] < color[y])
                cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}
