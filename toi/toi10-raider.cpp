#include <bits/stdc++.h>

int mem[105][105][5050];
int n,m;
int arr[105][105];
// dp[i][j][k] = dp[i something][j something][k-1];
int dx[2][6] = { {-1,1,0,0,1,1},{-1,1,0,0,-1,-1} };
int dy[2][6] = { {0,0,-1,1,1,-1},{0,0,-1,1,1,-1} };

int dp(int y,int x,int k) {
	if(y == n/2 +1  && x == 0 && k == 0) return 1;
	if(mem[y][x][k] != -1) return mem[y][x][k];
	if(k%arr[y][x] != 0) return mem[y][x][k] = 0;
	if(arr[y][x] == -1) return 0;
	if(k < 0) return mem[y][x][k] = 0;
	for(int i=0;i<6;i++) {
		int mod = (y+1)%2;
		int d_y = y + dy[mod][i];
		int d_x = x + dx[mod][i];
		if(arr[d_y][d_x] != 0 && dp(d_y,d_x,k-1))
			return mem[y][x][k] = 1;
	}
	return mem[y][x][k] = 0;
}

int main() {
	for(int i=0;i<=104;i++) {
		for(int j=0;j<=104;j++) {
			for(int k=0;k<5050;k++) {
				mem[i][j][k] = -1;
			}
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		arr[i][0] = -1;
		arr[i][m+1] = -1;
		for(int j=1;j<=m;j++) {
			arr[0][j] = -1;
			arr[n+1][j] = -1;
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=arr[n/2+1][m];i<=5000;i++) {
		if(i%arr[n/2+1][m] == 0)
			if(dp(n/2+1,m,i)) {
				printf("%d",i);
				return 0;
			}
	}
	return 0;
}
