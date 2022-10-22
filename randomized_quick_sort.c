#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a, int *b )
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *a, int *beg, int *end)
{
	int x,i;
	x=*(a+*end);
	i=*beg-1;
	for (int j = *beg; j <= *end-1; j++)
	{
		if (*(a+j)<=x)
		{
			i=i+1;
			swap((a+i),(a+j));
		}
	}
	swap((a+(i+1)),(a+*end));
	return (i+1);
}

int randomized_partition(int *a, int *beg, int *end)
{
	int i,q;
	i= *beg + rand() % (*end-*beg+1);
	swap((a+*beg),(a+i));
	q=partition(a,beg,end);
	return q;
}

int *randomized_quick_sort(int *a,int *beg,int *end)
{
	int q;
	if(*beg<*end)
	{
		q=randomized_partition(a,beg,end);
		int t=q-1;
		int s=q+1;
		randomized_quick_sort(a,beg,&t);
		randomized_quick_sort(a,&s,end);
	}
	return a;
}

void printelement(int *arr, int *beg, int *end)
{
	printf("\nPrinting all elements after randomized quick sort:\n");
	for (int i = *beg; i <= *end; i++)
	{
		printf("Element A[%d] is %d\n",i,*(arr+i));
	}
}

int main()
{
	int beg,end,n,i;
	printf("Enter the number of elements you want in array.....:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array....:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter A[%d]:\n",i);
		scanf("%d",(a+i));
	}

	beg=0;
	end=n-1;
	randomized_quick_sort(a,&beg,&end);
	printelement(a,&beg,&end);
	return 0;
}
