#include <iostream>
#include <vector>
#pragma once
using namespace std;

struct vertex{
    int weight;
    int path_weight;
    bool visited;
    explicit vertex();
};

class FindMinimumPath {
public:
    int size;
    int i_start, j_start, i_end, j_end;
    FindMinimumPath(int _size, int _i1, int _j1, int _i2, int _j2);
    vertex **connection_matrix = new vertex* [size];
    vector<vertex> solve();
};
