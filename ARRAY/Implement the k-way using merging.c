#include <stdio.h>
#include<stdlib.h>

void merge(int arr[], int left[], int leftsize, int right[], int rightsize){
    int k=0,i=0,j=0;
    
    while(i<leftsize && j<rightsize){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    
    while(i<leftsize)
        arr[k++]=left[i++];
   
    while(j<rightsize)
        arr[k++]=right[j++];
}

void mergesort(int arr[], int n){
    if(n<=1)
        return;

    int mid = n/2;
    int left[mid];
    int right[n - mid];
    
    for(int i=0;i<mid;i++)
        left[i]=arr[i];

    for(int i=mid;i<n;i++)
        right[i-mid]=arr[i];

    mergesort(left, mid);
    mergesort(right, n - mid);
    
    merge(arr, left, mid, right, n - mid);
}

void mergearrays(int* arr[], int k, int size[]){
    int c=0;
    
    for(int i=0;i<k;i++)
        c +=size[i];
    
    int a[c];
    int n=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<size[i];j++){
             a[n++] = arr[i][j];
        }
    }
    
    printf("\nMerged array: ");
    for(int i=0;i<c;i++){
        printf("%d ",a[i]);
    }
    
    mergesort(a, c);
    
    printf("\nSorted merged array: ");
    for(int i=0;i<c;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int n,i,k,j=0;
    do{
        printf("\nEnter the number of the arrays:");
        scanf("%d",&k);
        
        if(k<=2)
            printf("\nplease enter more than 2 arrays.....\n");
        else break;
    }while(1);
    int* arr[k];
    int size[k];
    for(i=0;i<k;i++){
        printf("\nEnter the size of the %d array :",i+1);
        scanf("%d",&size[i]);
        
        arr[i] = (int *)malloc(sizeof(int)*size[i]);
        
        for(j=0;j<size[i];j++){
            printf("Enter the %d value:",j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(i=0;i<k;i++){
        printf("\nThe %d array :",i+1);
        for(j=0;j<size[i];j++){
            printf("%d ",arr[i][j]);
        }
    }
    mergearrays(arr, k, size);
    return 0;
}
