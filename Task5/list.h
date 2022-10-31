#include <string>
#pragma once
using namespace std;

struct ListElement{
    string data;
    ListElement *next;
    explicit ListElement(string _data);
    //ListElement(string _data) : data(_data), next(nullptr){}
};

class List {
public:
    ListElement* first_element;
    ListElement* last_element;
    List();
    void push_back(string arg);
    bool is_empty();
    void pop(string arg);
    void remove_first();
    void remove_last();
    void print_list();

};