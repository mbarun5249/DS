#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

bool isValid(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            stack[++top] = '(';
        }
        else if (s[i] == ')')
        {
            if (top == -1 || stack[top] != '(')
                return false;
            top--;
        }
        else if (s[i] == '{')
        {
            stack[++top] = '{';
        }
        else if (s[i] == '}')
        {
            if (top == -1 || stack[top] != '{')
                return false;
            top--;
        }
        else if (s[i] == '[')
        {
            stack[++top] = '[';
        }
        else if (s[i] == ']')
        {
            if (top == -1 || stack[top] != '[')
                return false;
            top--;
        }
    }

    return top == -1;
}

int main()
{
    char s[10000];

    printf("Enter brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
