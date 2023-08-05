#include <iostream>

// ==============================================================================================================

template <typename Type_1, typename Type_2>
struct SameType
{
    static const bool value = false;
};

template <typename Type>
struct SameType<Type, Type> { static const bool value = true; };

// ==============================================================================================================

int main()
{
    struct Dummy { };
    typedef int type;

    std::cout << SameType<int, int>::value << std::endl;        // true
    std::cout << SameType<int, type>::value << std::endl;       // true
    std::cout << SameType<int, int&>::value << std::endl;       // false
    std::cout << SameType<Dummy, Dummy>::value << std::endl;    // true
    std::cout << SameType<int, const int>::value << std::endl;  // false
}