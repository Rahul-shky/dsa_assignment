# Q.1 Write a program to check if any given mathematical expression has balanced number of paranthesis or not?

# Data Structure
A constant value called 'MAX' has been defined and assigned a value of 20. Then, three integer variable called 'paranthesisCount', 'curlyParanthesisCount' and 'bigParanthesisCount' has been declared that counts the paranthesis in the mathematical expression. A stack has been created of type char that stores characters and all the functions needed for the stack like isFull(), isEmpty(), push(), pop(), display() has been defined.

# Functions:
## 1. push():
In push() function, we check if any paranthsis has been pushed. If any paranthesis has been found then we increase the respective count by 1.

## 2. checkParanthesis():
 We have defined a checkParanthesis() function that checks if the mathematical expression has balanced number of paranthesis. To check if the paranthesis is balaned, we check if the paranthesis count is even or odd. If the paranthesis count is even then the paranthesis is balanced else the paranthesis is not balanced.

 # In main():
Inside, the main() we have defined a string called test that stores the mathematical expression. Then, a for loop is used to push the expression. The loop runs till a null value has been found in the array. Then a display() function is called to check the values stored in stack and checkParanthesis() function is called to check if the mathematical expression have balanced number of paranthesis.

# Output:
![alt text](./output_img/prog_1.png)