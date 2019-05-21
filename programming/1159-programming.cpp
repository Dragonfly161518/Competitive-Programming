#include <bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
using namespace std;
int m,n;
pair<int,int> mem[1004][1004];
bool chk[1004][1004];
int A[1002],B[1002];

pair<int,int> dp(int i,int j) {
    if(chk[i][j]) return mem[i][j];
    chk[i][j] = true;
    if(i == 0 && j == 0) return mem[i][j] = {0,0};
    pair<int,int> a,b;
    a.first = 2e9+21;
    a.second = 2e9+21;
    b = a;
    if(i > 0)
        a = dp(i-1,j);
    if(j > 0)
        b = dp(i,j-1);
    if(a.second + A[i] > m) {
        a.second = A[i];
        a.first++;
    } else a.second+= A[i];
    if(b.second + B[j] > m) {
        b.second = B[j];
        b.first++;
    } else b.second +=B[j];
    return mem[i][j] = a < b ? a : b;
}
int main() {
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
       scanf("%d",&A[i]);
    }
    for(int i=1;i<=n;i++) {
       scanf("%d",&B[i]);
    }
    pair<int,int> ans = dp(n,n);
    printf("%d\n%d",ans.first+1 ,ans.second);
    return 0;
}
