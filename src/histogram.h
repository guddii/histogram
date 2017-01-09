/**
 *  @file histogram.h
 *  @brief Counts chars from a text file and displays them as a histogram.
 *
 *  @author Florian Gudat (guddii)
 *  @see https://github.com/guddii/histogram
 *  @bug https://github.com/guddii/histogram/issues
 */

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <locale>
#include <string>
#include <array>
#include <iterator>
#include <iostream>
#include <algorithm>

namespace histogram {

    /**
     * @brief Maximal available columns
     */
    const int maxVisibleColumns = 100;

    /**
     * @brief Get the char index
     * @param letter - The character you want to check
     * @return The char index within the alphabet
     */
    int getIndex(const char &letter);

    int getIndex(const char &letter) {
        int index = 0;
        if (isupper(letter)) {
            index = letter - 64; // Starting capital letters in the ASCII TBL
        } else if (islower(letter)) {
            index = letter - 96; // Starting lower letters in the ASCII TBL
        }
        return index;
    }

    /**
     * @brief Test every char within the text
     * @param text - A text that should be inspected
     * @return A array with the char count
     */
    std::array<int, 27> counter(const std::string &text);

    std::array<int, 27> counter(const std::string &text) {
        std::array<int, 27> result = {};
        for (size_t i = 0; i < text.length(); i++) {
            const char letter = text[i];
            result[static_cast<size_t>(getIndex(letter))] += 1;
        }
        return result;
    }

    /**
     * @brief Draws the bars
     * @param text - A text that should be inspected
     */
    void draw(const std::string &text);

    void draw(const std::string &text) {
        std::array<int, 27> array = counter(text);
        int totalCharsInText = 0;
        for (size_t i = 0; i < 27; i++) {
            totalCharsInText += array[i];
        }
        for (size_t i = 0; i < 27; i++) {
            int count = array[i];
            if (count) {
                double percentage = static_cast<double>(count) / static_cast<double>(totalCharsInText) * 100;
                int length = static_cast<int>((maxVisibleColumns * percentage) / 100);
                if (length) {
                    std::cout << static_cast<char>(64 + i) << ": ";
                    for (int j = 0; j < length; j++) {
                        std::cout << '#';
                    }
                    std::cout << " (" << percentage << "%)";
                    std::cout << std::endl;
                }
            }
        }
    }

}

#endif //HISTOGRAM_H
