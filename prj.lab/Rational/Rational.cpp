#include "rational.hpp"

int Rational::gcd() const{
	int nnum = std::abs(num);
	int nden = std::abs(den);
	while (nnum != 0 && nden != 0) {
		if (nnum >= nden) {
			nnum %= nden;
		}
		else {
			nden %= nnum;
		}
	}
	return (nnum > nden ? nnum : nden);
}
int Rational::lcm(int nnum, int nden) const{
	Rational P2(nnum, nden);
	return ((nnum * nden) / P2.gcd());
}
Rational Rational::operator-() const{
	return (Rational(-this->num, this->den));
}
bool Rational::operator==(const Rational& P2) const{
	return ((this->num / this->gcd() == P2.num / P2.gcd()) && (this->den / this->gcd() == P2.den / P2.gcd()));
}
bool Rational::operator==(const int& nnum) const{
	return (operator==(Rational(nnum)));
}
bool operator==(const int& nnum, const Rational& P2) {
	return ((P2.num / P2.gcd() == nnum) && (P2.den / P2.gcd() == 1));
}
bool Rational::operator!=(const Rational& P2) const{
	return (!operator==(P2));
}
bool Rational::operator!=(const int& nnum) const{
	return (operator!=(Rational(nnum, 1)));
}
bool operator!=(const int& nnum, const Rational& P2) {
	return (!operator==(nnum, P2));
}
bool Rational::operator>(const Rational& P2) const{
	return (this->num * P2.den > P2.num * this->den);
}
bool Rational::operator>(const int& nnum) const {
	return (operator>(Rational(nnum)));
}
bool operator>(const int& nnum, const Rational& P2) {
	return (P2.operator<(nnum));
}
bool Rational::operator>=(const Rational& P2) const {
	return (this->num * P2.den >= P2.num * this->den);
}
bool Rational::operator>=(const int& nnum) const {
	return (operator>=(Rational(nnum)));
}
bool operator>=(const int& nnum, const Rational& P2) {
	return (P2.operator<=(nnum));
}
bool Rational::operator<(const Rational& P2) const {
	return (this->num * P2.den < P2.num * this->den);
}
bool Rational::operator<(const int& nnum) const {
	return (operator<(Rational(nnum)));
}
bool operator<(const int& nnum, const Rational& P2) {
	return (P2.operator>(nnum));
}
bool Rational::operator<=(const Rational& P2) const {
	return (this->num * P2.den <= P2.num * this->den);
}
bool Rational::operator<=(const int& nnum) const {
	return (operator<=(Rational(nnum)));
}
bool operator<=(const int& nnum, const Rational& P2) {
	return (P2.operator>=(nnum));
}
Rational Rational::operator=(const int& nnum) {
	return operator=(Rational(nnum));
}
Rational::operator int() const {
	int nnum(num / den);
	return nnum;
}
Rational::operator double() const {
	double nnum(num / den);
	return nnum;
}
//int operator=(int nnum, const Rational& p2) {
//	nnum = p2.num;
//	return nnum;
//}
Rational Rational::operator+=(const Rational& P2) {
	int common_mul = lcm(this->den, P2.den);
	this->num = this->num * (common_mul / this->den) + P2.num * (common_mul / P2.den);
	this->den = common_mul;
	return *this;
}
Rational Rational::operator+=(const int& nnum) {
	return (operator+=(Rational(nnum)));
}
Rational Rational::operator-=(const Rational& P2) {
	int common_mul = lcm(this->den, P2.den);
	this->num = this->num * (common_mul / this->den) - P2.num * (common_mul / P2.den);
	this->den = common_mul;
	return *this;
}
Rational Rational::operator-=(const int& nnum) {
	return (operator-=(Rational(nnum)));
}
Rational Rational::operator*=(const Rational& P2) {
	this->num *= P2.num;
	this->den *= P2.den;
	return *this;
}
Rational Rational::operator*=(const int& nnum) {
	return (operator*=(Rational(nnum)));
}
Rational Rational::operator/=(const Rational& P2) {
	if (P2.num == 0) {
		throw std::invalid_argument("Division by zero is now allowed");
	}
	this->num *= P2.den;
	this->den *= P2.num;
	return *this;
}
Rational Rational::operator/=(const int& nnum) {
	return (operator*=(Rational(1,nnum)));
}
Rational Rational::operator+(const Rational& P2) const {
	Rational sum(*this);
	sum += P2;
	return sum;
}
Rational Rational::operator+(const int& nnum) const {
	return (operator+(Rational(nnum)));
}
Rational operator+(const int& nnum, const Rational& P2) {
	return (P2.operator+(nnum));
}
Rational Rational::operator-(const Rational& P2) const {
	Rational diff(*this);
	diff -= P2;
	return diff;
}
Rational Rational::operator-(const int& nnum) const {
	return (operator-(Rational(nnum)));
}
Rational operator-(const int& nnum, const Rational& P2) {
	return (P2.operator-(nnum));
}
Rational Rational::operator*(const Rational& P2) const {
	Rational mul(*this);
	mul *= P2;
	return mul;
}
Rational Rational::operator*(const int& nnum) const {
	return (operator*(Rational(nnum)));
}
Rational operator*(const int& nnum, const Rational& P2) {
	return (P2.operator*(nnum));
}
Rational Rational::operator/(const Rational& P2) const {
	Rational divi(*this);
	divi /= P2;
	return divi;
}
Rational Rational::operator/(const int& nnum) const {
	return (operator/(Rational(nnum)));
}
Rational operator/(const int& nnum, const Rational& P2) {
	return (P2.operator/(nnum));
}
Rational Rational::operator++() {
	this->num += this->den;
	return *this;
}
Rational Rational::operator++(int k) {
	Rational NP2(this->num, this->den);
	this->num += this->den;
	return NP2;
}
Rational Rational::operator--() {
	this->num -= this->den;
	return *this;
}
Rational Rational::operator--(int k) {
	Rational NP2(this->num, this->den);
	this->num -= this->den;
	return NP2;
}
std::ostream& Rational::writeto(std::ostream& ostrm) const {
	ostrm << this->num / this->gcd() << slash << this->den / this->gcd();
	return ostrm;
}
std::istream& Rational::readfrom(std::istream& istrm) {
	int nnum{ 0 };
	int nden{ 0 };
	char nslash{};
	istrm >> nnum >> nslash >> nden;
	if (istrm.good()) {
		if (nslash == slash) {
			this->num = nnum;
			this->den = nden;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}