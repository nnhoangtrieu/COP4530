// Template Function Implementation
#include <iostream>

template <typename T>
T genericMin (T a, T b)
{
    return a < b ? a : b;
}


template <typename T1, typename T2> 
class Pair 
{
    private: 
        T1 firstValue;
        T2 secondValue;

    public: 
        Pair(T1 first, T2 second) : firstValue(first), secondValue(second) {};
        
        void display() 
        {
            std::cout << "The pair is " << firstValue << " and " << secondValue;
        }
};




int main()
{
    int a = 10, b = 20;

    std::cout << "The smaller is " << genericMin(a, b) << std::endl;


    Pair<int, int> p1(a, b);

    p1.display();
    return 0;
}