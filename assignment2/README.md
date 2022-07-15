Team members
- Vincent Ledesma
- Clement Bowe

Panther ID
3020421
5442372

## Running memory allocation programs

- use "make firstfit" to build executable for firstfit.c (first)
- use "make nextfit" to build executable for nextfit.c (next)
- use "make bestfit" to build executable for bestfit.c (best)
- use "make worstfit" to build executable for worstfit.c (worst)


Things to be completed

- first fit - Clement Bowe
- next fit - Clement Bowe
- best fit - Vincent Ledesma
- worst fit - Clement Bowe
- creating tables - Vincent Ledesma 
- create report - Vincent Ledesma

Things completed by

- first fit - Clement Bowe
- next fit - Clement Bowe
- best fit - Vincent Ledesma
- worst fit - Clement Bowe
- creating tables - Vincent Ledesma 
- create report - Vincent Ledesma

Meeting Minutes 07/06/2022

Participants: 
Vincent Ledesma
Clement Bowe

18:32 Meeting start 
18:35 Cover cases where the head of the list is merged with another hole during release.
18:45 Right merge with the head of the list must relocate to the location of the potential bug spotted in request where the head is not 
    modified when an arbitrary request is made to allocate its location completely
18:57 Resolved by making sure that the previous value of head becomes the head of the list if there is another hole that exists.
    Note when merging the end of the block needs to be exactly block_start + new_size + 1 the end of the previous block is voided. 
19:10 Create four cases for handling the release of memory blocks
19:12 Release of a hole that merges with the left and right hole
19:36 Release of a hole that merges with the right hole
19:42 Release of a hole that merges with the left hole
19:55 Release of a hole that merges with no hole
20:05 Modulo function assuming the b value in a % b is positive returns the correct result.
20:30 Circling backwards using some modulo code you found on stackoverflow was probably not the best idea.
20:35 Once you find the next value you know essentially where your value is being inserted which allows you to still define a previous value
20:48 You don’t have to worry about the head messing up anything because this is a circular linked list so everything can have a previous and a next value. The 
    head is more for confirming that we have made a full circle around the linkedlist.
21:00 Had to add a modulo function to ensure that we get positive numbers when circling around the array backwards to find the previous pointer in the list
21:15 Meeting adjurned

Meeting Minutes 07/11/2022

Participants: 
Vincent Ledesma
Clement Bowe

20:00 Meeting Begins
20:01 Status updates on tasks
20:43 Begin cleaning up code and assessing for errors in assigned tasks
20:55 flip the negative number into a positive number
21:10 Next fit algorithm
21:50 Need to account for cases when a new hole is merged from the left of the head since the head is constantly moving
22:20 Best fit algorithm
22:30 Basically same as worstfit but changing the sign.
22:50 Created worstfit algorithm for filling holes
23:00 Iterates through each block and searches for the one with the largest number of memory space available
23:25 Begin compiling info for the reports
23:50 Meeting Adjurned
