#include <bits/stdc++.h>
using namespace std;
int n,s,d,f,m;

struct data{
    int price,card,next,tank;
    bool operator<(const data& x)const {
        return x.price < price;
    }
};

data setup(int a,int b,int c,int d) {
    data x;
    x.price = a;
    x.card = b;
    x.next = c;
    x.tank = d;
    return x;
}

int cost[102][122][2];
int vis[102][122][2];
int ans = 1e9;
int p[102];
vector<data> G[102][102][2];
vector<pair<int,int> > W[102];
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
        W[a].push_back({w,b});
        W[b].push_back({w,a});
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=f;j++) {
            if(j != f) {
                G[i][j][0].push_back(setup(p[i],0,i,j+1));
                G[i][j][1].push_back(setup(p[i],1,i,j+1));
            }
            G[i][j][0].push_back(setup(0,1,i,f));
            for(auto w: W[i]) {
                if(j >= w.first) {
                    G[i][j][0].push_back(setup(0,0,w.second,j-w.first));
                    G[i][j][1].push_back(setup(0,1,w.second,j-w.first));
                }
            }
        }
    }
    memset(cost,1e9+21,sizeof(cost));
    priority_queue<data> q;
    cost[s][0][0] = 0;
    q.push(setup(cost[s][0][0],0,s,0));
    while(!q.empty()) {
        data u = q.top();
        int price = u.price,card = u.card,next = u.next,tank = u.tank;
        q.pop();
        if (vis[next][tank][card])
            continue;
        vis[next][tank][card] = 1;
        for(auto x: G[next][tank][card]) {
            if(!vis[x.next][x.tank][x.card] && cost[x.next][x.tank][x.card] > cost[next][tank][card] + x.price) {
                cost[x.next][x.tank][x.card] = cost[next][tank][card] + x.price;
                q.push(setup(cost[x.next][x.tank][x.card],x.card,x.next,x.tank));
            }
        }
    }
    /*for(int i=1;i<=n;i++) {
        for(int j=0;j<=f;j++) {
            for(int k=0;k<=1;k++) printf("%d %d %d %d\n",i,j,k,cost[i][j][k]);
        }
    }*/
    printf("%d",cost[d][f][1]);
    return 0;
}
