#include <iostream>
#include <string>
#include <stack>

using namespace std;

int stack_principle(const string& str) {
    stack<int> parenthesesStack;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            parenthesesStack.push(i);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (parenthesesStack.empty()) {
                return false;
            }

            int topIndex = parenthesesStack.top();
            parenthesesStack.pop();

            if ((str[i] == ')' && str[topIndex] != '(') ||
                (str[i] == ']' && str[topIndex] != '[') ||
                (str[i] == '}' && str[topIndex] != '{')) {
                return false;
            }
        }
    }

    return parenthesesStack.empty();
}

int main() {

    string str;
    cout << "Enter a str: ";
    getline(cin, str);


    if (stack_principle(str)) {
        cout << "correct" << endl;
    }
    else {
        cout << "incorrect" << endl;
    }

    cout << int{'{'}; // index check

    system("pause");
    return 0;
};
