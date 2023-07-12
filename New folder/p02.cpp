#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

const int MOD = 1000000007;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return (a + b) % MOD;
        case '-':
            return (a - b + MOD) % MOD;
        case '*':
            return ((long long)a * b) % MOD;
        case '/': {
            int inverse_b;
            for (int i = 1; i < MOD; i++) {
                if ((b * i) % MOD == 1) {
                    inverse_b = i;
                    break;
                }
            }
            return ((long long)a * inverse_b) % MOD;
        }
    }
    return 0;
}

int evaluateInfixExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;
    int len = expression.length();

    for (int i = 0; i < len; i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = (num * 10) + (expression[i] - '0');
                i++;
            }
            values.push(num % MOD);
            i--;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(val1, val2, op));
            }
            if (!operators.empty())
                operators.pop(); // Discard '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(val1, val2, op));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression;
    getline(cin, expression);
    int result = evaluateInfixExpression(expression);
    cout << result;
    return 0;
}
