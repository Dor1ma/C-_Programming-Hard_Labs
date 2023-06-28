#include "solve.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int previous_cube[6][3][3] =
        {
                {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //yellow side
                {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, //orange side
                {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}, //blue side
                {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}, //red side
                {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}, //green side
                {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}}  //white side
        };

int cube[6][3][3] =
        {
                {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, //yellow side
                {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, //orange side
                {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}, //blue side
                {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}, //red side
                {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}, //green side
                {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}} ////white side
        };


string moves = "";

void customMakeup(int randomcube[6][3][3])
{
    cout << "Your cube:" << endl;
    ifstream fin("cubedata.txt");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int L;
                fin >> L;
                cout << L;
                randomcube[i][j][k] = L;
            }
        }
        cout << endl;
    }
}

bool correct(int randomcube[6][3][3])
{
    int colors[6] = {0};
    int uniquecenters[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int L;
                L = randomcube[i][j][k];
                colors[L]++;
                if (j == 1 and k == 1)
                {
                    uniquecenters[L]++;
                }
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (colors[i] != 9)
        {
            cout << "Your cube is incorrect, there is problem with colors" << endl;
            return false;
        }
        if (uniquecenters[i] != 1)
        {
            cout << "Your cube is incorrect, there is problem with centers" << endl;
            return false;
        }
    }
    return true;
}

void R()
{
    if (last() == "R  ")
    {
        removeLast();
        moves += "R2 ";
    }
    else if (last() == "R2 ")
    {
        removeLast();
        moves += "Ri ";
    }
    else if (last() == "Ri ")
    {
        removeLast();
    }
    else
    {
        moves += "R  ";
    }

    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[2][i][2] = previous_cube[5][i][2];
        cube[0][i][2] = previous_cube[2][i][2];
        cube[4][i][0] = previous_cube[0][2 - i][2];
        cube[5][i][2] = previous_cube[4][2 - i][0];
    }
    cube[3][0][2] = previous_cube[3][0][0];
    cube[3][2][2] = previous_cube[3][0][2];
    cube[3][2][0] = previous_cube[3][2][2];
    cube[3][0][0] = previous_cube[3][2][0];

    cube[3][1][2] = previous_cube[3][0][1];
    cube[3][2][1] = previous_cube[3][1][2];
    cube[3][1][0] = previous_cube[3][2][1];
    cube[3][0][1] = previous_cube[3][1][0];
}

void Ri()
{
    if (last() == "Ri ")
    {
        removeLast();
        moves += "R2 ";
    }
    else if (last() == "R2 ")
    {
        removeLast();
        moves += "R  ";
    }
    else if (last() == "R  ")
    {
        removeLast();
    }
    else
    {
        moves += "Ri ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[5][i][2] = previous_cube[2][i][2];
        cube[2][i][2] = previous_cube[0][i][2];
        cube[0][2 - i][2] = previous_cube[4][i][0];
        cube[4][2 - i][0] = previous_cube[5][i][2];
    }
    cube[3][0][0] = previous_cube[3][0][2];
    cube[3][0][2] = previous_cube[3][2][2];
    cube[3][2][2] = previous_cube[3][2][0];
    cube[3][2][0] = previous_cube[3][0][0];

    cube[3][0][1] = previous_cube[3][1][2];
    cube[3][1][2] = previous_cube[3][2][1];
    cube[3][2][1] = previous_cube[3][1][0];
    cube[3][1][0] = previous_cube[3][0][1];
}

void L()
{
    if (last() == "L  ")
    {
        removeLast();
        moves += "L2 ";
    }
    else if (last() == "L2 ")
    {
        removeLast();
        moves += "Li ";
    }
    else if (last() == "Li ")
    {
        removeLast();
    }
    else
    {
        moves += "L  ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[5][i][0] = previous_cube[2][i][0];
        cube[2][i][0] = previous_cube[0][i][0];
        cube[0][i][0] = previous_cube[4][2 - i][2];
        cube[4][2 - i][2] = previous_cube[5][i][0];
    }
    cube[1][0][2] = previous_cube[1][0][0];
    cube[1][2][2] = previous_cube[1][0][2];
    cube[1][2][0] = previous_cube[1][2][2];
    cube[1][0][0] = previous_cube[1][2][0];

    cube[1][1][2] = previous_cube[1][0][1];
    cube[1][2][1] = previous_cube[1][1][2];
    cube[1][1][0] = previous_cube[1][2][1];
    cube[1][0][1] = previous_cube[1][1][0];
}

