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

		inline double get_real() const { return m_real; };
		inline double get_imaginary() const { return m_imaginary; };

		Complex& operator=(const Complex &t_other);
		friend std::ostream& operator<<(std::ostream &t_stream, const Complex &t_complex);
		Complex& operator+=(const Complex &t_other);
		friend Complex operator+(const Complex &lhs, const Complex &rhs);
		friend Complex operator+(const Complex &lhs, double rhs);
		friend Complex operator+(double lhs, const Complex &rhs);
		bool operator==(const Complex &t_other) const;
		bool operator!=(const Complex &t_other) const;
		Complex operator*() const;

	private:

		double m_real = 0.0;
		double m_imaginary = 0.0;

	};
}