#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator, int denominator)
		: m_numerator{ numerator }
		, m_denominator{ denominator }
	{
		if (m_denominator == 0)
			throw std::runtime_error{ "Denominator 0!!!" };
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << "/" << f.m_denominator << '\n';
		return out;
	}
};


int main()
{
	int first{};
	std::cout << "Enter first integer: ";
	std::cin >> first;

	int second{};
	std::cout << "Enter second integer: ";
	std::cin >> second;

	try
	{
		Fraction fr{ first, second };
		std::cout << "Your fraction is " << fr;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}