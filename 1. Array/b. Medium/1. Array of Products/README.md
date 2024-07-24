# 1. Array of Products

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

### Inputs:

- `nums`: an integer array of length `n`

### Outputs:

- An integer array `answer` of length `n` where `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`

### Test Cases

**Test Case - 1**

Input:

```
nums = [1, 2, 3, 4]
```

Output:

```
[24, 12, 8, 6]
```

**Test Case - 2**

Input:

```
nums = [-1, 1, 0, -3, 3]
```

Output:

```
[0, 0, 9, 0, 0]
```

## Approach - 1 : Brute Force

1. **Time Complexity:** `O(n^2)`
2. **Space Complexity:** `O(1)`

**Algorithm:**

1.  Let `n` be the length of `nums`

2.  Initialize an empty list or array `ans` to store the result

3.  For `i` from `0` to `n - 1`:

    a. Initialize `product` to `1`

    b. For `j` from `0` to `n - 1`:

    - If `i` is not equal to `j`:

      - Multiply product by `nums[j]`

    c. Append `product` to `ans`

4.  Return `ans`

**Pseudocode:**

```
Function ArrayOfProducts(nums){
    n = length of nums
    ans = []
    For i from 0 to n - 1:
        product = 1
        For j from 0 to n - 1:
            If i != j:
                product *= nums[j]
        Append product to ans
    Return ans
}
```

## Approach - 2 : Prefix and Suffix Product Approach

1. **Time Complexity:** `O(n)`
2. **Space Complexity:** `O(n)`

**Algorithm:**

1. Let `n` be the length of `nums`
2. Initialize list or array `left` of size `n` with all elements as `1`
3. Initialize list or array `right` of size `n` with all elements as `1`
4. Initialize list or array `ans` of size `n` with all elements as `1`

5. For `i` from `1` to `n - 1`:

   - `left[i] = left[i - 1] * nums[i - 1]`

6. For `i` from `n - 2` to `0`:

   - `right[i] = right[i + 1] * nums[i + 1]`

7. For `i` from` 0` to `n - 1`:

   - `ans[i] = left[i] * right[i]`

8. Return `ans`

**Pseudocode:**

```
Function ArrayOfProducts(nums):
    n = length of nums
    left = [1] * n
    right = [1] * n
    ans = [1] * n

    For i from 1 to n - 1:
        left[i] = left[i - 1] * nums[i - 1]

    For i from n - 2 to 0:
        right[i] = right[i + 1] * nums[i + 1]

    For i from 0 to n - 1:
        ans[i] = left[i] * right[i]

    Return ans
```

## Approach - 3 : Optimized Prefix and Suffix Product Approach

1. **Time Complexity:** `O(n)`
2. **Space Complexity:** `O(1)`

**Algorithm:**

1. Let `n` be the length of `nums`
2. Initialize list or array `ans` of size `n` with all elements as `1`
3. Initialize `left` to `1`
4. Initialize `right` to `1`
5. For `i` from `0` to `n - 1`:

   - `ans[i] = ans[i] * left`
   - `left = left * nums[i]`
   - `ans[n - i - 1] = ans[n - i - 1] * right`
   - `right = right * nums[n - i - 1]`

6. Return `ans`

**Pseudocode:**

```
Function ArrayOfProducts(nums):
    n = length of nums
    ans = [1] * n
    left = 1
    right = 1

    For i from 0 to n - 1:
        ans[i] = ans[i] * left
        left = left * nums[i]
        ans[n - i - 1] = ans[n - i - 1] * right
        right = right * nums[n - i - 1]

    Return ans
```
