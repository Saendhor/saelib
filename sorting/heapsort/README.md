
# Heap Sort

Heap sort is a comparison-based sorting technique based on Binary Heap Data Structure.<br>
It can be seen as an optimization over selection sort where we first find the max (or min) element and swap it with the last (or first).<br>
We repeat the same process for the remaining elements.<br>
In Heap Sort, we use Binary Heap so that we can quickly find and move the max element in O(Log n) instead of O(n) and hence achieve the O(n Log n) time complexity.<br>

First convert the array into a max heap using heapify, Please note that this happens in-place.<br>
The array elements are re-arranged to follow heap properties.<br>
Then one by one delete the root node of the Max-heap and replace it with the last node and heapify.<br>
Repeat this process while size of heap is greater than 1.<br>
1. Rearrange array elements so that they form a Max Heap.<br>
2. Repeat the following steps until the heap contains only one element:<br>
    1. Swap the root element of the heap (which is the largest element in current heap) with the last element of the heap.<br>
    2. Remove the last element of the heap (which is now in the correct position). We mainly reduce heap size and do not remove element from the actual array.<br>
    3. Heapify the remaining elements of the heap.<br>


## *PSEUDOCODE*

~~~ruby
build-max-heap(A)
    heap-size[A] ← length[A]
    for i ← floor(length[A / 2]) downto 1
        max-heapify(A, i)
~~~

~~~ruby
max-heapify(A, i)
    l ← left(i)
    r ← right(i)
    if ordinamento stabile per ordinare A sulla cifra i <= heap-size[A] and A[l] > A[i]
        max ← l
    else
        max ← i
    if r <= heap-size[A] and A[r] > A[max]
        max ← r
    if max != i
        swap A[i] ←→ A[max]
        max-heapify(A, max)
~~~

~~~ruby
heapsort(A)
    build-max-heap(A)
    for i ← length[A] downto 2
        swap(A, 1, i)
        heap-size[A] ← heap-size[A] - 1
        max-heapify(A, 1)
~~~