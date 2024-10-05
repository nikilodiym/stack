#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Stack {
private:
    T* stackArray;
    int top;
    int capacity;

public:
    Stack(int size = 10) {
        stackArray = new T[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(T value) {
        if (top == capacity - 1) {
            cout << "Stack overflow";
            return;
        }
        stackArray[++top] = value;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty";
            return T();
        }
        return stackArray[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    friend ostream& operator<<(ostream& os, const Stack& s) {
        if (s.top == -1) {
            os << "Stack is empty";
        }
        else {
            os << "Stack elements: [";
            for (int i = 0; i <= s.top; ++i) {
                os << s.stackArray[i];
                if (i != s.top) os << ", ";
            }
            os << "]";
        }
        return os;
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    cout << "Pushed 10" << endl;
    stack.push(20);
    cout << "Pushed 20" << endl;
    stack.push(30);
    cout << "Pushed 30" << endl;
    cout << stack << endl;
    stack.pop();
    cout << stack << endl;

    system("pause");
    return 0;
}