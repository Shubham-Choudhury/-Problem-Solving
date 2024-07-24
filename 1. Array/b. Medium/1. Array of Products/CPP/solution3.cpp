/*
Time Complexcity: O(n)
Space Complexcity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    int left = 1;
    int right = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] *= left;
        left *= nums[i];
        ans[n - i - 1] *= right;
        right *= nums[n - i - 1];
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    nums = {-1, 1, 0, -3, 3};
    result = productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}