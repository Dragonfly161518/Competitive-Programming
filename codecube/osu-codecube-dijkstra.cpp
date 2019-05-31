#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll INF = 1e17;
int m,n,t;
int start,finish;
ll dist[14000][20];
int vis[13000][20];
vector<pair<ll,int> > G[14000];
int main() {
    cin >> n >> m >> t;
    cin >> start >> finish;
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back({c,b});
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=t;j++) {
            dist[i][j] = INF;
        }
    }
    priority_queue<pair<ll,pair<int,int> >, vector<pair<ll,pair<int,int> > > , greater<pair<ll,pair<int,int> > > > q;
    q.push({0,{1,start}});
    dist[start][1%t] = 0;
    while(!q.empty()) {
        int step = q.top().second.first, u = q.top().second.second;
        ll w = q.top().first;
        q.pop();
        if(vis[u][step%t])
            continue;
        vis[u][step%t] = true;
        for(auto v: G[u]) {
            if(!vis[v.second][(step+1)%t] && dist[v.second][(step+1)%t] > w + v.first) {
                dist[v.second][(step+1)%t] = w + v.first;
                q.push({dist[v.second][(step+1)%t],{step+1,v.second}});
            }
        }
    }
    printf("%lli",dist[finish][0] == INF ? -1: dist[finish][0]);
}
