#include "infix.h"
#include "stack.h"
#include "string.h"
#include "postfix.h"

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

// function declarations
int is_operator(char* c);
int is_higher(char op, char cmp);
int top_is_op(char* c);

double evaluate_infix_expression(char ** args, int nargs) 
{
  struct double_stack * stack = double_stack_new(nargs);
  char* output = malloc(2000 * sizeof(char));
  

  for (int i = 0; i < nargs; i++)
  {
    char* token = *(args + i);
    fprintf(stderr, "token %d=%s\n", i, token);
    int value = atoi(token);
    if (value != 0)
    {
      output = strcat(output, token);
    }
    else if (*token == '(')
    {
      double_stack_push(stack, i);
    }
    else if (is_operator(token))
    {
      double* stack_items = stack->items;
      int* stack_top = &stack->top;
      fprintf(stderr, "%s\n", *(args + (int) *(stack_items + *stack_top - 1)));
      while(is_operator(*(args + (int) *(stack_items + *stack_top - 1))) && is_higher(**(args + (int) *(stack_items + *stack_top - 1)), *token))
      {
        int index = (int) double_stack_pop(stack);
        output = strcat(output, *(args + index));
      }
      double_stack_push(stack, i);
    }
    else if (*token == ')')
    {
      double* stack_items = stack->items;
      int* stack_top = &stack->top;
      while(strcmp(*(args + (int) *(stack_items + *stack_top - 1)), "(") != 0)
      {
        int index = (int) double_stack_pop(stack);
        output = strcat(output, *(args + index));
        fprintf(stderr, "stack top = %d\n", *stack_top);
        fprintf(stderr, "output = %s\n", output);
      }
      double_stack_pop(stack);
    }
  }
  
  for (int i = stack->top; i > 0; i--)
  {
    int index = (int) double_stack_pop(stack);
    output = strcat(output, *(args + index));
  }
  return 0.0;
}

int is_operator(char* c)
{
  if (*c == '+' || *c == '-' || *c == 'X' || *c == '/' || *c == '^')
  {
    return 1;
  }

  return 0;
}

int is_higher(char op, char cmp)
{
  if (op == cmp)
  {
    return 1;
  }
  else if (op == '^')
  {
    return 1;
  }
  else if (cmp == '^')
  {
    return 0;
  }
  else if ((op == 'X' && cmp == '\\') || (op == '\\' && cmp == 'X'))
  {
    return 1;
  }
  else if ((op == '+' && cmp == '-') || (op == '+' && cmp == '-'))
  {
    return 1;
  }
  else if ((op == 'X' || op == '\\') && (cmp == '+' || cmp == '-'))
  {
    return 1;
  }
  return 0;
}