#include <bits/stdc++.h>
using namespace std;
//long long P[1220];
//const int PRIME = 69000001;
using pii = pair<int,int>;
map<vector<pii>,int> m;
int main() {
//    P[0] = 1;
//    for(int i=1;i<=1024;i++) {
//        P[i] = P[i-1]*PRIME;
//    }
    int t,q;
    scanf("%d%d",&t,&q);
    for(int i=1;i<=t;i++) {
        int n;
        scanf("%d",&n);
        vector<pii> v;
        for(int j=0;j<n-1;j++) {
            int a,b;
            scanf("%d %d",&a,&b);
            if(a > b) {
                int t=b;
                b = a;
                a = t;
            }
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        if(m[v] == 0) {
            m[v] = 1;
        } else m[v] += 1;
    }
    for(int i=1;i<=q;i++) {
        int n;
        scanf("%d",&n);
        vector<pii> v;
        for(int j=0;j<n-1;j++) {
            int a,b;
            scanf("%d %d",&a,&b);
            if(a > b) {
                int t=b;
                b = a;
                a = t;
            }
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        cout << m[v] << endl;
    }
}
