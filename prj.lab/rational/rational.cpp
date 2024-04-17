#include "rational.hpp"

void Rational::changeNumber() {
	if (den_ < 0) {
		den_ = std::abs(den_);
		num_ = -num_;
	}
	int64_t GCD = std::__gcd(num_, den_);
	num_ /= GCD;
	den_ /= GCD;
}

Rational Rational::operator+(const Rational &rhs) const noexcept
{	
	Rational temp = *this;
	temp += rhs;
	return temp;

}

Rational Rational::operator-(const Rational &rhs) const noexcept
{
    Rational temp = *this;
	temp -= rhs;
	return temp;
}

Rational Rational::operator*(const Rational &rhs) const noexcept
{
 	Rational temp = *this;
	temp *= rhs;
	return temp;   
}

Rational Rational::operator/(const Rational &rhs) const
{	
	if (rhs == 0) {
		throw std::invalid_argument("Division by 0 isn't defined\n");
	}
    Rational temp = *this;
	temp /= rhs;
	return temp;
}

Rational Rational::operator+(const int64_t &rhs) const noexcept
{
    Rational temp = *this;
	temp += rhs;
	return temp;
}

Rational Rational::operator-(const int64_t &rhs) const noexcept
{
    Rational temp = *this;
	temp -= rhs;
	return temp;
}

Rational Rational::operator*(const int64_t &rhs) const noexcept
{
    Rational temp = *this;
	temp *= rhs;
	return temp;
}

Rational Rational::operator/(const int64_t &rhs) const
{	
	if (rhs == 0) {
		throw std::invalid_argument("Division by 0 isn't defined\n");
	}
    Rational temp = *this;
	temp /= rhs;
	return temp;
}

Rational& Rational::operator+=(const Rational &rhs)
{
    num_ = num_ * rhs.getDen() + rhs.getNum() * den_;
	den_ = den_ * rhs.getDen();
	changeNumber();
	return *this;
}

Rational& Rational::operator+=(const int64_t& rhs)
{
    num_ = num_ + rhs * den_;
	changeNumber();
	return *this;
}

Rational &Rational::operator-=(const Rational &rhs)
{
    num_ = num_ * rhs.getDen() - rhs.getNum() * den_;
	den_ = den_ * rhs.getDen();
	changeNumber();
	return *this;
}

Rational &Rational::operator-=(const int64_t& rhs)
{
    num_ = num_ - rhs * den_;
	changeNumber();
	return *this;
}

Rational &Rational::operator*=(const Rational &rhs)
{
    num_ *= rhs.getNum();
	den_ *= rhs.getDen();
	changeNumber();
	return *this;
}

Rational &Rational::operator*=(const int64_t& rhs)
{
    num_ *= rhs;
	changeNumber();
	return *this;
}

Rational &Rational::operator/=(const Rational &rhs)
{	
	if (rhs == 0) {
		throw std::invalid_argument("Division by 0 isn't defined\n");
	}
    num_ *= rhs.getDen();
	den_ *= rhs.getNum();
	changeNumber();
	return *this;
}

Rational &Rational::operator/=(const int64_t& rhs)
{	
	if (rhs == 0) {
		throw std::invalid_argument("Division by 0 isn't defined\n");
	}
    den_ *= rhs;
	changeNumber();
	return *this;
}

bool Rational::operator==(const Rational &rhs) const
{
    return (num_ == rhs.getNum() && den_ == rhs.getDen());
}

bool Rational::operator!=(const Rational &rhs) const
{
    return !operator==(rhs);
}

bool Rational::operator>(const Rational &rhs) const
{
    return (num_ * rhs.getDen() > rhs.getNum() * den_);
}

bool Rational::operator>=(const Rational &rhs) const
{
    return (operator>(rhs) || operator==(rhs));
}

bool Rational::operator<(const Rational &rhs) const
{
    return !operator>=(rhs);
}

bool Rational::operator<=(const Rational &rhs) const
{
    return !operator>(rhs);
}

bool Rational::operator==(const int64_t &rhs) const
{
    return (num_ == rhs && den_ == 1);
}

bool Rational::operator!=(const int64_t &rhs) const
{
    return !operator==(rhs);
}

bool Rational::operator>(const int64_t &rhs) const
{
    return (num_ > rhs * den_);
}

bool Rational::operator>=(const int64_t &rhs) const
{
    return (operator>(rhs) || operator==(rhs));
}

bool Rational::operator<(const int64_t &rhs) const
{
    return !operator>=(rhs);
}

bool Rational::operator<=(const int64_t &rhs) const
{
    return !operator>(rhs);
}

std::istream &Rational::readFrom(std::istream &istr)
{
    int64_t num;
	int64_t den;
	char slash;
	istr >> num >> slash >> den;
	if (istr.good()) {
		if (slash == slash_) {
			num_ = num;
			den_ = den;
			changeNumber();
			return istr;
		}
	}
	istr.setstate(std::ios_base::failbit);
	return istr;
}

std::ostream &Rational::writeTo(std::ostream &ostr) const
{
    ostr << num_ << slash_ << den_;
	return ostr;
}

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs)
{
    return rhs.writeTo(ostrm);
}

std::istream &operator>>(std::istream &istrm, Rational &rhs)
{
	return rhs.readFrom(istrm);
}

Rational operator+(int64_t lhs, const Rational &rhs)
{
    return rhs.operator+(lhs);
}

Rational operator-(int64_t lhs, const Rational &rhs)
{
    return -rhs.operator-(lhs);
}

Rational operator*(int64_t lhs, const Rational &rhs)
{
    return rhs.operator*(lhs);
}

Rational operator/(int64_t lhs, const Rational &rhs)
{
    return Rational(lhs * rhs.getDen(), rhs.getNum());
}

bool operator==(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator==(lhs);
}

bool operator!=(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator!=(lhs);
}

bool operator<(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator>(lhs);
}

bool operator>(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator<(lhs);
}

bool operator<=(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator>=(lhs);
}

bool operator>=(const int64_t lhs, const Rational &rhs)
{
    return rhs.operator<=(lhs);
}

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Rational z;
  istrm >> z;

  bool istrm_good = istrm.good() || (!istrm.fail() && !istrm.bad());
  if (istrm_good) {
    std::cout << "Read success: " << str << '\n';
  } else {
    std::cout << "Read error : " << str << '\n';
  }
  return istrm_good;
}