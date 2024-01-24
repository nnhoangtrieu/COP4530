#include <cstdlib>
#include <iostream> 

using namespace std;


void learn_pointers() { 
    char ch = 'Q'; 

    char *p = &ch; 

    cout << *p; // outputs 'Q'

    ch = 'Z';

    cout << *p; // outputs 'Z' 

    *p = 'X';

    cout << ch; // outputs 'X'
    
}


void learn_array() 
{
    double f[5]; 
    int m[10];

    f[4] = 2.5;
    m[2] = 4;

    cout << f[m[2]];

    int a[] = {1, 2, 3, 4};
    bool b[] = {false, true};
    char c[] = {'c', 'a', 't'};

    char *p = c; // p points to c[0] 
    char *q = &c[0]; // q also points to c[0] 

    cout << c[2] << p[2] << q[2]; // print 'ttt'
    
}


void learn_structure() 
{
    enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGAN};

    struct Passenger {
        string name;
        MealType mealPref;
        bool isFreqFlyer;
        string flyerNo;
    };

    Passenger pass1 = {"Trieu Nguyen", REGULAR, true, "123"};

    pass1.name = "Trieu Ngoc Hoang Nguyen"; // change name

    cout << pass1.name;


    // Structure new Operator 

    Passenger *p; 
    p = new Passenger; // p points to the new Passenger

    p->name = "Vy"; 
    p->mealPref = REGULAR; 

    delete p; // destroy the object p points to 

}


void learn_buffer() 
{
    char *buffer = new char[500]; // allocate a buffer of 500 chars
    buffer[3] = 'a';              // still accessed using []
    delete [] buffer; 

    /*
    - If an object is allocated with new, it should eventually be 
    deallocated with 'delete'
    - Inaccessible objects in dynamic memory can cause a memory leak
    */
}


/*
- By default, arguments in C++ programs are passed by value.
=> The system only makes a copy of the variable to be passed to the function
=> Modification to this copy does not alter the actual argument 

===> To modify an argument, a pointer must be passed
*/


void learn_argument_passing(int value, int &ref) 
{
    value++;        // Has no effect on the actual argument
    ref++;          // Modifies the actual argument 

    cout << value << endl;
    cout << ref << endl;

}

// void overloading_new_operators(
//     bool operator==(const Passenger &x, const Passenger &y) 
//     {
//         return x.name == y.name 
//         && x.mealPref == y.mealPref 
//         ...
//     }
// )


/* Classes
- A class consists of members:
    + Members that are variables or constants are data members
    + Members that are functions are called member functions (methods)

- Access Control:
    + Public: they are accessible from outside the class
    + Private: they are accessible only from within the class

- All external access to class objects takes place through the public member,
or public interface 
*/


class Counter {
public:
    Counter();                  // initialization
    int getCount();             // get the current count 
    void increaseBy(int x);     // add x to count 

private:
    int count;
};

Counter::Counter()
{
    count = 0;
}

int Counter::getCount()
{
    return count;
}

void Counter::increaseBy(int x) 
{
    count += x;
}


class Passenger {
public:
    Passenger();
    bool isFrequentFlyer() const; 
    /*
    - The keyword "const" indicates that the member function isFreqFlyer()
    is an accessor (only read class data)
    */
private:
    bool isFreqFlyer;
};

bool Passenger::isFrequentFlyer() const {
    return isFreqFlyer;
}



/* Classes - Constructors */

class Passenger {
public:
    Passenger(); // default constructor
    Passenger(const string& nm, MealType mp, const string& ffn = "NONE");
    Passenger(const Passenger& pass); // copy constructor
    // ...
};
Passenger::Passenger() {
    name = "--NO NAME--";
    mealPref = NO PREF; isFreqFlyer = false; freqFlyerNo = "NONE";
}
Passenger::Passenger(const string& nm, MealType mp, const string& ffn) {
    name = nm; mealPref = mp;
    isFreqFlyer = (ffn != "NONE"); // true only if ffn given
    freqFlyerNo = ffn;
}
Passenger::Passenger(const  Passenger& pass) {
    name = pass.name; mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer; freqFlyerNo = pass.freqFlyerNo;
}





int main() 
{ 

    int a = 10, b = 20;

    learn_argument_passing(a, b);

    cout << a << endl;
    cout << b << endl;
    return 0;
}