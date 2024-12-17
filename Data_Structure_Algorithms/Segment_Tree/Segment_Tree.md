# Segment Tree

A **segment tree** is a data structure that stores a range of elements in its node. It allows to modify the array and perform range query operation in smaller complexity.
We can perform to find the maximum or minimum number between the range L to R and also modify the array L to R all in O(log) complexity.

## Construction of Segment Tree 
The segment tree mainly works on the principle of divide and conquer.

- At each level we divide the array segment into two part. Left part is **0 to mid** and right part is **mid+1 to n-1**. where n is lenght of the array segment array and **mid = (0 + n) / 2**.
- We will go on until the lower and upper bounds of the range become equal. Finally the segment tree looks like a **binary tree**.

There are two common approch to construct the segment tree. **Recursive method** and **iterative method**.

As we noted 