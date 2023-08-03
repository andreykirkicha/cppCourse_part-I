#include <cstddef>
#include <iostream>

//  assignment operator and default constructor are considered as defined

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

int main()
{
    typedef Array<float> ArrayF;
    typedef Array<ArrayF> AArrayF;

    ArrayF a0(1, 3.14);
    std::cout << "a0 created" << std::endl;
    std::cout << a0[0] << std::endl << std::endl;

    AArrayF a(5, a0);
    std::cout << "a created" << std::endl;
    std::cout << a[0][0] << std::endl << std::endl;

    AArrayF b(a);
    std::cout << "b created" << std::endl << std::endl;

    AArrayF c;
    std::cout << "c created" << std::endl << std::endl;
    c = b;
    std::cout << "c changed" << std::endl << std::endl;

    return 0;
}