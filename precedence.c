int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
void print() {
   printf("Postfix Expression : %s\n",postfix);
   return;
}

