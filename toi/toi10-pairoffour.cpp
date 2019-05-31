#include <bits/stdc++.h>
using namespace std;
int n;
char arr[5000];
int mem[1003][1004];
int dp(int i,int j) {
    if(mem[i][j] != -1) return mem[i][j];
    if( j-i < 2) return mem[i][j] = 0;
    if(j-i == 2) {
        return mem[i][j] = (arr[i] == arr[j] ? 1 : 0);
    }
    if(arr[i] == arr[j]) return mem[i][j] = dp(i+1,j-1) + 1;
    int MAX = 0;
    for(int a=i;a<j;a++) {
        if(arr[i] == arr[a])
            MAX = max(MAX,dp(i,a) + dp(a+1,j));
    }
    return mem[i][j] = MAX;
}
int main() {
    memset(mem,-1,sizeof(mem));
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf(" %c",&arr[i]);
    }
    printf("%d",dp(0,n-1));
    return 0;
}
