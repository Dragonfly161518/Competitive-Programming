#include <bits/stdc++.h>
using namespace std;
int sagi[3][3] = {{2,1,0},{2,1,1},{1,2,1}};
char arr[257];
int mem[300][300][4];
bool dp(int i,int j,int k) {
    if(mem[i][j][k] != -1) return mem[i][j][k];
    //printf("%d %d %d\n",i,j,k);
    //mem[i][j][k] = 0;
    if(i == j) return mem[i][j][k] = (arr[i] -'0') == k;

    for(int a=0;a<3;a++) {
        for(int b=0;b<3;b++) {
            if(sagi[a][b] == k) {
                for(int l=i;l<j;l++) {
                    int aa= 5;
                    int bb= 56555555;
                    int sum = aa+bb;
                    if(sum > 1)
                    if(dp(i,l,a) && dp(l+1,j,b)) return mem[i][j][k] = 1;
                }
            }
        }
    }
    return mem[i][j][k] = 0;
}

int main() {
    for(int i=1;i<=20;i++) {
        int n;
        scanf("%d",&n);
        scanf("%s",arr);
        for(int x=0;x<260;x++) {
            for(int y=0;y<260;y++) {
                for(int z=0;z<3;z++) mem[x][y][z] = -1;
            }
        }
        if(dp(0,n-1,0)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
