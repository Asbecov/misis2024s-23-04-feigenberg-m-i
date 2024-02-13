#ifndef RATIONALHPP08122024
#define RATIONALHPP08122024

#include <sstream>
#include <iostream>

class Rational {
private:
	int num{ 0 };
	int den{ 1 };
public:
	Rational() = default;
	Rational(const Rational& P2) = default;
	explicit Rational(const int& nnum)
		: Rational(nnum, 1)
	{
	}
	Rational(const int& nnum, const int& nden)
		: num((nnum* (nden > 0 ? 1 : -1)))
		, den(std::abs(nden))
	{
		if (den == 0) {
			throw std::invalid_argument("Division by zero is not allowed");
		}
	}
	Rational& operator=(const Rational& P2) = default;
	Rational operator-() const;

	bool operator==(const Rational& P2) const;
	bool operator==(const int& nnum) const;
	friend bool operator==(const int& num, const Rational& P2);
	bool operator!=(const Rational& P2) const;
	bool operator!=(const int& nnum) const;
	friend bool operator!=(const int& num, const Rational& P2);
	bool operator>(const Rational& P2) const;
	bool operator>(const int& nnum) const;
	friend bool operator>(const int& nnum, const Rational& P2);
	bool operator>=(const Rational& P2) const;
	bool operator>=(const int& nnum) const;
	friend bool operator>=(const int& nnum, const Rational& P2);
	bool operator<(const Rational& P2) const;
	bool operator<(const int& nnum) const;
	friend bool operator<(const int& nnum, const Rational& P2);
	bool operator<=(const Rational& P2) const;
	bool operator<=(const int& nnum) const;
	friend bool operator<=(const int& nnum, const Rational& P2);

	Rational operator=(const int& nnum);
	operator int() const;
	operator double() const;
	//friend int operator=(int nnum, const Rational& p2);
	Rational operator+=(const Rational& P2);
	Rational operator+=(const int& nnum);
	Rational operator-=(const Rational& P2);
	Rational operator-=(const int& nnum);
	Rational operator*=(const Rational& P2);
	Rational operator*=(const int& nnum);
	Rational operator/=(const Rational& P2);
	Rational operator/=(const int& nnum);
	Rational operator+(const Rational& P2) const;
	Rational operator+(const int& nnum) const;
	friend Rational operator+(const int& nnum, const Rational& P2);
	Rational operator-(const Rational& P2) const;
	Rational operator-(const int& nnum) const;
	friend Rational operator-(const int& nnum, const Rational& P2);
	Rational operator*(const Rational& P2) const;
	Rational operator*(const int& nnum) const;
	friend Rational operator*(const int& nnum, const Rational& P2);
	Rational operator/(const Rational& P2) const;
	Rational operator/(const int& nnum) const;
	friend Rational operator/(const int& nnum, const Rational& P2);
	Rational operator++();
	Rational operator++(int k);
	Rational operator--();
	Rational operator--(int k);

	static const char slash{ '/' };

	std::ostream& writeto(std::ostream& ostr) const;
	std::istream& readfrom(std::istream& istrm);

	int gcd() const;
	int lcm(int nnum, int nden) const;
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& P2) {
	return P2.writeto(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& P2) {
	return P2.readfrom(istrm);
}

#endif //RATIONALHPP08122024