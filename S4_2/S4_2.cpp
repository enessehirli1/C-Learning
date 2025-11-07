#include <iostream>


float distanceFallen(int height, int seconds)
{
	float GRAVITY{ 9.8f };
	float new_hight = height - ((GRAVITY * (seconds * seconds)) / 2);

	return new_hight;
}


void printProcess(int height, int seconds)
{
	float new_hight{ distanceFallen(height, seconds) };
	if (new_hight > 0)
		std::cout << "At " << seconds << " seconds, " << "the ball is at height: " << new_hight << '\n';
	else
		std::cout << "At " << seconds << " seconds, " << "the ball is on the ground.\n";
}

int main()
{
	int height{};
	std::cout << "Enter the height of the tower in meters: ";
	std::cin >> height;


	printProcess(height, 0);
	printProcess(height, 1);
	printProcess(height, 2);
	printProcess(height, 3);
	printProcess(height, 4);
	printProcess(height, 5);



	return 0;
}