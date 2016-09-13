#include "Complex.h"

namespace tutorial
{

	Complex::Complex(double t_real, double t_imaginary) :
		m_real(t_real),
		m_imaginary(t_imaginary)
	{
	}

	const Complex& Complex::operator=(const Complex &t_other)
	{
		m_real = t_other.m_real;
		m_imaginary = t_other.m_imaginary;
		return *this;
	}

	std::ostream& operator<<(std::ostream &t_stream, const Complex &t_complex)
	{
		t_stream << "Real: " << t_complex.m_real << ", Imaginary: " << t_complex.m_imaginary;
		return t_stream;
	}

} // namespace tutorial