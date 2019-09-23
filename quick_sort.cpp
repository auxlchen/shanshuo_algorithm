#include<iostream>
using namespace std;

int Partition(int a[], int start, int end){
    swap(a[start], a[end]);
    int small = start - 1;
    for(int i=start; i<end;i++){
        if(a[i]<a[end]){
            small++;
            if(i!=small)
                swap(a[i], a[small]);
        }
    }
    small++;
    swap(a[small], a[end]);
    
    return small;
}

void Qsort(int a[], int start, int end){
    
    if(start==end)
        return;
    
    int mid = Partition(a, start ,end);
    
    if(mid>start)
        Qsort(a, start, mid-1);
    if(mid<end)
        Qsort(a, mid+1, end);
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n;i++)
        cin>>a[i];
    Qsort(a, 0, n-1);
    for(int i=0; i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}