#include <iostream>
class Beta; //Class beta forward declaration
class Alpha {
private:
    int data;
public:
    Alpha() : data(3) {}
    friend int sum(const Alpha&, const Beta&); // Friend function declaration
};
class Beta {
private:
    int data;
    public:
    Beta() : data(7) {}
    friend int sum(const Alpha&, const Beta&); // Friend function declaration
};

// Friend function definition
int sum(const Alpha& a, const Beta& b) {
    return a.data + b.data;
}

int main() {
    Alpha a;
    Beta b; 
    int result = sum(a, b);
    std::cout << "Sum of data members of Alpha and Beta: " << result << std::endl;
    return 0;
}