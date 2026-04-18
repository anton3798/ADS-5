// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include <cctype>

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
          return 1;
        case '*':
        case '/':
          return 2;
        default:
          return 0;
    }
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> operators;
    std::string postfix;
    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];
        if (isdigit(c)) {
            while (i < inf.length() && isdigit(inf[i])) {
                postfix += inf[i];
                ++i;
            }
            postfix += ' ';
            --i;
            continue;
        }
        switch (c) {
            case '(':
                operators.push(c);
                break;
            case ')':
                while (!operators.isEmpty() && operators.top() != '(') {
                    postfix += operators.pop();
                    postfix += ' ';
                }
                if (!operators.isEmpty())
                  operators.pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!operators.isEmpty() && operators.top() != '(' &&
                       getPriority(operators.top()) >= getPriority(c)) {
                    postfix += operators.pop();
                    postfix += ' ';
                }
                operators.push(c);
                break;
            default:
                break;
        }
    }
    while (!operators.isEmpty()) {
        postfix += operators.pop();
        postfix += ' ';
    }
    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }
    return postfix;
}

int eval(const std::string& pref) {
  TStack<int, 100> numbers;

    for (size_t i = 0; i < post.length(); ++i) {
        char c = post[i];
        if (isdigit(c)) {
            int num = 0;
            while (i < post.length() && isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                ++i;
            }
            numbers.push(num);
            --i;
            continue;
        }
        switch (c) {
            case '+': case '-': case '*': case '/':
                int right = numbers.pop();
                int left = numbers.pop();
                int res = 0;
                switch (c) {
                    case '+':
                      res = left + right;
                      break;
                    case '-':
                      res = left - right;
                      break;
                    case '*':
                      res = left * right;
                      break;
                    case '/':
                      res = left / right;
                      break;
                }
                numbers.push(res);
                break;
            default:
                break;
        }
    }
    return numbers.pop();
}
