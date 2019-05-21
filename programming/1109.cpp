#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100004];
double sum;
int n;

void Q(int l,int m,int r)
{
    int L1 = m-l + 1;
    int L2 = r-m;

    pair<int,int> STR1[L1];
    pair<int,int> STR2[L2];

    for(int i=0;i<L1;i++)
        STR1[i] = arr[l+i];
    for(int i=0;i<L2;i++)
        STR2[i] = arr[m+1+i];

    int index = l;
    double sumL=0,sumnub=0;

    int LEFT =0,RIGHT = 0;
    while(LEFT < L1 && RIGHT < L2) {
        if(STR1[LEFT].second > STR2[RIGHT].second) {
            sumL += STR2[RIGHT].first;
            sumnub++;
            arr[index++] = STR2[RIGHT++];
        } else
        {
            sum += sumL + (sumnub*STR1[LEFT].first);
            arr[index++] = STR1[LEFT++];
        }
    }

    while(LEFT < L1)
    {
        sum += sumL + (sumnub*STR1[LEFT].first);
        arr[index++] = STR1[LEFT++];
    }
    while(RIGHT < L2)
        arr[index++] = STR2[RIGHT++];
        /*
    for(int i=0;i<n;i++)
        printf("%d %d\n",arr[i]);
    printf("\n");*/
}

void mergeSort(int l,int r)
{
    if(l>=r ) return;
    int m = (l+r)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    Q(l,m,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    mergeSort(0,n-1);
    printf("%.0lf",sum);

    return 0;
}
