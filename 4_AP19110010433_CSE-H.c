#include <stdio.h>
int main()
{
	int i, j,low, high, middle, n, search,swap;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int array[n];
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d",&array[i]);

	printf("Enter value to be searched:");
	scanf("%d", &search);
	low = 0;
	high = n - 1;
	//Bubble sorting in increasing order
	for (i=0;i <n-1;i++)
  	{
  	  for (j=0;j< n-i-1;j++)
   	 {
  	    if (array[j] > array[j+1])
     		 {
     		   swap       = array[j];
       		   array[j]   = array[j+1];
       		   array[j+1] = swap;
     		 }
   	 }
        }

	//Searching begins
	while (low <= high)
	{
		middle = (low + high)/2;
		if(array[middle] < search)
		low = middle + 1;
		else if (array[middle] == search)
		{
			printf("%d found at location %d",search, middle+1);
			break;
		}
		else
		high = middle - 1;

	}		
	if(low > high)
	printf("Not found! %d isn't present in the list.",search);
	return 0;
}
