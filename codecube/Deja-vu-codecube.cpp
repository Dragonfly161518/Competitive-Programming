#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll v[100002];
priority_queue<pair<int,int> > s[100002];
int a[100020];
int length = 1;


int bis(int l,int r,int x) {
    if(l > r) {
        return l;
    }
    int m = (l + r)/2;
    if(v[m] > x) {
        r = m-1;
    } else l=m+1;
    bis(l,r,x);
}

int main() {
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	v[0] = a[0];
	s[0].push({a[0],0});
	for(int i=1;i<n;i++) {
        if(v[length-1] <= a[i]) {
			v[length] =  a[i];
			s[length].push({a[i],i});
			length++;
		}
		else {
			int index = bis(0,length,a[i]);
            s[index].push({a[i],i});
			v[index] = a[i];
		}
	}
	ll sum = 0;
	for(int i=length-1;i>=0;i--) {
        if(i != length-1)
            while(s[i].top().second > s[i+1].top().second || s[i].top().first > s[i+1].top().first) s[i].pop();
        sum += s[i].top().first;
	}
	cout << length << " " << sum << endl;
	return 0;
}

