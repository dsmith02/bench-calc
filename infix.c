#include "infix.h"
#include "stack.h"

/*
for each token in the input string {
  if ( token is a number ) {
    append token to the output string
  }
  else if (token is a left bracket) {
    push bracket to stack
  }
  else if ( token in an operator ) {
    while ( there is operator  op  on top of the stack  AND op has equal or higher precedence than token ) {
      pop stack and append op to the output string
    }
    push token operator to stack
  }
  else if ( token is right bracket ) {
    while ( top of stack != left bracket ) {
      pop operator from stack and append to output string
    pop left bracket
  }
}
*/
// evaluate expression stored as an array of string tokens

// ^ = 0
// X = 1
// / = 2
// + = 3
// - = 4
// ( = 5
double evaluate_infix_expression(char ** args, int nargs) 
{
  struct double_stack * stack = double_stack_new(nargs);
  char* output;
  for (int i = 0; i < nargs; i++)
  {
    char * current = *(args[i]);
    if (current >= '0' && current <= '9')
    {
      output = output + *(args[i]);
    }
    else if (current == '(')
    {
      double_stack_push(stack, 0);
    }
    else if (is_operator(current))
    {

    }
  }
}

// Determines if a character is an operator
int is_operator(char * c)
{
  if (c == '+' || c == '-' || c == 'X' || c == '\\' || c == '^')
  {
    return 1;
  }
  return 0;
}
