// Operator Overloading 
#include <string>
#include <iostream>

enum MealType {NO_PREF, REGULAR, LOWFAT, VEGETARIAN};
struct Passenger 
{
    std::string name;
    MealType mealPref;
    bool isFreqFlyer;
    std::string freqFlyerNo;
};
bool operator==(const Passenger& x, const Passenger& y) 
{
    return x.name == y.name;
}


template <typename T> 
class MyVector 
{
    public: 
        MyVector(int capacity = 10);
        T& operator[] (int i) 
        {
            return a[i];
        }
        ~MyVector()
        {
            delete[] a;
        }

    private: 
        T* a;
        int capacity;
};

template <typename T>
MyVector<T>::MyVector(int cap)
{
    capacity = cap;
    a = new T[capacity];
}


int main()
{
    // Passenger p1 = {"Trieu Nguyen", REGULAR, true, "123"};

    // p1.name = "Trieu Dep Trai";
    // p1.freqFlyerNo = "910";

    // Passenger p2 = {"Trieu Dep Trai", REGULAR, true, "910"};

    // std::cout << p1 == p2 << std::endl;

    MyVector<int> iv(5);
    MyVector<double> dv(20);
    MyVector<std::string> sv(10);

    iv[0] = 0;
    sv[0] = "Trieu";


    std::cout << sv[0] << std::endl;


    return 0;
}