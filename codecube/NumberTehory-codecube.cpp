#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int prime = 2;
ll P[200200];
int arr[200020];
ll b[200020];

ll power(int x,int y) {
    if(y == 1) return x;
    if(y%2 == 0) {
        return power(x,y/2) * power(x,y/2);
    } else return power(x,y-1) * x;
}

ll sum = 1;
vector<ll> v;
int main() {
    int n,m;
    cin >> n >> m;
    P[0] = 1;
    for(int i=1;i<=n;i++) P[i] = prime * P[i-1];
    for(int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
        sum *= power(arr[i],P[i]);
        if(i>=m) {
            v.push_back(sum);
            sum /= power(arr[i-m+1],P[i-m+1]);
        }
    }
    sum = 1;
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]);
        sum *= power(b[i],P[i]);
    }
    int start = 0,ans=0;
    for(auto x: v) {
        cout << sum << " " << x << endl;
        if(sum%x==0 || x%sum == 0) {
            ans++;
        }
        sum *= sum;
    }
    printf("%d",ans);
    return 0;
}
