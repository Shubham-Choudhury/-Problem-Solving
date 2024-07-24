"""
Time Complexcity: O(n^2)
Space Complexcity: O(1)
"""


def twoNumberSum(array, targetSum):
    for i in range(len(array)):
        for j in range(i + 1, len(array)):
            if array[i] + array[j] == targetSum:
                return [array[i], array[j]]
    return []


if __name__ == "__main__":
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    targetSum = 10
    print(twoNumberSum(array, targetSum))
