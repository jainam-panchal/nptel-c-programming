#include <stdio.h>

int findPath(int matrix[100][100], int n, int x, int y, char *path, int pathIndex)
{

	// If the destination is reached, print the path and return
	if (x == n - 1 && y == n - 1)
	{
		path[pathIndex] = '\0'; // Null terminate the string
		printf("%s", path);
		return 1;
	}

	int last = 'I';

	if (pathIndex != 0)
		last = path[pathIndex - 1];

	// Try moving Right
	if (last != 'L' && y + 1 < n && matrix[x][y + 1] == 1)
	{
		path[pathIndex] = 'R';
		if (findPath(matrix, n, x, y + 1, path, pathIndex + 1))
			return 1;
	}

	// Try moving Left
	if (last != 'R' && y - 1 >= 0 && matrix[x][y - 1] == 1)
	{
		path[pathIndex] = 'L';
		if (findPath(matrix, n, x, y - 1, path, pathIndex + 1))
			return 1;
	}

	// Up
	if (last != 'D' && x - 1 >= 0 && matrix[x - 1][y] == 1)
	{
		path[pathIndex] = 'U';
		if (findPath(matrix, n, x - 1, y, path, pathIndex + 1))
			return 1;
	}

	// Down
	if (last != 'U' && x + 1 < n && matrix[x + 1][y] == 1)
	{
		path[pathIndex] = 'D';
		if (findPath(matrix, n, x + 1, y, path, pathIndex + 1))
			return 1;
	}

	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);

	int matrix[100][100];
	char path[1000];

	// Read the matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	findPath(matrix, n, 0, 0, path, 0);

	return 0;
}