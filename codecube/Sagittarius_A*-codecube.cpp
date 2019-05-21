#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
ll sum;
int head[100050];
struct element {
    int w,fir,sec,index;
    bool operator <(const MyStruct& x, const MyStruct& y) {
        return x.w < y.w;
    }
}
priority_queue<element> pq;
int main() {
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        element x;
        scanf("%d%d%d",&x.fir,&x.sec,&x.w);
        x.index = i;
        pq.push(x);
    }
    int next = 0;
    while(!pq.empty()) {
        element x = pq.top();
        x.fir = fhead(x.fir), x.sec = fhead(x.sec);
        pq.pop();
        if(x.fir != x.sec) {
            head[x.fir] = x.sec;
            sum += x.w;
            v.push_back(x.index);
        } else {
            next = max(w,next);
        }
    }
    scanf("%d",&t);
    if(v.size() == n-1) {
        printf("%lli",sum + next);
        if(t == 1)
            for(auto x: v) printf("%d ",v);
    } else {
        printf("-1");
    }
    return 0;
}