void Li()
{
    if (last() == "Li ")
    {
        removeLast();
        moves += "L2 ";
    }
    else if (last() == "L2 ")
    {
        removeLast();
        moves += "L  ";
    }
    else if (last() == "L  ")
    {
        removeLast();
    }
    else
    {
        moves += "Li ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[2][i][0] = previous_cube[5][i][0];
        cube[0][i][0] = previous_cube[2][i][0];
        cube[4][i][2] = previous_cube[0][2 - i][0];
        cube[5][i][0] = previous_cube[4][2 - i][2];
    }
    cube[1][0][0] = previous_cube[1][0][2];
    cube[1][0][2] = previous_cube[1][2][2];
    cube[1][2][2] = previous_cube[1][2][0];
    cube[1][2][0] = previous_cube[1][0][0];

    cube[1][0][1] = previous_cube[1][1][2];
    cube[1][1][2] = previous_cube[1][2][1];
    cube[1][2][1] = previous_cube[1][1][0];
    cube[1][1][0] = previous_cube[1][0][1];
}

void U()
{
    if (last() == "U  ")
    {
        removeLast();
        moves += "U2 ";
    }
    else if (last() == "U2 ")
    {
        removeLast();
        moves += "Ui ";
    }
    else if (last() == "Ui ")
    {
        removeLast();
    }
    else
    {
        moves += "U  ";
    }

    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[1][0][i] = previous_cube[2][0][i];
        cube[4][0][i] = previous_cube[1][0][i];
        cube[3][0][i] = previous_cube[4][0][i];
        cube[2][0][i] = previous_cube[3][0][i];
    }
    cube[0][0][0] = previous_cube[0][2][0];
    cube[0][0][2] = previous_cube[0][0][0];
    cube[0][2][2] = previous_cube[0][0][2];
    cube[0][2][0] = previous_cube[0][2][2];

    cube[0][0][1] = previous_cube[0][1][0];
    cube[0][1][2] = previous_cube[0][0][1];
    cube[0][2][1] = previous_cube[0][1][2];
    cube[0][1][0] = previous_cube[0][2][1];
}

void Ui()
{
    if (last() == "Ui ")
    {
        removeLast();
        moves += "U2 ";
    }
    else if (last() == "U2 ")
    {
        removeLast();
        moves += "U  ";
    }
    else if (last() == "U  ")
    {
        removeLast();
    }
    else
    {
        moves += "Ui ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[2][0][i] = previous_cube[1][0][i];
        cube[1][0][i] = previous_cube[4][0][i];
        cube[4][0][i] = previous_cube[3][0][i];
        cube[3][0][i] = previous_cube[2][0][i];
    }
    cube[0][2][0] = previous_cube[0][0][0];
    cube[0][0][0] = previous_cube[0][0][2];
    cube[0][0][2] = previous_cube[0][2][2];
    cube[0][2][2] = previous_cube[0][2][0];

    cube[0][1][0] = previous_cube[0][0][1];
    cube[0][0][1] = previous_cube[0][1][2];
    cube[0][1][2] = previous_cube[0][2][1];
    cube[0][2][1] = previous_cube[0][1][0];
}

void D()
{
    if (last() == "D  ")
    {
        removeLast();
        moves += "D2 ";
    }
    else if (last() == "D2 ")
    {
        removeLast();
        moves += "Di ";
    }
    else if (last() == "Di ")
    {
        removeLast();
    }
    else
    {
        moves += "D  ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[2][2][i] = previous_cube[1][2][i];
        cube[1][2][i] = previous_cube[4][2][i];
        cube[4][2][i] = previous_cube[3][2][i];
        cube[3][2][i] = previous_cube[2][2][i];
    }
    cube[5][0][0] = previous_cube[5][2][0];
    cube[5][0][2] = previous_cube[5][0][0];
    cube[5][2][2] = previous_cube[5][0][2];
    cube[5][2][0] = previous_cube[5][2][2];

    cube[5][0][1] = previous_cube[5][1][0];
    cube[5][1][2] = previous_cube[5][0][1];
    cube[5][2][1] = previous_cube[5][1][2];
    cube[5][1][0] = previous_cube[5][2][1];
}

void Di()
{
    if (last() == "Di ")
    {
        removeLast();
        moves += "D2 ";
    }
    else if (last() == "D2 ")
    {
        removeLast();
        moves += "D  ";
    }
    else if (last() == "D  ")
    {
        removeLast();
    }
    else
    {
        moves += "Di ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[1][2][i] = previous_cube[2][2][i];
        cube[4][2][i] = previous_cube[1][2][i];
        cube[3][2][i] = previous_cube[4][2][i];
        cube[2][2][i] = previous_cube[3][2][i];
    }
    cube[5][2][0] = previous_cube[5][0][0];
    cube[5][0][0] = previous_cube[5][0][2];
    cube[5][0][2] = previous_cube[5][2][2];
    cube[5][2][2] = previous_cube[5][2][0];

    cube[5][1][0] = previous_cube[5][0][1];
    cube[5][0][1] = previous_cube[5][1][2];
    cube[5][1][2] = previous_cube[5][2][1];
    cube[5][2][1] = previous_cube[5][1][0];
}

