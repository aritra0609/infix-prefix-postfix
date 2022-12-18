#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    return (stack[top--]);
}
void main()
{
    char postfix[SIZE], ch;
    int i = 0, k = 0, op1, op2, n;
    printf("\nPostfix Expression :");
    scanf("%s", postfix);
    while ((ch = postfix[i++]) != '\0')
    {
        if (isalpha(ch))
        {
            printf("Enter the value of %c: ", ch);
            scanf("%d", &n);
            push(n);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '%':
                push(op1 % op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            }
        }
    }
    printf("\n Postfix evaluation : %d\n", stack[top]);
}
