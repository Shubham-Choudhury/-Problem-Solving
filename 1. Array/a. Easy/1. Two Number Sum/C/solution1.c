/*
Time Complexcity: O(n^2)
Space Complexcity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int *twoNumberSum(int array[], int arraySize, int targetSum)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        int firstNum = array[i];
        for (int j = i + 1; j < arraySize; j++)
        {
            int secondNum = array[j];
            if (firstNum + secondNum == targetSum)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = firstNum;
                result[1] = secondNum;
                return result;
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
