#include <bits/stdc++.h>
using namespace std;
int sum;
int main() {
    for(int i=1;i<1000;i++) {
        if(i%3 ==0 || i%5 == 0) sum+= i;
    }
    cout << sum;
    return 0;
}
