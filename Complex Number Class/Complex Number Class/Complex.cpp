#include "Complex.h"

namespace tutorial
{

	Complex::Complex(double t_real, double t_imaginary) :
		m_real(t_real),
		m_imaginary(t_imaginary)
	{
	}

	Complex& Complex::operator=(const Complex &t_other)
	{	
		// check for self-assignment
		if (this != &t_other) 
		{
			m_real = t_other.m_real;
			m_imaginary = t_other.m_imaginary;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream &t_stream, const Complex &t_complex)
	{
		t_stream << "Real: " << t_complex.m_real << ", Imaginary: " << t_complex.m_imaginary;
		return t_stream;
	}

	Complex& Complex::operator+=(const Complex &t_other)
	{
		m_real += t_other.m_real;
		m_imaginary += t_other.m_imaginary;
		return *this;
	}

	Complex operator+(const Complex &lhs, const Complex &rhs)
	{
		return{ lhs.m_real + rhs.m_real, lhs.m_imaginary + rhs.m_imaginary };
	}

	Complex operator+(const Complex &lhs, double rhs)
	{
		return{ lhs.m_real + rhs, lhs.m_imaginary };
	}

	Complex operator+(double lhs, const Complex &rhs)
	{
		return{ lhs + rhs.m_real, rhs.m_imaginary };
	}

	bool Complex::operator==(const Complex &t_other) const
	{
		return m_real == t_other.m_real && m_imaginary == t_other.m_imaginary;
	}

	bool Complex::operator!=(const Complex &t_other) const
	{
		// define operator != in terms of operator ==
		return !(*this == t_other);
	}

	Complex Complex::operator*() const
	{
		// complex conjugate
		return { m_real, -m_imaginary };
	}

} // namespace tutorial