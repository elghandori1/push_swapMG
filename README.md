## Push Swap Project

The goal of this project is to sort an array of integers using the fewest number possible of the given instructions :
- sa : swap a - swap the first 2 elements at the top of stack a.
- sb : swap b - swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a.
- pb : push b - take the first element at the top of a and put it at the top of b.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time .
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## Algorithm 

### Three Sort:
I just compar the first element with it's successors and based of this comparision decid wich instructions to do. I should not do more than three instructions.

### Five Sort:
I find the smallest two element in stack_A and push them to stack _B, when stack_A is of size three, i sort it with three sort, and the push the tow elements in stack_B to stack_A.

### for 100 and 500 
I used many algorithms, including sort list and bubble sort. The goal is to ignore the large numbers above and below the stack and the smaller elements in the middle, 
in order to reach the largest element faster, so if it is at the top, I raise it to stack_a, and if it is at the bottom, I put it at the top,
then raise it to stack_a, and this is how it works for me.  Fewer instructions .
Thus, in the case of 100 numbers, I get less than 700 orders, and in the case of 500 numbers, I get less than 5,500 orders.

## What i learned 
I really enjoyed working on this project, it was very hard at the first but because of it i learned a lot about Sorting Algorihms wich is a very important thing to know for every developper.
Also managing memory by prveting any kind of memory leaks and freeing any allocated memory is crucial to validate this project.
