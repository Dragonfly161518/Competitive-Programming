#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;
long long int dist[2040][10010];
int n,p,U,l,e;
using edge = pair<int,int >;
int vis[2040][10010];
vector<edge> G[2040];
using node = pair<int,pair<int,int> >;
priority_queue<node,vector<node>,greater<node> > pq;
int main() {
    scanf("%d%d%d%d",&n,&p,&U,&e);
    for(int i=0;i<e;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back({c,b});
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<e;j++) {
            dist[i][j] = INF;
        }
    }
    pq.push({0,{p,0}});
    dist[p][0] = 0;
    int MIN_EDGE;
    ll MIN_W = INF;
    vector<pair<ll,ll> > ans;
    while(!pq.empty()) {
        node x = pq.top();
        int u = x.second.first;
        int step = x.second.second;
        int distance = x.first;
        pq.pop();
        if(u == U) {
            ans.push_back({step,distance});
            goto AA;
        }
        if(vis[u][step] || step >= e) {
            goto AA;
        }
        vis[u][step] = 1;
        for(auto v: G[u]) {
            if(!vis[v.second][step+1] && dist[v.second][step+1] > distance + v.first) {
                dist[v.second][step+1] = distance + v.first;
                pq.push({dist[v.second][step+1],{v.second,step+1}});
            }
        }
        AA:;
    }
    scanf("%d",&l);
    for(int i=0;i<l;i++) {
        int Q;
        scanf("%d",&Q);
        printf("%lli ",ans[0].second - Q*(ans[0].first-1));
    }
    return 0;
}
