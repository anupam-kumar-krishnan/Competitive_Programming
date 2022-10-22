#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int m,l,mid;
int maxcrossingsum(int *a,int low,int mid,int high)
{
	int crosssum,sum,i,j,maxleft,maxright,sum1;
	double leftsum = -INFINITY;
	sum=0;
	for(i=mid;i>=low;i--)
	{
		sum=sum+*(a+i);
		if(sum>leftsum)
		{
			leftsum=sum;
			maxleft=i;
			
		}
	}
	double rightsum = -INFINITY;
	sum1=0;
	for(j=mid+1;j<=high;j++)
	{
		sum1=sum1+*(a+j);
		if(sum1>rightsum)
		{
			rightsum=sum1;
			maxright=j;
		}
	}
	crosssum=leftsum+rightsum;
	return crosssum;
}
int maxsubarraysum(int *a,int low,int high)
{
	int mid,leftsum,rightsum,crosssum;
	if(high==low)
	{
		return *(a+low);
	}
	mid=(high+low)/2;
	leftsum=maxsubarraysum(a,low,mid);
	rightsum=maxsubarraysum(a,mid+1,high);
	crosssum=maxcrossingsum(a,low,mid,high);
	if((leftsum>rightsum||leftsum==rightsum)&&(leftsum>crosssum||leftsum==crosssum))
	{
		return leftsum;
	}
	else if((rightsum>leftsum||rightsum==leftsum)&&(rightsum>crosssum||rightsum==crosssum))
	{
		return rightsum;
	}
	else
	{
		return crosssum;
	}
}
int maxsubarraynaive(int *a,int n)
{
	int i,sum,j,maxs;
	maxs=*(a+1);
	
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=i;j<=n;j++)
		{
			sum=sum+*(a+j);
			if(sum>=maxs)
			{
				m=i;
				l=j;
				maxs=sum;	
			}
		}
	}
	return maxs;
}
int main()
{
	int n,x,i,a[20],maxsum,k;
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}
    for ( i = 1; i <= n ; i++)
    {
        printf("A[%d] = %d\n",i,a[i]);
    }
    printf("Let's get max subarray:\n");
	do
	{
		printf("\n1. Find the maximum subarray using naive approach\n");
        printf("2. Find the maximum subarray using divide and conquer approach\n");
        printf("3. Exit from the program\n");
        printf("Enter your option.......\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			maxsum=maxsubarraynaive(a,n);
			printf("The maximum sum is: %d\n",maxsum);
			printf("The maximum subarray is:\n");
			for(k=m;k<=l;k++)
			{
				printf("A[%d]=%d",k,a[k]);
				printf("\n");
			}
			break;
			case 2:
			maxsum=maxsubarraysum(a,1,n);
			printf("The maximum sum is: %d\n",maxsum);
			for(k=m;k<=l;k++)
			{
				printf("The maximum subarray is: ");
				printf("A[%d]=%d\n",k,a[k]);
			}
			break;
            case 3:
            printf("You have entered to take 'EXIT' from code...\n.......THANK YOU.....\n");
            exit(0);
            break;
        default:
            printf("You have entered 'INVALID INPUT'\n");
            printf("Please entered 'VALID INPUT'......\n");
            break;
		}
	}
	while(x<=2);
	return 0;
}