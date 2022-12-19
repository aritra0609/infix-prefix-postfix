#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char *stack[SIZE];
int top = -1;
void push(char* str)
{
    stack[++top]=(char*)malloc(SIZE*sizeof(char));
    strcpy(stack[top],str);
}

void pop(char* res)
{
    strcpy(res,stack[top--]);
    
}
void main()
{
    char postfix[SIZE],ch,op1[SIZE],op2[SIZE];
    int i = 0;
    printf("\nPostfix Expression :");
    scanf("%s", postfix);
    while ((ch = postfix[i++]) != '\0')
    {
        if (isalpha(ch))
        {
            char buffer[]={ch,'\0'};
            push(buffer);
        }
        else
        {
            char buffer[]={ch,'\0'};
            char buffer1[SIZE]={'(','\0'};
            char buffer2[SIZE]={')','\0'};
            pop(op2);
            pop(op1);
            strcat(buffer1,op1);
            strcat(buffer1,buffer);
            strcat(buffer1,op2);
            strcat(buffer1,buffer2);
            push(buffer1);
        }
    }
    printf("\n Infix : %s\n",stack[top]);
}

