#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pp = pair<int,pair<int,pii> >;
int n,p[102],s,d,f,m;
int cost[102][102][2];
int vis[102][102][2];
int ans = 1e9;
vector<pii> G[102];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> p[i];
        G[i].push_back({i,0});
    }
    cin >> s >> d >> f;
    cin >> m;
    for(int i=1;i<=m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    memset(cost,1e9+21,sizeof(cost));
    priority_queue<pp, vector<pp>, greater<pp> > q;
    cost[s][0][0] = 0;
    q.push({cost[s][0][0],{s,{0,0}}});
    while(!q.empty()) {
        int paid = q.top().first, u = q.top().second.first, tank = q.top().second.second.first, use = q.top().second.second.second;
        q.pop();
        printf("%d %d %d %d\n",paid,u,tank,use);
        if (vis[u][tank][use])
            continue;
        vis[u][tank][use] = 1;
        for(auto v: G[u]) {
            for(int i=f;i>tank;i--) {
                if(!vis[v.first][i-v.second][use] && cost[v.first][i-v.second][use] > paid + ((i-tank) * p[u])) {
                    cost[v.first][i-v.second][use] = paid + ((i-tank) * p[u]);
                    if(i >= v.second)
                        q.push({cost[v.first][i-v.second][use],{v.first,{i-v.second,use}}});
                    if(!use) {
                        cost[v.first][i-v.second][!use] = paid;
                        if(i >= v.second)
                            q.push({cost[v.first][i-v.second][!use],{v.first,{i-v.second,!use}}});
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=f;j++) {
            for(int k=0;k<=1;k++) {
                printf("[%d %d %d %d]\n",i,j,k,cost[i][j][k]);
            }
        }
    }
    return 0;
}
