# Powergrid

## Overview
Powergrid is a terminal based strategy game in which you play as the district attourney of Smogville, and have a goal of replacing all unsustainable power with clean, new energy.

## Building
### gcc
```
git clone https://github.com/lorencoomer/PowerGrid
cd PowerGrid
gcc src/main.c src/ui.c src/commands.c -o PowerGrid.o -O3
```
### cmake
```
git clone https://github.com/lorencoomer/PowerGrid
cd PowerGrid
mkdir build
cd build
cmake ..
cmake --build .
```
## Instructions and General Gamerules

! put your terminal in fullscreen !

The objective of the game is to produce enough energy for your town while alse keeping your sustainability in check. You do this by suing unsustainable power plants, causing them to go out of buisness, and then building new and sustainable power plants that produce clean energy for the town of Smogville.

- if you do not meet the energy requirements of Smogville, you will lose money at the end of each turn
- you will also lose money if you dont are not sustainable enough
- sue unsustainable power plants to get money and take them out
- build more power plants to produce more energy
- if you money dips below zero you are fired and lose the game!

### Commands
The ```sue``` command allows you to sue a power plant for breaking a law/act, and gain money out of it. Be careful! if you are wrong about the plant ot the law its breaking, you lose money.
Use this command by passing the tile of the power plant you are suing, and the number corrisponding to the law/act that it is breaking.
For example, if there was a power plant in tile c7, and residents near there claimed to be getting sick due to water poolution, you should run ```sue c7 5``` because 5 corrisponds to the Safe Drinking Water Act (SDWA).

The ```build``` command allows you to build a sustainable power plant on any unoccupied tile if you have enough money. to use this command, run ```build``` plus the tile you want to build on, and the capital letter that corrisponds to the plant you want to build. For example, if i wanted to build a geothermal plant on b4, i would run ```build b4 G``` because G corrisponds to the geothermal plant

The ```pass``` command allows you to pass your turn
