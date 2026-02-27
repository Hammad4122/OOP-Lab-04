#include <iostream>
#include <string>
#include <limits>
#include <conio.h>
class Student {
private:
    int studentID;
    std::string name;
    double totalMarks;
public:
    Student() : studentID(1), name(""), totalMarks(0) {} // Default constructor
    Student(int id, const std::string& name, double marks) : studentID(id), name(name), totalMarks(marks) {} //Parameterized constructor
    
    void displayBasicInfo() const {
        std::cout << "Student ID: " << studentID << ", Name: " << name << std::endl;
    }
    
    friend std::string compareTotalMarks(const Student& s1, const Student& s2); // Friend function declaration
    friend class Teacher; // Friend class declaration
};


std::string compareTotalMarks(const Student& s1, const Student& s2) {
    if (s1.totalMarks > s2.totalMarks) {
        return s1.name + " has higher total marks (" + std::to_string(s1.totalMarks) + ") than " + s2.name + " (" + std::to_string(s2.totalMarks) + ").\n";
    } else if (s1.totalMarks < s2.totalMarks) {
        return s2.name + " has higher total marks (" + std::to_string(s2.totalMarks) + ") than " + s1.name + " (" + std::to_string(s1.totalMarks) + ").\n";
    } else {
        return s1.name + " and " + s2.name + " have the same total marks (" + std::to_string(s1.totalMarks) + ").\n";
    }
}

class Teacher {
public:
    void updateTotalMarks(Student& student, double newMarks) {
        student.totalMarks = newMarks; // Accessing private member of Student
    }
};

int main() {
    Student student1;
    Student student2;
    Teacher teacher;

    int id1;
    std::string name1;
    double marks1;

    int id2;
    std::string name2;
    double marks2;

    std::cout<<"Enter details for student 1 (ID Name TotalMarks): ";
    std::cout<<"\nEnter Name: ";
    std::getline(std::cin, name1);
    std::cout<<"\nEnter ID: ";
    std::cin >> id1;
    std::cout<<"\nEnter Total Marks: ";
    std::cin >> marks1;
    std::cin.ignore();

    student1 = Student(id1, name1, marks1);

    std::cout<<"Enter details for student 2 (ID Name TotalMarks): ";
    std::cout<<"\nEnter Name: ";
    std::getline(std::cin, name2);
    std::cout<<"\nEnter ID: ";
    std::cin >> id2;
    std::cout<<"\nEnter Total Marks: ";
    std::cin >> marks2;

    student2 = Student(id2, name2, marks2);

    student1.displayBasicInfo();
    student2.displayBasicInfo();
    
    std::cout << compareTotalMarks(student1, student2);
    
    double newMarks;
    while (true)
    {
        /* code */
        std::cout<<"\nDo you want to update marks (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            while (true)
            {          
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
                std::cout<<"\nWhich student do you want to update marks for (1/2): ";
                int studentChoice = 0;
                std::cin >> studentChoice;
                newMarks = 0; // Reset new marks
                if (studentChoice == 1) {
                    std::cout<<"\nEnter new marks: ";
                    std::cin >> newMarks;
                    std::cout<<"\nAfter updating marks for student 1: ";
                    teacher.updateTotalMarks(student1, newMarks);
                    std::cout << compareTotalMarks(student1, student2);
                    break;
                } else if (studentChoice == 2) {
                    std::cout<<"\nEnter new marks: ";
                    std::cin >> newMarks;
                    teacher.updateTotalMarks(student2, newMarks);
                    std::cout<<"\nAfter updating marks for student 2: ";
                    std::cout << compareTotalMarks(student1, student2);
                    break;
                } else {
                    std::cerr << "\n\033[31mInvalid student choice.\033[0m" << std::endl;
                    
                }
            }
            break;
        }
        else if (choice == 'n' || choice == 'N') {
            break;
        }
        else {
            std::cerr << "\n\033[31mInvalid input.\033[0m" << std::endl;
        }
    }    
    getch();
    return 0;
}