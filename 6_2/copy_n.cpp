#include <cstddef>
#include <iostream>

//================================================================================================================

template <typename Type_1, typename Type_2>
void copy_n(Type_1 *dest, Type_2 *src, size_t n)
{
    for (size_t i = 0; i < n; ++i) { dest[i] = static_cast<Type_1>(src[i]); }
}

//========================================================================================================

int main()
{
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};

    for (size_t i = 0; i < 4; ++i) { std::cout << ints[i] << ", " << doubles[i] << std::endl; }

    copy_n(doubles, ints, 4);

    std::cout << std::endl;
    for (size_t i = 0; i < 4; ++i) { std::cout << ints[i] << ", " << doubles[i] << std::endl; }

    return 0;
}