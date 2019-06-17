#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[2040][2040];
int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d",&arr[i][j]);
            if(i >= 2 && j >= 2)
                arr[i][j] += arr[i-1][j-1] + arr[i][j-1];
        }
    }

}
