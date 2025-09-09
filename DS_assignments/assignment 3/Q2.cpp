#include <iostream>
#include <stack>   
using namespace std;

int main() {
    string str = "DataStructure";  
    stack<char> st;                

    
    for (char ch : str) {
        st.push(ch);
    }

    
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();  
        st.pop();              
    }

    // Output the reversed string
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}