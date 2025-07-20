//
// Created by Pranav .
//

#ifndef GENERICRCUBE_H
#define GENERICRCUBE_H

#include "bits/stdc++.h"
using namespace std;
class GenericRcube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const=0;
    static char getColorLetter(COLOR color);
    virtual bool isSolved() const=0;
    static string getMove(MOVE move);
    void print() const;
    vector<MOVE> randomShuffleCube(unsigned int times);
    GenericRcube &move(MOVE ind);
    GenericRcube &invert(MOVE ind);
    virtual GenericRcube &f() = 0;

    virtual GenericRcube &fPrime() = 0;

    virtual GenericRcube &f2() = 0;

    virtual GenericRcube &u() = 0;

    virtual GenericRcube &uPrime() = 0;

    virtual GenericRcube &u2() = 0;

    virtual GenericRcube &l() = 0;

    virtual GenericRcube &lPrime() = 0;

    virtual GenericRcube &l2() = 0;

    virtual GenericRcube &r() = 0;

    virtual GenericRcube &d() = 0;

    virtual GenericRcube &dPrime() = 0;

    virtual GenericRcube &d2() = 0;

    virtual GenericRcube &rPrime() = 0;

    virtual GenericRcube &r2() = 0;

    virtual GenericRcube &b() = 0;

    virtual GenericRcube &bPrime() = 0;

    virtual GenericRcube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;


 };



#endif //GENERICRCUBE_H
