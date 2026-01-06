#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char opStack[MAX];		//Stack for operators
int topOp = -1;

void pushOp(char c) { opStack[++topOp] = c; }
char popOp() { return opStack[topOp--]; }
char peekOp() { return opStack[topOp]; }
int isEmptyOp() { return topOp == -1; }

int precedence(char c) 		//Operator precedence
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

void infixToPostfix(char infix[], char postfix[]) //Convert Infix ? Postfix
{
    int i, k = 0;
    char c;

    for (i = 0; infix[i]; i++) {
        c = infix[i];

        if (isdigit(c)) {
            postfix[k++] = c;   // operand goes directly
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (!isEmptyOp() && peekOp() != '(') {
                postfix[k++] = popOp();
            }
            popOp(); // remove '('
        }
        else { // operator
            while (!isEmptyOp() && precedence(peekOp()) >= precedence(c)) {
                postfix[k++] = popOp();
            }
            pushOp(c);
        }
    }

    while (!isEmptyOp()) {
        postfix[k++] = popOp();
    }
    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[])     //Evaluate Postfix
{
    int valStack[MAX];
    int i,topVal = -1;

    for (i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            valStack[++topVal] = c - '0';   // convert char to int
        }
        else {
            int val2 = valStack[topVal--];
            int val1 = valStack[topVal--];

            switch (c) {
                case '+': valStack[++topVal] = val1 + val2; break;
                case '-': valStack[++topVal] = val1 - val2; break;
                case '*': valStack[++topVal] = val1 * val2; break;
                case '/': valStack[++topVal] = val1 / val2; break;
                case '^': valStack[++topVal] = (int)pow(val1, val2); break;
            }
        }
    }
    return valStack[topVal];
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

