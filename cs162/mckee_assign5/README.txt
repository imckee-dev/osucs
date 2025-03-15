Hey Bruce Yan thank you for grading my assignment thank u for grading my prev assignments :3

*** USING 2 Grace Days for this one. The last two I have ***


1. Ian McKee ONID 934-424-206


2. There are two sections to this program. The first section allows you to input a staircase's length and we will display how 
many ways you can climb it using 1-, 2-, or 3- steps(If you are an expert at skipping stairs).

The second section tests a wide range of functionalities for a linked list, a standard data structure in code.
This test code and skeleton code was mostly written by 
the CS162 people but I added the functionalities here because yeah.

In each folder, if you're in your SSH in terminal, you can just type "make" and it'll create some object files.
After that to run, you can just type "./run" within the same file directory in terminal.

3. When you run with the steps in #2 above, for Part 1, you can input any number of steps you want and it'll output your result.

For Part 2, as do you the same, press enter within each printed function in the console to see each function being tested, starting with 
print, get_length and push_back.

4. Limitations: For the staircase problem After about 30 steps of a staircase it's just a lot of complex math and depending on your cpu
it could crash. So basically I wouldn't recommend entering something above 30+ there.

For part 2 we can judt see what is outputed here. The limitations are the enter key and different testing regions.
Another limitation is the descending part. The code is close and slighltly altered but as it is maintains the original list.Ascending should work though.


5. a. For ascending, I used the top down implementation, where we split the list recursively and compare. After the two sides are sorted, the merge function connects the whole list back together. Recurisvely as well

Runtime should be O(n*logn) complexity or linearithmic. The log part comes from the recursively splitting the original length by two over and over until we get a list of 1.
The n part comes from inputting those lists into our final list that is sorted.


b. For descending, same idea, as a), but with a different comparison factor <= instead of >= and push_front instead of push_back.
Runtime should be O(n*logn) complexity or linearithmic, for the same reason as above