#include <iostream>

// ================================================================================================

struct ICloneable
{
	virtual ICloneable *clone() const = 0;
	virtual ~ICloneable() {}
};

template <typename Type>
struct ValueHolder : ICloneable
{
    ValueHolder(const Type& data) : data_(data) {}
    ~ValueHolder() {}

    ValueHolder *clone() const { return new ValueHolder(this->data_); }    

    Type data_;
};

// ================================================================================================

// Non-template class "Any" contains value of any type.
class Any
{
    public:
        // Default constructor
        Any() : holder_(nullptr) {}
        
        // Template constructor
        template <typename Type>
        Any(const Type& value) { holder_ = new ValueHolder<Type>(value); }

        // Destructor
        ~Any() { delete holder_; }

        // ========================================================================================

        // Copy constructor
        Any(const Any& other)
        {
            if (other.holder_) { this->holder_ = other.holder_->clone(); }
            else { this->holder_ = nullptr; }
        }

        // Assignment operator
        Any& operator=(const Any& other)
        {
            if (this != &other && other.holder_)
            {
                this->~Any();
                this->holder_ = other.holder_->clone();
            }

            return *this;
        }

        // Template assignment operator
        template <typename Type>
        Any& operator=(const Type& value)
        {
            this->~Any();
            this->holder_ = new ValueHolder<Type>(value);

            return *this;
        }

        // ========================================================================================
        
        // Template method "cast" returns pointer to contained value
        template <typename Type>
        Type *cast()
        {
            if (this->holder_ == nullptr) { return nullptr; }

            ValueHolder<Type> *check_ptr = dynamic_cast<ValueHolder<Type> *>(this->holder_);

            if (check_ptr) { return &(check_ptr->data_); }

            return nullptr;
        }

    private:
        ICloneable *holder_;
};

int main()
{
    Any *anyd = new Any(3.14);                                              // double:  3.14
    Any *anyf = new Any(3.14f);                                             // float:   3.14
    Any *anyi = new Any(3);                                                 // int:     3
    Any *anys = new Any(std::string("Hello"));                              // string:  "Hello"

    std::cout << *anyd->cast<double>() << std::endl;                        // output:  "3.14"
    std::cout << *anyf->cast<float>() << std::endl;                         // output:  "3.14"
    std::cout << *anyi->cast<int>() << std::endl;                           // output:  "3"
    std::cout << *anys->cast<std::string>() << std::endl;                   // output:  "Hello"
    std::cout << anys->cast<int>() << std::endl;                            // output:  "0"

    {
        Any empty;                                                          // empty class "empty"
        Any clone(empty);                                                   // empty class "clone"
        int *p = empty.cast<int>();                                         // nullptr
        const char *message = p == 0 ? "empty" : "p is not empty";
        std::cout << message << std::endl;                                  // output:  "empty"

        clone = empty;                                                      // it must work

        empty = *anyd;                                                      // double:  3.14
        message = empty.cast<double>() == 0 ? "empty" : "is not empty";
        std::cout << message << std::endl;                                  // output:  "is not empty"
        std::cout << *empty.cast<double>() << std::endl;                    // output:  "3.14"
        std::cout << *anyd->cast<double>() << std::endl;                    // output:  "3.14"

        delete anyd;
        std::cout << *empty.cast<double>() << std::endl;                    // output:  "3.14"

        anyd = new Any(empty);
        std::cout << *anyd->cast<double>() << std::endl;                    // output:  "3.14"
        (void)clone;
    }

    std::cout << *anyd->cast<double>() << std::endl;                        // output:  "3.14"

    return 0;
}