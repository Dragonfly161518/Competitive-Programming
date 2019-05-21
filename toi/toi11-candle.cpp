#include <bits/stdc++.h>
using namespace std;
int m,n;
char x[2002][2002];
int number;

void floodfill(int a,int b) {
    queue<pair<int,int> > q;
    q.push({a,b});
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(x[i][j] == '0') {
            continue;
        }
        x[i][j] = '0';
        for(int k=i-1;k<=i+1;k++) {
            for(int l=j-1;l<=j+1;l++) {
                if(k >= 0 && k < m && l >= 0 && l < n)
                    if(x[k][l] == '1') {
                        q.push({k,l});
                    }
            }
        }
    }
}

int main() {
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++) {
        scanf("%s",x[i]);
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(x[i][j] == '1') {
                number++;
                floodfill(i,j);
            }
        }
    }
    cout << number << endl;
    return 0;
}
