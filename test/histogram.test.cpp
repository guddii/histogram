/**
 *  @file caesar.test.cpp
 *  @brief Unit test for caesar en- and decryption.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/google/googletest/tree/master/googletest/docs
 *  @see https://github.com/guddii/histogram
 *  @bug https://github.com/guddii/histogram/issues
 */

#include "../src/histogram.h"
#include "gtest/gtest.h"

TEST(histogramIndexerTest, histogramTests) {
    EXPECT_EQ(1, histogram::getIndex('A'));
    EXPECT_EQ(1, histogram::getIndex('a'));
    EXPECT_EQ(26, histogram::getIndex('Z'));
    EXPECT_EQ(26, histogram::getIndex('z'));
    EXPECT_EQ(0, histogram::getIndex('+'));
}

TEST(histogramCounterTest, histogramTests) {

    std::string test = "AbCCBBA+ZfhH";
    std::array<int, 27> result = histogram::counter(test);
    std::array<int, 27> expected = {};

    expected[0] = 1;
    expected[1] = 2;
    expected[2] = 3;
    expected[3] = 2;
    expected[6] = 1;
    expected[8] = 2;
    expected[26] = 1;

    for (int i = 0; i <= 25; i++) {
        EXPECT_EQ(expected.at(i), result.at(i));
    }

}