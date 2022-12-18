#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
int precedence(char s)
{
    switch (s)
    {
        case ')':
            return 0;
            break;
        case '(':
            return 1;
            break;
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
    }
}
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return (stack[top--]);
}
void main()
{
    char infix[100], postfix[100], c;
    int i = 0, k = 0;
    printf("infix : ");
    scanf("%s", infix);
    push('(');
    while ((c = infix[i++]) != '\0')
    {
        if (c == '(')
            push(c);
        else if (isalnum(c))
            postfix[k++] = c;
        else if (c == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(c);
        }
        else
        {
            while (precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (stack[top] != '(')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("\npostfix : %s\n", postfix);
}
