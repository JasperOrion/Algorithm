// 实现了中缀表达式转换为后缀表达式以及后缀表达式的计算
// 但没有实现负数的计算,该计算仅仅只对>=0的数有效
#include <cctype> // 用于字符类型判断
#include <iostream>
#include <map> // 用于运算符优先级映射
#include <stack>
#include <string>
#include <vector>

// 运算符的优先级映射表
const std::map<char, int> precedence = {
    {'+', 1}, {'-', 1},           // 加减优先级较低
    {'*', 2}, {'/', 2}, {'%', 2}, // 乘除模优先级较高
    {'(', 0}                      // 左括号优先级最低
};
// 中缀表达式转后缀表达式
std::vector<std::string> infixToPostfix(const std::string &infix) {
    std::stack<char> opStack;         // 运算符栈
    std::vector<std::string> postfix; // 后缀表达式结果
    std::string currentNum;
    int length = infix.length();
    for (size_t i = 0; i < length; ++i) {
        char c = infix[i];
        // 处理多余空格
        if (c == ' ')
            continue;
        if (std::isdigit(c)) {
            currentNum += c;
            if (i + 1 < length && std::isdigit(infix[i + 1]))
                continue;
            postfix.push_back(currentNum);
            currentNum = "";
        } else if (c == '(') {
            // 处理(
            opStack.push(c);
        } else if (c == ')') {
            // 处理括号内的运算符
            while (!opStack.empty() && opStack.top() != '(') {
                postfix.push_back(std::string(1, opStack.top()));
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(')
                opStack.pop();
        } else {
            // 当前运算符优先级<=栈顶运算符优先级时,出栈
            while (!opStack.empty() &&
                   precedence.at(opStack.top()) >= precedence.at(c)) {
                postfix.push_back(std::string(1, opStack.top()));
                opStack.pop();
            }
            // 当前运算符入栈
            opStack.push(c);
        }
    }
    // 弹出剩余的运算符
    while (!opStack.empty()) {
        postfix.push_back(std::string(1, opStack.top()));
        opStack.pop();
    }
    return postfix;
}

//*计算后缀表达式
int evaluatePostfix(const std::vector<std::string> &postfix) {
    std::stack<int> operandStack;
    int rightOperand, leftOperand;
    for (const auto &token : postfix) {
        // isdigit()只能判断'0'~'9'
        if (std::isdigit(token[0]))
            operandStack.push(std::stoi(token));
        else {
            rightOperand = operandStack.top();
            operandStack.pop();
            leftOperand = operandStack.top();
            operandStack.pop();
            switch (token[0]) {
            case '+':
                operandStack.push(leftOperand + rightOperand);
                break;
            case '-':
                operandStack.push(leftOperand - rightOperand);
                break;
            case '*':
                operandStack.push(leftOperand * rightOperand);
                break;
            case '/':
                operandStack.push(leftOperand / rightOperand);
                break;
            case '%':
                operandStack.push(leftOperand % rightOperand);
                break;
            default:
                break;
            }
        }
    }
    return operandStack.top();
}
void test() {
    std::cout << "请输入中缀表达式,例如: \n";
    std::cout << "中缀: 2 + 3 \n";
    std::cout << "后缀: 2 3 + \n结果: 5" << std::endl;
    std::cout << "中缀: 3 + 4 * 5 \n";
    std::cout << "后缀: 3 4 5 * + \n结果: 23" << std::endl;
    std::cout << "中缀: (3 + 4) * 5 \n";
    std::cout << "后缀: 3 4 + 5 * \n结果: 35" << std::endl;
    std::cout << "中缀: 8 / (2 * (1 + 1)) \n";
    std::cout << "后缀: 8 2 1 1 + * / \n结果: 2" << std::endl;
    std::cout << "中缀: 10 - 3 * 2 + 8 / 4 \n";
    std::cout << "后缀: 10 3 2 * - 8 4 / + \n结果: 6" << std::endl;
    std::cout << "中缀: 15 % 4 * 3 + 2 \n";
    std::cout << "后缀: 15 4 % 3 * 2 + \n结果: 11" << std::endl;
    std::cout << "中缀: (20 - (3 * 4)) / (2 + 2) * 5 \n";
    std::cout << "后缀: 20 3 4 * - 2 2 + / 5 * \n结果: 10" << std::endl;
    std::cout << "中缀: 10 + (20 * 3 - 5) % 7 / 2 \n";
    std::cout << "后缀: 10 20 3 * 5 - 7 % 2 / + \n结果: 13" << std::endl;
}
int main() {
    // 输入中缀表达式
    std::string infix;
    test();
    std::cout << "\n输入: ";
    std::getline(std::cin, infix);
    // 转换为后缀表达式
    std::vector<std::string> postfix = infixToPostfix(infix);
    // 打印后缀表达式
    std::cout << "后缀表达式: ";
    for (const auto &token : postfix) {
        std::cout << token << " ";
    }
    std::cout << "\n";
    // 计算并输出结果
    int result = evaluatePostfix(postfix);
    std::cout << "计算结果: " << result << std::endl;

    return 0;
}