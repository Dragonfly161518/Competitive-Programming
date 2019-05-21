#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int n,k;
ll dp[100020],X[100020],C[100030];
pair<int,int> res[100020];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &res[i].first, &res[i].second);
    sort(res+1, res+n+1);
    for (int i = 1; i <= n; ++i)
        X[i] = res[i].first, C[i] = res[i].second;
    deque<int> dq;
    for(int i=1;i<=n;i++) {
        while(!dq.empty() && X[i] - X[dq.front()] > k) dq.pop_front();
        ll sum = dq.empty() ? -1e14 : X[dq.front()] + C[dq.front()] + dp[dq.front()-1];
        dp[i] = max(dp[i-1], sum + C[i] - X[i]);
        ll add = dp[i-1] + X[i] + C[i];
        while(!dq.empty() && add >= C[dq.back()] + X[dq.back()] + dp[dq.back()-1]) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n];
    return 0;
}
