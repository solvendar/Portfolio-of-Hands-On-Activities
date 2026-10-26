#include <iostream>
#include <string.h>

class Student
{
private:
    std::string studentName;
    int studentAge;

public:
    // constructor
    Student(std::string newName = "John Doe", int newAge = 18)
    {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    };
    // deconstructor
    ~Student()
    {
        std::cout << "Destructor Called." << std::endl;
    }
    // Copy Constructor
    Student(const Student &copyStudent)
    {
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }
    // Display Attributes
    void printDetails()
    {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};
int main()
{
    Student student1("Roman", 28);
    Student student2(student1);
    Student student3;
    student3 = student2;

    const size_t j = 5;
    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};
    return 0;
}