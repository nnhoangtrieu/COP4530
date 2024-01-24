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


/*

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
    Person(const string& name, const string &idNum);
    void print();
    string get_name();
};


Person::Person(const string& name, const string& idNum) : name(name), idNum(idNum) {}


void Person::print() {
    cout << "Name: " << name << endl;
    cout << "Id Number: " << idNum << endl;
}


string Person::get_name() {return name;};

// Subclass 
class Student : public Person {
    private: 
    string major;
    int gradYear; 

    public: 
    Student(const string& name, const string& idNum, const string& major, const int gradYear);
    void print();
    void changeMajor(const string& newMajor);
};


Student::Student(
    const string& name, const string& idNum, const string& major, const int gradYear
) : Person(name, idNum), major(major), gradYear(gradYear) {}



void Student::print() 
{
    Person::print();
    cout << "Major: " << major << endl;
    cout << "Graduation Year: " << gradYear << endl;
}


void Student::changeMajor(const string& newMajor) {
    cout << "Change major from " << major << "to " << newMajor << endl;
    cout << "/////////////////////////////////" << endl;
    major = newMajor;
    cout << "New information: " << endl;
    Student::print();
}


///////////////////// Template ////////////////////////////
template <typename T> 

T genericMin(T a, T b) {
    return (a < b ? a : b);
}


// Class template for a generic Pair 
template <typename T1, typename T2> 

class Pair {
    public: 
        Pair(T1 first, T2 second) : firstValue(first), secondValue(second) {}

        void display() const {
            cout << "Pair: " << firstValue << ", " << secondValue << endl;
        }

    private: 
        T1 firstValue; 
        T2 secondValue;
};


///////////////////////// Exceptions ////////////////////////////////

class MathException {
    public: 
        MathException(const string& err) : errMsg(err) {} 

        string  getError() {return errMsg;}

    private: 
        string errMsg;
}

class ZeroDivision : public MathException {
    public: 
        ZeroDivision(const string &err) : MathException(err) {}
};

class NegativeRoot : public MathException {
    public: 
        NegativeRoot(const string& err) : MathException(err) {}
};






















int main()
{
    // Person person("Trieu", "12");
    // person.print();

    // Student student1("Trieu", "12", "Computer Science", 2026);
    // student1.print();

    // student1.changeMajor("Math");


    //////////////////////////////////////////////////////////////


    // Person *pp[100];        // array of 100 Person pointers

    // pp[0] = new Person("Trieu", "12");
    // pp[1] = new Student("Vy", "13", "Marketing", 2025); // add a Student 

    // cout << pp[1]->get_name() << "\n";

    // pp[0]-> print();            // calls Person::print()
    // pp[1]->print();             // calls Person::print()

    // // pp[1]->changeMajor("Math"); // ERROR !!!!
    // /*
    // - Since pp[1] is declared to be a pointer to a Person,
    // the members for that class are used
    // */


   ////////////////////////// Template /////////////////////////////////////
//    cout << genericMin(3, 4) << genericMin(1.1, 3.1) << genericMin('t', 'g') << endl;


   ////////////////////////// Exceptions /////////////////////////////////////

    double numerator = 12, denominator = 0;

    try {
        if (denominator == 0) throw ZeroDivision("Divide by zero !");
    }
    catch (ZeroDivision& zde) {
        // handle division by zero
    }
    catch (MathException& me) {
    // handle any math exception other than division by zero
    }
};