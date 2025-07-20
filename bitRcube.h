#ifndef RUBIKSCUBE_BITBOARD_H
#define RUBIKSCUBE_BITBOARD_H

#include "GenericRcube.h"
#include <cstdint>
#include <string>

class RubiksCubeBitboard : public GenericRcube {
private:
    // Face bitboards: each face stores 8 stickers (excluding center) -> 8 * 8 bits = 64 bits
    // Sticker indexing layout per face (arr):
    //   0 1 2
    //   7   3
    //   6 5 4
    uint64_t bitboard[6]{};
    uint64_t solved_side_config[6]{};

    // 2D mapping (row,col) -> ring index (0..7), 8 = center
    int arr[3][3] = {
        {0, 1, 2},
        {7, 8, 3},
        {6, 5, 4}
    };

    // Masks (8-bit and 24-bit)
    static constexpr uint64_t ONE_8  = (1ULL << 8)  - 1ULL;
    static constexpr uint64_t ONE_24 = (1ULL << 24) - 1ULL;

    // --- Helpers ---
    void rotateFace(int faceIndex);  // Rotate a face ring 90° clockwise (advances ring by +2 positions)
    void rotateSide(int dstFace, int d1, int d2, int d3,
                    int srcFace, int s1, int s2, int s3); // Copy 3 stickers from src->dst (single leg of 4-way cycle)
    int  get5bitCorner(const std::string& corner) const;  // Encode corner id + orientation into 5 bits

public:
    // ctor
    RubiksCubeBitboard();

    // --- GenericRcube interface overrides ---
    COLOR        getColor(FACE face, unsigned row, unsigned col) const override;
    bool         isSolved() const override;

    GenericRcube& u() override;
    GenericRcube& uPrime() override;
    GenericRcube& u2() override;

    GenericRcube& l() override;
    GenericRcube& lPrime() override;
    GenericRcube& l2() override;

    GenericRcube& f() override;
    GenericRcube& fPrime() override;
    GenericRcube& f2() override;

    GenericRcube& r() override;
    GenericRcube& rPrime() override;
    GenericRcube& r2() override;

    GenericRcube& b() override;
    GenericRcube& bPrime() override;
    GenericRcube& b2() override;

    GenericRcube& d() override;
    GenericRcube& dPrime() override;
    GenericRcube& d2() override;

    // --- Utilities ---
    uint64_t getCorners() const;          // Packs 8 corners (5 bits each) into a 64-bit value (top to bottom order)
    bool operator==(const RubiksCubeBitboard& other) const;
    RubiksCubeBitboard& operator=(const RubiksCubeBitboard& other);
};

// Hash functor for unordered_{set,map}
struct HashBitboard {
    size_t operator()(const RubiksCubeBitboard& cube) const;
};

#endif // RUBIKSCUBE_BITBOARD_H
