int main() {
    char expression[100];

    // Input the infix expression
    printf("Enter infix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character from input (if present)
    expression[strcspn(expression, "\n")] = 0;

    // Call function to convert infix to postfix
    infix_to_postfix(expression);

    return 0;
}

