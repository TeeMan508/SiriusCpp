#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#pragma once


enum prev {
    up,
    own_left,
    own_right,
    none
};

struct vertice {
    bool visited;
    int path_weight;
    int weight;
    prev previous;
};

void print_matrix(vertice *p, int n, int k);
std::vector<int> get_row(std::string line);
std::pair<std::vector<int>, std::vector<int>> get_path(vertice *v, int n, int start, int finish_j);
std::pair<int,int> FindMinimumNeightbor(vertice *p, int n, int k);
void findMinimumPath(int **arr, std::vector<int> &path, int x_i, int x_f, int rows, int cols);