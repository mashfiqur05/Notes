# Mathematics - I

## Modular arithmatic

### Mod operation
```c++
a = a % m;
if (a < 0) a += m;
```

### Modular Addition/Subtraction

`Modular Addition, Subtraction formula`

(a + b) mod m = ((a mod m) + (b mod m)) mod m.
(a - b) mod m = ((a mod m) - (b mod m)) mod m.

Both formula is similar. 

Example:

(7 + 6) mod 4 = ?

7 mod 4 = 3 and 6 mod 4 = 2.

So, (7 + 6) mod 4 = (3 + 2) mod 4 = 5 mod 4 = 1.

Try with Subtraction also.

```
ll add (ll x, ll y) {x += y; return x >= mod ? x - mod : x;}
ll sub (ll x, ll y) {x -= y; return x < 0> ? x + mod : x;}
```

`Modular Multiplication`

Multiplication is simillar also addition. Because if I say 3 * 4 = what?
<br> I can say 3 * 4 = 3 + 3 + 3 + 3. add 3 for 4 times. This is mainly multiplicaton. 

```
(a * b) mod m = ((a mod m) * (b mod m)) mod m.
```

`Modular Division`
```
(a/b) mod m != ((a mod m) / (b mod m)) mod m.
```

Modular division does not work in this formula. Because division can have floating point but in Modular arithmatic floating point is not applicable.

Let's see some modular operation.


**Modulo 7**              | **Modulo 6**              | **Modulo 9**              
--------------------------|---------------------------|----------------------------
0 * 4 mod 7 = 0           | 0 * 4 mod 6 = 0           | 0 * 4 mod 9 = 0           
1 * 4 mod 7 = 4           | 1 * 4 mod 6 = 4           | 1 * 4 mod 9 = 4           
2 * 4 mod 7 = 1           | 2 * 4 mod 6 = 2           | 2 * 4 mod 9 = 8           
3 * 4 mod 7 = 5           | 3 * 4 mod 6 = 0           | 3 * 4 mod 9 = 3           
4 * 4 mod 7 = 2           | 4 * 4 mod 6 = 4           | 4 * 4 mod 9 = 7           
5 * 4 mod 7 = 6           | 5 * 4 mod 6 = 2           | 5 * 4 mod 9 = 2           
6 * 4 mod 7 = 3           | -                         | 6 * 4 mod 9 = 6          
| -                 | -        | 7 * 4 mod 9 = 1           
| -                 | -        | 8 * 4 mod 9 = 5           


Look at the 1st table `Modulo 7` here 0 to 6 every elemenmt is present after mod. 
Is this happen every time? `NO`. Look at the 2nd table `Modulo 6` here only 0, 2, 4 is present. 
But in the next table `Modulo 9` 0 to 8 everything is present after mod. Have you find any patter?
in the 1st and 3rd table 4, 7 and 4, 9 are co-prime. That's why 0 to n-1 everything is present.
For 2nd table common divisor of 4,6 is 2. That's why 2's multiple is present.<br>
So, you can find `(a / b) mod m` if b and m are co-prime. Otherwise some element will be missing 0 to n-1 like 2nd table `Modulo 6`.

## Modular Inverse (Fermat's Little Theorem)


```c++
ll mod (ll x) {x = x % MOD; return a < 0 ? a+MOD : a;}
ll modAdd (ll x, ll y) {ll ret = mod (x) + mod (y); return mod (ret);}
ll modSub (ll x, ll y) {ll ret = mod (x) - mod (y); return mod (ret);}
ll modMul(ll x, ll y) {ll ret = mod(x) * mod(y);return mod(ret);}
```