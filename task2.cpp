#include <iostream>
class alpha {
private:
    double num1, num2;
public:
    alpha(double a, double b) : num1(a), num2(b) {}
    friend double sum(const alpha&); // Friend function declaration
    friend double sub(const alpha&); // Friend function declaration
    friend double mul(const alpha&); // Friend function declaration
    friend double div(const alpha&); // Friend function declaration
};

// Friend function definitions
double sum(const alpha& a) {
    return a.num1 + a.num2;
}
double sub(const alpha& a) {
    return a.num1 - a.num2;
}
double mul(const alpha& a) {
    return a.num1 * a.num2;
}
double div(const alpha& a) {
    if (a.num2 != 0) {
        return a.num1 / a.num2;
    } else {
        std::cerr << "Error: Division by zero!" << std::endl;
    }
}

int main() {
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    alpha a(num1, num2);
    
    std::cout << "Sum: " << sum(a) << std::endl;
    std::cout << "Difference: " << sub(a) << std::endl;
    std::cout << "Product: " << mul(a) << std::endl;
    std::cout << "Division: " << div(a) << std::endl;
    
    return 0;
}