#include <iostream>
#include <vector>
#include <string>

int main()
{
	// construct a "grid" with 3 rows and 4 columns, where every cell is 0
	std::vector<std::vector<int>> grid(3, std::vector<int>(4, 0));

	for (size_t row = 0; row < grid.size(); ++row)
	{
		for (size_t col = 0; col < grid[row].size(); ++col)
		{
			grid[row][col] = row * col;
			std::cout << "Cell (" << row << "," << col << "): " << grid[row][col] << std::endl;
		}
	}
	return 0;
}