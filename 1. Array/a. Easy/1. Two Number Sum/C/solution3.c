/*
Time Complexcity: O(nlogn)
Space Complexcity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *twoNumberSum(int array[], int arraySize, int targetSum)
{
    qsort(array, arraySize, sizeof(int), compare);
    int left = 0;
    int right = arraySize - 1;
    while (left < right)
    {
        int currentSum = array[left] + array[right];
        if (currentSum == targetSum)
        {
            int *result = (int *)malloc(2 * sizeof(int));
            result[0] = array[left];
            result[1] = array[right];
            return result;
        }
        else if (currentSum < targetSum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return NULL;
}

int main()
{
    int array[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int targetSum = 10;
    int arraySize = sizeof(array) / sizeof(array[0]);
    int *result = twoNumberSum(array, arraySize, targetSum);

    if (result != NULL)
    {
        printf("%d %d\n", result[0], result[1]);
        free(result);
    }
    else
    {
        printf("No pair found that sums to the target.\n");
    }

    return 0;
}