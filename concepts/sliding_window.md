Sliding window:


Make a window.
Maintain the window.
Expand or contract according to the conditions.


Sliding window is a subset of input data structure.
We loop over that data structure (array and string) and make a window .
 this window size adjusted  dynamically according to conditions. 

Maintain then expand or contract.


----:Steps:----

-initialize two pointers left and right .
(right pointer is a moving pointer and left moves when certain conditions met.)

-we expand the window  moving right 

-Do actions.

-If a condition is met we shrink the window by moving left.

-we keep track of best solutions (length, sum, etc)