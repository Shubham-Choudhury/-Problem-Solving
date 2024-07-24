/*
Time Complexcity: O(n)
Space Complexcity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *twoNumberSum(int array[], int arraySize, int targetSum)
{
    bool nums[100000] = {false};
    for (int i = 0; i < arraySize; i++)
    {
        int potentialMatch = targetSum - array[i];
        if (potentialMatch >= 0 && potentialMatch < 100000 && nums[potentialMatch])
        {
            int *result = (int *)malloc(2 * sizeof(int));
            result[0] = array[i];
            result[1] = potentialMatch;
            return result;
        }
        else
        {
            if (array[i] >= 0 && array[i] < 100000)
            {
                nums[array[i]] = true;
            }
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
