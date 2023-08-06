#include <iostream>

// ================================================================================================

// Function "array_size" calculates length of array and works only for arrays
// For example, if "array_size" gets a pointer to array, compilation error occurs
template <typename Type, size_t Size>
size_t array_size(Type (&array)[Size]) { return Size; }

// ================================================================================================

int main()
{
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};

    std::cout << array_size(ints) << std::endl;               // returns 4
    std::cout << array_size(doubles) << std::endl;            // returns 1
    std::cout << array_size(iptr) << std::endl;               // compilation error

    return 0;
}