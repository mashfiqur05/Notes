# Segment Tree

A **segment tree** is a data structure that stores a range of elements in its node. It allows to modify the array and perform range query operation in smaller complexity.
We can perform to find the maximum or minimum number between the range L to R and also modify the array L to R all in O(log) complexity.

## Construction of Segment Tree 
The segment tree mainly works on the principle of divide and conquer.

- At each level we divide the array segment into two part. Left part is **0 to mid** and right part is **mid+1 to n-1**. where n is lenght of the array segment array and **mid = (0 + n) / 2**.
- We will go on until the lower and upper bounds of the range become equal. Finally the segment tree looks like a **binary tree**.

There are two common approch to construct the segment tree. **Recursive method** and **iterative method**.

We will store the segment tree as a array tree[] with a size of four times the input size n.

**implementation of construction**

```c++
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = arr[l];
    }
    else 
    {
        int mid = (l + r) / 2;
        
        build (2 * node, l, mid);
        build (2 * node + 1, mid + 1, r);

        // Storing the sum of both the children into the parent
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
```

Now we are going to update the segment tree. Given a index and update the value of the index with v.

```c++
void update (int node, int l, int r, int id, int new_val)
{
    if (l == r) 
    {
        arr[idx] = new_val;
        tree[node] = new_val;
    }
    else
    {
        int mid = (l + r) / 2;
        if (l <= id) update (2 * node, l, mid, id, val);
        else update (2 * node + 1, mid + 1, r, id, val);

        /// Store the information.
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
```

Now we are going to do a query on the tree. Given two integers l and r return the sum of the segment [l, r].

```c++
int query(int node, int tl, int tr, int l, int r)
{

    // If it lies out of range then return 0
    if (r < tl or tr < l) return 0;

    // If the node contains the range then return the node value
    if (l <= tl and tr <= r) return tree[node];
    int tm = (tl + tr) / 2;

    return query(2 * node, tl, tm, l, r) + query(2 * node + 1, tm + 1, tr, l, r);
}
```

#### Time Complexity
- The building operation takes O(N) time
- The query operation takes O(logN) time
- Each update is performed in O(logN) time

**``Note``**
A segment tree with 2<sup>x</sup> leaf node will have total 2<sup>x</sup>-1 nodes due to its perfect binary structure. But if we are not dealing with a non-power-of-two number of elements, extra leaf nodes may be present. To represent all elements, the number of leaf nodes must be rounded up to the nearest power of two, resulting in a maximum of almost 2*n leaf nodes.


For instance, if n is 2<sup>j</sup> + 1, 2<sup>(j+1)</sup> leaf nodes will be required, leading to an O(2*n) space complexity. As the total number of nodes is about twice the number of leaf nodes, the total space complexity of the segment tree is O(4n)