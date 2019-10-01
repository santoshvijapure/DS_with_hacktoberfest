#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

int median(int x, int y, int z) {
    if (x <= y) {
	if   (z <= x) return x;
    	if   (z <= y) return z;
	else          return y;
    } else {
	if   (z <= y) return y;
	if   (z <= x) return z;
	else          return x;
    }
}

int partition(int *a, int n)
/* Median of first, middle and last
   It would be preferable to choose random element */
{
    int n2 = (n - 1)/2;
    int mid = median(a[0], a[n2], a[n - 1]);
    if (a[0] == mid)   return 0;
    if (a[n2] == mid) return n2;
    return n - 1;

    /** Or
     *  return rand()%n;
     **/
}

void quick_sort(int *a, int n)
{
    if (n < 2) return;

    /* Select Pivot Element */
    int p = partition(a, n);
    swap(a, a + p);

    /* Linear Partition */
    int m = 1;
    for (int i = 1; i < n; ++i) {
	if (a[i] < a[0]) {
	    swap(a + m, a + i);
	    m = m + 1;
	}
    }
    swap(a, a + m - 1);

    quick_sort(a, m - 1);
    quick_sort(a + m + 1, n - m);
}

int main()
{
    int size;
    printf("Size of Array : ");
    scanf("%d", &size);
    int *a = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
	scanf(" %d", a + i);
    quick_sort(a, size);
    for (int i = 0; i < size; ++i)
	printf("%d ", a[i]);
    putchar('\n');
    free(a);
    return 0;
}
