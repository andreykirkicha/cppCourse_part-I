#include <cstring>

struct Expression
{
    Expression(const char *str = "") 
    {
        this->size = strlen(str);
        this->str = new char[this->size + 1];

        for (int i = 0; i < this->size; i++) { (this->str)[i] = str[i]; }

        (this->str)[this->size] = '\0';
    }
    ~Expression() { delete [] str; }

	size_t size;
	char *str;
};

struct Fields
{
    Fields(Expression *ptr = nullptr)
    {
        ptr_ = ptr;
        counter_ = 1;
    }
    ~Fields() { delete ptr_, counter_ = 0; }

    Expression *ptr_;
    mutable int counter_;
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = nullptr)
    {
        if (ptr != nullptr) { fields = new Fields(ptr); }
        else { fields = nullptr; }
    }
    ~SharedPtr()
    { 
        if (fields != nullptr)
        {
            --(fields->counter_);

            if (fields->counter_ == 0)
                delete fields;
        }
    }
    
    SharedPtr(const SharedPtr &other)
    {
        ++(other.fields->counter_);
        this->fields = other.fields;
    }
    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            this->~SharedPtr();
            this->fields = other.fields;

            ++(other.fields->counter_);
        }

        return *this;
    }
    Expression *get() const { return fields->ptr_; }
    void reset(Expression *ptr = nullptr)
    {
        this->~SharedPtr();
        if (ptr != nullptr) { fields = new Fields(ptr); }
        else { fields = nullptr; }
    }
    Expression &operator*() const { return *fields->ptr_; }
    Expression *operator->() const { return fields->ptr_; }

    private:
        Fields *fields;
};

int main()
{
    SharedPtr p1;
    {
        SharedPtr p2(new Expression("expr1"));
        SharedPtr p3(new Expression("expr2"));
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(nullptr);
        p3 = p5;
        p5.reset(nullptr);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(nullptr);
        p7.reset(new Expression("expr3"));
        SharedPtr p8(new Expression("expr4"));
        p8.reset(NULL);
    }
    p1 = p1;

    return 0;
}