#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {}

    void add(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ = denominator_ * rational.denominator_;
    }
    void sub(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ = denominator_ * rational.denominator_;
    }
    void mul(Rational rational)
    {
        numerator_ = numerator_ * rational.numerator_;
        denominator_ = denominator_ * rational.denominator_;
    }
    void div(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_;
        denominator_ = denominator_ * rational.numerator_;
    }

    void neg()
    {
        numerator_ = -numerator_;
    }
    void inv()
    {
        int tmp = numerator_;
        numerator_ = denominator_;
        denominator_ = tmp;
    }
    double to_double() const
    {
        return numerator_ / (double)denominator_;
    }

    Rational & operator+=(Rational const &r)
    {
        this->add(r);
        return *this;
    }
    Rational & operator-=(Rational const &r)
    {
        this->sub(r);
        return *this;
    }
    Rational & operator*=(Rational const &r)
    {
        this->mul(r);
        return *this;
    }
    Rational & operator/=(Rational const &r)
    {
        this->div(r);
        return *this;
    }

    Rational operator-() const
    {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }
    Rational operator+() const
    {
        Rational r(this->numerator_, this->denominator_);
        return r;
    }

    private:
        int numerator_;
        int denominator_;
};

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    r1 += r2;
    std::cout << r1.to_double() << std::endl;
    r1 -= r2;
    std::cout << r1.to_double() << std::endl;
    -r1;
    std::cout << r1.to_double() << std::endl;
    r3 *= r1;
    std::cout << r3.to_double() << std::endl;
    r3 /= r2;
    std::cout << r3.to_double() << std::endl;
}
