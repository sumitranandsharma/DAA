#include <stdio.h>
void merge(int a[], int s, int m, int e) {
    int t[50], i=s, j=m+1, k=s;
    while(i<=m && j<=e)
        t[k++] = a[i]<a[j]?a[i++]:a[j++];
    while(i<=m) t[k++] = a[i++];
    while(j<=e) t[k++] = a[j++];
    for(i=s;i<=e;i++) a[i]=t[i];
}
void mergeSort(int a[], int s, int e) {
    if(s<e){
        int m=(s+e)/2;
        mergeSort(a,s,m);
        mergeSort(a,m+1,e);
        merge(a,s,m,e);
    }
}
int main(){
    int n,a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
