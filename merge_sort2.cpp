#include <iostream>

using namespace std;

const int N = 100010;

int a[N];
int tmp[N];
int n;

void merge(int q[], int start, int sz, int n)
{
    int mid = start + sz/2, end = min(n,start+sz);
    
    int i = start, j = mid, idx = 0;
    
    while(i<mid && j<end) {
        if(q[i]<=q[j]) tmp[idx++] = q[i++];
        else tmp[idx++] = q[j++];
    }
    
    while(i<mid) tmp[idx++] = q[i++];
    while(j<end) tmp[idx++] = q[j++];
    
    for(i=0,j=start ; j < end ; i++,j++)
        q[j] = tmp[i];
}

void merge_sort(int q[], int n)
{
    for(int sz = 2 ; sz/2 <= n ; sz *= 2)
        for(int i = 0 ; i+sz/2 < n ; i+=sz)
            merge(q,i,sz,n);
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n;  i++) scanf("%d",&a[i]);
    
    merge_sort(a,n);
    
    for(int i = 0 ; i < n ; i++) printf("%d ",a[i]);
    return 0;
}
