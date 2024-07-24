/*
Time Complexcity: O(n^2)
Space Complexcity: O(1)
*/

#include <iostream>
using namespace std;

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
                int *result = new int[2];
                result[0] = firstNum;
                result[1] = secondNum;
                return result;
            }
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