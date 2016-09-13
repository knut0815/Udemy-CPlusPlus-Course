#pragma once

#include <iostream>

namespace tutorial
{
	class Complex
	{
	public:
		Complex() = default;
		Complex(double t_real, double t_imaginary);
		Complex(const Complex &t_other) = default;
		const Complex& operator=(const Complex &t_other);

		inline double get_real() { return m_real; };
		inline double get_imaginary() { return m_imaginary; };

		friend std::ostream& operator<<(std::ostream &t_stream, const Complex &t_complex);
	private:
		double m_real = 0.0;
		double m_imaginary = 0.0;
	};
}