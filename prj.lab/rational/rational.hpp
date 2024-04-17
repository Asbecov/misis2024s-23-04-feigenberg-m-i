#ifndef RATIONALHPP08122024
#define RATIONALHPP08122024

#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>

class Rational {
private:
	int64_t num_{ 0 };
	int64_t den_{ 1 };
	void changeNumber();
	static const char slash_{ '/' }; 
public:
	Rational() = default;
	Rational(const Rational& rhs) = default;
	Rational(Rational&& rhs) = default;
	explicit Rational(const int64_t& rhs)
		: Rational(rhs, 1)
	{}
	Rational(const int64_t& num, const int64_t& den)
		: num_{num}, den_{den}
	{
		if (den_ == 0) {
			throw std::invalid_argument("Division by 0 ins't defined");
		}
		changeNumber();
	}

	Rational& operator=(const Rational& P2) = default;
	Rational& operator=(const int64_t& rhs) {
		num_ = rhs;
		den_ = 1;
		return *this;
	}
	Rational& operator=(Rational&& P2) = default;

	Rational operator-() const {
		return Rational(-num_, den_);
	}

	Rational operator+(const Rational& rhs) const noexcept;
	Rational operator-(const Rational& rhs) const noexcept;
	Rational operator*(const Rational& rhs) const noexcept;
	Rational operator/(const Rational& rhs) const;
	Rational operator+(const int64_t& rhs) const noexcept;
	Rational operator-(const int64_t& rhs) const noexcept;
	Rational operator*(const int64_t& rhs) const noexcept;
	Rational operator/(const int64_t& rhs) const;

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int64_t& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int64_t& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int64_t& rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int64_t& rhs);

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;

	bool operator==(const int64_t& rhs) const;
	bool operator!=(const int64_t& rhs) const;
	bool operator>(const int64_t& rhs) const;
	bool operator>=(const int64_t& rhs) const;
	bool operator<(const int64_t& rhs) const;
	bool operator<=(const int64_t& rhs) const;

	int64_t getNum() const {
		return num_;
	}
	int64_t getDen() const {
		return den_;
	}
	
	std::istream& readFrom(std::istream& istr);
	std::ostream& writeTo(std::ostream& ostr) const;
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

std::istream& operator>>(std::istream& istrm, Rational& rhs);


Rational operator+(int64_t lhs, const Rational& rhs);
Rational operator-(int64_t lhs, const Rational& rhs);
Rational operator*(int64_t lhs, const Rational& rhs);
Rational operator/(int64_t lhs, const Rational& rhs);

bool operator==(const int64_t lhs, const Rational& rhs);
bool operator!=(const int64_t lhs, const Rational& rhs);
bool operator<(const int64_t lhs, const Rational& rhs);
bool operator>(const int64_t lhs, const Rational& rhs);
bool operator<=(const int64_t lhs, const Rational& rhs);
bool operator>=(const int64_t lhs, const Rational& rhs);

bool testParse(const std::string& str);

#endif //RATIONALHPP08122024