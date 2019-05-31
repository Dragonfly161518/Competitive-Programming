#include <bits/stdc++.h>
using namespace std;
deque<pair<int,int> > d;
int MAX,SIZE;
int main() {
    int n,w;
    scanf("%d%d",&n,&w);
    d.push_front({0,0});
    int S = 0;
    for(int i=1;i<=n;i++) {
        int why;
        scanf("%d",&why);
        S += why;
        while(!d.empty() && i - d.front().second > w)
            d.pop_front();
        while(!d.empty() && d.back().first >= S)
            d.pop_back();
        int SUM = S - d.front().first;
        d.push_back({S,i});
        if(SUM > MAX) {
            MAX = SUM;
            SIZE = i-d.front().second;
        } else if(SUM == MAX) {
            SIZE = min(i-d.front().second,SIZE);
        }
    }
    printf("%d\n%d",MAX,SIZE);
    return 0;
}
