#include <iostream>
using namespace std;

#include "SortingSystem.h"



int main() {

    int n;
    cout << "Enter number of elements: ";
    getValidIntegerInput(n);


    SortingSystem<int> sorter(n);


    sorter.showMenu();

}
