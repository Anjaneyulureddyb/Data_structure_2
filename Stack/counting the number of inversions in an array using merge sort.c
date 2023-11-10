#include <stdio.h>
#include <stdlib.h>
int c = 0;

void merge(int arr[], int left[], int leftsize, int right[], int rightsize) {
    int i = 0, j = 0, k = 0;
    
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else{
            arr[k++] = right[j++];
            c += leftsize - i;
        }
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
    int n,y;
    while(1)
    {
        printf("\nEnter 1 to start / 0 to exit:");
        scanf("%d",&y);
        if(y==1)
        {
            printf("Enter the size of the list:");
            scanf("%d", &n);
    
            int arr[n];
            for (int i = 0; i < n; i++){
                 printf("Enter the number %d:",i);
                scanf("%d", &arr[i]);
            }
            c = 0;
            mergesort(arr, n);
           
           printf("\nSorted List: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            
            printf("\nNumber of inversions: %d\n", c);
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}
