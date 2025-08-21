
### Second Lecture
---
Geek teaches a maths class in Geekland state university in which you have enrolled. Today is your second lecture. In the previous lecture Geek has taught integer numbers so before starting the next topic he wants to test your understanding of integers for which he gave you a problem - Given an integer  **N**  find the ratio of sum of squares of first  **N**  positive integers by sum of first  **N**  positive integers. Sometimes the ratio is not an integer, then you have to print "NO" (without quotes) as you know only about integer numbers currently. Otherwise print "YES" (without quotes) and the ratio separated by a space.  

**Input:**  
1. The first line of the input contains a single integer  **T**  denoting the number of test cases. The description of **T**  test cases follows.  
2. The first line of each test case contains one integer **N**.  

**Output:**  For each test case, print the answer on a new line.  

**Constraints:**  
1. 1 ≤ T ≤ 10<sup>4</sup>  
2. 1 ≤ N ≤ 10<sup>9</sup>  

**Example:**

**Input:**
2
2
4
**Output:**
NO
YES 3
**Explanation:**
**Test Case 1:** sum of first N natural numbers = 1 + 2 = 3 and sum of squares of first N natural numbers = 1 + 4 = 5. Since 5 is not divisible by 3, you have to print "NO".

**Test Case 2:** sum of first N natural umbers = 1 + 2 + 3 + 4 = 10 and sum of squares of first N natural numbers = 1 + 4 + 9 + 16 = 30. Since 30 is divisible by 10, you have to print "YES 3".

---
## 🔹 All Possible Methods
According to given constraint, the approaches that **will run all test cases correctly** are:  
**(2) Formula-Based, 
(3) Simplified Formula Check, and 
(5) Pattern Observation.**

### **1. Iterative Approach (Loop-based)**
-   **Idea:** Directly calculate both sums using a loop.
   ```cpp
long long sqSum = 0, sum = 0;
for (long long i = 1; i <= N; i++) 
{
    sum += i;
    sqSum += i * i;
}
if (sqSum % sum == 0)
    cout << "YES " << sqSum / sum;
else
    cout << "NO";

```
    
-   **Complexity:** O(N)
-   **Suggestion:** Only for **small N** (like N≤10<sup>5</sup>). Not optimized for big inputs.

---
### **2. Formula-Based Approach**

-   **Idea:** Use direct math formulas.
    -   Sum of integers: N ( N + 1 ) / 2
    -   Sum of squares: N ( N + 1 ) ( 2N + 1 ) / 6
    -   Ratio = ( 2N + 1 ) / 3​
  ```cpp
if ((2*N + 1) % 3 == 0)
    cout << "YES " << (2*N + 1) / 3;
else
    cout << "NO";

```
    
-   **Complexity:** O(1)
-   **Suggestion:** This is the **best and most optimized approach**.

---
### **3. Simplified Formula Check (Modulo Only)**

-   **Idea:** We don’t even need full formula — just check divisibility of 2N+12N+12N+1 by 3.
    
```cpp
if ((2*N + 1) % 3 == 0)
    cout << "YES " << (2*N + 1) / 3;
else
    cout << "NO";
```
    
-   **Complexity:** O(1)
-   **Suggestion:** Same as (2), but even cleaner. Best for contests.

---
### **4. Precomputation (Prefix Sums)**

-   **Idea:** If there are **multiple queries** (many values of N), we can precompute sums up to a certain limit.
```cpp
vector<long long> sum(N+1,0), sqSum(N+1,0);
for (int i=1; i<=N; i++) {
    sum[i] = sum[i-1] + i;
    sqSum[i] = sqSum[i-1] + 1LL*i*i;
}
// then check ratio for any N quickly
```
    
-   **Complexity:** Precomputation O(N), each query O(1).
-   **Suggestion:** Useful if you need answers for **all N up to limit** quickly.

---
### **5. Mathematical Pattern Observation**

-   **Idea:** Notice that ratio = (2N+1)/3.
-   So integer solution exists **only when 2N+1≡0(mod3).
-   That means:  
						N ≡ 1 ( mod 3 )
```cpp
if (N % 3 == 1)
    cout << "YES " << (2*N + 1) / 3;
else
    cout << "NO";
```
    
-   **Complexity:** O(1)
-   **Suggestion:** Very elegant, just one modulus check.

---
### ✅ Final Result
-   ❌ Iterative Loop (1) → Too slow.
-   ✅ Formula-Based (2) → Works.
-   ✅ Simplified Formula Check (3) → Works.
-   ❌ Precomputation (4) → Not possible.
-   ✅ Pattern Observation (5) → Best and fastest.
