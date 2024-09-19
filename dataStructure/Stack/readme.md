# Stack
Last in first out

## Basic operation on stack data structure 
    - push(int x): inserts x to the top of the stack 
    - pop(); removes the top element from the stack 
    - top(): returns the top element without removing it
    - isEmpty(): return true if the stack is empty
    - isFull(): return true if the stack is full

## Proces1
int arr[4]
intitial = [] -> top = -1
push(5) [5] -> top = 0
push(6) [5,6] -> top = 1
push(8) [5,6,8] -> top = 2
push(9) [5,6,8,9] -> top = 3
push(12) => stack over flow {as top == size-1} 


pop() [5,6,8] -> top = 2
pop() [5,6] -> top = 1
pop() [5] -> top = 0
pop() [] -> top = -1

pop() => stack under flow {as top == -1}