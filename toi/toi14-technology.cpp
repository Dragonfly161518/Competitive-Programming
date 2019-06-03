#include <bits/stdc++.h>
using namespace std;
int n,k,t;
vector<int> G[100020];
vector<int> level[100002];
int develop[100020];
int dp[10020];
int dfs(int u) {
    if(develop[u] == 2) {
        return 0;
    } else if(develop[u] == 1) {
        return 2000000;
    }
    develop[u] = 1;
    int sum = 0;
    for(auto v: G[u]) {
        int dev = dfs(v);
        if(sum + dev > t) {
            return sum+dev;
        }
        else sum += dev;
    }
    develop[u] = 2;
    return sum + 1;
}
int main() {
    scanf("%d%d%d",&n,&k,&t);
    for(int i=1;i<=n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        level[a].push_back(i);
        for(int j=1;j<=b;j++) {
            int c;
            scanf("%d",&c);
            G[i].push_back(c);
        }
    }
    for(int i=1;i<=k;i++) {
        dp[i] = dp[i-1];
        for(auto node: level[i]) {
            dp[i] += dfs(node);
        }
        if(dp[i] > t) {
            if(i-1 == 0) printf("-1");
            else
            printf("%d",i-1);
            return 0;
        }
        develop[i] = 2;
    }
    printf("%d",k);
    return 0;
}
