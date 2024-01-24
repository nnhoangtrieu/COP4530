/* Object-Oriented Design Principles

- Abstraction: Displaying only essential information and hiding 
               the details

    + Using Class
    + Using Header files
    + Using access specifiers: 
        * We can use access specifiers to enforce restriction on class members
            $ public
            $ private
            $ protected

- Encapsulation
- Modularity
*/


/* Inheritance

- The capability of a class to derive properties and characteristics 
from another class 
    + Sub Class: Class that inherits properties from another class
    + Super Class (Base Class): Class whose properties are inherited

*/

#include <string> 
#include <iostream> 


using namespace std; 

// Base class 
class Person {
    private: 
    string name;
    string idNum;

    public: 
    Person(const string& newName, const string &newIdNum);
    void print();
    string get_name();
};


Person::Person(const string& newName, const string& newIdNum) : name(newName), idNum(newIdNum) {}


void Person::print() {
    cout << "Name: " << name << endl;
}


// Subclass 
class Student : public Person {
    private: 
    string major;
    int gradYear; 

    public: 
    Student(const string& newName, const string& newIdNum, const string& newMajor, const int gradYear);
    void print();
    void changeMajor(const string& newMajor);
};


Student::Student(
    const string& newName, const string& newIdNum, const string& newMajor, const int gradYear
) : Person(newName, newIdNum), major(newMajor), gradYear(gradYear) {}



void Student::print() 
{
    Person::print();
    cout << "Major: " << major << endl;
    cout << "Graduation Year: " << gradYear << endl;
}


int main()
{
    Person person("Trieu", "12");
    person.print();

    Student student1("Trieu", "12", "Computer Science", 2026);
    student1.print();


    //////////////////////////////////////////////////////////////


    
};