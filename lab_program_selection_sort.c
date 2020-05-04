#include <stdio.h>

int main()
{
  int n, i, j, pos,temp;

  printf("Enter number of elements\n");
  scanf("%d", &n);
  int array[n];
  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);

  for (i = 0; i < (n - 1); i++) // finding minimum element (n-1) times
  {
    pos = i;

    for (j = i + 1; j < n; j++)
    {
      if (array[pos] > array[j])
        pos = j;
    }
    if (pos!= i)
    {
      temp = array[i];
      array[i] = array[pos];
      array[pos] = temp;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i< n; i++)
    printf("%d\n", array[i]);

  return 0;
}
