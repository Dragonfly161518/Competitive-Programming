#include <bits/stdc++.h>
using namespace std;
int t[500050];
int h[500050];
int n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    for(int i=0;i<n;i++) {
        scanf("%d",&h[i]);
    }
    sort(t,t+n);
    sort(h,h+n,greater<int>());
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(t[i]+h[i]);
    sort(v.begin(),v.end());
    long long sum = 0;
    for(int i=0;i<n-1;i++) {
        sum += v[i+1]-v[i];
    }
    printf("%lli",sum);
    return 0;
}
