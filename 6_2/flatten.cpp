#include <iostream>
#include <cstddef>

//================================================================================================================

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

//================================================================================================================

/*
    Function "flatten" prints all the lowest level elements
    of multidimensional array (the nesting depth is unknown).

    Recursion is used here.
*/

template <typename Type>
void flatten(const Type& data, std::ostream& out)
{
    out << data << " ";
}

template <typename Type>
void flatten(const Array<Type>& array, std::ostream& out)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        flatten(array[i], out);
    }
}

//================================================================================================================

int main()
{
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout);   //  output: "10 20"
    std::cout << std::endl;

    Array< Array<int> > array_of_ints(2, ints);
    flatten(array_of_ints, std::cout);  //  output: "10 20 10 20"
    std::cout << std::endl;

    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout);    //  also working
    std::cout << std::endl;

    return 0;
}