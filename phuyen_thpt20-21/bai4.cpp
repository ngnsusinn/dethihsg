#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second
typedef pair<int, int>p;
typedef vector<p>vp;

vp a[256];
int n, m, us, vs;
int d[256], path[256];

const int inf = 1e9+7;

void dijkstra(){
    priority_queue<p, vp, greater<p>>q;
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[us] = 0;
    path[us] = -1; 
    q.push({0, us});
    while (q.size()){
        int u = q.top().s;
        int du = q.top().f;
        q.pop();

        if (du != d[u]) continue;

        for (int i = 0; i < a[u].size(); i++){
            int v = a[u][i].s;
            int dv = a[u][i].f;
            if (d[v] > du + dv){
                d[v] = du + dv;
                q.push({d[v], v});
                path[v] = u;
            }         
        }
    }
}

int main(){
    freopen("bai4.inp", "r", stdin);
    freopen("bai4.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cin >> us >> vs;
    dijkstra();
    cout << d[vs] << "\n";
    int way[256], cnt = 0;
    while (vs != -1){
        way[++cnt] = vs;
        vs = path[vs];
    }
    cout << cnt << " ";
    for (int i = cnt; i >= 1; i--){
        cout << way[i] << " ";
    }
    return 0;
}