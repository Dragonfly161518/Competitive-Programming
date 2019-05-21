#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
int arr[1655];
ll dp[1666][150];
pair<ll,int> quick[1506][1505];
int main() {
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++) {
        priority_queue<int,vector<int>, greater<int> > MIN;
        priority_queue<int> MAX;
        quick[i][i] = {0,i};
        int temp = (arr[i]+arr[i+1])/2;
        quick[i][i+1] = {abs(temp-arr[i]) + abs(temp-arr[i+1]),i};
        if(arr[i] > arr[i+1]) {
            MIN.push(arr[i+1]);
            MAX.push(arr[i]);
        } else {
            MAX.push(arr[i+1]);
            MIN.push(arr[i]);
        }
        for(int j=i+2;j<=n;j++) {
           int bias = 0;
           MIN.push(arr[j]);
           while(MIN.size() > MAX.size()) {
                MAX.push(MIN.top());
                MIN.pop();
           }
           while(MIN.top() < MAX.top()) {
                int x = MIN.top(), y = MAX.top();
                MIN.pop(); MAX.pop();
                MIN.push(y); MAX.push(x);
           }
           int median;
           if(MIN.size() == MAX.size()) {
                median = (MIN.top() + MAX.top())/2;
                bias++;
           } else median = MAX.top();
            bias *= abs(temp - median);
            //printf("[%d %d %d ]",bias,MIN.size(),MAX.size());
            quick[i][j] = { quick[i][j-1].first + abs(arr[j] - median) + bias , i };
            temp = median;
            //printf("%d %d %d\n",i,j,quick[i][j].first);
        }
    }

    for(int i=1;i<=n;i++) {
        dp[i][0] = quick[1][i].first;
        for(int j=1;j<k;j++) {
            dp[i][j] = INF;
            for(int l=i;l>1;l--) {
                dp[i][j] = min(dp[l-1][j-1] + quick[l][i].first, dp[i][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++) {
        for(int j=0;j<k;j++) {
            printf("%d %d %lli\n",i,j,dp[i][j]);
        }
    }*/
    printf("%lli ",dp[n][k-1]);
    return 0;
}
