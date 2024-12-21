# Binary Exponentiation

Binary exponentiation  is a trick which allows to calculate a^n using only O(log⁡n) multiplications (instead of O(n) multiplications required by the naive approach).

## Why to Use Binary Exponentiation?
If we have to calculate (a<sup>n</sup>), we can simply multiply a for n times with 1. The time complexity for this approch is O(n). But with the help of binary exponentiation we can do it with O(log n) complexity which is very efficient than the previous approch.


## Approch for Binary Exponentiation

When we are calculating a<sup>n</sup>, we can have 3 possible positive values of n:

**`Case 1:`** If n = 0, whatever be the value of a, our result will be **1**.

**`Case 2:`** If n is an even number, then instead of calculating a<sup>n</sup>, we can calculate (a<sup>2</sup>)<sup>n/2</sup> and the result will be the same.

**`Case 3:`** If n is an odd number, then instead of calculating a<sup>n</sup>, we can calculate a × (a<sup>(n-1)/2</sup>)<sup>2</sup>.

### Recursive Implementation
```c++
long long binexp(long long a, long long n) {
    if (n == 0)
        return 1;
    long long res = binexp(a, n / 2);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}
```

### Iterative Implementation
```c++
long long binexp(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) 
            res = res * a;
        a = a * a;
        n >>= 1;    /// n /= 2
    }
    return res;
}
```

## Applications

### 1. Find N<sup>th</sup> Fibonacci number
We can simply compute N<sup>th</sup> Fibonacci number by running a loop till N and in every iteration we have to find ith fibonacci using (i-1)<sup>th</sup> and (i-2)<sup>th</sup> number. The complexity of this approch is `O(n)`.
But we can do it in `O(log n)` complexity with the help of Matrix exponentiation.
### Approach to Solve Fibonacci, Tribonacci, or Similar Series Using Matrix Exponentiation

1. **Understand the Recurrence Relation**
-  **Fibonacci:** F(n) = F(n-1) + F(n-2)
- **Tribonacci:** T(n) = T(n-1) + T(n-2) + T(n-3)
- **General \( k \)-step Recurrence:**  S(n) = c<sub>1</sub> * S(n-1) + c<sub>3</sub> * S(n-2) + ..... + c<sub>k</sub> * S(n-k) 

This means each term is a linear combination of the \( k \) previous terms.

2. **Convert Recurrence Relation to Matrix Form**

Example for Tribonacci:

```math
\begin{bmatrix}
T(n) \\ T(n-1) \\ T(n-2) \\
\end{bmatrix}
 = 
\begin{bmatrix}
1 && 1 && 1 \\ 1 && 0 && 0 \\ 0 && 1 && 0 \\
\end{bmatrix}
.
\begin{bmatrix}
T(n-1) \\ T(n-2) \\ T(n-3) \\
\end{bmatrix}
```
For a 𝑘-step recurrence, the matrix is 𝑘×𝑘
```math
A = 
\begin{bmatrix}
c_1 & c_2 & \dots & c_k \\
1 & 0 & \dots & 0 \\
0 & 1 & \dots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \dots & 1
\end{bmatrix}
```


3. **Use Matrix Exponentiation**
To compute S(n), raise the matrix A to `𝑛 − (𝑘−1)` and multiply it with the initial state vector.

**Key Formula:**
$$
S(n) = First row of (A^{n-(k-1)}) * \begin{bmatrix} S(k-1) \\ S(k-2) \\ \dots \\ \dots \\ S(0) \end{bmatrix}$$

- For Fibonacci, raise A to n-1
- for Tribonacci, raise A to n-2 

**Implementation**
```c++
/// Function to multiply two matrix
void multiply(vector<vector<long long> >& A,
              vector<vector<long long> >& B)
{
    // Matrix to store the result
    vector<vector<long long> > C(2, vector<long long>(2));

    // Matrix Multiply
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

      // Copy the result back to the first matrix
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}

// Function to find (Matrix M ^ expo)
vector<vector<long long> >
power(vector<vector<long long> > M, int expo)
{
    // Initialize result with identity matrix
    vector<vector<long long> > ans = { { 1, 0 }, { 0, 1 } };

    // Fast Exponentiation
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }

    return ans;
}

// function to find the nth fibonacci number
int nthFibonacci(int n)
{
    // base case
    if (n == 0 || n == 1)
        return 1;

    vector<vector<long long> > M = { { 1, 1 }, { 1, 0 } };
    
    // Matrix F = {{f(0), 0}, {f(1), 0}}, where f(0) and f(1) are first two terms of fibonacci sequence
    vector<vector<long long> > F = { { 1, 0 }, { 0, 0 } };

    // Multiply matrix M (n - 1) times
    vector<vector<long long> > res = power(M, n - 1);

    // Multiply Resultant with Matrix F
    multiply(res, F);

    return res[0][0] % MOD;
}
```
**Try to implement for Tribonacci**


