
# Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the input list element by element comparing the current element with the one after it and swapping their values if needed.<br>
These passes through the list are repeated until no swaps have to be performed during a pass thus meaning that the list has become fully sorted.<br>
The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.<br>


## *PSEUDOCODE*

~~~ruby
bubblesort(A)
    for i ← 0 to length[A] - 1
        swapped  ← false
            for j ← 0 to length[A] - i - 1
                if A[j] > A[j + 1]
                    swap(A, j, j + 1)
                    swapped ← true
                if swapped == false
                    break
~~~