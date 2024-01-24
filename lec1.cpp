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

    p->name = 'Vy'; 
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
}
int main() 
{ 

    learn_structure();

    return 0;
}