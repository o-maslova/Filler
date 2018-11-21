# Filler


Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one square
above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.
Each successfully placed piece yields a number of points, and has only one player, the goal of the game
could be to get the best score possible. However, it is with two players that the filler takes all his interest.
Each player has for the purpose of placing as many pieces as possible while attempting to prevent
his opponent from doing the same.
At the end of the game, the one with the most points wins the match...

FOR EXAMPLE:
........................................          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
...O....................................          XXXOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................          XXXXOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................          XXXXOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................          XXXXOOOXXXXXXXXXXXXXXXXXXXXXXOOOOXXXXXXX
........................................          XXXXX.OXXXXXXXXXXXXXXOOXOOOXXOOOOX.XXXXX
........................................          XX.XXXOXXXXXXXXOOOOOOOOOOOOOOOOOOOOOOXXX
........................................          .XXXXXOOXXXXXXXXOOOOOOOOOOOOOOOOOOOOXXOO
........................................          ..XXXXOOXOOOOOOXXOOOOOOOOOOOOOOOOOOOOOOO
........................................          .XXXoooOOOOOOOOOXOOXOOOOOOOOOOOOOOOOOOO.
........................................          .XXXOOOOOOOOOOOOXXXXOOOOOOOOOOOOOOOOOOOO
........................................          ...OOOOOOOOOOOOOOOOXXOOOOOOOOOOOOOOOOOOO
........................................          ..OOOOOOOOOOOOOOOOOOXXOOOOOOOOOOOOOOOOOO
........................................          ....OOOOOOOOOOOOOOOOXXXOOOOOOOOOOOOOOOOO
........................................          ....OOOOOOOOOOOOOOOOOOXXXXXXXOOOOOOOOOOO
........................................          ..OOOOOOOOOOOOOOOOOOOOOOOOOXXOOOOOOOOOOO
........................................          ..OOOOOOOOOOOOOOOOOOOOOOOOOOXXOOOOOOOOOO
................................X.......          ..OOOOOOOOOOOOOOOOOOOOOOOOOOXXXXXOOOOOOO
........................................          ..OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
........................................          ..OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
........................................          ...OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
........................................          ....OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.

The project contain the folder 'resources', where the virtual machine which generates the pieces to set is.
In that folder also exist the folder 'players', where the opponent players are, and the folder 'maps',
where maps for the play is stored.

To run the project you need to clone all files, than make the project with command 'make'
and write next string in command line:
resources/filler.vm -p1 omaslova.filler -p2 resources/players/*any_of_file_in_the_directory* -f maps/*any_of_file_in_the_directory*
