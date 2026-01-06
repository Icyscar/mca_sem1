#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 25

char stack[MAX];
int top = -1;

// stack functions
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}
int isEmpty() {
    return top == -1;
}

// precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// reverse a string and swap parentheses
void reverse(char* exp) {
    int n = strlen(exp);
    int i;
    for (i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
    for (i = 0; i < n; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

// convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
	int i,k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else { // operator
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty())
        postfix[k++] = pop();
    postfix[k] = '\0';
}

// convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    char postfix[MAX];
    reverse(infix);
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}

