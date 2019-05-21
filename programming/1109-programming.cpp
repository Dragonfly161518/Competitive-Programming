#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll sum;
pair<int,int> arr[103200];
void dc(int l,int r) {

    if(l == r) return;
    int m = (l + r)/2;
    dc(l,m);
    dc(m+1,r);

    pair<int,int> temp[100040];
    int index=0,num=0;
    int l1 = l, l2 = m+1;
    while(l1 <= m && l2 <= r) {
        if(arr[l1].second > arr[l2].second) {
            temp[index++] = arr[l2];
            sum += arr[l2++].second * (m-l1 + 1);
            num++;
        } else {
            temp[index++] = arr[l1];
            sum += num * arr[l1++].second;
            num = 0;
        }
    }
    while(l1 <= m) {
        temp[index++] = arr[l1];
        sum += num * arr[l1++].second;
    }
    while(l2 <= r) {
        temp[index++] = arr[l2++];
    }
    for(int k=0;k<index;k++) {
        arr[l+k] = temp[k];
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr+1,arr+n+1);
    dc(1,n);
    cout << sum;
    return 0;
}
