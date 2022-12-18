#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50 
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
char stack[SIZE];
int top=-1; 
int precedence(char s)
{                
	switch (s)
    {
        case '(':
            return 0;
            break;
        case ')':
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
    stack[++top]=c;
}
char pop()
{                      
    return(stack[top--]);
}
void main()
{                        
    char infix[100],prefix[100],c;
    int i=0,k=0;
    printf("infix : ");
    scanf("%s",infix);
    reverse(infix);
    push(')');
    while((c=infix[i++])!='\0')
    {
        if( c == ')') 
            push(c);
        else
            if(isalnum(c)) 
                prefix[k++]=c;
            else
                if( c == '(')
                {
                    while( stack[top] != ')')
                        prefix[k++]=pop();
                    pop(c); 
                }
                else
                {       
                    while( precedence(stack[top]) > precedence(c) )
                        prefix[k++]=pop();
                    push(c);
                }
    }
    while( stack[top] != ')')     
        prefix[k++]=pop();
    prefix[k]='\0';   
    reverse(prefix);
    printf("\nprefix : %s\n",prefix);
}
