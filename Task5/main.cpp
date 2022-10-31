#include "list.h"
#include <fstream>
#include <iostream>
int main(int argc, char **argv){
    List l;

    string buf;
    ifstream file;
    file.open(argv[1]);
    while (!file.eof()){
        file >> buf;
        l.push_back(buf);
    }
    file.close();
    cout << "Imported list: ";
    l.print_list();
    l.pop((*l.last_element).data);
    cout << "Popped list: ";
    l.print_list();
    return 0;
}