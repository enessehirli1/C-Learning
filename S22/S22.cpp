#include <string>
#include <iostream>
#include "Creature.h"
#include "Point2D.h"

int main()
{
	std::cout << "Enter a name for your creature: ";
	std::string name;
	std::cin >> name;

	Creature creature{ name, { 4, 7 } };
	while (true)
	{
		// print the creature's name and location
		std::cout << creature << '\n';

		std::cout << "Enter new X location for creature (-1 to quit): ";
		int x{ 0 };
		std::cin >> x;
		if (x == -1)
			break;

		std::cout << "Enter new Y location for creature (-1 to quit): ";
		int y{ 0 };
		std::cin >> y;
		if (y == -1)
			break;

		creature.moveTo(x, y);
	}

	return 0;
}




















/*
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1{ std::make_shared<Resource>() };
	auto ptr2{ ptr1};

	return 0;
}





class Person
{
private:
	std::string m_name{};
	std::weak_ptr<Person> m_partner{};

public:
	Person(const std::string& name)
		: m_name{ name } 
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;
		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;

	}

	std::shared_ptr<Person> getPartner() const { return m_partner.lock(); }
	const std::string& getName() const { return m_name; }

};

int main()
{
	auto lucy{ std::make_shared<Person>("Lucy") };
	auto ricky{ std::make_shared<Person>("Ricky") };

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

	auto partner = ricky->getPartner(); // get shared_ptr to Ricky's partner
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';



	return 0;
}


template<typename T>
class DynamicArray
{
private:
	T* m_array{};
	int m_length{};

	void alloc(int length)
	{
		m_array = new T[static_cast<std::size_t>(length)];
		m_length = length;

	}

public:
	DynamicArray(int length)
	{
		alloc(length);

	}

	~DynamicArray()
	{
		delete[] m_array;
	}

	DynamicArray(const DynamicArray& arr) = delete;
	DynamicArray& operator=(const DynamicArray& arr) = delete;

	DynamicArray(DynamicArray&& arr) noexcept
		: m_array {arr.m_array}
		, m_length {arr.m_length}
	{
		arr.m_array = nullptr;
		arr.m_length = 0;
	}

	DynamicArray& operator=(DynamicArray&& arr) noexcept
	{
		if (&arr == this)
			return *this;

		delete[] m_array;

		m_array = arr.m_array;
		m_length = arr.m_length;
		arr.m_array = nullptr;
		arr.m_length = 0;

		return *this;
	}

	int getLength() const { return m_length; }
	T& operator[](int index) { return m_array[index]; }
	const T& operator[](int index) const { return m_array[index]; }
};

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::high_resolution_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

// Return a copy of arr with all of the values doubled
DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

int main()
{
	Timer t;

	DynamicArray<int> arr(1000000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);

	std::cout << t.elapsed();
}
*/
