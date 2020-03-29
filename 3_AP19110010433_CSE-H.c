#include<stdio.h>
int main()
{
	int n,i,search,ctr=0,x=0;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter an element:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&search);
	//Checking each element in the array with the search number
	for(i=0;i<n;i++)
	{
		if(a[i]==search)
		{       printf("%d is present at position:%d\n",search,i+1);
			ctr=1;
		}
	}
	if(ctr==0)
		printf("%d is not present in the given array.",search);
	return 0;
}

