#include <cstdlib>
#include <iostream> 

using namespace std;



// void learn_pointers() { 
//     char ch = 'Q'; 

//     char *p = &ch; 

//     cout << *p; // outputs 'Q'

//     ch = 'Z';

//     cout << *p; // outputs 'Z' 

//     *p = 'X';

//     cout << ch; // outputs 'X'
    
// }

// void learn_array() 
// {
//     double f[5]; 
//     int m[10];

//     f[4] = 2.5;
//     m[2] = 4;

//     cout << f[m[2]];

//     int a[] = {1, 2, 3, 4};
//     bool b[] = {false, true};
//     char c[] = {'c', 'a', 't'};

//     char *p = c; // p points to c[0] 
//     char *q = &c[0]; // q also points to c[0] 

//     cout << c[2] << p[2] << q[2]; // print 'ttt'
    
// }






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
}

int main() 
{ 

    learn_structure();

    return 0;
}