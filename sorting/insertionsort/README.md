
# Insertion Sort

Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. <br>
It is like sorting playing cards in your hands.<br>
You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.<br>


## *PSEUDOCODE*

~~~ruby
insertionsort(A)
    for j ← 1 to length[A]
        key ← A[j]
        # Insert A[j] in the already ordered sequence A[0, 1, ... ,j-1]
        i ← j-1
        while i >= 0 and A[i] > key
            A[i+1] ← A[i]
            i ← i-1
        A[i+1] ← key
~~~