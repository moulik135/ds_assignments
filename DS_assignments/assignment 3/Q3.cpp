#include <iostream>
using namespace std;

int main() {
    char expr[100];  
    cout << "Enter an expression: ";
    cin >> expr;

    char stack[100];  
    int top = -1;     
    int balanced = 1;

   
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

       
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
       
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { 
                balanced = 0;
                break;
            }
            char open = stack[top--]; 
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                balanced = 0;
                break;
            }
        }
    }

    
    if (top != -1) balanced = 0;

  
    if (balanced == 1)
        cout << "Balanced Expression" << endl;
    else
        cout << "Not Balanced Expression" << endl;

    return 0;
}