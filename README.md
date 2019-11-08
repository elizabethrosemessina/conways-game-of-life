# conways-game-of-life

#### By: Elizabeth Messina
#### Last Edited: May 2019
-------------------------------
Languages/Tools:
 - C++
-------------------------------

Description:

Conway's Game of Life, completed for my Data Structures course.


Rules of Game:
	
	1. Survival: Each cell that has two or three adjacent cells survives until the next generation.
	2. Death: Each cell that has at least four adjacent cells disappears (or dies) by overpopulation. Also, each cell that has at most one adjacent cell dies by isolation.
	3. Birth: Each empty square (i.e., dead cell) that is adjacent to exactly three cells gives birth to a new cell for the next generation. 
	
	-- need to check all 8 spaces surrounding it and add/count with each 1 - if val = 2 or 	  3, nothing happens/survives; if val >= four or val <=1, the space = 0 instead of      1/dies; each cell that already is dead or = 0 and has val = 3 will birth or become    1 again
	-- make a for loop that counts up/gets a numAdj for each value
	-- then separate for loop for killing/birthing depending on the values
