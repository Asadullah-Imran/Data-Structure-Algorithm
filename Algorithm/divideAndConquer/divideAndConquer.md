Overview of Divide and Conquer
The divide and conquer technique breaks a problem down into smaller subproblems, solves each subproblem independently, and combines their solutions to solve the original problem. This approach is particularly powerful for recursive problems and is widely used in algorithms that reduce complex problems to simpler ones (e.g., sorting and searching).

Steps in Divide and Conquer:
Divide: Split the problem into smaller, self-contained subproblems.
Conquer: Recursively solve each subproblem.
Combine: Merge the solutions of the subproblems to get the solution for the original problem.
Key Problems and Concepts
1. Merge Sort
Concept: Split the array into two halves, recursively sort each half, and then merge the sorted halves.
Key Points:
Time Complexity: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
Good practice for recursion and understanding how the merging process works.
2. Quick Sort
Concept: Choose a pivot element, partition the array around the pivot (so elements smaller than the pivot are on one side and larger ones are on the other), and then recursively sort each partition.
Key Points:
Average Time Complexity: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn), but worst case can be 
𝑂
(
𝑛
2
)
O(n 
2
 ) if pivot selection is poor.
Practice partitioning methods (like Lomuto or Hoare) for better intuition on pivoting.
3. Binary Search (Divide and Conquer Example)
Concept: Given a sorted array, divide the search range in half each time to locate a target value.
Key Points:
This is a classic example of divide and conquer, where you repeatedly divide the array.
Complexity: 
𝑂
(
log
⁡
𝑛
)
O(logn)
4. Matrix Multiplication (Strassen’s Algorithm)
Concept: Strassen’s algorithm reduces the number of multiplications needed in matrix multiplication, making it more efficient.
Key Points:
Not as commonly used as standard matrix multiplication due to added complexity but demonstrates divide and conquer on a 2D scale.
Complexity: 
𝑂
(
𝑛
log
⁡
2
7
)
≈
𝑂
(
𝑛
2.81
)
O(n 
log 
2
​
 7
 )≈O(n 
2.81
 )
Example: Merge Sort