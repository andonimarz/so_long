# so_long

## Final grade 100/100
  
## Description
  Solo – about 60 hours

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

## Table of Contents

- [Installation](#installation)
- [Mandatory](#Mandatory)
  - [Game](#Game)
  - [Graphic_management](#Graphic_management)
  - [Map](#Map)
  

## Installation

Clone this repository using the following command.

    git clone https://github.com/andonimarz/so_long.git

## Mandatory
  
Your project must comply with the following rules:

• You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.

• You have to turn in a Makefile which will compile your source files. It must not relink.

• Your program has to take as parameter a map description file ending with the .ber extension.

  ### Game

• The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.

• The W, A, S, and D keys must be used to move the main character.

• The player should be able to move in these 4 directions: up, down, left, right.

• The player should not be able to move into walls.

• At every move, the current number of movements must be displayed in the shell.

• You have to use a 2D view (top-down or profile).

• The game doesn’t have to be real time.

• Although the given examples show a dolphin theme, you can create the world you want.

  ### Graphic_management
  
• Your program has to display the image in a window.

• The management of your window must remain smooth (changing to another window, minimizing, and so forth).

• Pressing ESC must close the window and quit the program in a clean way.

• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.

• The use of the images of the MiniLibX is mandatory.

  ###  Map

• The map has to be constructed with 3 components: walls, collectibles, and free space.

• The map can be composed of only these 5 characters:

      0 for an empty space,
      1 for a wall,
      C for a collectible,
      E for a map exit,
      P for the player’s starting position.

Here is a simple valid map:

      1111111111111
      10010000000C1
      1000011111001
      1P0011E000001
      1111111111111
      
• The map must contain at least 1 exit, 1 collectible, and 1 starting position.

• The map must be rectangular.

• The map must be closed/surrounded by walls. If it’s not, the program must return an error.

• You have to check if there’s a valid path in the map.

• You must be able to parse any kind of map, as long as it respects the above rules.

• Another example of a minimal .ber map:

      1111111111111111111111111111111111
      1E0000000000000C00000C000000000001
      1010010100100000101001000000010101
      1010010010101010001001000000010101
      1P0000000C00C0000000000000000000C1
      1111111111111111111111111111111111

• If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.
