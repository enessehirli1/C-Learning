#pragma once
#include <iostream>
#include <array>
#include <optional>
#include <vector>
#include <algorithm>
#include "Random.h"

class Board
{
private:
	std::array<std::array<int, 4>, 4> m_board{ {} };

public:
	Board()
	{
		std::vector<int> numbers{};
		for (std::size_t i{ 0 }; i < 16; ++i)
			numbers.push_back(static_cast<int>(i));

		std::shuffle(numbers.begin(), numbers.end(), Random::mt);

		std::size_t index{ 0 };
		for (size_t row{ 0 }; row < 4; ++row)
			for (size_t col{ 0 }; col < 4; ++col)
				m_board[row][col] = numbers[index++];
	}

	std::pair<size_t, size_t> findZero() const;
	std::pair<size_t, size_t> getRelativeZero(char input) const;
	void swap(char input);
	bool winCondition();

	friend std::ostream& operator<<(std::ostream& out, const Board& b);

};