void F()
{
    if (last() == "F  ")
    {
        removeLast();
        moves += "F2 ";
    }
    else if (last() == "F2 ")
    {
        removeLast();
        moves += "Fi ";
    }
    else if (last() == "Fi ")
    {
        removeLast();
    }
    else
    {
        moves += "F  ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[0][2][i] = previous_cube[1][2 - i][2];
        cube[3][i][0] = previous_cube[0][2][i];
        cube[5][0][2 - i] = previous_cube[3][i][0];
        cube[1][2 - i][2] = previous_cube[5][0][2 - i];
    }
    cube[2][0][2] = previous_cube[2][0][0];
    cube[2][2][2] = previous_cube[2][0][2];
    cube[2][2][0] = previous_cube[2][2][2];
    cube[2][0][0] = previous_cube[2][2][0];

    cube[2][1][2] = previous_cube[2][0][1];
    cube[2][2][1] = previous_cube[2][1][2];
    cube[2][1][0] = previous_cube[2][2][1];
    cube[2][0][1] = previous_cube[2][1][0];
}

void Fi()
{
    if (last() == "Fi ")
    {
        removeLast();
        moves += "F2 ";
    }
    else if (last() == "F2 ")
    {
        removeLast();
        moves += "F  ";
    }
    else if (last() == "F  ")
    {
        removeLast();
    }
    else
    {
        moves += "Fi ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[1][i][2] = previous_cube[0][2][2 - i];
        cube[0][2][2 - i] = previous_cube[3][2 - i][0];
        cube[3][2 - i][0] = previous_cube[5][0][i];
        cube[5][0][i] = previous_cube[1][i][2];
    }
    cube[2][0][0] = previous_cube[2][0][2];
    cube[2][0][2] = previous_cube[2][2][2];
    cube[2][2][2] = previous_cube[2][2][0];
    cube[2][2][0] = previous_cube[2][0][0];

    cube[2][0][1] = previous_cube[2][1][2];
    cube[2][1][2] = previous_cube[2][2][1];
    cube[2][2][1] = previous_cube[2][1][0];
    cube[2][1][0] = previous_cube[2][0][1];
}

void B()
{
    if (last() == "B  ")
    {
        removeLast();
        moves += "B2 ";
    }
    else if (last() == "B2 ")
    {
        removeLast();
        moves += "Bi ";
    }
    else if (last() == "Bi ")
    {
        removeLast();
    }
    else
    {
        moves += "B  ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[1][2 - i][0] = previous_cube[0][0][i];
        cube[0][0][i] = previous_cube[3][i][2];
        cube[3][i][2] = previous_cube[5][2][2 - i];
        cube[5][2][2 - i] = previous_cube[1][2 - i][0];
    }
    cube[4][0][2] = previous_cube[4][0][0];
    cube[4][2][2] = previous_cube[4][0][2];
    cube[4][2][0] = previous_cube[4][2][2];
    cube[4][0][0] = previous_cube[4][2][0];

    cube[4][1][2] = previous_cube[4][0][1];
    cube[4][2][1] = previous_cube[4][1][2];
    cube[4][1][0] = previous_cube[4][2][1];
    cube[4][0][1] = previous_cube[4][1][0];
}

void Bi()
{
    if (last() == "Bi ")
    {
        removeLast();
        moves += "B2 ";
    }
    else if (last() == "B2 ")
    {
        removeLast();
        moves += "B  ";
    }
    else if (last() == "B  ")
    {
        removeLast();
    }
    else
    {
        moves += "Bi ";
    }
    copyCube();
    for (int i = 0; i < 3; i++)
    {
        cube[0][0][i] = previous_cube[1][2 - i][0];
        cube[3][i][2] = previous_cube[0][0][i];
        cube[5][2][2 - i] = previous_cube[3][i][2];
        cube[1][2 - i][0] = previous_cube[5][2][2 - i];
    }
    cube[4][0][0] = previous_cube[4][0][2];
    cube[4][0][2] = previous_cube[4][2][2];
    cube[4][2][2] = previous_cube[4][2][0];
    cube[4][2][0] = previous_cube[4][0][0];

    cube[4][0][1] = previous_cube[4][1][2];
    cube[4][1][2] = previous_cube[4][2][1];
    cube[4][2][1] = previous_cube[4][1][0];
    cube[4][1][0] = previous_cube[4][0][1];
}

