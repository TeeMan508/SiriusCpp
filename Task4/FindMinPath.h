#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#pragma once

enum prev {
    up,
    left,
    right,
    none
};

struct Vertice {
    bool visited;
    int path_weight;
    int weight;
    prev previous;
};

void print_matrix(Vertice *p, int n, int k);
std::vector<int> get_row(std::string line);
std::pair<std::vector<int>, std::vector<int>> get_path(Vertice *p, int n, int k, int start, int finish_j);

std::pair<int,int> FindMinimumPath(Vertice *p, int n, int k);