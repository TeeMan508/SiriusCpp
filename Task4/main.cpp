#include "FindMinPath.h"
#include "load_png/lodepng.h"
#include "ArgErrorsHandler.h"
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
    //Encode the image
    unsigned error = lodepng::encode(output_file, image, cols, rows);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

int main(int argc, char **argv) {

    if (argc != 7) {
        cout << get_argument_error_name(ErrorHandler::INSUFFICIENT_OR_OVERSUFFICIENT_ARGUMENTS) << endl;
        return -1;
    }
    int rows = stoi(argv[2]), cols = stoi(argv[3]);
    int x_i = stoi(argv[4]), x_f = stoi(argv[5]);
    char *input_file = argv[1], *output_file = argv[6];

    std::vector<unsigned char> image; // vector to store value of pixels with all 4 channels RGBA
    decodeFromPng(image, input_file, rows, cols); // read png file

    int **arr = new int *[rows];
    for (int row = 0; row < rows; ++row)
        arr[row] = new int[cols];

    // инициализируем выделенный массив arr синим каналом нашего изображения
    getBlueChannel(image, arr, rows, cols);

    // можно опционально выводить массив в консоль для отладки
    printArray(arr, rows, cols);

    //функцию ниже вам нужно реализовать
    //-----------------------------------------------------------------------------
    vector<int> path;  // вектор к которому нужно делать push_back для добавления точек пути
    findMinimumPath(arr, path, x_i, x_f, rows, cols);
    //------------------------------------------------------------------------------

    // далее можно отрисовать path используя фукцию ниже
    drawPath(path, image, rows, cols, output_file);

    // очищаем память
    for (int row = 0; row < rows; ++row)
        delete[] arr[row];
    delete arr;
    getchar();
}

