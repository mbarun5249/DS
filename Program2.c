#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;
    int expectOperand = 1;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            if (!expectOperand)
                return 0;

            postfix[j++] = c;
            expectOperand = 0;
        }
        else if (c == '(')
        {
            if (!expectOperand)
                return 0;

            push(c);
        }
        else if (c == ')')
        {
            if (expectOperand)
                return 0;

            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top == -1)
                return 0;

            pop();
            expectOperand = 0;
        }
        else if (isOperator(c))
        {
            if (expectOperand)
                return 0;

            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && c != '^')))
            {
                postfix[j++] = pop();
            }

            push(c);
            expectOperand = 1;
        }
        else
        {
            return 0;
        }
    }

    if (expectOperand)
        return 0;

    while (top != -1)
    {
        if (stack[top] == '(')
            return 0;

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return 1;
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    if (infixToPostfix(infix, postfix))
        printf("Postfix expression: %s\n", postfix);
    else
        printf("Invalid expression\n");

    return 0;
}
