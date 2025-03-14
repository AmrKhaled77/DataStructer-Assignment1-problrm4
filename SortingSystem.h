#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class SortingSystem {
private:
    T* data;  // Dynamic array for storing input data
    int size; // Size of the array

public:
    SortingSystem(int n);  // Constructor
    ~SortingSystem();      // Destructor

    void insertionSort();  // (1) Insertion Sort
    void selectionSort();  // (2) Selection Sort
    void bubbleSort();     // (3) Bubble Sort
    void shellSort();      // (4) Shell Sort
    void mergeSort(int left, int right); // (5) Merge Sort
    void quickSort(int left, int right); // (6) Quick Sort
    void countSort();      // (7) Count Sort (Only for int)
    void radixSort();      // (8) Radix Sort (Only for int)
    void bucketSort();     // (9) Bucket Sort
    void merge(int left, int mid, int right); // Merge Sort Helper

    int partition(int low, int high);        // Quick Sort Helper
    bool isIntArray(T* data); // checks if the data array is of int type for count and radix sort.
    void displayData();   // Print the current state of the array
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
    void rebeatMenu();
};


#include <iostream>
using namespace std;


void getValidIntegerInput(int &num) {

    while (true) {

        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Please enter a valid integer.\n";
        } else{
            return ;
        }
    }
}
int n;
template <typename T>

void SortingSystem<T>::rebeatMenu(){
    cout<<"Do you want to sort another dataset?  \n"
          "1-> yes\n "
          "2-> no  ";


    while (!(std::cin >> n) || (n != 1 && n != 2)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Please enter 1 or 2: ";
    }
    switch (n) {
        case 1:
            delete[] data;  // Free previous data
            cout << "Enter number of elements: ";
            getValidIntegerInput(n);
            data = new T[n];  // Allocate new array
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++) cin >> data[i];

            showMenu();
            break;
        case 2:
            delete[] data;
            cout<<"Thank you for using the sorting system! Goodbye!";
            exit(0);

    }
}

template <typename T>
void print(T data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

#include "SortingSystem.h"
#include <chrono>
using namespace std;
// Constructor
template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

// Destructor
template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

template <typename T>

bool SortingSystem<T>::isIntArray(T* data)
{
    if(!is_same_v<T,int>)
    {
        return false;
    }
    return true;
}

template <typename T>

//this function executes the sorting function and calculates the time taken by 
void SortingSystem<T>::measureSortTime(void(SortingSystem<T>::*sortFunc)())
{
    auto startTime = chrono::high_resolution_clock::now();

    (this->*sortFunc)();

    auto endTime = chrono::high_resolution_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::microseconds>(endTime-startTime);
    cout<<"Time taken: "<<timeTaken.count()<<" microseconds\n";
}      

template <typename T>
void SortingSystem<T>::showMenu(){
    int choice;
do {
    cout << "\n Menu:\n";
    cout << "1-> Insertion Sort\n";
    cout << "2-> Selection Sort\n";
    cout << "3-> Bubble Sort\n";
    cout << "4-> Shell Sort\n";
    cout << "5-> Merge Sort\n";
    cout << "6-> Quick Sort\n";
    cout << "7-> Count Sort\n";
    cout << "8-> Radix Sort\n";
    cout << "9-> Bucket Sort\n";
    cout << "10-> Display Data\n";
    cout << "0-> Exit\n";
    cout << "Enter your choice: ";
    getValidIntegerInput(choice);

    switch (choice) {
        case 1:
            insertionSort();
            measureSortTime(&SortingSystem::insertionSort);
            rebeatMenu();

            break;
        case 2:
            selectionSort();
            measureSortTime(&SortingSystem::selectionSort);
            rebeatMenu();
            break;
        case 3:
            bubbleSort();
            measureSortTime(&SortingSystem::bubbleSort);
            rebeatMenu();
            break;
        case 4:
            shellSort();
            measureSortTime(&SortingSystem::shellSort);
            rebeatMenu();
            break;
        case 5:
            mergeSort(0, size - 1);
            measureSortTime(&SortingSystem::shellSort);
            rebeatMenu();
            break;
        case 6:
            quickSort(0, size - 1);
            cout<<"Sorted data : ";
            displayData();
            cout<<"\n";

            rebeatMenu();
            break;
        case 7:
            if (!isIntArray(data)) {
                cout
                        << "To implement Count Sort the data you entered must be of integer type\nChoose another algorithm or redefine your data\n";
            } else {

                measureSortTime(&SortingSystem::countSort);
                rebeatMenu();
            }
            break;
        case 8:
            if (!isIntArray(data)) {
                cout
                        << "To implement Radix Sort the data you entered must be of integer type\nChoose another algorithm or redefine your data\n";
            } else {
                measureSortTime(&SortingSystem::radixSort);
                rebeatMenu();
            }
            break;
        case 9:
            bucketSort();
            measureSortTime(&SortingSystem::bucketSort);
            rebeatMenu();
            break;
        case 10:
            displayData();
            break;
        case 0:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
    }
} while (choice!=0);


}
template <typename T>
int SortingSystem<T>:: partition( int l, int h) {
    int p = data[l];
    int i = l;
    int j = h;

    while (i < j) {

        while (i < h && data[i] <= p) {
            i++;
        }

        while (j > l && data[j] > p) {
            j--;
        }

        if (i < j) {
            swap(data[i], data[j]);
        }
    }

    swap(data[l], data[j]);
    return j;
}


template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
    if (left < right) {
        int piv = partition( left, right);

        std::cout << "Pivot: " << data[piv] << " -> [ ";
        for (int i = left; i < piv; i++) {
            cout << data[i] << " ";
        }
        cout << "] " << data[piv] << " [ ";
        for (int i = piv + 1; i <= right; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;


        quickSort(left, piv - 1);
        quickSort(piv + 1, right);
    }



}
template <typename T>
void SortingSystem<T>::selectionSort() {
    cout<<"Data : ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout<<"\n";
    for (int i = 0; i < size - 1; ++i) {

        int minIndex = i;


        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }


        if (minIndex != i) {
            cout << "Swapping " << data[i] << " with " << data[minIndex] << "\n";
            swap(data[i], data[minIndex]);
        }


        cout << "Array after swap " << i + 1 << ": ";
        for (int k = 0; k < size; k++) {
            cout << data[k] << " ";
        }
        cout << "\n";
    }


    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << "\nSelection Sort Completed\n";
}


