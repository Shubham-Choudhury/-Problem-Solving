/*
Time Complexcity: O(nlogn)
Space Complexcity: O(1)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int *twoNumberSum(int array[], int arraySize, int targetSum)
{
    sort(array, array + arraySize);
    int left = 0;
    int right = arraySize - 1;
    while (left < right)
    {
        int currentSum = array[left] + array[right];
        if (currentSum == targetSum)
        {
            int *result = new int[2];
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
    return nullptr;
}

int main()
{
    int array[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int targetSum = 10;
    int arraySize = sizeof(array) / sizeof(array[0]);
    int *result = twoNumberSum(array, arraySize, targetSum);

    if (result != nullptr)
    {
        cout << result[0] << " " << result[1] << endl;
        delete[] result;
    }
    else
    {
        cout << "No pair found that sums to the target." << endl;
    }

    return 0;
}