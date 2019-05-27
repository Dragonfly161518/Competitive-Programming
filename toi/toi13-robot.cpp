#include <bits/stdc++.h>
using namespace std;
int n,m;
char arr[2004][2005];
const int INF = 1e9;
int dist[2003][2004];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,pair<int,int> > > q;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",arr[i]);
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 'X') {
                q.push({0,{i,j}});
                dist[i][j] = 0;
            } else dist[i][j] = INF;
        }
    }
    while(!q.empty()) {
        int w = q.front().first;
        for(int k=0;k<4;k++) {
            int x = q.front().second.second + dx[k], y = q.front().second.first + dy[k];
            if(x >= 0 && x < m && y < n && y >= 0 && arr[y][x] != 'W' && arr[y][x] != 'X') {
                if(w +1 < dist[y][x]) {
                    dist[y][x] = w + 1;
                    q.push({w+1,{y,x}});
                }
            }
        }
        q.pop();
    }
    int sum,keep;
    sum=keep=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(dist[i][j] != INF && arr[i][j] == 'A')
                sum += dist[i][j], keep++;
    printf("%d %d",keep, sum * 2);
    return 0;
}
