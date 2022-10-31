#include "list.h"
#include <iostream>
ListElement::ListElement(std::string _data) {
    data = _data;
    next = nullptr;
}

List::List(){
    first_element = nullptr;
    last_element = nullptr;
}

bool List::is_empty() {
    return first_element == nullptr;
}

void List::push_back(std::string arg) {
    ListElement* p = new ListElement(arg);
    if (List::is_empty()){
        first_element = p;
        last_element = p;
        return;
    }
    (*last_element).next = p;
    last_element = p;
}
void List::print_list() {
    if (List::is_empty()){
        cout << "[]";
        return;
    }
    else{
        ListElement* p = first_element;
        cout << "[";
        while (p != nullptr){
            if ((*p).next == nullptr){
                cout << (*p).data << "]" << endl;
                return;
            }
            else {
                cout << (*p).data << ", ";
                p = (*p).next;
            }
        }
    }
}
void List::remove_first() {
    if (is_empty()) return;
    ListElement* p = first_element;
    first_element = (*p).next;
    delete p;
}
void List::remove_last() {
    if (List::is_empty()) return;
    if (first_element == last_element){
        List::remove_first();
        return;
    }
    ListElement* p = first_element;
    while ((*p).next != last_element) p = (*p).next;
    (*p).next = nullptr;
    delete last_element;
    last_element = p;
}

void List::pop(std::string arg) {
    if (List::is_empty()) return;
    if ((*first_element).data == arg){
       List::remove_first();
    }
    if ((*last_element).data == arg){
       List::remove_last();
    }
    ListElement* p = first_element;
    ListElement* next_p = (*p).next;
    while (next_p != nullptr){
        if ((*next_p).data != arg){
            p = (*p).next;
            next_p = (*next_p).next;
        }
        else {
            (*p).next = (*next_p).next;
            delete next_p;
            next_p = (*p).next;
        }
    }

}