#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int n,m;
int degree[100300];
ll component[100300];
vector<int> G[100300];
pair<int,int> E[100300];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        E[i] = {a,b};
        degree[a]++;
        degree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        component[i] = 1;
        if(degree[i] == 1)
            q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        for(auto v: G[u]) {
            if(degree[v] != 0) {
                component[v] += component[u];
                degree[u]--;
                degree[v]--;
                if(degree[v] == 1)
                    q.push(v);
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++) {
        int a,b;
        a = E[i].first;
        b = E[i].second;
        ll MIN = min(component[a],component[b]);
        if(degree[a] && degree[b]) printf("0 ");
        else
            printf("%lli ",MIN*(n-MIN));
    }
    return 0;
}
