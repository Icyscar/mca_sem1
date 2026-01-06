#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

// Convert infix ? postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;
    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isdigit(c)) { // operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // operator
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int stackEval[MAX];
    int i,topEval = -1;

    for (i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            stackEval[++topEval] = c - '0';  // convert char to int
        } else {
            int val2 = stackEval[topEval--];
            int val1 = stackEval[topEval--];

            switch (c) {
                case '+': stackEval[++topEval] = val1 + val2; break;
                case '-': stackEval[++topEval] = val1 - val2; break;
                case '*': stackEval[++topEval] = val1 * val2; break;
                case '/': stackEval[++topEval] = val1 / val2; break;
                case '^': stackEval[++topEval] = pow(val1, val2); break;
            }
        }
    }
    return stackEval[topEval];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (single-digit numbers only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated result: %d\n", result);

    return 0;
}

