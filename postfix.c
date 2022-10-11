#include "postfix.h"
#include "stack.h"

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) 
{
  struct double_stack * stack = double_stack_new(nargs);
  for (int i = 0; i < nargs; i++) 
  {
    char current = **(args + i);
    if (current >= '0' && current <= '9') 
    {
      int value = current - '0';
      double_stack_push(stack, value);
    }
    else 
    {
      double operandTwo = double_stack_pop(stack);
      double operandOne = double_stack_pop(stack);
      double result = 0;
      switch(current)
      {
        case '+':
          result = operandOne + operandTwo;
          break;
        case '-':
          result = operandOne - operandTwo;
          break;
        case 'X':
          result = operandOne * operandTwo;
          break;
        case '/':
          result = operandOne / operandTwo;
          break;
        case '^':
          break;
      }
      double_stack_push(stack, result);
    }
  }
  return double_stack_pop(stack);
}
