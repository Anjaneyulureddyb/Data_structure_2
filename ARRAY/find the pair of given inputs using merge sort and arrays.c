#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int leftsize, int right[], int rightsize) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    
    while (i < leftsize)
        arr[k++] = left[i++];
    
    while (j < rightsize)
        arr[k++] = right[j++];
}

void mergesort(int arr[], int size) {
    if (size <= 1)
        return;
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];
    
    mergesort(left, mid);
    mergesort(right, size - mid);
    
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int n,s,s1;
    
    printf("Enter the size of the list:");
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++){
        printf("Enter the number %d:",i);
        scanf("%d", &arr[i]);
    }
    
    mergesort(arr, n);

    printf("Enter the sum to find the pair:");
    scanf("%d",&s);

    int i=0,j=n-1;
    while(i<j)
    {
        s1=arr[i]+arr[j];
        if( s1 == s)
        {
            printf("%d and %d are the sum of the %d.",arr[i],arr[j],s);
            return 0;
        }
        else if(s1 < s)
        {
            i++;
        }
        else
        {
            j--;
        }
    }printf("%d pair of this number is not found.",s);
    return 0;
}
