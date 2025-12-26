
# Selection Sort

Selection sort is an in-place comparison sorting algorithm.<br>
It has a O(n²) time complexity, which makes it inefficient on large lists and generally performs worse than the similar insertion sort.<br>
Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.<br>


## *PSEUDOCODE*

~~~ruby
selectionsort(A)
    for i ← 0 to length[A] - 1
        min_index = i
        for j ← i + 1 to length[A]
            if A[j] < A[min_index]
                min_index ← j
        if min_index != i
            swap(i, min_index)
~~~