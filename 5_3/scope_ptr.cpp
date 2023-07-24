struct Expression;
struct Number;
struct BinaryOperation;

struct ScopedPtr
{
    explicit ScopedPtr(Expression *ptr = 0) { ptr_ = ptr; }
    ~ScopedPtr() { delete ptr_; }

    Expression *get() const { return ptr_; }
    Expression *release()
    {
        Expression *new_ptr = ptr_;
        ptr_ = 0;

        return new_ptr;
    }
    void reset(Expression *ptr = 0)
    {
        delete ptr_;
        ptr_ = ptr;
    }
    Expression &operator*() const { return *ptr_; }
    Expression *operator->() const { return ptr_; }


    private:
        ScopedPtr(const ScopedPtr&);
        ScopedPtr& operator=(const ScopedPtr&);

        Expression *ptr_;
};