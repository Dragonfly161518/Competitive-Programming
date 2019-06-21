//Name: Nattapat Sriwichailumpun
//Lang: C++
#include <bits/stdc++.h>
using namespace std;
string A,B;
int dp[1000][1000];
int ans = 0,iR,iC;
int main() {
    cin >> A >> B;
    for (int i=1; i<=A.size(); i++) {
		for (int j=1; j<=B.size(); j++) {
			if (A[i-1] == B[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				if(ans < dp[i][j]) {
                    ans = dp[i][j];
                    iR = i;
                    iC = j;
				}
			}
		}
	}
    for(int i=ans-1;i>=0;i--) {
        cout << A[iR-i-1];
    }
    return 0;
}
