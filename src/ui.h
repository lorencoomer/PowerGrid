#pragma once

typedef struct {
    int col, row;
} PlantPos;

extern PlantPos filled[100];
extern int filled_size;

extern PlantPos filled_sustainable[100];
extern int filled_sustainable_size;

void render(int rows, int columns);