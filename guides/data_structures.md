# Stacks, Queues and Basic Search

<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Balanced Parenthesis and Stacks</a></li>
<li><a href="#sec-2">2. Queues</a></li>
<li><a href="#sec-3">3. Search Trees</a>
<ul>
<li><a href="#sec-3-1">3.1. Examples</a>
<ul>
<li><a href="#sec-3-1-1">3.1.1. n Queens</a></li>
<li><a href="#sec-3-1-2">3.1.2. Knight Cover</a></li>
</ul>
</li>
</ul>
</li>
<li><a href="#sec-4">4. Practice Problems</a></li>
</ul>
</div>
</div>

# Balanced Parenthesis and Stacks

A common problem in parsing expressions is to check whether it has
the right amount of parenthesis. Consider the following mathematical
expression:

2 + ((3 + 4) \* 8)

We say that the expression is "well-formed" because it is valid, 
and the parenthesis are balanced. Contrast with the following:

2 + (3 + (4 \* 8)

In this case, the expression is missing one trailing parenthesis.

To check if an expression has balanced parenthesis, we can use a
Stack data structure, which implements a "Last-in, First-out" (LIFO)
policy. The stack has two fundamental operations:
1.  Push - Add an element to the top of the stack
2.  Pop  - Remove an element from the top of the stack

We can simplify the problem to deal only with parenthesis (after all,
we can ignore non-bracket characters). The algorithm is simple:

1.  Initialize a stack of characters
2.  Traverse the input string. There are two types of brackets we deal with:
    (a) If it is a opening bracket, push to the stack
    (b) If it is a closing bracket, pop from the stack if there is a matching
        opening bracket, otherwise the parenthesis are inbalanced
3.  After traversal, check for an empty stack. If it is non-empty then it is
inbalanced.

```python
stack = []
s = raw_input()
ok = True
for c in s:
      if c == '(': 
          stack.append(c) # This is the "Push" operation!
      elif c == ')' and len(stack) > 0 and stack[-1] == '(':
          stack.pop()
      else:
          ok = False
          break
if not ok or len(stack) > 0:
    print "inbalanced"
else:
    print "balanced"
```
		
Note that we can modify this code to deal with multiple types of
parenthesis.

We've used an ordinary list to represent our stack here; We can do a
similar thing in C++ using vectors:

```cpp
#include <vector>
vector<int> A;
A.push_back(1); // enqueue
A.back(); // get the last element in the array
A.pop_back();  // dequeue
```

More information on C++ vectors can be found [here](https://en.cppreference.com/w/cpp/container/vector)

# Queues

The queue data structure can be intuitively thought of as queues IRL- we have
a line of people waiting to buy something, for example. We can think of this
as a "First-in, First-out" (FIFO) principle- objects that enter the queue first
are also the first to be removed.

Similar to stacks, queues also have two fundamental operations:
1.  enqueue - Add an element to the back of the queue.
2.  dequeue - Remove an element from the front of the queue.

We can see how these two operations enforce the FIFO policy: Elements enter 
at the tail of the queue via enqueue, while elements are processed from first-to-last 
with dequeue.

# Search Trees

A fundametal problem solving paradigm in competitive programming is the technique
of Complete Search, a.k.a "Brute-Force". The latter name comes from the nature of
how the algorithm of such a solution works: it usually tries every possible 
combination of a potential answer and checks if it works. In the heart of the 
search, stacks and queues are usually used to guide the search path (though usually
recursion is used instead of an explicitly declared stack, but both are equal).

## Examples

### n Queens

Problem: Place n queens on an n x n chess board so that no queen is attacked by
another queen.

Solution: Depth First Search (DFS)
There is an easy recursive solution to this: We add queens on the board
one by one, trying all possible placements, and observe that there must be exactly
one queen on each column. A pseudocode implementation can be done:

```
    def search(col):
        if filled all columns:
            print solution and exit
        for each row:
            if board(row,col) not attacked:
                place queen at (row,col)
                search(col+1)
                remove queen at (row,col)
```

Exercise 1: Implement the above pseudocode.
Exercise 2: Solve the same problem, but instead of recursion, use a stack. Hint:
  Placing a queen can be thought of as "pushing" to the stack, and removing as
  "popping" from the stack.

### Knight Cover

Problem: Place as few knights as possible on an n × n chessboard so that every square
is attacked. A knight is not considered to attack the square it sits on.

Solution: Breadth First Search (BFS)
Here, we want to try all solutions with *k* knights before *k+1* knights. 
We call this breadth first search, because we cover the entire row of the
current search row (i.e. the one with *k* knights) before moving to the next row.
Contrast with the n Queens problem, in which the recursion will search until
the end before it begins to backtrack.

To implement BFS, we use a queue to store the states visited:

```
    def process(state):
        for each possible next state:
            enqueue(next state)
    def search():
        while !empty(queue):
            state = dequeue(queue)
            process(state)
```
			
Exercise: Implement the knight cover solution. Your answer should terminate and return the
fewest knights required. You can assume n = 8.

Hint: To check which states to enqueue next, write a checker function that takes a current
chessboard state as an argument and returns the list of possible positions for potential
knight placements.

Since there hasn't been an explicit implementation of queues, here are some code
fragments in Python (or C++) to guide you on your path:

```python
import Queue
    
q = Queue.Queue()

# enqueue some items
for i in range(4):
    q.put((i,i+1))
    
# dequeue items
while not q.empty():
    print q.get()
```


```cpp
#include <queue>

queue<int> q;

// enqueue
q.push(3);
// get the front item of the queue
q.front();
// remove the first item of the queue
q.pop();
```

More information on C++ queues can be found [here](https://en.cppreference.com/w/cpp/container/queue)

# Practice Problems

-   Stacks: <https://www.hackerrank.com/challenges/largest-rectangle/problem>
-   Search: <https://www.hackerrank.com/challenges/knightl-on-chessboard/problem?h_r=next-challenge&h_v=legacy>
-   More Search: <http://codeforces.com/problemset/problem/514/B>
