#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name = "";
    int age = 0;
    string profession;
public:
    virtual void Input()
    {
        cout << "Enter name person: ";
        cin >> name;
        cout << "Enter age person: ";
        cin >> age;
        cin.ignore();
    }

    virtual void Output() const
    {
        cout << "Name person: " << name << "\tAge person: " << age << endl;
        cout << "Profession: " << profession << endl;
    }

    Person(const string& prof) : profession(prof) {}
};

class Student : public Person
{
    string academy;
public:
    Student() : Person("Student") {}

    void Input() override
    {
        Person::Input();
        cout << "Enter academy name: ";
        getline(cin, academy);
    }

    void Output() const override
    {
        Person::Output();
        cout << "Academy: " << academy << endl;
    }
};

class Teacher : public Person
{
    string school;
    string subject;
public:
    Teacher() : Person("Teacher") {}

    void Input() override
    {
        Person::Input();
        cout << "Enter school name: ";
        getline(cin, school);
        cout << "Enter subject: ";
        getline(cin, subject);
    }

    void Output() const override
    {
        Person::Output();
        cout << "School: " << school << "\tSubject: " << subject << endl;
    }
};

class Doctor : public Person
{
    string hospital;
    double salary;
public:
    Doctor() : Person("Doctor") {}

    void Input() override
    {
        Person::Input();
        cout << "Enter hospital name: ";
        getline(cin, hospital);
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();
    }

    void Output() const override
    {
        Person::Output();
        cout << "Hospital: " << hospital << "\tSalary: " << salary << endl;
    }
};

int main()
{
    Student student;
    Teacher teacher;
    Doctor doctor;

    cout << "Enter for student:" << endl;
    student.Input();
    cout << "\nEnter for teacher:" << endl;
    teacher.Input();
    cout << "\nEnter for doctor:" << endl;
    doctor.Input();

    cout << "\nOutput for student:" << endl;
    student.Output();
    cout << "\nOutput for teacher:" << endl;
    teacher.Output();
    cout << "\nOutput for doctor:" << endl;
    doctor.Output();
}
