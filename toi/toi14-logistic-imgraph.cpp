#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pp = pair<int,pair<int,pii> >;
int n,p[102],s,d,f,m;


int cost[102][102][2];
int vis[102][102][2];
int ans = 1e9;
vector<pp> G[102][102][2];
vector<pii> W[102];

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> p[i];
    }
    cin >> s >> d >> f;
    cin >> m;
    for(int i=1;i<=m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        W[a].push_back({b,w});
        W[b].push_back({a,w});
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<f;j++) {
            G[i][j][0].push_back({p[i],{0,{i,j+1}}});
            G[i][j][0].push_back({0,{1,{i,f}}});
            for(auto w: W[i]) {
                if(j >= w.second) {
                    G[i][j][0].push_back({0,{0,{w.first,j-w.second}}});
                    G[i][j][1].push_back({0,{1,{w.first,j-w.second}}});
                }
            }
        }
    }
    memset(cost,1e9+21,sizeof(cost));
    priority_queue<pp, vector<pp>, greater<pp> > q;
    cost[s][0][0] = 0;
    q.push({cost[s][0][0],{s,{0,0}}});
    while(!q.empty()) {
        int u,
        q.pop();
        printf("%d %d %d %d\n",paid,u,tank,use);
        if (vis[u][tank][use])
            continue;
        vis[u][tank][use] = 1;
        for(int i)

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
