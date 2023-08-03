#include <cstddef>
#include <iostream>

//  assignment operator and default constructor of type "Type" aren't considered as defined
//  copy constructor of type "Type" is defined

template <typename Type>
class Array
{
    public:

        //====================================================================================================

        //  use "new char[...]" to avoid incorrect memory alignment
        explicit Array(size_t size, const Type& value)
            : size_(size), data_(reinterpret_cast<Type*>(new char[size * sizeof(Type)]))
        {
            // initialization of memory
            for (size_t i = 0; i < size_; ++i) { new (data_ + i) Type(value); }
        }

        //  default constructor
        explicit Array() : size_(0), data_(nullptr) {}

        ~Array()
        {
            //  delete each object
            for (size_t i = 0; i < size_; ++i) { data_[i].~Type(); }

            //  delete allocated memory
            delete [] reinterpret_cast<char*>(data_);
        }

        //====================================================================================================

        Array(const Array& other)
        {
            this->size_ = other.size_;
            this->data_ = reinterpret_cast<Type*>(new char[size_ * sizeof(Type)]);
            for (size_t i = 0; i < this->size_; ++i) { new (this->data_ + i) Type(other.data_[i]); }
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                this->~Array();
                this->size_ = other.size_;
                this->data_ = reinterpret_cast<Type*>(new char[size_ * sizeof(Type)]);
                for (size_t i = 0; i < this->size_; ++i) { new (this->data_ + i) Type(other.data_[i]); }
            }

            return *this;
        }

        //====================================================================================================
        
        size_t size() const { return this->size_; }

        Type& operator[](size_t index) { return this->data_[index]; }

        const Type& operator[](size_t index) const { return this->data_[index]; }

        //====================================================================================================

    private:
        Type* data_;
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
