#include "complex.hpp"

Complex Complex::operator-() const
{
    return {-re_, -im_};
}

Complex Complex::operator+(const Complex& rhs)
{
    return {re_ + rhs.getRe(), im_ + rhs.getIm()};
}

Complex Complex::operator-(const Complex &rhs)
{
    return {re_ - rhs.getRe(), im_ - rhs.getIm()};
}

Complex Complex::operator*(const Complex &rhs)
{
    return Complex(*this) *= rhs;
}

Complex Complex::operator/(const Complex &rhs)
{
    return Complex(*this) /= rhs;
}

Complex &Complex::operator+=(const Complex &rhs)
{
    re_ += rhs.getRe();
	im_ += rhs.getIm();
	return *this;
}

Complex &Complex::operator+=(const double rhs)
{
    re_ += rhs;
	return *this;
}

Complex &Complex::operator-=(const Complex &rhs)
{
    re_ -= rhs.getRe();
	im_ -= rhs.getIm();
	return *this;
}

Complex &Complex::operator-=(const double rhs)
{
	re_ -= rhs;
	return *this;
}

Complex &Complex::operator*=(const Complex &rhs)
{	
	double tempRe = re_;
	double tempIm = im_;
    re_ = tempRe * rhs.getRe() - tempIm * rhs.getIm();
	im_ = tempRe * rhs.getIm() + tempIm * rhs.getRe();
	return *this;
}

Complex &Complex::operator*=(const double rhs)
{
	re_ *= rhs;
	im_ *= rhs;
	return *this;
}

Complex &Complex::operator/=(const Complex &rhs)
{
	if (rhs != Complex()) {
		double tempRe = re_;
		double tempIm = im_;
		re_ = (tempRe * rhs.getRe() + tempIm * rhs.getIm()) / (rhs.getRe() * rhs.getRe() + rhs.getIm() * rhs.getIm());
		im_ = (tempIm * rhs.getRe() - tempRe * rhs.getIm()) / (rhs.getRe() * rhs.getRe() + rhs.getIm() * rhs.getIm());
		return *this;
	}
	throw std::invalid_argument("Division by 0 isn't defined\n");
}

Complex &Complex::operator/=(const double rhs)
{
    return (*this).operator/=(Complex(rhs));
}

bool Complex::operator==(const Complex &rhs) const
{
    return ((re_ == rhs.getRe()) && (im_ == rhs.getIm()));
}
