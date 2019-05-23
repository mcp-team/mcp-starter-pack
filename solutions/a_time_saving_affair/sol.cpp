#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;
typedef pair<int,int> ii; // (node,weight)
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
    int V, k, E, u, v, w, xd;
    vector<vii> AdjList;
    scanf("%d %d %d", &V, &k, &E);
    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w); u--; v--;
        AdjList[u].push_back(ii(v,w));
        AdjList[v].push_back(ii(u,w));
    }
    vi dist(V, INF); dist[0] = 0;  
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, 0));
    
    while (!pq.empty()) {                                            
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        if (u == V-1) { printf("%d\n", dist[u]); return 0; }
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
          ii v = AdjList[u][j];  
          xd = (dist[u] + v.second) % (2*k) >= k ? 2*k - (dist[u] + v.second) % (2*k) : 0;
          if (v.first == V-1) xd = 0;
          if (dist[u] + v.second + xd < dist[v.first]) {
            dist[v.first] = dist[u] + v.second + xd;     
            pq.push(ii(dist[v.first], v.first));
    } } }  
    printf("%d\n", -1);
    return 0;
}
