int longestValidParentheses(char* s) {

    int stack[30005];
    int top = -1;

    // Starting boundary
    stack[++top] = -1;

    int maxLen = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '(') {
            // Store index of '('
            stack[++top] = i;
        }
        else {
            // Remove matching '('
            top--;

            if (top == -1) {
                // No valid starting point
                stack[++top] = i;
            }
            else {
                // Length of valid substring
                int len = i - stack[top];

                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}