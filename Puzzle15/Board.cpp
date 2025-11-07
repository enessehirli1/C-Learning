#include <iostream>
#include <vector>
#include <algorithm> 
#include "Board.h"


void displayBoard(const Board& b)
{
	std::cout << b;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	for (const auto& arow : b.m_board)
	{
		for (const auto& e : arow)
		{
			if (e == 0)
				out << "" << '\t';
			else
				out << e << '\t';
		}

		out << '\n';
	}

	return out;
}

std::pair<size_t, size_t> Board::findZero() const
{
	for (std::size_t row{ 0 }; row < 4; row++)
	{
		for (std::size_t col{ 0 }; col < 4; col++)
		{
			if (m_board[row][col] == 0)
				return { row, col };
		}
	}

	return { -1, -1 };
}

std::pair<size_t, size_t> Board::getRelativeZero(char input) const
{
	auto [row, col] { findZero() };

	size_t newRow{ row };
	size_t newCol{ col };
	switch (input)
	{
	case 'w': newRow = row + 1; break;
	case 's': newRow = row - 1; break;
	case 'a': newCol = col + 1; break;
	case 'd': newCol = col - 1; break;
	default: -1;
	}

	if (newRow >= 0 && newRow < 4 && newCol >= 0 && newCol < 4)
		return {newRow, newCol};

	return { row, col };
}

void Board::swap(char input)
{
	auto [zeroRow, zeroCol] = findZero();
	auto [valueRow, valueCol] = getRelativeZero(input);

	std::swap(m_board[zeroRow][zeroCol], m_board[valueRow][valueCol]);
}

bool Board::winCondition()
{
	int counter{ 1 };
	for (std::size_t row{ 0 }; row < 4; row++)
	{
		for (std::size_t col{ 0 }; col < 4; col++)
		{
			if (row == 3 && col == 3)
			{
				std::cout << "\nCongratulations. You won!\n";
				return m_board[row][col] == 0;
			}

			if (m_board[row][col] != counter)
				return false;

			counter += 1;
		}
	}
	
	return false;
}
