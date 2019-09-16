#include <iostream>

using namespace std;

const int N = 100010;

int a[N];

int tmp[N];

void merge_sort(int q[], int l, int r)
{
	if(l>=r) return;

	int mid = l+r>>1;

	merge_sort(q,l,mid);
	merge_sort(q,mid+1,r);

	int i = l, j = mid+1;
	int idx = 0;
	while(i<=mid && j<=r) {
		if(q[i] <= q[j]) tmp[idx++] = q[i++];
		else tmp[idx++] = q[j++];
	}
	
	while(i<=mid) tmp[idx++] = q[i++];
	while(j<=r) tmp[idx++] = q[j++];
	
	i = 0, j = l;
	for(; j<= r ; i++,j++)
		q[j] = tmp[i];
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

	merge_sort(a,0,n-1);
	for(int i = 0 ; i < n ; i++) printf("%d ",a[i]);
	return 0;
}
