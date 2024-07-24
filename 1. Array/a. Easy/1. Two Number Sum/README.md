# 1. Two Number Sum

Given an array of integers and a target sum, write a function that returns two numbers from the array that add up to the target sum. If no such pair exists, the function should return an empty array or null.

### Inputs:

- `array`: An array of integers (positive, negative, or zero).
- `targetSum`: An integer representing the target sum.

### Outputs:

- An array or list containing two integers from the input array that add up to the `targetSum`. If no such pair exists, return an empty array or null.

### Assumptions:

- The input array will always have at least one number.
- The output array should contain the two numbers in any order.
- The input array will only contain unique numbers.

### Test Cases

**Test Case - 1**

Input:

```
array = [3, 5, -4, 8, 11, 1, -1, 6]
targetSum = 10
```

Output:

```
[-1, 11]
```

Explanation: The numbers 11 and -1 add up to 10.

**Test Case - 2**

Input:

```
array = [4, 6, 1, -3]
targetSum = 3
```

Output:

```
[6, -3]
```

Explanation: The numbers 6 and -3 add up to 3.

**Test Case - 3**

Input:

```
array = [1, 2, 3, 4, 5]
targetSum = 10
```

Output:

```
[]
```

Explanation: There are no two numbers in the array that add up to 10.

## Approach - 1 : Brute Force

1. **Time Complexity:** `O(n^2)`
2. **Space Complexity:** `O(1)`

**Algorithm:**

1. **Initialize Function:** Define a function `twoNumberSum` that takes an array `array` and an integer targetSum as inputs.

2. **Outer Loop:** Loop through each element of the array using an index `i` from 0 to `length(array) - 1`.

3. **Get First Number:** Inside the outer loop, set `firstNum` to `array[i]`.

4. **Inner Loop:** Loop through the elements that come after the current element in the array using an index `j` from `i + 1` to `length(array)`.

5. **Get Second Number:** Inside the inner loop, set `secondNum` to `array[j]`.

6. **Check Sum:** Check if the sum of `firstNum` and `secondNum` is equal to `targetSum`.

   - If true, go to step 7.
   - If false, continue to the next iteration of the inner loop.

7. **Return Result:** If the sum is equal to the target sum, return an array containing `firstNum` and `secondNum`.

8. **Return Empty Array:** If the outer loop completes without finding a pair of numbers that sum to the target sum, return an empty array or null.

9. **End Function:** End the function.

**Pseudocode:**

```
function twoNumberSum(array, targetSum) {
    for (let i = 0; i < array.length - 1; i++) {
        const firstNum = array[i];
        for (let j = i + 1; j < array.length; j++) {
            const secondNum = array[j];
            if (firstNum + secondNum === targetSum) {
                return [firstNum, secondNum];
            }
        }
    }
    return [];
}
```

## Approach - 2 : Using Hash Table

1. **Time Complexity:** `O(n)`
2. **Space Complexity:** `O(n)`

**Algorithm:**

1. **Initialize Hash Table:** Create an empty hash table (or dictionary) `nums` to store the numbers encountered so far.

2. **Iterate Through Array:** Loop through each element `num` in the input array.

3. **Calculate Potential Match:** For each `num`, calculate the potential match as `potentialMatch = targetSum - num`.

4. **Check for Match:**

   - If `potentialMatch` exists in the hash table `nums`:
     - Return the pair `[potentialMatch, num]`.

5. **Add to Hash Table:** If `potentialMatch` is not found, add the current `num` to the hash table `nums` with any value (e.g., `true`).

6. **Return Result:** If no pair is found after iterating through the entire array, return an empty array or null.

**Pseudocode:**

```
function twoNumberSum(array, targetSum) {
    nums = {}; // Initialize a hash table
    // Iterate through each number in the array
    for ( num of array) {
        // Calculate the potential match
         potentialMatch = targetSum - num;
        // Check if the potential match exists in the hash table
        if (potentialMatch in nums) {
            return [potentialMatch, num];
        }
        nums[num] = true;
    }
    return [];
}
```

## Approach - 3 : Using Two Pointer

1. **Time Complexity:** `O(nlogn)`
2. **Space Complexity:** `O(1)`

**Algorithm:**

1.  Sort the array in non-decreasing order

2.  Initialize left pointer to the start of the array (index 0)

3.  Initialize right pointer to the end of the array (index length of array - 1)

4.  While left pointer is less than right pointer:

    a. Calculate the sum of the elements at the left and right pointers

    b. If the sum is equal to targetSum:

    - Return the elements at the left and right pointers as the result

    c. If the sum is less than targetSum:

    - Increment the left pointer to increase the sum

    d. If the sum is greater than targetSum:

    - Decrement the right pointer to decrease the sum

5.  If no such pair is found, return an empty result

**Pseudocode:**

```
Function TwoNumberSum(array, targetSum):
    1. Sort array in non-decreasing order
    2. Set left = 0
    3. Set right = length of array - 1

    4. While left < right:
        a. Set currentSum = array[left] + array[right]

        b. If currentSum == targetSum:
            i. Return [array[left], array[right]]

        c. Else if currentSum < targetSum:
            i. Increment left by 1

        d. Else:
            i. Decrement right by 1

    5. Return an empty array

```
