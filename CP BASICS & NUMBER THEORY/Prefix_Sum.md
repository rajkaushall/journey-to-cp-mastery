
## **Title: 📊 Range Sum Query – Naive vs Optimized Approach**
You are given an array arr[] of n integers and Q queries. Each query consists of a pair (L, R) representing a range. Your task is to print the sum of elements from index L to R (1-based indexing) for each query.

This problem helps understand prefix sums and how to optimize repetitive range-sum calculations.

🧪 Sample Input
n = 6
arr[] = {3, 6, 2, 8, 9, 2}
Q = 4
Queries:
1. L = 2, R = 3
2. L = 4, R = 6
3. L = 1, R = 5
4. L = 3, R = 6
  
✅ Expected Output
8
19
28
21

---
## Naive Approach (Time: O(Q * n))
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Naive approach: Simply iterate for each query
void rangeSumNaive(const vector<int>& arr, const vector<pair<int, int>>& queries) 
{
    for (auto [l, r] : queries) 
    {
        int sum = 0;
        for (int i = l - 1; i <= r - 1; i++) 
        {
            sum += arr[i];
        }
        cout << sum << endl;
    }
}

int main() {
    vector<int> arr = {3, 6, 2, 8, 9, 2};
    vector<pair<int, int>> queries = {{2, 3}, {4, 6}, {1, 5}, {3, 6}};
    
    cout << "Naive Approach:\n";
    rangeSumNaive(arr, queries);
    
    return 0;
}
```

---
## Optimal Approach using Prefix Sum (Time: O(n + Q))
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Precompute prefix sums and use it to answer each query in O(1)
void rangeSumOptimal(const vector<int>& arr, const vector<pair<int, int>>& queries) 
{
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    
    // Building prefix sum array
    for (int i = 1; i <= n; ++i) 
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    for (auto [l, r] : queries) 
    {
        int sum = prefix[r] - prefix[l - 1];
        cout << sum << endl;
    }
}

int main() {
    vector<int> arr = {3, 6, 2, 8, 9, 2};
    vector<pair<int, int>> queries = {{2, 3}, {4, 6}, {1, 5}, {3, 6}};
    
    cout << "Optimal Approach:\n";
    rangeSumOptimal(arr, queries);
    
    return 0;
}
```

  
