// 这个只是实现了一位数的加减乘除取余运算，而且还没有括号，和求出后缀表达是的方法
#include <iostream>
#include <stack>
using std::cin, std::cout, std::endl;
enum TokenType { LEFT_PARE, RIGHT_PARE, ADD, SUB, MUL, DIV, MOD, EOS, NUM };
char expr[] = "82/2+56*-";
TokenType getToken(char *symbol, int *index) {
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol) {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}
int eval(std::stack<char> &s) {
    char symbol;
    int op1, op2;
    int index = 0;
    TokenType token;
    token = getToken(&symbol, &index);
    int result;
    while (token != EOS) {
        if (token == NUM)
            s.push(symbol - '0');
        else {
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (token) {
            case ADD:
                s.push(op1 + op2);
                break;
            case SUB:
                s.push(op1 - op2);
                break;
            case MUL:
                s.push(op1 * op2);
                break;
            case DIV:
                s.push(op1 / op2);
                break;
            case MOD:
                s.push(op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getToken(&symbol, &index);
    }
    return s.top();
}
int main() {
    std::stack<char> s;
    std::cout << eval(s);
    return 0;
}