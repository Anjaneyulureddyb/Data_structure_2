#include <stdio.h>

int main()
{
    int n,n1,m,temp=0,h,j;
    
    printf("Enter the of rows:");
    scanf("%d",&n);
    printf("Enter the of columns:");
    scanf("%d",&m);
    
    int a[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("Enter the %d%d number:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
   
            printf("\nEnter the rotate times:");
            scanf("%d",&n1);
            
            for(int i=0;i<n1;i++)
            {
                temp = a[0][0];
                 for(int i=0;i<m-1;i++)
                 {
                    a[0][i]=a[0][i+1];
                 }
                 
                 for(int i=0;i<n-1;i++)
                 {
                     a[i][m-1]=a[i+1][m-1];
                 }
                 
                 for(int i=m-1;i>0;i--)
                 {
                     a[n-1][i]=a[n-1][i-1];
                 }
                 
                 for(int i=n-1;i>0;i--)
                 {
                     a[i][0]=a[i-1][0];
                 }
                 a[1][0]=temp;
            }
    
    printf("The numbers in the array:\n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
             printf("%d ",a[i][j]);
        }
        printf(" \n");
    }

    return 0;
}
