#include <iostream>
class beta; //Class beta forward declaration
class alpha {
private:
    int data;
public:
    alpha() : data(3) {}
    friend int sum(const alpha&, const beta&); // Friend function declaration
};
class beta {
private:
    int data;
    public:
    beta() : data(7) {}
    friend int sum(const alpha&, const beta&); // Friend function declaration
};

// Friend function definition
int sum(const alpha& a, const beta& b) {
    return a.data + b.data;
}

int main() {
    alpha a;
    beta b; 
    int result = sum(a, b);
    std::cout << "Sum of data members of alpha and beta: " << result << std::endl;
    return 0;
}