#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Stack {
private:
    stack<char> s;
public:
    void push(char c) { s.push(c); }
    char pop() { char c = s.top(); s.pop(); return c; }
    char top() { return s.top(); }
    bool isEmpty() { return s.empty(); }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string expression) {
    Stack s;
    string output;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        if (isalnum(ch)) {
            output += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                output += s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.top()) >= precedence(ch)) {
                output += s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.isEmpty()) {
        output += s.pop();
    }
    
    return output;
}

int main() {
    string expression;
    cout << "Masukkan ekspresi infix: ";
    cin >> expression;
    cout << "Postfix: " << infixToPostfix(expression) << endl;
    return 0;
}
