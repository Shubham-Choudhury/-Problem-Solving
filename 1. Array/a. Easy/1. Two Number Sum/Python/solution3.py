"""
Time Complexity: O(nlogn)
Space Complexity: O(1)
"""


def twoNumberSum(array, targetSum):
    array.sort()
    left = 0
    right = len(array) - 1
    while left < right:
        currentSum = array[left] + array[right]
        if currentSum == targetSum:
            return [array[left], array[right]]
        elif currentSum < targetSum:
            left += 1
        elif currentSum > targetSum:
            right -= 1
    return []


if __name__ == "__main__":
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    targetSum = 10
    print(twoNumberSum(array, targetSum))
