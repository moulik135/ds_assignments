#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    reverse(s.begin(), s.end());
    cout << "Reversed string: " << s << endl;
    return 0;
}
