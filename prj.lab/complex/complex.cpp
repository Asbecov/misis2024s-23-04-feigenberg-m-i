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
    return operator/=(Complex(rhs));
}

bool Complex::operator==(const Complex &rhs) const
{
    return ((re_ == rhs.getRe()) && (im_ == rhs.getIm()));
}

bool Complex::operator!=(const Complex &rhs) const
{
    return !operator==(rhs);
}

bool Complex::operator==(const double &rhs) const
{
    return (re_ == rhs && im_ == 0.0);
}

bool Complex::operator!=(const double &rhs) const
{
    return !operator==(rhs);
}

bool Complex::operator>(const Complex &rhs) const
{
    return (re_ > rhs.getRe() ? true : im_ > rhs.getIm());
}

bool Complex::operator>=(const Complex &rhs) const
{
    return operator>(rhs) || operator==(rhs);
}

bool Complex::operator<(const Complex &rhs) const
{
    return !operator>=(rhs);
}

bool Complex::operator<=(const Complex &rhs) const
{
    return !operator>(rhs);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << left_brace << re_ << comma << im_ << right_brace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
	char LeftBrace(0);
	double nreal(0.0);
	char Comma(0);
	double nimagine(0.0);
	char RightBrace(0);
	istrm >> LeftBrace >> nreal >> Comma >> nimagine >> RightBrace;
	if (istrm.good()) {
		if ((LeftBrace == Complex::left_brace) && (Comma == Complex::comma) && (RightBrace == Complex::right_brace)) {
			re_ = nreal;
			im_ = nimagine;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

bool operator==(const double &lhs, const Complex &rhs)
{
    return rhs.operator==(lhs);
}

bool operator!=(const double &lhs, const Complex &rhs)
{
    return rhs.operator!=(lhs);
}

Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs.getRe(), rhs.getIm());
}

Complex operator-(double lhs, const Complex& rhs) {
  return Complex(lhs - rhs.getRe(), -rhs.getIm());
}

Complex operator*(double lhs, const Complex& rhs) {
  return Complex(lhs * rhs.getRe(), lhs * rhs.getIm());
}

Complex operator/(double lhs, const Complex& rhs) {
  double denominator = rhs.getRe() * rhs.getRe() + rhs.getIm() * rhs.getIm();
  return Complex((lhs * rhs.getRe()) / denominator, (-lhs * rhs.getIm()) / denominator);
}

Complex operator+(const Complex& lhs, double rhs) {
  return operator+(rhs, lhs);
}

Complex operator-(const Complex& lhs, double rhs) {
  return -operator-(rhs, lhs);
}

Complex operator*(const Complex& lhs, double rhs) {
  return operator*(rhs, lhs);
}

Complex operator/(const Complex& lhs, double rhs) {
  return Complex(lhs.getRe() / rhs, lhs.getIm() / rhs);
}