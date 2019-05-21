#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
const ll INF = 1e16;
int k,m,n;
ll qs[50002];
ll pm[2][50002];
ll dp[2][50002];

int main() {
    cin >> n >> k >> m;
    pm[0][0] = INF;
    for(int i=1;i<=n;i++) {
        cin >> qs[i];
        qs[i] += qs[i-1];
        pm[0][i] = min(pm[0][i-1], -qs[i-1]);
    }
    for(int i=1;i<=k;i++) {
        int row = i&1;
        dp[row][0] = INF;
        pm[row][0] = INF;
        for(int j=1;j<=n;j++) {
            dp[row][j] = dp[row][j-1];
            if(j-m >= 0)
                dp[row][j] = min(dp[row][j], pm[row^1][j - m + 1] + qs[j]);
            pm[row][j] = min(pm[row][j-1], dp[row][max(j-2,0)] - qs[j-1]);
        }
    }
    cout << qs[n] - dp[k&1][n];
    return 0;
}
