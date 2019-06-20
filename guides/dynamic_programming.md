# Dynamic Programming Guide

## TOP-DOWN DP

### FIBONACCI 

Let's write a function *fib* to compute the ith fibonacci #

```
We define the fibonacci sequence as:

BASE CASE
fib(0) = 1
fib(1) = 1

RECURRENCE (How a given problem can be solved by smaller problem(s))
fib(i) = fib(i-1) + fib(i-2), i >= 2
```

We can write this recursively in python:
```python 
def fib(i):
    if i == 0 or i == 1:
        return 1
    return fib(i-1) + fib(i-2)
```
### +Dynamic Programming

> If you read nothing else read this

It is easy to convert most recursive solutions to dynamic programming solutions. Do this:

- When you calculate a solution, store it for later
- When you try to solve something, check if it is already solved 


```python
# We'll store past solutions here 
dp = {}

def fib(i):
    # Load solution if we already have it
    if i in dp:
        return dp[i]

    if i == 0 or i == 1:
        return 1
    
    # Store solution for later
    dp[i] = fib(i-1) + fib(i-2)

    return dp[i]
```
*That's all.* 

You just learned dynamic programming   ***Pat yourself on the back***

>This particular method is called *Memoization*. It is referred to as 'top-down' DP, since we start with a large problem and break it down into smaller sub-problems ( i.e. To solve fib(3) we first solve fib(2) and fib(1) ) 

What makes memoization (and DP in general) special is that we only compute any particular thing once.   

*Below are the function calls made when we compute fib(6):*

#### WITHOUT DP
```
fib(6)
fib(5)
fib(4)
fib(3)
fib(2)
fib(1)
fib(0)
fib(1)
fib(2)
fib(1)
fib(0)
fib(3)
fib(2)
fib(1)
fib(0)
fib(1)
fib(4)
fib(3)
fib(2)
fib(1)
fib(0)
fib(1)
fib(2)
fib(1)
fib(0)

```


#### WITH DP
```
With DP:
fib(6)
fib(5)
fib(4)
fib(3)
fib(2)
fib(1)
fib(0)
fib(1) 
fib(2) 
fib(3) 
fib(4) 
```

Notice that when we hit a solution we have already seen we **DONT** need to expand it. We just load our existing solution.
```
With DP:
fib(6)
fib(5)
fib(4)
fib(3)
fib(2)
fib(1)
fib(0)
fib(1) *Loads old solution*
fib(2) *Loads old solution*
fib(3) *Loads old solution*
fib(4) *Loads old solution*
```
The end result is that this DP solution takes linear time. The non-dp solution, on the other hand, is exponential.

Despite it's simplicity memoization is a ridiculously powerful technique. Often you can get by just by writing a brute force approach and memoizing on part of the problem. Note that a dictionary is used in the example above but memoization is not limited to a particular data structure or language.

[Click for Sample Problem](https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem) 

</br> 
</br>
</br> 

## BOTTOM-UP DP

In top-down DP a problem is broken down into smaller sub-problems. 

With bottom-up we start with solutions to small problems and use them to solver larger problems.

The best way to learn is to solve a few problems yourself.

</br>

### FIBONACCI

```python
dp = [0]*N
dp[0], dp[1] = 0, 1 #Base case

for i in range(2, N):
    dp[i] = dp[i-1] + dp[i-2]
```

[Click for Sample Problem](https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem)
> Sample problems start out similar to the examples given in this document. They will start to diverge later on ☻

</br>

### STAIRCASE
A staircase is in front of you. You stand on the bottom (0th) step.
You can walk 1, 2, or 3 steps at a time. 

Let dp[i] be the number of ways to get to the nth step.
```python
dp = [0]*(n+1)
dp[0] = 1 # Base case

for i in range(n+1):
    for k in [1,2,3]:
        if i-k >= 0:
            dp[i] += dp[i-k]
```

[Click for Sample Problem](https://leetcode.com/problems/climbing-stairs/)

</br>

### KNAPSACK
You have a backpack that can hold at most N pounds. 

You are given a list of items S you can put in the backpack, each weighs S[i] pounds. 

Let dp[i] be the number of ways to fill up the backpack to i pounds; **you can use an item multiple times**.
```python
dp = [0]*(N+1)
dp[0] = 1

for k in S:
    for i in range(N+1):
        if i-k >= 0:
            dp[i] += dp[i-k]
```     
> Exercise #1: Why did we switch the order of the loops?

> Exercise #2: How can we change this to **only use each item once**?


[Click for Sample Problem](https://www.hackerrank.com/challenges/coin-change/problem)

</br> </br> </br>

## RECIPES

Adding DP to a recursive solution:
```python
    ## WITHOUT DP
    def foo(x):
        # implementation
        return result

    ## WITH DP
    dp = {}
    def foo(x):
        if x in dp: return dp[x]
        # implementation
        dp[x] = result
        return dp[x]
```

If you have multiple parameters you can do:
```python
    if (arg1, arg2) is in dp:
        return dp[(arg1, arg2)]
```

The hashtable lookup might be too slow for some problems. If your parameter is an integer you can do:

```python
    dp = [None] * MAX_SIZE
    def foo(x):
        if dp[x] != None: return dp[x]
        # implementation
        dp[x] = result
        return dp[x]
```
Still too slow? C++ is your friend
```c++
    int dp[MAX_SIZE]; // NOTE: When you set up an array in global scope the compiler will zero all the memory for you :)

    int foo(int x){
        if (dp[x]) return dp[x];
        // implementation
        return dp[x] = result;
    }
```
Often it can be convienent to use higher order arrays when dealing with multiple parameters in C++.
```c++
    int dp[MAX_X][MAX_Y][MAX_Z]; 

    int foo(int x, int y, int z){
        if (dp[x][y][z]) return dp[x][y][z];
        // implementation
        return dp[x][y][z] = result;
    }
```
Dealing with something that isn't an integer? Use a map.
```c++
    // This is implemented with Binary Search Trees -> Queries take O(lg N)
    map<string, int> dp; 

    int foo(x){
        if (dp.find(x) != dp.end()) return dp[x];
        // implementation
        return dp[x] = result;
    }
```
Better yet, use an unordered_map (but it better be hash-able!)
```c++
    // This is implemented with a Hash Table -> Queries take amortized O(1)
    unordered_map<string, int> dp;

    int foo(x){
        if (dp.find(x) != dp.end()) return dp[x];
        // implementation
        return dp[x] = result;
    }
```