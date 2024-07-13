# Expression Notation

There are primarily three kinds of expression notations:
- infix
- prefix (polish)
- postfix (reverse polish)

While infix finds its use in regular human day to day analysis, polish notations are used in compiler grammars for unambiguous analysis of expression used in formal logic and computer-assisted theory proving.

## Infix

Our day to day used expression:
```python
2 + 3 - 4
2 + 3 * (4 - 5)
```

We can check for validity of infix expression's bracket using stack by pushing opening ones and popping closing ones with opening.

## Postfix

The operator comes after the operands
```python
2 3 + 4 -
```

To check validity of a postfix expression we will again use stack.
- push numbers onto stack
- if operator then pop top 2 operands perform operation and push back the result
- last item left on stack is the result

### Conversion from infix
- Scan infix from left to right.
- if operand then append to our resulting string
- if operator, pop operators from the stack and append them to the output string until:
  - the stack is empty
  - top of stack is opening parenthesis
  - precedence of the current operator is lower than the top of the stack
- push operator onto the stack
- if opening parenthesis push it onto the stack
- if closing parenthesis keep popping until opening parenthesis and append all operators to string
- pop remaining operators and append to string

### Convert to infix
- evaluate from left to right
- operand push onto stack
- operator pop last 2 add them to parenthesis and push back on the stack

## Prefix

The operator comes before operands
```python
- 4 + 3 2
```

To check its validity we can just reverse the string and run postfix validation method.

### Conversion from infix
- Reverse the infix expression.
- Convert the reversed infix expression to postfix notation using the postfix conversion algorithm.
- Reverse the resulting postfix expression to obtain the prefix notation.

### Convert to infix
- read from right to left
- add operands to stack
- if operator pop 2 from stack add parenthesis and add to the stack
- final expression in the stack
