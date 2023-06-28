#ifndef RUBICKS_CUBE_SOLVE_H
#define RUBICKS_CUBE_SOLVE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

void copyCube();

void print();

void solveTopCross();

void findNextTopEdge(int &s, int &p);

void moveTopEdges();

void solveTopCorners();

void findNextTopCorner(int &s, int &p);

void moveTopCorners();

void random();

void solveMiddleLayer();

int findBottomMatch(int color);

void placeMiddleEdge(int color, int edgeSide);

void middleAlgorithm(int color, int direction);

std::string last(); //gets the last move performed
void removeLast(); //removes the last move performed
void UpdateMoves(); //clears all moves

void solveBottomLayer();

void positionBottomCorners();

int numCorrectCorners();

void getCorner(int num, int corners[]);

void swapCorners(int face);

void positionBottomEdges();

int numEdgesInCorrectPos();

void rotateEdges(int face, bool rotClockwise);

void correctBottomCorners();

int cornerOrientation();

int FindIdealRotation(int cornerNum);

void twoCornerRotate(int face, bool goForward);

void correctBottomEdges();

void twoEdgeRotate(int face, bool isNextTo);

void R();
void Ri();

void L();
void Li();

void U();
void Ui();

void D();
void Di();

void F();
void Fi();

void B();
void Bi();

void start();

#endif //RUBICKS_CUBE_SOLVE_H
