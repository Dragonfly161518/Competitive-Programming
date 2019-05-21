#include <bits/stdc++.h>
#define mm(a,b,c) min(a,min(b,c))
using namespace std;
int n,m,k;
const int INF = 1e9+21;
int dp[2][5005];
int pm[2][5005];
int A[5005];
int B[5005];


int main() {
	cin >> n >> m >> k;
	int ans;
	for(int i=1;i<=n;i++) cin >> A[i];
	for(int i=1;i<=m;i++) {
		cin >> B[i];
		pm[0][i] = dp[0][i] = i;
	}
	for(int i=1;i<=n;i++) {
		int row = i&1;
		dp[row][0] = 1;
		for(int j=1;j<=m;j++) {
			dp[row][j] = A[i] == B[j] ? dp[row^1][j-1] : INF;
            dp[row][j] = min(dp[row][j],1 + mm(dp[row^1][j-1], pm[row^1][j], dp[row][j-1]));
			if (dp[row][j] <= k) ans = max(ans, j);
			pm[row][j] = min(dp[row^1][j],pm[row^1][j]);
		}
	}
	cout << ans;
	return 0;
}
