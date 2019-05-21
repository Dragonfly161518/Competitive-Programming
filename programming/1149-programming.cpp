#include <bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
using namespace std;
int n;
int MAP[1005][1005];
int vis[1005][1005];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ANS;
struct comp
{
    bool operator() (pair<pair<int,int>,int >  const &a, pair<pair<int,int>, int  >  const &b) { return a.second > b.second; }
};

priority_queue<pair< pair<int,int>,int> , vector<pair<pair<int,int>,int > >, comp  >  q;

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&MAP[i][j]);
            if(MAP[i][j] == 0 && q.empty()) {
                vis[i][j] = 1;
                q.push(mk(mk(i,j),MAP[i][j]));
            }
        }
    }
    while(!q.empty()) {
        int x = q.top().first.first, y = q.top().first.second;
        int dis = q.top().second;
        q.pop();
        if(MAP[x][y] == 0 && !vis[x][y]) {
            ANS = dis;
            break;
        } else {
        vis[x][y] = 1;
            for(int i=0;i<4;i++) {
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if(n_x >= 1 && n_x <=n && n_y >=1 && n_y <= n) {
                    if(!vis[n_x][n_y]) {
                        q.push(mk(mk(n_x,n_y),max(dis,MAP[n_x][n_y])));
                    }
                }
            }
        }
    }
    cout << ANS;
    return 0;
}
