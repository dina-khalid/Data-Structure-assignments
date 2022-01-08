# Submission of Codeforce div3 #479 and #478

## div3 #479

- #### Wrong subtraction
  - Here the problem was about a girl that decrease the number while the last digit is non-zero, else she divides by 10.
  - I used % expression to check that and do the subtraction.
- #### Two gram
  - The task was to find any two-gram contained in the given string as a substring a maximal number of times.
  - So, I looped over each character in the string and count the number of occurrences the char and its next repeated then store the two-gram if the number of occurrences is bigger than the last one.
- #### lessOrEqual
  - Given a sequence of integers of length n and integer number k. We should print an integer number x such that exactly k elements of the given sequence are less than or equal to x.
  - I sorted the given array then take the value of index k-1 as long as the number of element less then it is equal to k else print -1.

### Screen Shot for contest 1
![Screen_shot1](https://i.imgur.com/vsRIpZD.png)


## div3 #478

- #### A
  - We are given 3 votes and required to calculate how many votes each one needs to win.
  - I get the max number and print the differance+1 for each if it isn't = max else print 0.
- #### B
  - Get min number of digits removed to make the number dividable by 25.
  - I made a vector with the possible ends for a number to be dividable by 25, loop in the number with each end of them, detect the place of each digit of ends, calculate the number of digits to be removed store it as an array then choose the min number.
  - If the number is dividable by 25 in the first place returns 0.


### Screen Shot for contest 2
![Screen_shot2](https://i.imgur.com/d56viPk.png)