void solveTopCross()
{
    moveTopEdges();
    for (int i = 1; i < 5; i++)
    {
        int side = 0;
        int pos = 0;
        findNextTopEdge(side, pos);
        int turnsNum = 0;
        if (side == 1) {
            while (cube[5][1][0] == 0)
            {
                D();
            }
            while (cube[0][1][0] == 0)
            {
                U();
                turnsNum++;
            }
            if (pos == 1)
            {
                L();
                L();
            }
            else if (pos == 2)
            {
                L();
            }
            else if (pos == 4)
            {
                Li();
            }
        }
        else if (side == 2)
        {
            while (cube[5][0][1] == 0)
            {
                D();
            }
            while (cube[0][2][1] == 0)
            {
                U();
                turnsNum++;
            }
            if (pos == 1)
            {
                F();
                F();
            }
            else if (pos == 2)
            {
                F();
            }
            else if (pos == 4)
            {
                Fi();
            }
            Di();
        }
        else if (side == 3)
        {
            while (cube[5][1][2] == 0)
            {
                D();
            }
            while (cube[0][1][2] == 0)
            {
                U();
                turnsNum++;
            }
            if (pos == 1)
            {
                R();
                R();
            }
            else if (pos == 2)
            {
                R();
            }
            else if (pos == 4)
            {
                Ri();
            }
            D();
            D();
        }
        else if (side == 4)
        {
            while (cube[5][2][1] == 0)
            {
                D();
            }
            while (cube[0][0][1] == 0)
            {
                U();
                turnsNum++;
            }
            if (pos == 1)
            {
                B();
                B();
            }
            else if (pos == 2)
            {
                B();
            }
            else if (pos == 4)
            {
                Bi();
            }
            D();
        }
        else if (side == 5)
        {
            for (int j = 0; j < 4 - pos; j++)
            {
                D();
            }
        }
        for (int j = 0; j < turnsNum; j++)
        {
            Ui();
        }
        if (side == 5)
        {
            int color = cube[1][2][1];
            for (int a = 1; a < color; a++)
            {
                U();
            }
            L();
            L();
            for (int a = 1; a < color; a++)
            {
                Ui();
            }
        }
        else
        {
            int color = cube[5][1][0];
            if (color < 4)
            {
                for (int a = 1; a < color + 1; a++)
                {
                    U();
                }
            }
            L();
            Bi();
            Li();
            if (color < 4)
            {
                for (int a = 1; a < color + 1; a++)
                {
                    Ui();
                }
            }
        }
    }
}

void moveTopEdges()
{
    for (int i = 0; i < 4; i++)
    {
        if (cube[0][2][1] == 0)
        {
            while (cube[5][0][1] == 0)
            {
                D();
            }
            F();
            F();
        }
        U();
    }
}

void findNextTopEdge(int &s, int &p)
{
    for (s = 1; s < 6; s++)
    {
        if (cube[s][0][1] == 0)
        {
            p = 1;
            break;
        }
        else if (cube[s][1][2] == 0)
        {
            p = 2;
            break;
        }
        else if (cube[s][2][1] == 0)
        {
            p = 3;
            break;
        }
        else if (cube[s][1][0] == 0)
        {
            p = 4;
            break;
        }
    }
}

void solveTopCorners()
{
    moveTopCorners();
    for (int i = 1; i < 5; i++)
    {
        bool bottom = false;
        bool rig = false;
        int side = 0;
        int pos = 0;
        findNextTopCorner(side, pos);
        if (side < 5)
        {
            if (pos == 2)
            {
                rig = true;
            }
            for (int t = 0; t < side + pos - 1; t++)
            {
                Di();
            }
        }
        else
        {
            bottom = true;
            for (int t = 0; t < pos; t++)
            {
                Di();
            }
        }
        if (rig)
        {
            int color = cube[4][2][0];
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    U();
                }
            }
            R();
            D();
            Ri();
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    Ui();
                }
            }
        }
        else if (bottom)
        {
            int color = cube[3][2][2];
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    U();
                }
            }
            R(), D(), D(), Ri();
            Di(), R(), D(), Ri();
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    Ui();
                }
            }
        }
        else
        {
            int color = cube[5][2][2];
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    U();
                }
            }
            Bi(), Di(), B();
            if (color < 4)
            {
                for (int t = 0; t < color; t++)
                {
                    Ui();
                }
            }
        }
    }
}

void moveTopCorners()
{
    for (int i = 0; i < 4; i++)
    {
        if (cube[0][2][2] == 0 || cube[2][0][2] == 0 || cube[3][0][0] == 0)
        {
            while (cube[1][2][2] == 0 || cube[2][2][0] == 0 || cube[5][0][0] == 0)
            {
                D();
            }
            Ri(), D(), R();
        }
        U();
    }
}

void findNextTopCorner(int &s, int &p)
{
    for (s = 1; s < 5; s++)
    {
        if (cube[s][2][0] == 0)
        {
            p = 1;
            return;
        }
        else if (cube[s][2][2] == 0)
        {
            p = 2;
            return;
        }
    }
    if (cube[5][0][0] == 0)
    {
        p = 2;
    }
    else if (cube[5][0][2] == 0)
    {
        p = 3;
    }
    else if (cube[5][2][2] == 0)
    {
        p = 0;
    }
    else
    {
        p = 1;
    }
}

