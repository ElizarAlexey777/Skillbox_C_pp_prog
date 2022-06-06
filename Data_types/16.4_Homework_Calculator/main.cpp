#include <iostream>
#include <sstream>

int main() {
    std::cout << "Calculator" << std::endl;
    std::cout << std::endl;

    std::string buffer;

    std::cout << "Enter calculator string: " << std::endl;
    std::cin >> buffer;

    std::stringstream buffer_stream(buffer);
    double a;
    char math_operator;
    double b;
    buffer_stream >> a >> math_operator >> b;

    double result;
    if (math_operator == '+') {
        result = a + b;
    } else if (math_operator == '-') {
        result = a - b;
    } else if (math_operator == '*') {
        result = a * b;
    } else result = a / b;

    std::cout << buffer << "=" << result << std::endl;
    return 0;
}
