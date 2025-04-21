//*后缀（逆波兰）表示法
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

// 函数用于分割字符串
std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// 函数用于计算逆波兰表达式的值
int evaluateRPN(const std::string &expression)
{
    std::stack<int> stack;
    std::vector<std::string> tokens = split(expression, ' ');

    for (const std::string &token : tokens)
    {
        if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])))
        {
            // 如果是操作数，将其转换为整数并入栈
            stack.push(std::stoi(token));
        }
        else
        {
            // 如果是运算符，从栈中弹出两个操作数进行计算
            int rightOperand = stack.top();
            stack.pop();
            int leftOperand = stack.top();
            stack.pop();

            if (token == "+")
            {
                stack.push(leftOperand + rightOperand);
            }
            else if (token == "-")
            {
                stack.push(leftOperand - rightOperand);
            }
            else if (token == "*")
            {
                stack.push(leftOperand * rightOperand);
            }
            else if (token == "/")
            {
                stack.push(leftOperand / rightOperand);
            }
        }
    }

    return stack.top();
}

int main()
{
    std::string expression = "3 4 + 2 *";
    int result = evaluateRPN(expression);
    std::cout << "后缀表达式 " << expression << " 的值为: " << result << std::endl;
    return 0;
}
