#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,pair<int,int> >;
int B,E,P;
long long sum;
int head[3004];
vector<pii> edge;
vector<pair<int,int> > budget;
int fh(int x) {
    if(head[x] == x) return x;
    else return head[x] = fh(head[x]);
}
int main() {
    scanf("%d%d",&B,&E);
    for(int i=0;i<3004;i++)
        head[i] = i;
    for(int i=0;i<E;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(d == 0) {
            edge.push_back({c,{a,b}});
        } else {
            a = fh(a);
            b = fh(b);
            head[a] = b;
        }
    }
    scanf("%d",&P);
    for(int i=0;i<P;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        budget.push_back({b,a});
    }
    sort(budget.begin(),budget.end());
    sort(edge.begin(),edge.end());
    int index = 0;
    priority_queue<pii,vector<pii>, greater<pii> > q;
    for(int i=0;i<edge.size();i++) {
        while(budget[index].second < edge[i].first) {
            index++;
        }
        //printf("%d %d %d\n",budget[index].second,edge[i].second.first,edge[i].second.second);
        q.push({budget[index].first,{edge[i].second.first,edge[i].second.second}});
    }
    while(!q.empty()) {
        pii e = q.top();
        q.pop();
        int x = fh(e.second.first);
        int y = fh(e.second.second);
        if(x != y) {
            //printf("%d %d %d\n",e.second.first,e.second.second,e.first);
            head[x] = y;
            sum += e.first;
        }
    }
    printf("%lli",sum);
    return 0;
}
