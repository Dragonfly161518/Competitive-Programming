#include <bits/stdc++.h>
using namespace std;
int n;
int c[500500];
pair<int,int> p;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        p.push_back({a,i});
    }
    sort(p.begin(),p.end());
    for(int i=1;i<p.size();i++) {

    }
    long long sum = 0;
    for(int i=0;i<p.size();i++) {
        if(p[i].first > MIN) break;
        int d = p[i].first - p[i-1].first;
        sum -= d*(p.size()-i);
        sum += c[p[i-1].second]-p[i].first + p[i-1].first;
        sum -= d*;
        MIN = min(MIN,sum);
    }
    printf("%lli",MIN);
    return 0;
}
