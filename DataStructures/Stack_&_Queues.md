# Stacks and Queues

## [Queue](./queue_ll.cpp)

Singly linked list with a HEAD and TAIL. Can be made using two pointers in array but contstrained space.

## [Stack](./stack_ll.cpp)

Singly Linked list with HEAD. Can be made using array single pointer with contstrained space.

## [Deque](./dequeue.cpp)

Doubly Linked List with HEAD and TAIL.

## [Min Stack](./min_stack.cpp)

As we push a value into stack we actually keep two values the current value and associated minimum below it or it itself is the minimum. Getting minimum of stack then becomes as easy as checking second element of the top.

## [Min Queue](./min_queue.cpp)

Only the 2 Stack implementation is done in the file probably best but lengthy one.

### Deque implementation

- when inserting element at back keep on popping elements from back until one less than or equal to it is encountered or queue becomes empty.
- removing element requires checking if its the element you want to remove or we can even blindly remove the element

```cpp
// getting minimum
int minimum = q.front();

// adding elements
while (!q.empty() && q.back() > new_element)
    q.pop_back();
q.push_back(new_element);

// popping element
if (!q.empty() && q.front() == remove_element)
    q.pop_front();
```

### Counter based

we keep two counters one for `cnt_added` and one for `cnt_removed`

- when we add element also push the `cnt_added` with it while following the same procedure as 1st implementation of popping from back and then increase `cnt_added`.
- we we try to remove element check if the `cnt_removed` equals that of element if so remove it. and finally increase the `cnt_removed`

```cpp
// getting minimum
int minimum = q.front().f;

// adding elements
while (!q.empty() && q.back().f > new_element)
    q.pop_back();
q.push_back({new_element,cnt_added});
cnt_added++;

// popping element
if (!q.empty() && q.front().s == cnt_removed)
    q.pop_front();
cnt_removed++;
```

### 2 Stack

We keep two min stacks one we calling pushing stack and other one we call popping stack.

- we add element to the pushing stack just the same way we add to a min_stack
- when we want to remove element we remove it from popping stack if it isn't empty.
	- If it is empty then we move all the elements of pushing element into popping by inserting the **first** value into popping stack
	- We ensure min stack property of popping stack
- for getting minimum we take minimum of push and pop stack's minimums.

Front is also defined here as the first element of the top of pop stack if it isn't empty. else do the procedure we do to remove element.
Back is the top element of push stack if it isn't empty otherwise we can't get it it O(1) time.


```cpp
// push_stack and pop_stack are object of MinStack Class.
// min element
if(!pop_stack.empty() && !push_stack.empty())
  return min(pop_stack.minElement(),push_stack.minElement());
else
  return (pop_stack.empty() ? push_stack.minElement() : pop_stack.minElement());

// adding element
push_stack.push(x);

// removing element
if(pop_stack.empty()){
  while(!push_stack.empty()){
    auto [x,minx] = push_stack.top();
    push_stack.pop();
    pop_stack.push(x);
  }
}
pop_stack.pop();
```
