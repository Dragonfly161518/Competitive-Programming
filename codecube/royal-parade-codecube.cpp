#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll,pair<int,int> >;
bool visited[100005];
ll dist[100005];
vector<pair<int,int> > G[100005];
vector<int> parent[100005];
int n,m,r_s,r_e,p_s,p_e;

void delEdge(int u) {
	visited[u] = true;
	if(u == r_s) return;
	for(auto v: parent[u]) if(!visited[v]) delEdge(v);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	scanf("%d%d%d%d",&r_s,&r_e,&p_s,&p_e);
	for(int i=1;i<=n;i++) dist[i] = -1;
	priority_queue<pli,vector<pli>,greater<pli> > q;
	dist[r_s] = 0;
	q.push({dist[r_s],{r_s,r_s}});
	while(!q.empty()) {
		int u = q.top().second.first, pnode = q.top().second.second;
		ll distance = q.top().first;
		q.pop();
		if(visited[u] && dist[u] != distance) continue;
		visited[u] = true;
		parent[u].push_back(pnode);
		for(auto v: G[u]) {
			if(!visited[v.first] && ( dist[v.first] >= distance + v.second || dist[v.first] == -1)) {
				dist[v.first] = distance + v.second;
				q.push({dist[v.first],{v.first,u}});
			}
		}
	}
    //printf("\n[%d]\n",parent[r_e].size());
	memset(visited,0,sizeof(visited));
	delEdge(r_e);
	/*for(int i=1;i<=n;i++)
        if(visited[i]) printf("%d ",i);
    printf("\n");*/
	for(int i=1;i<=n;i++) dist[i] = -1;
	dist[p_s] = 0;
	q.push({dist[p_s],{p_s,p_s}});
	while(!q.empty()) {
		int u = q.top().second.first, pnode = q.top().second.second;
		ll distance = q.top().first;
		q.pop();
		if(visited[u]) continue;
		visited[u] = true;
		parent[u].push_back(pnode);
		for(auto v: G[u]) {
			if(!visited[v.first] && ( dist[v.first] > distance + v.second || dist[v.first] == -1)) {
				dist[v.first] = distance + v.second;
				q.push({dist[v.first],{v.first,u}});
			}
		}
	}
	printf("%lli",dist[p_e]);
	return 0;
}

