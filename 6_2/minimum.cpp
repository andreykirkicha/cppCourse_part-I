#include <iostream>
#include <cstddef>

template <typename Type>
class Array
{
    public:
        explicit Array(size_t size = 0, const Type& value = Type()) : size_(size), data_(new Type[size])
        {
            for (size_t i = 0; i < size_; ++i) { data_[i] = value; }
        }
        ~Array() { delete [] data_; }

        Array(const Array& other)
        {
            this->size_ = other.size_;
            this->data_ = new Type[size_];
            for (size_t i = 0; i < this->size_; ++i) { this->data_[i] = other.data_[i]; }
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                this->~Array();
                this->size_ = other.size_;
                this->data_ = new Type[size_];
                for (size_t i = 0; i < this->size_; ++i) { this->data_[i] = other.data_[i]; }
            }

            return *this;
        }
        
        size_t size() const { return this->size_; }

        Type& operator[](size_t index) { return this->data_[index]; }
        const Type& operator[](size_t index) const { return this->data_[index]; }

    private:
        Type *data_;
        size_t size_;
};

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

template <typename Type, typename Comp>
Type minimum(Array<Type> &arr, Comp less)
{
    Type min = arr[0];
    for (size_t i = 0; i < arr.size(); ++i) { if (less(arr[i], min)) { min = arr[i]; } }

    return min;
}

int main()
{
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less);      //  min = 2
    int max = minimum(ints, Greater()); //  max = 15

    std::cout << min << ", " << max << std::endl;

    return 0;
}