void solveMiddleLayer()
{
    int side = -1;
    int color = -1;
    int count = 0;

    beginning:
    if (side != -1)
    {
        placeMiddleEdge(color, side);
        count++;
        side = -1;
        color = -1;
    }

    for (int i = 1; i <= 4; i++)
    {
        side = findBottomMatch(i);

        if (side != -1) {
            color = i;
            goto beginning;
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        if (cube[i][1][0] != (i))
        {
            middleAlgorithm(i, 1);
            if (count >= 15)
            {
                solveTopCross();
                solveTopCorners();
            }

            goto beginning;
        }
        else if (cube[i][1][2] != i)
        {
            middleAlgorithm(i, 2);

            if (count >= 10)
            {
                solveTopCross();
                solveTopCorners();
            }

            goto beginning;
        }
    }

    int done = 0;
}

int findBottomMatch(int color)
{
    for (int i = 1; i <= 4; i++)
    {
        if (cube[i][2][1] == color)
        {
            if (i % 2 == 0)
            {
                if (cube[5][abs(2 - i)][1] != 5)
                {
                    return i;
                }
            }
            else
            {
                if (cube[5][abs(2 - i)][i - 1] != 5)
                {
                    return i;
                }
            }
        }
    }

    return -1;
}

void placeMiddleEdge(int color, int edgeSide)
{
    if (edgeSide - color == 0)
    {
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == 1)
    {
        Di();
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == 2)
    {
        Di();
        Di();
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == 3)
    {
        D();
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == -1)
    {
        D();
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == -2)
    {
        D();
        D();
        middleAlgorithm(color, -1);
    }
    else if (edgeSide - color == -3)
    {
        Di();
        middleAlgorithm(color, -1);
    }
}

void middleAlgorithm(int color, int direction)
{
    if (color == 1)
    {
        if (cube[5][1][0] == 4 || direction == 1)
        {
            D(), B(), Di(),Bi();
            Di(), Li(), D(), L();
        }
        else if (cube[5][1][0] == 2 || direction == 2) {
            Di(), Fi(), D(), F();
            D(), L(), Di(), Li();
        }
    }
    else if (color == 2)
    {
        if (cube[5][0][1] == 1 || direction == 1)
        {
            D(), L(), Di(), Li();
            Di(), Fi(), D(), F();
        }
        else if (cube[5][0][1] == 3 || direction == 2)
        {
            Di(), Ri() ,D(), R();
            D(), F(), Di(), Fi();
        }
    }
    else if (color == 3)
    {
        if (cube[5][1][2] == 2 || direction == 1)
        {
            D(), F(), Di(), Fi();
            Di(), Ri(), D(), R();
        }
        else if (cube[5][1][2] == 4 || direction == 2)
        {
            Di(), Bi(), D(), B();
            D(), R(), Di(), Ri();
        }
    }
    else if (color == 4)
    {
        if (cube[5][2][1] == 3 || direction == 1)
        {
            D(), R(), Di(), Ri();
            Di(), Bi(), D(), B();
        }
        else if (cube[5][2][1] == 1 || direction == 2)
        {
            Di(), Li(), D(), L();
            D(), B(), Di(), Bi();
        }
    }
}

void solveBottomLayer()
{
    positionBottomCorners();
    positionBottomEdges();
    correctBottomCorners();
    correctBottomEdges();
}

void positionBottomCorners()
{
    int dTurns[4];

    int bestNumDTurns = 0;
    int pos1 = -1;
    int pos2 = -1;

    for (int i = 0; i < 4; i++)
    {
        dTurns[i] = numCorrectCorners();

        if (dTurns[i] == 4)
        {
            pos1 = 4;
            bestNumDTurns = i;
            break;
        }
        else if (dTurns[i] < 4 && dTurns[i] > -1)
        {
            if (pos2 == -1)
            {
                pos1 = dTurns[i];
                bestNumDTurns = i;
            }
        }
        else if (dTurns[i] > 4)
        {
            int side1 = dTurns[i] % 10 + 1;
            int side2 = (int) (dTurns[i] / 10) + 1;
            if (side2 == (side1 + 1) || side1 == (side2 + 1) || (side2 == 4 && side1 == 1) ||
                (side2 == 1 && side1 == 4))
            {
                pos1 = side1;
                pos2 = side2;
                bestNumDTurns = i;
            }
            else if (pos2 == -1)
            {
                pos1 = side1;
                pos2 = side2;
                bestNumDTurns = i;
            }
        }

        D();
    }

    for (int i = 0; i < bestNumDTurns && pos1 != 4; i++)
    {
        D();
    }


    if (pos1 == 4)
    {
        return;
    }
    else if (pos2 != -1 &&
             (pos2 == (pos1 + 1) || pos1 == (pos2 + 1) || (pos2 == 4 && pos1 == 1) || (pos2 == 1 && pos1 == 4))) {
        int oppFace = pos2 + 3;

        if (oppFace > 4)
        {
            oppFace = oppFace - 4;
        }

        swapCorners(oppFace);
        positionBottomCorners();
        return;
    }
    else if (pos2 != -1)
    {
        int face = pos1 + 4;

        if (face > 4)
        {
            face = face - 4;
        }

        int face2 = face + 1;
        if (face2 > 4)
        {
            face2 = face2 - 4;
        }

        swapCorners(face);
        swapCorners(face2);
        swapCorners(face);
        positionBottomCorners();
        return;
    }
    else
    {
        int face = pos1 + 2;

        if (face > 4)
        {
            face = face - 4;
        }

        swapCorners(face);
        positionBottomCorners();
        return;
    }

}

void swapCorners(int face)
{
    if (face == 1)
    {
        Di(),Fi(), D(), B(), Di();
        F(), D(), Bi(), Di();
    }
    else if (face == 2)
    {
        Di(), Ri(), D(), L(), Di();
        R(), D(), Li(), Di();
    }
    else if (face == 3)
    {
        Di(), Bi(), D(), F(), Di();
        B(), D(), Fi(), Di();
    }
    else if (face == 4)
    {
        Di(), Li(), D(), R() ,Di();
        L(), D(), Ri(), Di();
    }
}

int numCorrectCorners()
{
    int cornerColors[3];
    int side1 = 0;
    int side2 = 0;

    int count = 0;

    int colorsMatch = 0;
    int position[4] = {-1, -1, -1, -1};

    for (int i = 0; i < 4; i++)
    {
        getCorner(i, cornerColors);

        side1 = i + 1;
        side2 = i + 2;

        if (side2 == 5)
        {
            side2 = 1;
        }

        for (int j = 0; j < 3; j++)
        {
            if (cornerColors[j] == side1 || cornerColors[j] == side2)
            {
                colorsMatch++;
            }
        }

        if (colorsMatch == 2)
        {
            position[i] = 1;
            count++;
        }

        colorsMatch = 0;
    }

    int pos = 0;
    int multiplier = 1;

    if (count == 4)
    {
        return 4;
    }
    else if (count == 2 || count == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (position[i] == 1)
            {
                pos += i * multiplier;
                multiplier *= 10;
            }
        }
    }
    else
    {
        pos = -1;
    }

    return pos;
}

