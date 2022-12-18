#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
void reverse(char *s)
{
    int size=strlen(s)-1;
    int k;
    char temp;
    for(k=0;k<strlen(s)/2;k++){
        temp=s[k];
        s[k]=s[size];
        s[size--]=temp;
    }        
}

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
    char prefix[SIZE], ch;
    int i = 0, k = 0, op1, op2, n;
    printf("\nPrefix Expression :");
    scanf("%s", prefix);
    reverse(prefix);
    while ((ch = prefix[i++]) != '\0')
    {
        if (isalpha(ch))
        {
            printf("Enter the value of %c: ", ch);
            scanf("%d", &n);
            push(n);
        }
        else
        {
            op1 = pop();
            op2 = pop();
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
    printf("\n Prefix evaluation : %d\n", stack[top]);
}
