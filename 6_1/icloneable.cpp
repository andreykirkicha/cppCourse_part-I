struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() {}
};

template <typename Type>
struct ValueHolder : ICloneable
{
    ValueHolder(const Type& data) : data_(data) {}
    ~ValueHolder() {}

    ValueHolder* clone() const { return new ValueHolder(this->data_); }    

    Type data_;
};