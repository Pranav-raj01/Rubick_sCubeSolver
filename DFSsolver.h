//
// Created by Pranav .
//

#include<bits/stdc++.h>
#include "GenericRcube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<GenericRcube::MOVE> moves;
    int max_search_depth;

    //    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(GenericRcube::MOVE(i));
            moves.push_back(GenericRcube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(GenericRcube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<GenericRcube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H