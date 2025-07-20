cmake_minimum_required(VERSION 3.31)
project(Rubick_sCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubick_sCubeSolver main.cpp
        GenericRcube.cpp
        GenericRcube.h
        3dRcube.cpp
        1dRcube.cpp
        bitRcube.cpp
        BFSsolver.h
        DFSsolver.h
        IDAstarSolver.h
        IDDFSSsolver.h
        bitRcube.h
        CornerDBMaker.cpp
        CornerDBMaker.h
        CornerPatternDatabase.cpp
        CornerPatternDatabase.h
        NibbleArray.cpp
        NibbleArray.h
        Patterndatabase.cpp
        Patterndatabase.h
        PermutationIndexer.cpp
        PermutationIndexer.h
        math.cpp
        math.h)
