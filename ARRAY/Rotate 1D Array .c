
#include <stdio.h>

int main()
{
    int n,n1,temp=0,h;
    
    printf("Enter the size of the array:");
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d number:",i);
        scanf("%d",&a[i]);
    }
            printf("\nEnter the rotate times:");
            scanf("%d",&n1);
            
            for(int i=0;i<n1;i++)
            {
                temp = a[n-1];
                for(int j=n-1;j>=0;j--)
                {
                    a[j] = a[j-1];
                }
                a[0] = temp;
            }
            
          
    
    printf("\nThe numbers in the array: ");
    
    for(int i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
