#  Euclidean Algorithm (Basic and Extended)

## Computing GCD using Euclidean Algorithm

GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common prime factors.

```
36 = 2 * 2 * 3 * 3
60 = 2 * 2 * 3 * 5

GCD = Multiplication of common factor
    = 2 * 2 * 3
    = 12
```

### Intuition
- If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
- Now instead of subtraction, if we divide the larger number, the algorithm stops when we find the remainder 0.

**Recursive Implementation**
```c++
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
```
**Time Complexity:** `O(log (min (a, b)))`

## Least common multiple
```c++
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
```

## Extended Euclidean Algorithm

