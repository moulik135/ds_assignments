#include <bits/stdc++.h>
using namespace std;


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
       
        if (isalnum(ch)) {
            postfix += ch;
        }
       
        else if (ch == '(') {
            st.push(ch);
        }
       
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
     
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

  
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}