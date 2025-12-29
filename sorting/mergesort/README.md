
# Merge Sort

Merge Sort is a divide-and-conquer, comparison-based sorting algorithm.<br>
Most implementations of merge sort are stable.<br>
Here's a step-by-step explanation of how merge sort works:<br>
1. Divide: Divide the list or array recursively into two halves until it can no more be divided.<br>
2. Conquer: Each subarray is sorted individually using the merge sort algorithm.<br>
3. Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.


## *PSEUDOCODE*

~~~ruby
merge(A, p, q, r)
    n ← q -p + 1
    m ← r - q
    create array L[n + 1] e R[m + 1]
    for i ← 1 to n
        L[i] ← A[p + i - 1]
    for j ← 1 to m
        R[j] ← A[q + j]
    L[n] ← INF
    R[m] ← INF
    i ← 1
    j ← 1
    for k ← p to r
        if L[i] <= R[j]
            A[k] ← L[i]
            i ← i + 1
        else A[k] ← R[j]
            j ← j + 1
~~~

~~~ruby
mergesort(A, p, r)
    if p < r
        q ← floor((p+r) / 2)
        mergesort(A, p, q)
        mergesort(A, q+1, r)
        merge(A, p, q, r)
~~~