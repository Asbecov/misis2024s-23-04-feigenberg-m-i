#ifndef COMPLEXHPP08122023
#define COMPLEXHPP08122023

#include <sstream>
#include <iostream>

struct Complex {
	private: 
		double re_{ 0.0 };
		double im_{ 0.0 };
	public:
		Complex()
			: re_{0.0}, im_{0.0}
		{}
		Complex(const Complex& rhs)
			: re_{rhs.getRe()}, im_{rhs.getIm()}
		{}
		Complex(Complex&& rhs)
			: re_{rhs.getRe()}, im_{rhs.getIm()}
		{}
		explicit Complex(double re)
			:re_{re}, im_ {0.0}
		{}
		Complex(double re, double im)
			: re_{re}, im_{im}
		{}
		~Complex() = default;


		Complex& operator=(const Complex& rhs)
		{
			re_= rhs.getRe();
			im_ = rhs.getIm();
			return *this;
		}
		Complex& operator=(Complex&& rhs) {
			re_= rhs.getRe();
			im_ = rhs.getIm();
			return *this;
		}
		
		double getRe() const
		{
			return re_;
		}
		double getIm() const
		{
			return im_;
		}
		void setRe(double re)
		{
			re_ = re;
		}
		void setIm(double im) {
			im_ = im;
		}

		Complex operator-() const;

		Complex operator+(const Complex& rhs);
		Complex operator-(const Complex& rhs);
		Complex operator*(const Complex& rhs);
		Complex operator/(const Complex& rhs);

		Complex& operator+=(const Complex& rhs);
		Complex& operator+=(const double rhs);
		Complex& operator-=(const Complex& rhs);
		Complex& operator-=(const double rhs);
		Complex& operator*=(const Complex& rhs);
		Complex& operator*=(const double rhs);
		Complex& operator/=(const Complex& rhs);
		Complex& operator/=(const double rhs);

		bool operator==(const Complex& rhs) const;
		bool operator!=(const Complex& rhs) const;
		bool operator>(const Complex& rhs) const;
		bool operator>=(const Complex& rhs) const;
		bool operator<(const Complex& rhs) const;
		bool operator<=(const Complex& rhs) const;

		std::ostream& writeTo(std::ostream& ostrm) const;
		std::istream& readFrom(std::istream& istrm);

		static const char left_brace{ '{' };
		static const char comma{ ',' };
		static const char right_brace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& P2) {
	return P2.writeTo(ostrm);
}
inline std::istream& operator<<(std::istream& istrm, Complex& P2) {
	return P2.readFrom(istrm);
}

#endif //COMPLEXHPP08122023