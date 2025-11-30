#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::stack<int> s;
        std::string token;

        while (iss >> token) {
            if (token == "+") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a + b);
            } else if (token == "-") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a - b);
            } else if (token == "*") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a * b);
            } else if (token == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a / b);
            } else {
                s.push(std::stoi(token));
            }
        }

        fout << line << " = " << s.top() << "\n";
    }

    return 0;
}