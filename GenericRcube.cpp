#include "GenericRcube.h"
#include <ctime>     // time()
#include <cstdlib>   // rand(), srand()
#include <iostream>  // cout

using namespace std;

char GenericRcube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::RED:    return 'R';
        case COLOR::GREEN:  return 'G';
        case COLOR::BLUE:   return 'B';
        case COLOR::YELLOW: return 'Y';
        case COLOR::WHITE:  return 'W';
        case COLOR::ORANGE: return 'O';
    }
    return '?'; // safety
}

string GenericRcube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::L:       return "L";
        case MOVE::LPRIME:  return "L'";
        case MOVE::L2:      return "L2";
        case MOVE::R:       return "R";
        case MOVE::RPRIME:  return "R'";
        case MOVE::R2:      return "R2";
        case MOVE::U:       return "U";
        case MOVE::UPRIME:  return "U'";
        case MOVE::U2:      return "U2";
        case MOVE::D:       return "D";
        case MOVE::DPRIME:  return "D'";
        case MOVE::D2:      return "D2";
        case MOVE::F:       return "F";
        case MOVE::FPRIME:  return "F'";
        case MOVE::F2:      return "F2";
        case MOVE::B:       return "B";
        case MOVE::BPRIME:  return "B'";
        case MOVE::B2:      return "B2";
    }
    return "?";
}

GenericRcube& GenericRcube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:       return this->l();
        case MOVE::LPRIME:  return this->lPrime();
        case MOVE::L2:      return this->l2();
        case MOVE::R:       return this->r();
        case MOVE::RPRIME:  return this->rPrime();
        case MOVE::R2:      return this->r2();
        case MOVE::U:       return this->u();
        case MOVE::UPRIME:  return this->uPrime();
        case MOVE::U2:      return this->u2();
        case MOVE::D:       return this->d();
        case MOVE::DPRIME:  return this->dPrime();
        case MOVE::D2:      return this->d2();
        case MOVE::F:       return this->f();
        case MOVE::FPRIME:  return this->fPrime();
        case MOVE::F2:      return this->f2();
        case MOVE::B:       return this->b();
        case MOVE::BPRIME:  return this->bPrime();
        case MOVE::B2:      return this->b2();
    }
    return *this;
}

GenericRcube& GenericRcube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:       return this->lPrime();
        case MOVE::LPRIME:  return this->l();
        case MOVE::L2:      return this->l2();
        case MOVE::R:       return this->rPrime();
        case MOVE::RPRIME:  return this->r();
        case MOVE::R2:      return this->r2();
        case MOVE::U:       return this->uPrime();
        case MOVE::UPRIME:  return this->u();
        case MOVE::U2:      return this->u2();
        case MOVE::D:       return this->dPrime();
        case MOVE::DPRIME:  return this->d();
        case MOVE::D2:      return this->d2();
        case MOVE::F:       return this->fPrime();
        case MOVE::FPRIME:  return this->f();
        case MOVE::F2:      return this->f2();
        case MOVE::B:       return this->bPrime();
        case MOVE::BPRIME:  return this->b();
        case MOVE::B2:      return this->b2();
    }
    return *this; // safety
}

void GenericRcube::print() const {
    cout << "Rubik's Cube:\n\n";

    // UP
    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << ' ';
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::UP, row, col)) << ' ';
        cout << '\n';
    }
    cout << '\n';

    // L F R B
    for (int row = 0; row <= 2; row++) {
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << ' ';
        cout << ' ';
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << ' ';
        cout << ' ';
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << ' ';
        cout << ' ';
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << ' ';
        cout << '\n';
    }
    cout << '\n';

    // DOWN
    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << ' ';
        for (int col = 0; col <= 2; col++)
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << ' ';
        cout << '\n';
    }
    cout << '\n';
}

vector<GenericRcube::MOVE> GenericRcube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(static_cast<unsigned>(time(0))); // NOTE: seeding each call
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = rand() % 18;
        auto m = static_cast<MOVE>(selectMove);
        moves_performed.push_back(m);
        this->move(m);
    }
    return moves_performed;
}


string GenericRcube::getCornerColorString(uint8_t ind) const {
    string str;

    switch (ind) {
        case 0: // UFR
            str += getColorLetter(getColor(FACE::UP,    2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;
        case 1: // UFL
            str += getColorLetter(getColor(FACE::UP,    2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT,  0, 2));
            break;
        case 2: // UBL
            str += getColorLetter(getColor(FACE::UP,    0, 0));
            str += getColorLetter(getColor(FACE::BACK,  0, 2));
            str += getColorLetter(getColor(FACE::LEFT,  0, 0));
            break;
        case 3: // UBR
            str += getColorLetter(getColor(FACE::UP,    0, 2));
            str += getColorLetter(getColor(FACE::BACK,  0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;
        case 4: // DFR
            str += getColorLetter(getColor(FACE::DOWN,  0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;
        case 5: // DFL
            str += getColorLetter(getColor(FACE::DOWN,  0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT,  2, 2));
            break;
        case 6: // DBR
            str += getColorLetter(getColor(FACE::DOWN,  2, 2));
            str += getColorLetter(getColor(FACE::BACK,  2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;
        case 7: // DBL
            str += getColorLetter(getColor(FACE::DOWN,  2, 0));
            str += getColorLetter(getColor(FACE::BACK,  2, 2));
            str += getColorLetter(getColor(FACE::LEFT,  2, 0));
            break;
    }
    return str;
}

uint8_t GenericRcube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);
    uint8_t ret = 0;

    // U/D color (W/Y) -> bit 2
    for (auto c : corner) {
        if (c == 'Y') { ret |= (1 << 2); break; }
        if (c == 'W') { break; }
    }
    // F/B color (R/O) -> bit 1
    for (auto c : corner) {
        if (c == 'O') { ret |= (1 << 1); break; }
        if (c == 'R') { break; }
    }
    // R/L color (B/G) -> bit 0
    for (auto c : corner) {
        if (c == 'G') { ret |= (1 << 0); break; }
        if (c == 'B') { break; }
    }
    return ret;
}

uint8_t GenericRcube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    char ud = 0; // store W or Y
    for (auto c : corner) {
        if (c == 'W' || c == 'Y') { ud = c; break; }
    }

    if (corner[1] == ud) return 1;
    if (corner[2] == ud) return 2;
    return 0;
}