void getCorner(int num, int corners[])
{
    if (num == 0)
    {
        corners[0] = cube[1][2][2];
        corners[1] = cube[2][2][0];
        corners[2] = cube[5][0][0];
    }
    else if (num == 1)
    {
        corners[0] = cube[2][2][2];
        corners[1] = cube[3][2][0];
        corners[2] = cube[5][0][2];
    }
    else if (num == 2)
    {
        corners[0] = cube[3][2][2];
        corners[1] = cube[4][2][0];
        corners[2] = cube[5][2][2];
    }
    else if (num == 3)
    {
        corners[0] = cube[4][2][2];
        corners[1] = cube[1][2][0];
        corners[2] = cube[5][2][0];
    }
}

void positionBottomEdges()
{
    int pos = numEdgesInCorrectPos();

    if (pos == 0)
    {
        rotateEdges(2, true);
        positionBottomEdges();
        return;
    }
    else if (pos == 5)
    {
        return;
    }
    else
    {
        bool clockwise = pos > 0;

        int face = abs(pos) + 1;

        if (face > 4)
        {
            face = face - 4;
        }

        rotateEdges(face, clockwise);
        return;
    }
}

int numEdgesInCorrectPos()
{
    int edges[4][2] = {{cube[5][1][0], cube[1][2][1]},
                       {cube[5][0][1], cube[2][2][1]},
                       {cube[5][1][2], cube[3][2][1]},
                       {cube[5][2][1], cube[4][2][1]}};

    int correctPos = -1;
    int numCorrect = 0;
    bool isOneCorrect = false;
    int positions[4];

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (edges[i - 1][j] == i)
            {
                isOneCorrect = true;
                correctPos = i - 1;
                numCorrect++;
            }

            if (edges[i - 1][j] != 5)
            {
                positions[i - 1] = edges[i - 1][j];
            }
        }
    }

    if (numCorrect == 4)
    {
        return 5;
    }

    if (!isOneCorrect)
    {
        return 0;
    }
    else
    {
        bool clockwise = false;
        bool firstTime = true;
        int numTimesThrough = 0;
        numCorrect = 0;
        int temp;
        int temp2;

        while (numCorrect != 4)
        {
            firstTime = true;
            numCorrect = 0;
            for (int i = 0; i < 4; i++)
            {
                if (i != correctPos)
                {
                    if (firstTime)
                    {
                        firstTime = false;
                        temp = positions[i];

                        int j = i - 1;

                        if (j < 0)
                        {
                            j = 4 + j;
                        }

                        if (j == correctPos)
                        {
                            j--;
                            if (j < 0)
                            {
                                j = 4 + j;
                            }
                        }

                        positions[i] = positions[j];
                    }
                    else
                    {
                        temp2 = positions[i];
                        positions[i] = temp;
                        temp = temp2;
                    }
                }

                if (positions[i] == i + 1)
                {
                    numCorrect++;
                }
            }

            numTimesThrough++;
        }

        clockwise = numTimesThrough == 1;
        correctPos++;

        if (!clockwise)
        {
            correctPos = -1 * (correctPos);
        }
    }

    return correctPos;
}

