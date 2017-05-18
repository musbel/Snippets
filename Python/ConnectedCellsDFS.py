def getRegionSize(grid, row, column):
	# Make sure we're within the grid boundaries
	if row < 0 or row >= len(grid) or column < 0 or column >= len(grid[row]):
		return 0
	
	if grid[row][column] == 0:
		return 0

	grid[row][column] = 0

	size = 1;
	# Note Python needs +2 because of how range works
	for r in range(row - 1, row + 2):
		for c in range(column - 1, column + 2):
			if r != row or c != column:
				size = size + getRegionSize(grid, r, c)

	return size

def get_biggest_region(grid):
	biggest = 0
	for ri, row in enumerate(grid):
		for ci, column in enumerate(row):
			if grid[ri][ci] == 1:
				biggest = max(biggest, getRegionSize(grid, ri, ci)) 
				
	return biggest

n = int(raw_input().strip())
m = int(raw_input().strip())
grid = []
for grid_i in xrange(n):
	grid_temp = map(int, raw_input().strip().split(' '))
	grid.append(grid_temp)
print get_biggest_region(grid)

