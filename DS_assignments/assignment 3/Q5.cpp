#include <iostream>
using namespace std;

int main() {
    char postfix[100];
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int stack[100]; 
    int top = -1;     

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If digit, push it
        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0'; 
        }
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];  
            int result;

            if (ch == '+') result = val1 + val2;
            else if (ch == '-') result = val1 - val2;
            else if (ch == '*') result = val1 * val2;
            else if (ch == '/') result = val1 / val2;

            stack[++top] = result;  
        }
    }

    cout << "Result = " << stack[top] << endl;
    return 0;
}