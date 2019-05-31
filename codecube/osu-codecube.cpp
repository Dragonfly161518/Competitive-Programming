#include <bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
using namespace std;
using lli = long long int;
int m,n,t;
int start,finish;
vector<pair<int,int> > G[10050];
lli mem[10050][8];
int chk[10050][8];
lli dp(int u,int step) {
    cout << u << " " << step<<endl;
    if(mem[u][step%t] != -1) return mem[u][step%t];
    if(u == finish && step%t == 0) {
        return 0;
    }
    if(chk[u][step%t]) return 1e9+21;
    chk[u][step%t] = 1;
    lli MIN = 1e9+21;
    for(int i=0;i<G[u].size();i++) {
        lli doo = dp(G[u][i].first,step+1) + G[u][i].second;
        chk[u][(step+1)%]
        if(doo < MIN) MIN = doo;
    }
    return mem[u][step%t] = MIN;
}

int main() {
    cin >> n >> m >> t;
    cin >> start >> finish;
    memset(mem,-1,sizeof(mem));
    for(int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(mk(b,c));
    }
    printf("%lli",dp(start,1));
    return 0;
}
