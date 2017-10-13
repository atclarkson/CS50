# Analyze This

## Questions

1a. Yes

1b. What is being described would be a hash table O(n) where the hash function
    just take the second digit, then merging all those in order and hashing
    them again this time the hash function just uses the first digit.
    So the result should be O(n) + O(n) or O(2n) or 200

2a. Yes it would work.

2b. The Worst Case scenerio would not improve.  What it sounds like is being described
    is alternating between a bubble sort and an insertion sort. Both of which are O(n^2).

3a. Yes this algorithm is correct.

3b. O(n) This is a linear seek.  Considering the cards are already in an unknown order, shuffeling
    between each check is an unecassary step but it does not add any more complexity to the
    problem.


## Debrief

1. http://bigocheatsheet.com/  (Used to find the Big O notation of a hash table sorting algorithm)

2. 45 Minutes.
