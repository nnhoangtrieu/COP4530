#include <iostream>
#include <iomanip>
#include <sstream>


/*
Use setw(0) for the assignmnt. 
*/
int main() {
    // Using std::setw from iomanip to set the width of the output
    std::cout << std::setw(0) << "Name" << std::setw(0) << "Age" << std::setw(0) << "Salary" << std::endl;

    // Using std::setprecision from iomanip to set the precision of floating-point numbers
    double salary = 50000.123456789;
    std::cout << std::setw(0) << "John" << std::setw(0) << 25 << std::fixed << std::setprecision(2) << std::setw(10) << salary << std::endl;

    // Using std::stringstream to concatenate and manipulate strings
    std::stringstream ss;
    ss << "Hello, ";
    ss << "world!";
    
    // Convert the stringstream to a string
    std::string result = ss.str();

    std::cout << "Concatenated string: " << result << std::endl;

    return 0;
}
