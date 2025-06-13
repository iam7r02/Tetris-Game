# Tetris-Game

I wrote C++ code for Tetris game.

At first, I established the game grid structure.
And then I made blocks. They're tetrominos. There are 7 blocks(L, J, I, O, S, T, Z). I gave them own color.
Random block appears the upper part of screen and it keeps falling down.
You can move them by pressing keypad 1(left),2(down),3(right). If you want to use other key, you can change it at the function HandleInput() in game.cpp file. Every time you press keypad 2, you can get 1 point.
and you can rotate them by pressing space bar. You can also change this.
If you complete a row without hole, that row will be erase automatically. If you erase a row, you can get 100 points. If you erase 2 rows at the same time, you can get 300 points. and If you erase 3 rows at the same time, you can get 500 points.
I set stage. Blocks falling speed up as the stage go up.
When newly spawned block reaches ceiling of grid, this game is over.
You can see next block, score and stage on the right side of display.
and I added sounds(erase row, rotate) and background music.

Thank you for reading this.
