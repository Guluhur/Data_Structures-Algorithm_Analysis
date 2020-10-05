//: selection_problem.c
#include <stdio.h>
#include <math.h> 
#include <time.h>

/** 找到一数组按从小到大排列后的第k个元素 
 * @author Guluhur 
 * @date 2020/10/5 
 * @version 1.0
 */
#define N 8192
#define MAX 1000

void printArray(int array[], int n)
{
	int i;
	printf("Array = [\n");
    for(i = 0; i < n; i++)
    {
    	printf("%d\t", array[i]);
    	if((i+1)%10 == 0) puts("");
	}
	printf("]\n");
}

void selectSoft(int array[], int n, int softLength)
{
	int i, j, idx, tmp;
	for(i = 0; i < softLength; i++)
	{
	    idx = i;
	    for(j = i+1; j < n; j++)
	        if(array[idx] > array[j])
	            idx = j;
	    if(idx != i)
	    {
	    	tmp = array[idx];
	    	array[idx] = array[i];
	    	array[i] = tmp;
		}
    }
}

int main()
{
	int ary[N], i,
	    k = N/2;
	srand(11);
	for(i = 0; i < N; i++)
	    ary[i] = rand() % MAX + 1;
	//printArray(ary, N);
	clock_t begin_t = clock();
	selectSoft(ary, N, k);
    clock_t end_t = clock();
	//printArray(ary, N);
	printf("Element[%d] = %d\n", k, ary[k-1]);
    printf("Cost: %.3lfms\n", (double)(end_t-begin_t)/CLK_TCK*1000);
	return 0;
}   /* Output(50% match):
Element[4096] = 495
Cost: 46.000ms
*///:~ 
