#include "FindMinPath.h"
#include "load_png/lodepng.h"
#include <iostream>
using namespace std;

void decodeFromPng(std::vector<unsigned char> &image, const char *filename, unsigned height, unsigned width) {
    std::vector<unsigned char> png;

    unsigned error = lodepng::load_file(png, filename);
    if (!error) error = lodepng::decode(image, width, height, png);


    if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

}

void getBlueChannel(const std::vector<unsigned char> &image, int **arr, int rows, int cols) {
    for (int i = 2, j = 0, k = 0; i < image.size(); i += 4, ++k) {
        if (k == cols) {
            k = 0;
            ++j;
        }
        arr[j][k] = int(image[i]);
    }
}

void printArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void drawPath(const vector<int> &path, vector<unsigned char> &image, int rows, int cols, const char *output_file) {
    int i = 0, j = -1;
    int previousPoint = -1;
    for (auto &e: path) {
        if (previousPoint == e)
            ++i;
        else
            j = e;
        previousPoint = e;
        int index = (i * cols + j) * 4;
        image[index] = (unsigned char) 255;
        image[++index] = (unsigned char) 0;
        image[++index] = (unsigned char) 0;
    }
}