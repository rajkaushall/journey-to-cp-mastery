
## Finding Equilibrium index in an array

**Problem Statement: Finding Equilibrium index in an array**

Given a 0-indexed integer array nums, find the leftmost equilibrium Index.

An equilibrium Index is an index at which sum of elements on its left is equal to the sum of element on its right. That is, nums[0] + nums[1] + ... + nums[equilibriumIndex-1] == nums[equilibriumIndex+1] + nums[equilibriumIndex+2] + ... + nums[nums.length-1]. If equilibriumIndex == 0, the left side sum is considered to be 0. Similarly, if equilibriumIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost equilibrium Index that satisfies the condition, or -1 if there is no such index.

**Examples:**

**Example 1:**
**Input:** 
nums = [2,3,-1,8,4]

**Output: 3**
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

**Example 2:**
**Input:** 
nums = [1,-1,4]

**Output: 2**
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0

---
## Brute Force Approach
```cpp
#include <iostream>
using namespace std;

int equilibriumPoint(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int leftSum = 0;
        int rightSum = 0;

        // Calculate sum of elements before index i
        for (int j = 0; j < i; j++) 
        {
            leftSum += arr[j];
        }

        // Calculate sum of elements after index i
        for (int j = i + 1; j < n; j++) 
        {
            rightSum += arr[j];
        }

        // Check if left sum equals right sum
        if (leftSum == rightSum) 
        {
            return i + 1;  // Return 1-based index
        }
    }

    return -1; // No equilibrium point found
}

int main() 
{
    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = equilibriumPoint(arr, n);

    if (result != -1)
        cout << "Equilibrium Point is at index: " << result << endl;
    else
        cout << "No Equilibrium Point found" << endl;
    return 0;
}
```

## Optimal Approach - Prefix Sum Technique

```cpp
#include <iostream>
using namespace std;

int equilibriumPoint(int arr[], int n) 
{
    int totalSum = 0;
    for (int i = 0; i < n; i++) 
    {
        totalSum += arr[i];  // Calculate total sum of the array
    }

    int leftSum = 0;
    for (int i = 0; i < n; i++) 
    {
        totalSum -= arr[i];  // totalSum now acts as rightSum

        if (leftSum == totalSum) 
        {
            return i + 1;     // Return 1-based index
        }

        leftSum += arr[i];   // Update leftSum for next index
    }

    return -1; // No Equilibrium Point found
}

int main() 
{
    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = equilibriumPoint(arr, n);

    if (result != -1)
        cout << "Equilibrium Point is at index: " << result << endl;
    else
        cout << "No Equilibrium Point found" << endl;

    return 0;
}
```
