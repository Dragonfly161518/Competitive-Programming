#include <bits/stdc++.h>
using namespace std;
int n,m,MAX,indexd;
vector<int> G[500050];
int degree[500050];
bool check[500050];
int circle[500050];
int component[500050];
bool dfs(int u,int p) {
    if(check[u] == 1) {
        check[u] = 2;
        return true;
    }
    check[u] = true;
    for(auto v: G[u]) {
        if(v != p)
            if(dfs(v,u)) {
                if(check[u] == 1)
                    return true;
                else return false;
            }
    }
    return false;
}

int comcount(int u,int p) {
    if(check[u])
        return 0;
    check[u] = true;
    if(G[u].size() == 0) return 1;
    int sum = 0;
    for(auto v: G[u])
        if(v != p)
            sum += comcount(v,u);
    return sum + 1;
}

int main() {
    scanf("%d%d",&n,&m);
    queue<int> q;
    for(int i=1;i<=n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    if(dfs(m,-1)) {
        for(int i=1;i<=n;i++)
            if(degree[i] == 1)
                q.push(i);
        while(!q.empty()) {
            int u = q.front();
            for(auto v: G[u]) {
                if(degree[v] != 0 && v != m) {
                    component[v] += component[u] + 1;
                    if(component[v] > MAX) {
                        indexd = v;
                        MAX = component[v];
                    } else if(component[v] == MAX) {
                        indexd = min(v,indexd);
                    }
                    degree[u]--;
                    degree[v]--;
                    if(degree[v] == 1)
                        q.push(v);
                }
            }
            q.pop();
        }
    } else {
        memset(check,0,sizeof(check));
        for(auto v: G[m]) {
            int com = comcount(v,m);
            if(com > MAX) {
                MAX = com;
                indexd = v;
            } else if(com == MAX){
                indexd = min(v,indexd);
            }
        }
    }
    printf("%d\n%d",indexd,MAX);
    return 0;
}
