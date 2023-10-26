/*
ID: tcarvel1
TASK: castle
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

typedef unsigned char uchar;
typedef unsigned int uint;

int WIDTH;
int HEIGHT;

int walls[50][50];

uint components[50][50] = {0};
int componentSize[50*50] = {0};
int numComponents = 0;

uchar WEST = 1;
uchar NORTH = 2;
uchar EAST = 4;
uchar SOUTH = 8;

bool isWall(int x, int y, uchar direction) {
    return (walls[x][y] / direction) % 2 == 1;
}

void setComponent(int x, int y, int comp) {
    components[x][y] = comp;
    if (!isWall(x,y,NORTH) && components[x][y-1] == 0)  setComponent(x,y-1,comp);
    if (!isWall(x,y,SOUTH) && components[x][y+1] == 0) setComponent(x,y+1,comp);
    if (!isWall(x,y,EAST) && components[x+1][y] == 0) setComponent(x+1,y,comp);
    if (!isWall(x,y,WEST) && components[x-1][y] == 0) setComponent(x-1,y,comp);
    componentSize[comp-1] += 1;
}

int main() {
    std::string _;
    std::ifstream fin("castle.in");

    fin >> WIDTH;
    fin >> HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fin >> walls[x][y];
        }
    }

    fin.close();

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (components[x][y] < 1) {
                numComponents += 1;
                setComponent(x,y,numComponents);
            }
        }
    }

    int bestX = 0;
    int bestY = 0;
    uchar bestDir = 0;
    int bestCombinedSize = 0;

    for (int x = WIDTH-1; x >= 0; x--) {
        for (int y = 0; y < HEIGHT; y++) {
            if (x < WIDTH-1) {
                if (components[x][y] != components[x+1][y] && componentSize[components[x][y]-1]+componentSize[components[x+1][y]-1] >= bestCombinedSize) {
                    bestX = x;
                    bestY = y;
                    bestDir = EAST;
                    bestCombinedSize = componentSize[components[x][y]-1]+componentSize[components[x+1][y]-1];
                }
            }

            if (y > 0) {
                if (components[x][y] != components[x][y-1] && componentSize[components[x][y]-1]+componentSize[components[x][y-1]-1] >= bestCombinedSize) {
                    bestX = x;
                    bestY = y;
                    bestDir = NORTH;
                    bestCombinedSize = componentSize[components[x][y]-1]+componentSize[components[x][y-1]-1];
                }
            }
        }
    }

    std::ofstream fout("castle.out");

    fout << numComponents << std::endl;
    int max = 0;
    for (int n = 0; n < numComponents; n++) {
        if (componentSize[n] > max) {
            max = componentSize[n];
        }
    }
    fout << max << std::endl;

    fout << bestCombinedSize << std::endl;
    fout << bestY+1 << " " << bestX+1 << " ";

    if (bestDir == NORTH) fout << "N" << std::endl;
    else fout << "E" << std::endl;

    fout.close();

    return 0;
}