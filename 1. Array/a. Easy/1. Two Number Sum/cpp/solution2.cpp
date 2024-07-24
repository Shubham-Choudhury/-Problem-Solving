/*
Time Complexcity: O(n)
Space Complexcity: O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int *twoNumberSum(int array[], int arraySize, int targetSum)
{
    unordered_map<int, bool> nums;
    for (int i = 0; i < arraySize; i++)
    {
        int potentialMatch = targetSum - array[i];
        if (nums.find(potentialMatch) != nums.end())
        {
            int *result = new int[2];
            result[0] = array[i];
            result[1] = potentialMatch;
            return result;
        }
        else
        {
            nums[array[i]] = true;
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