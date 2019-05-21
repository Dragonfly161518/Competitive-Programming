#include <bits/stdc++.h>
using namespace std;
int n,m;
int mem[4][1005][1005];
char board[1005][1005];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dp(int direct,int y,int x,int sum) {
    if(mem[direct+1][y][x] != -1) return mem[direct+1][y][x];
    if(mem[direct][y][x] != -1) return mem[direct][y][x];
    if(board[y][x] == '0' || x < 0 || y < 0 || x >= n || y >= m) return 0;
    mem[direct + 1][y][x] = sum + 1;
    return mem[direct][y][x] = dp(direct,y + dy[direct],x + dx[direct],sum + 1) + 1;
}

int main() {
    int k;
    scanf("%d",&k);
    while(k-- > 0) {
        scanf("%d %d",&m,&n);
        memset(mem,-1,sizeof(mem));
        int MAX=0;
        for(int i=0;i<m;i++)
            scanf("%s",board[i]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //for(int l=0;l<4;l++) {
                    if(board[i][j] != '0') {
                        dp(0,i,j,0);
                        dp(2,i,j,0);
                    }
                //}
                for(int h=0;h<4;h++) {
                    for(int g=h+1;g<4;g++) {
                        MAX = max(MAX, mem[h][i][j] + mem[g][i][j] -1);
                    }
                }
            }
        }
        printf("%d\n",MAX);
    }
    return 0;
}