void rotateEdges(int face, bool rotClockwise)
{
    if (face == 1)
    {
        if (rotClockwise)
        {
            F(), F(), D(), Li();
            R(), F(), F(), L();
            Ri(), D(), F(), F();
        }
        else
        {
            F(), F(), Di(), Li();
            R(), F(), F(), L();
            Ri(), Di(), F(), F();
        }
    }
    else if (face == 2)
    {
        if (rotClockwise)
        {
            R(), R(), D(), Fi();
            B(), R(), R(), F();
            Bi(), D(), R(), R();
        }
        else
        {
            R(), R(), Di(), Fi();
            B(), R(), R(), F();
            Bi(), Di(), R(), R();
        }
    }
    else if (face == 3)
    {
        if (rotClockwise)
        {
            B(), B(), D(), Ri();
            L(), B(), B(), R();
            Li(), D(), B(), B();
        }
        else
        {
            B(), B(), Di(),Ri();
            L(), B(), B(), R();
            Li(), Di(), B(), B();
        }
    }
    else if (face == 4)
    {
        if (rotClockwise)
        {
            L(), L(), D(), Bi();
            F(), L(), L(), B();
            Fi(), D(), L(), L();
        }
        else
        {
            L(), L(), Di(), Bi();
            F(), L(), L(), B();
            Fi(), Di(), L(), L();
        }
    }
}

void correctBottomCorners()
{
    int result = cornerOrientation();

    while (result != 5)
    {
        twoCornerRotate(abs(FindIdealRotation(result)), FindIdealRotation);

        result = cornerOrientation();
    }
}

int cornerOrientation()
{
    int numCorrect = 0;
    int wrongPosition = 0;

    int corners[4] = {cube[5][0][0], cube[5][0][2], cube[5][2][2], cube[5][2][0]};

    for (int i = 0; i < 4; i++)
    {
        if (corners[i] == 5)
        {
            numCorrect++;
        }
        else
        {
            wrongPosition = i;
        }
    }

    if (numCorrect == 4)
    {
        return 5;
    }

    return wrongPosition;
}

int FindIdealRotation(int cornerNum)
{
    int corners[4] = {cube[5][0][0], cube[5][0][2], cube[5][2][2], cube[5][2][0]};

    int corner1 = cornerNum + 1;
    int corner2 = cornerNum - 1;

    if (corner1 > 3)
    {
        corner1 = 4 - corner1;
    }

    if (corner2 < 0)
    {
        corner2 = 4 + corner2;
    }

    int finalCorner = -1;
    int face = -1;

    if (corners[cornerNum] == corners[corner1])
    {
        finalCorner = corner1;

        face = corners[finalCorner] + 1;

        if (face > 4)
        {
            face = face - 4;
        }

        return face;
    }
    else if (corners[cornerNum] == corners[corner2])
    {
        finalCorner = corner2;

        face = corners[finalCorner] + 1;

        if (face > 4)
        {
            face = face - 4;
        }

        return face;
    }
    else if (abs(corners[cornerNum] - corners[corner1]) == 2 && corners[corner1] != 5)
    {
        finalCorner = corner1;
        face = corners[finalCorner];
        return -face;
    }
    else if (abs(corners[cornerNum] - corners[corner2]) == 2 && corners[corner2] != 5)
    {
        finalCorner = corner2;
        face = corners[cornerNum];
        return -face;
    }
    else
    {
        face = corners[cornerNum];
        return face;
    }
}

void twoCornerRotate(int face, bool goForward)
{
    if (face == 1)
    {
        if (goForward)
        {
            Bi(), U(), B(), L();
            U(), Li(), D(), L();
            Ui(), Li(), Bi(), Ui();
            B(), Di();
        }
        else
        {
            D(), Bi(), U(), B();
            L(), U(), Li(), Di();
            L(), Ui(), Li(), Bi();
            Ui(), B();
        }
    }
    else if (face == 2)
    {
        if (goForward)
        {
            Li(), U(), L(), F();
            U(), Fi(), D(), F();
            Ui(), Fi(), Li(), Ui();
            L(), Di();
        }
        else
        {
            D(), Li(), U(), L();
            F(), U(), Fi(), Di();
            F(), Ui(), Fi(), Li();
            Ui(), L();
        }
    }
    else if (face == 3)
    {
        if (goForward)
        {
            Fi(), U(), F(), R();
            U(), Ri(), D(), R();
            Ui(), Ri(), Fi(), Ui();
            F(), Di();
        }
        else
        {
            D(), Fi(), U(), F();
            R(), U(), Ri(), Di();
            R(), Ui(), Ri(), Fi();
            Ui(), F();
        }
    }
    else if (face == 4)
    {
        if (goForward)
        {
            Ri(), U(), R(), B();
            U(), Bi(), D(), B();
            Ui(), Bi(), Ri(), Ui();
            R(), Di();
        }
        else
        {
            D(), Ri(), U(), R();
            B(), U(), Bi(), Di();
            B(), Ui(), Bi(), Ri();
            Ui(), R();
        }
    }
}

