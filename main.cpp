#include <iostream>
#include <string>
#include <stack>

using namespace std;

int stack_principle(const string& str, string& fixedStr) {
    stack<int> parenthesesStack;
    fixedStr = str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            parenthesesStack.push(i);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (parenthesesStack.empty()) {
                fixedStr.insert(i, "(");
                return i;
            }

            int topIndex = parenthesesStack.top();
            parenthesesStack.pop();

            if ((str[i] == ')' && str[topIndex] != '(') ||
                (str[i] == ']' && str[topIndex] != '[') ||
                (str[i] == '}' && str[topIndex] != '{')) {
                fixedStr.insert(i, string(1, str[topIndex]));
                return i;
            }
        }
    }

    while (!parenthesesStack.empty()) {
        int openIndex = parenthesesStack.top();
        parenthesesStack.pop();

        if (str[openIndex] == '(') {
            fixedStr += ')';
        }
        else if (str[openIndex] == '[') {
            fixedStr += ']';
        }
        else if (str[openIndex] == '{') {
            fixedStr += '}';
        }
    }

    return -1;
}

int main() {
    string str;
    cout << "Enter a str: ";
    getline(cin, str);

    string fixedStr;
    int result = stack_principle(str, fixedStr);

    if (result == -1) {
        cout << "correct" << endl;
    }
    else {
        cout << "incorrect at index: " << result << endl;
        cout << "correct format: " << fixedStr << endl;
    }

    system("pause");
    return 0;
}