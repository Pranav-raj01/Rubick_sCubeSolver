//
// Created by Pranav .
//
#include "GenericRcube.h"
/*
 * up    ->  0 white
 * left  ->  1 green
 * front ->  2 red
 * right ->  3 blue
 * back  ->  4 orange
 * down  ->  5 yellow
 */
class array3dRcube : public GenericRcube{
private:
    void rotateFace(int ind) {
        char temp[3][3]={};
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                temp[i][j]=cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp[2][2 - i];
    }
public:
    char cube[6][3][3];
    array3dRcube() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE face, unsigned row,unsigned col) const override {
        char color=cube[(int)face][row][col];
        switch (color) {
            case 'B': return COLOR::BLUE;
            case 'R': return COLOR::RED;
            case 'G': return COLOR::GREEN;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            default : return COLOR::WHITE;
        }
    }
    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }
    GenericRcube&u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }
    GenericRcube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }
    GenericRcube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    GenericRcube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    GenericRcube &lPrime() override {
        this->l();
        this->l();
        this->l();
        return *this;
    }

    GenericRcube &l2() override {
        this->l();
        this->l();
        return *this;
    }

    GenericRcube &f() override {
        this->rotateFace(2);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];
        return *this;
    }

    GenericRcube &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    }

    GenericRcube &f2() override {
        this->f();
        this->f();
        return *this;
    }

    GenericRcube &r() override {
        this->rotateFace(3);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];
        return *this;
    }

    GenericRcube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    GenericRcube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    GenericRcube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    GenericRcube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    GenericRcube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    GenericRcube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    GenericRcube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    GenericRcube &d2() override {
        this->d();
        this->d();

        return *this;
    }
    bool operator==(const array3dRcube &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }
    array3dRcube &operator=(const array3dRcube &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }


};
struct Hash3d {
    size_t operator()(const array3dRcube &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k]; // concatenate all stickers
                }
            }
        }
        return hash<string>()(str);
    }
};
