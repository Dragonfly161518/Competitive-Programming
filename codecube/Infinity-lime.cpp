#include <bits/stdc++.h>
using namespace std;
int m,k;
vector<pair<int,int> > qs;
vector<int> v;

int bis(int l,int r,int x) {
    while (r >= l) {
        int m = l + (r - l) / 2;
        if(qs[m].first == x) return m;
        else if (qs[m].first > x)
            r = m-1;
        else
            l = m+1;
    }
    return r;
}

int main() {
    cin >> m >> k;
    for(int i=1;i<=m;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    qs.push_back({0,0});
    for(int i=0;i<m;i++) {
        if(qs[qs.size()-1].first != v[i]-i)
            qs.push_back({v[i]-i,i+1});
        else qs[qs.size()-1].second = i+1;
    }
    qs.push_back({1e9+5,m});
    int start =0;
    for(int i=1;i<=k;i++) {
        int n;
        scanf("%d",&n);
        printf("%d ",n + qs[bis(0,qs.size()-1,n)].second);
    }
    return 0;
}
