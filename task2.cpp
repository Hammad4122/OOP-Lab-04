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
        std::cerr << "Error: Division by zero!"<<std::endl;
        return -1;
    }
}

int main() {
    double num1, num2;
    while(true){
        std::cout<<"\nEnter first number: ";
        if (!(std::cin>>num1)){
            std::cerr<<"\nInvalid Input.";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else {
            break;
        }
    }
    while (true)
    {
        std::cout<<"\nEnter second number: ";
        if (!(std::cin>>num2)){
            std::cerr<<"\nInvalid Input.";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else {
            break;
        }
    }
    
    
    alpha a(num1, num2);
    
    std::cout << "Sum: " << sum(a) << std::endl;
    std::cout << "Difference: " << sub(a) << std::endl;
    std::cout << "Product: " << mul(a) << std::endl;
    std::cout << "Division: " << div(a) << std::endl;
    
    return 0;
}