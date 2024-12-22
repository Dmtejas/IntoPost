void infix_to_postfix(char *expression) {
    int n;
    printf("Enter the size of the stack\n");
    scanf("%d",&n);
    char stack[n];  // Stack to hold operators
    int top = -1;     // Stack pointer
    char result[100]; // Array to store the postfix expression
    int j = 0;        // Result array pointer

    // Iterate over the expression
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If the character is an operand, add it to the result
        if (isalnum(ch)) {
            result[j++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            stack[++top] = ch;
        }
        // If the character is ')', pop from the stack to result until '(' is found
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--;  // Pop '('
        }
        else if (ch == ' ') {
            continue;
        }
        // If the character is an operator, handle operator precedence
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                result[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0'; // Null-terminate the result string

    // Print the postfix expression
    printf("Postfix expression: %s\n", result);
}

