#include <stdio.h>


void swap(int* p1, int* p2)
{
   int temp =*p1;
   *p1 = *p2;
   *p2 = temp;
}
void bubblesort(int arr[], int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int* arr =(int*)malloc((n+1) * sizeof(int));
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    bubblesort(arr,n);
    for(int i=1;i<=n;i++)
       printf("%d ",arr[i]);

 return 0;
}