void correctBottomEdges()
{
    int edges[4] = {cube[5][1][0], cube[5][0][1], cube[5][1][2], cube[5][2][1]};

    bool isTogether = false;
    bool isStart = false;
    int numWrong = 0;
    int pos1 = -1;
    int pos2 = -1;
    int j = 0;

    for (int i = 0; i < 5; i++)
    {
        j = i;

        if (i == 4)
        {
            j = 0;
        }

        if (edges[j] != 5)
        {
            numWrong++;
            if (isStart)
            {
                pos1 = j;
                isStart = true;
            }
            else
            {
                pos2 = j;
                isTogether = true;
            }
        }
        else
        {
            isStart = false;
        }
    }

    if (numWrong >= 4)
    {
        twoEdgeRotate(1, false);
        twoEdgeRotate(2, false);
        return;
    }
    else
    {
        if (pos2 != -1)
        {
            twoEdgeRotate(pos2 + 1, isTogether);
        }
        else
        {
            twoEdgeRotate(pos1 + 1, isTogether);
        }
        return;
    }
}

void twoEdgeRotate(int face, bool isNextTo)
{
    if (face == 1)
    {
        if (isNextTo)
        {
            L(), Ui(), D(), F();
            F(), D(), D(), U();
            U(), B(), D(), Bi();
            U(), U(), D(), D();
            F(), F(), Di(), U();
            Li(), Di();
        }
        else
        {
            L(), Ui(), D(), F();
            F(), D(), D(), U();
            U(), B(), D(), D();
            Bi(), U(), U(), D();
            D(), F(), F(), Di();
            U(), Li(), Di(), Di();
        }
    }
    else if (face == 2)
    {
        if (isNextTo)
        {
            F(), Ui(), D(), R();
            R(), D(), D(), U();
            U(), L(), D(), Li();
            U(), U(), D(), D();
            R(), R(), Di(), U();
            Fi(), Di();
        }
        else
        {
            F(), Ui(), D(), R();
            R(), D(), D(), U();
            U(), L(), D(), D();
            Li(), U(), U(), D();
            D(), R(), R(), Di();
            U(), Fi(), Di(), Di();
        }
    }
    else if (face == 3)
    {
        if (isNextTo)
        {
            R(), Ui(), D(), B();
            B(), D(), D(), U();
            U(), F(), D(), Fi();
            U(), U(), D(), D();
            B(), B(), Di(), U();
            Ri(), Di();
        }
        else
        {
            R(), Ui(), D(), B();
            B(), D(), D(), U();
            U(), F(), D(), D();
            Fi(), U(), U(), D();
            D(), B(), B(), Di();
            U(), Ri(), Di(), Di();
        }
    }
    else if (face == 4)
    {
        if (isNextTo)
        {
            B(), Ui(), D(), L();
            L(), D(), D(), U();
            U(), R(), D(), Ri();
            U(), U(), D(), D();
            L(), L(), Di(), U();
            Bi(), Di();
        }
        else
        {
            B(), Ui(), D(), L();
            L(), D(), D(), U();
            U(), R(), D(), D();
            Ri(), U(), U(), D();
            D(), L(), L(), Di();
            U(), Bi(), Di(), Di();
        }
    }
}

void copyCube()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                previous_cube[i][j][k] = cube[i][j][k];
            }
        }
    }
}

void print()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << cube[i][j][k] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

string last()
{
    if (moves.size() < 3)
    {
        return "";
    }
    int s = moves.size();
    return moves.substr(s - 3, 3);
}

void removeLast()
{
    if (moves.size() < 3)
    {
        return;
    }
    int s = moves.size();
    moves = moves.substr(0, s - 3);
}

void UpdateMoves()
{
    moves = "";
}

void random()
{
    srand(time(NULL));
    for (int i = 0; i < 30; i++)
    {
        int num = rand() % 12 + 1;
        switch (num)
        {
            case 1:
                R();
                break;
            case 2:
                Ri();
                break;
            case 3:
                U();
                break;
            case 4:
                Ui();
                break;
            case 5:
                F();
                break;
            case 6:
                Fi();
                break;
            case 7:
                L();
                break;
            case 8:
                Li();
                break;
            case 9:
                B();
                break;
            case 10:
                Bi();
                break;
            case 11:
                D();
                break;
            case 12:
                Di();
                break;
        }
    }
}

void solver()
{
    UpdateMoves();
    print();
    solveTopCross();
    cout << "cross-making: " << endl << moves << endl;
    UpdateMoves();
    print();
    solveTopCorners();
    cout << "corners-making: " << endl << moves << endl;
    UpdateMoves();
    print();
    solveMiddleLayer();
    cout << "middle layer: " << endl << moves << endl;
    UpdateMoves();
    print();
    solveBottomLayer();
    cout << "Bottom layer: " << endl << moves << endl;
    UpdateMoves();
    print();
}

void start()
{
    customMakeup(cube);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                previous_cube[i][j][k] = cube[i][j][k];
            }
        }
        cout << endl;
    }
    random();
    cout << "Random shuffle for your cube: " << endl << moves << endl;
    if (correct(cube))
    {
        cout << "The randomly shuffled cube is correct" << endl;
        solver();
    }
}