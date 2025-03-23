#include <iostream>
using namespace std;

#include "SortingSystem.h"


int main() {

    int n,type;

    cout << "Enter number of elements: ";
    getValidIntegerInput(n);

    SortingSystem<int> sorter(n);


    sorter.showMenu();

}

/*
int main()
{
    int n, choice;
    cout << "Enter number of elements: ";
    getValidIntegerInput(n);

    cout << "Choose a data type:\n";
    cout << "1. Integer\n";
    cout << "2. Double\n";
    cout << "3. String\n";
    cout << "Enter choice: ";
    getValidIntegerInput(choice);

    if (choice == 1)
    {
        SortingSystem<int> sorter(n);
        sorter.showMenu();
    }
    else if (choice == 2)
    {
        SortingSystem<double> sorter(n);
        sorter.showMenu();
       // (hena by2oly in el count sort mynf34 t4t8l ela m3 intger) 
       // Et7lt ya man. MSY 
    }
    else if (choice == 3)
    {
        SortingSystem<string> sorter(n);
        sorter.showMenu();
       // (hena brdo fe error m4 fahmo)
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
*/