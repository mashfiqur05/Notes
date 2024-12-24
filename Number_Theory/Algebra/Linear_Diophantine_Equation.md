# Linear Diophantine Equations

A Diophantine Equation is a equation of general form
```
ax + by = c
```
where a, b, c are given integers and x, y are unknown integers.
Determine if the equation has a solution such that x and y are both integral.

Example:
```
1. If a = 6, b = 3, c = 9 
Then x and y integral value possible for x = 1 and y = 1.

2. If a = 3, b = 6, c = 8
Then x and y integral value not possible for this equation.

3. If a = 2, b = 5, c = 1
Then for (-2, 1) and (3, -1) integral value possible.
```

For linear Diophantine equation equations, integral solutions exist if and only if, 
the GCD of coefficients of the two variables divides the constant term perfectly. 
In other words, the integral solution exists if, GCD(a ,b) divides c.

### Implementation
```c++
int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
 
// Function to check if integral solutions are possible
bool isPossible(int a, int b, int c)
{
    int gcd_val = gcd(a, b);
    return (c % gcd_val == 0);
}
```

### Finding a particular solution

Extended Euclidean algorithm can be used for finding a particular solution.
Assume that a, b is non negative and we can find g = gcd(a, b).
If c is divisible by g = gcd(a, b), then the given Diophantine equation has a solution.

Now supposed that c is divisible by g, then we have:

```math
a \cdot x_g \cdot \frac{c}{g} + b \cdot y_g \cdot \frac{c}{g} = c
```

The solution to the equation is:

```math
x_0 = x_g \cdot \frac{c}{g},
```

```math
y_0 = y_g \cdot \frac{c}{g}.
```

### Implementation
`Note:` this code does not consider the case a = b = 0
```c++
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
```

### Getting all Solution
After finding one soluion we can devired a general solution for generating all solution.
```math
x = x_0 + \frac{b} {gcd (a, b)} \cdot t
```
```math
y = y_0 - \frac{a} {gcd (a, b)} \cdot t
```
where k is a integer

### Finding the number of solution in a given interval

We understand from the previous part that we can find infinite number of solution. We can find solutions within a specified interval by follwing these steps.
- Find any solution of the equation.
- Shift the solution to get the smallest x >= min<sub>x</sub> and the largest x <= max<sub>x</sub>. These are denoted as l<sub>x1</sub> and r<sub>x1</sub>.
- Finding the corresponding values of y for y >= min<sub>y</sub> and the largest y <= max<sub>y</sub> denoted as l<sub>x2</sub> and r<sub>x2</sub>.
- The final solution is the intersection of [l<sub>x1</sub> r<sub>x1</sub>] and  [l<sub>x2</sub> r<sub>x2</sub>], represented as [l<sub>x</sub> r<sub>x</sub>].

### Implementation

```c++
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
```