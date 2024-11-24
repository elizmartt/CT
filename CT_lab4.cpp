#include <iostream>
#include <stack>
#include <string>

bool areBracesBalanced(const std::string& text) {
    std::stack<char> stack;

    for (char ch : text) {
        if (ch == '(' || ch == '{' ||  ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' ||  ch == '}' ||  ch == ']') {
            if (stack.empty())
            { return false;
            }
            char top = stack.top();
            stack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::string text;
    std::cout << "Enter an expression: ";
    std::cin >> text;

    if (areBracesBalanced(text)) {
        std::cout << "The braces are correct.--->true" << std::endl;
    }
    else {
        std::cout << "The braces are not correct.---->false" << std::endl;
    }

    return 0;
}