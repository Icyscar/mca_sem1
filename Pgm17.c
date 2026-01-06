#include <stdio.h>
#include <ctype.h>  // for isalnum()
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

void push(char c)		//push operation 
{
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() 			//pop operation
{
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() 		//peek operation
{
    if (top == -1)
        return -1;
    return stack[top];
}

int precedence(char op) 	//Function to return precedence of operators
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;  // exponent
    return 0;
}

void infixToPostfix(char* infix, char* postfix)  // Infix to Postfix conversion function
{
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand, add to postfix
        if (isalnum(c)) 
            postfix[k++] = c;
        // If '(', push to stack
        else if (c == '(')
            push(c);
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