template <typename T>
void SortingSystem<T>::bubbleSort() {
    cout<<"Data : ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }

    for (int i = 0; i < size- 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);

                swapped = true;

                    cout << "Swapping " << data[j] << " with " << data[j+1] << "\n";
                    cout << "Array after swap " << i + 1 << ": ";
                    for (int k = 0; k < size; k++) {
                        cout << data[k] << " ";
                    }
                    cout<<"\n";




            }

        }
        if (!swapped) break;


    }
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    }


template <typename T> void SortingSystem<T>::insertionSort() {
    cout << "Insertion Sort Called\n";
}

template <typename T> void SortingSystem<T>::shellSort() {
    cout << "Shell Sort Called\n";
}

template <typename T> void SortingSystem<T>::mergeSort(int left, int right) {
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        cout << "\nDividing process : ";
        for (int i = left; i <= right; i++)
            cout << data[i] << " ";
        cout << endl;

        mergeSort(left, middle);
        mergeSort(middle + 1, right);

        merge(left, middle, right);
    }
}
template <typename T>
void SortingSystem<T>:: merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T *lArr = new T[n1];
    T *rArr = new T[n2];

    for (int i = 0; i < n1; ++i)
    {
        lArr[i] = data[left + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        rArr[i] = data[mid + 1 + i];
    }

    cout<<"\nMerging process\n";
    cout << "Left part of array: ";
    print(lArr, n1);
    cout << "Right part of array: ";
    print(rArr, n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (lArr[i] <= rArr[j])
        {
            data[k] = lArr[i];
            i++;
        }
        else
        {
            data[k] = rArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        data[k] = lArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        data[k] = rArr[j];
        j++;
        k++;
    }
    cout << "Merged result: ";
    print(data, size);
    delete[] lArr;
    delete[] rArr;
}



template <typename T> void SortingSystem<T>::countSort()
{
     cout << "Count Sort Called\n";

     int maxNumber = *(max_element (data,data+size));
     int minNumber = *(min_element (data,data+size));

     int range = maxNumber - minNumber + 1; //the range is the size of my count array.

     int *countArray = new int[range];

     // counting occurences.

     for (int i = 0 ; i<size ; i++)
     {
        int index = data[i] - minNumber; //the index of the value in the count array.
        countArray[index]++;
     }

     //showing the counting state

     for(int i = 0 ; i < range ; i++)
     {
        int element = i+minNumber;
        int freq = countArray[i];
        cout<<"The element: "<< element << " occured: "<<freq<<" Times\n"; 
     }

     //inserting the sorted data and displaying each step to the user.

     int dataIndex = 0 ;

     for(int i = 0 ; i < range ; i++)
     {
        while(countArray[i] > 0)
        {
            data[dataIndex] = i + minNumber;
            countArray[i]--;
            dataIndex++;
        }
        cout<<"The data after step: "<<i+1<<": ";
        displayData();
        cout<<'\n';
     }

     //Cleaning

     delete[] countArray;
}

template <typename T> void SortingSystem<T>::radixSort()
 {
     cout << "Radix Sort Called\n";
     
 }

template <typename T> void SortingSystem<T>::bucketSort()
 {
     cout << "Bucket Sort Called\n";
 }

template <typename T> void SortingSystem<T>::displayData() {


    for (int i = 0; i < size; ++i) {


        cout<<data[i]<<",";
    }


}










#endif // SORTINGSYSTEM_H
