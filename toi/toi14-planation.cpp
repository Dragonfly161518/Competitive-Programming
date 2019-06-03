#include <bits/stdc++.h>

float cal(int i,int j) {
    return (sqrt(pow(p[i].first-p[j].first,2)) + pow(p[i].second-p[j].second,2)));
}

int closetpair(int l,int r) {
    if(r - l <= 2) {
        int MIN = 1e9;
        for(int i=l;i<=r;i++) {
            for(int j=l+1;j<=r;j++) {
                MIN = min(MIN,cal(i,j));
            }
        }
        return MIN;
    }

    int m = (l+r)/2;

    int d1= closetpair(l,m);
    int d2 = closetpair(m+1,r);

    int d = min(d1,d2);
    vector<float,int> > v;
    for(int i=0;i<n;i++) {
        if(abs(p[m]-p[i]) < d) {
            v.push_back({p[i].second,i});
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++)
            if(abs(p[v[i]].second-p[v[j]].second) < d) {
                d = min(d,cal(i,j));
            }
            else break;
    }
    return d;
}

int main() {

}
