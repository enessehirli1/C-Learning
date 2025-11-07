#include <iostream>

double getDoubleValue()
{
	double value{};
	std::cout << "Enter a double value: ";
	std::cin >> value;

	return value;
}


char getOperator()
{
	char op{};
	std::cout << "Enter +, -, *, or /: ";
	std::cin >> op;

	return op;
}

void printResult(double x, double y, char op)
{
	double result{};

	if (op == '+')
		result = x + y;

	else if (op == '-')
		result = x - y;

	else if (op == '*')
		result = x * y;

	else if (op == '/')
		result = x / y;

	else
		return;

	std::cout << x << ' ' << op << ' ' << y << " = " << result << '\n';

}

int main()
{
	double doubleFirst { getDoubleValue() };
	double doubleSecond { getDoubleValue() };

	char op { getOperator() };

	printResult(doubleFirst, doubleSecond, op);

	return 0;
}