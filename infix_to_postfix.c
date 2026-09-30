#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item)
{
    if (top == MAX - 1)
        printf("Stack is full\n");
    else
    {
        top++;
        stack[top] = item;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

int main()
{
    int i = 0, j = 0;
    char infix[100], postfix[100];
    char symbol;
    printf("Enter the Infix expression: ");
    scanf("%s", infix);
    while (infix[i] != '\0')
    {
        symbol = infix[i];

        if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(')
                pop();
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("The Postfix expression is: %s", postfix);
    return 0;
}
