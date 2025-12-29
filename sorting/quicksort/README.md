
# Quick sort

QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.<br>
It works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.<br>
There are mainly three steps in the algorithm:<br>
1. Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).<br>
2. Partition the Array: Re arrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.<br>
3. Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).<br>
4. Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.<br>


## *PSEUDOCODE*

~~~ruby
partition(A, p, r)
    x ← A[r]
    i ← p-1
    for j← p to r-1
        if A[j] <= x
            i ← i + 1
            swap(A, i, j)
    swap(A, i + 1, r)
    return i + 1
~~~

~~~ruby
quicksort(A, p, r)
    if p < r
        q ← partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)
~~~