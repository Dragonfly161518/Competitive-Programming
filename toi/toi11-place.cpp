#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,t;
ll sum;
int head[100050];
vector<int> v;
struct element {
    int w,fir,sec,index;
    bool operator <(const element& x) const{
        return x.w > w;
    }
};
int fhead(int x) {
    if(head[x] == x) return x;
    return head[x] = fhead(head[x]);
}
priority_queue<element> pq;
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) head[i] = i;
    for(int i=1;i<=m;i++) {
        element x;
        scanf("%d%d%d",&x.fir,&x.sec,&x.w);
        x.index = i;
        pq.push(x);
    }
    int next = -1;
    while(!pq.empty()) {
        element x = pq.top();
        x.fir = fhead(x.fir), x.sec = fhead(x.sec);
        pq.pop();
        if(x.fir != x.sec) {
            head[x.fir] = x.sec;
            sum += x.w;
            v.push_back(x.index);
        } else if(next == -1) {
            next = x.w;
            v.push_back(x.index);
        }
    }
    scanf("%d",&t);
    if(v.size() == n) {
        printf("%lli\n",sum + next);
        if(t == 2)
            for(auto x: v) printf("%d ",x);
    } else {
        printf("-1");
    }
    return 0;
}
