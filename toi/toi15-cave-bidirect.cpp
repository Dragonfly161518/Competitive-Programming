#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;
int n,p,U,e,l;
pair<ll,int> dist[2004];
int vis[2004];
using node = pair<ll,pair<int,int> >;
vector<pair<int,int> > G[2004];

pair<ll,int> shortestpath(int u,int step) {
    if(u == U) {
        return dist[u][step] = 0;
    }
    if(dist[u][step] != -1) return dist[u][step];
    ll MIN = INF;
    for(auto v: G[u]) {
        MIN = min(MIN, shortestpath(v,step+1));
    }
    return dist[u][step] = MIN;
}

int main() {
    scanf("%d%d%d%d",&n,&p,&U,&e);
    for(int i=0;i<e;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[0][a].push_back({c,b});
        G[1][b].push_back({c,a});
    }
    for(int i=0;i<n;i++) {
        dist[0][i].first = INF;
        dist[1][i].first = INF;
    }
    shortestpath(0,p);
    shortestpath(1,u);
    scanf("%d",&l);
    printf("\n\n");
    for(int j=0;j<n;j++)
        printf("%d %lli %lli\n",n,dist[0][j].first,dist[1][j].first);
    for(int i=0;i<l;i++) {
        int Q;
        scanf("%d",&Q);
        ll MIN = INF;
        for(int j=0;j<n;j++) {
            MIN = min(MIN,dist[0][j].first + dist[1][j].first + Q*(dist[0][j].second + dist[1][j].second));
        }
        printf("%lli ",MIN - Q);
    }
    return 0;
}
