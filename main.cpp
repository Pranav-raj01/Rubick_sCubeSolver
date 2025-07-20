//
// main.cpp
//

#include <bits/stdc++.h>
#include "GenericRcube.h"
#include "GenericRcube.cpp"
#include "bitRcube.cpp"
#include "1dRcube.cpp"
#include "3dRcube.cpp"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFSSsolver.h"


using namespace std;

int main() {
        RubiksCubeBitboard cube;
        cube.print();
        auto shuffle = cube.randomShuffleCube(6);
        cout << "Shuffled with: ";
        for (auto m: shuffle) cout << cube.getMove(m) << " ";
        cout << "\n";
        DFSSolver<RubiksCubeBitboard, HashBitboard> dfs(cube, 8);
        auto sol = dfs.solve();
        cout << "Solution: ";
        for (auto m: sol) cout << cube.getMove(m) << " ";
        cout << "\n";
        dfs.rubiksCube.print();
        return 0;
}


