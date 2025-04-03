#include <iostream>


using namespace std;

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;

public:
    StatisticalCalculation() : data(nullptr), size(0) {} 
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (data[j] < data[i]) {
                    swap(data[i], data[j]);
                }
            }
        }
    }

    T findMedian() {
        sort();
        if (size % 2 != 0) {
            return data[size / 2];
        } else {
            return (data[(size - 1) / 2] + data[size / 2]) / 2.0;
        }
    }

    T findMin() {
        T min = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min) {
                min = data[i];
            }
        }
        return min;
    }

    T findMax() {
        T max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    double findMean() {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum / size;
    }

    T findSummation() {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum;
    }

    void displayArray() {
        cout << "{";
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i != size - 1) { cout << ", "; }
        }
        cout << "}" << endl;
    }

    void inputData() {
        cout << "Enter number of elements: ";
        cin >> size;
        data = new T[size];

        for (int i = 0; i < size; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void staticMenu() {
        int selection;
        while (true) {
            cout << "\nSelect a statistical calculation:\n"
                 << "1. Find Median\n"
                 << "2. Find Minimum\n"
                 << "3. Find Maximum\n"
                 << "4. Find Mean\n"
                 << "5. Find Summation\n"
                 << "6. Exit\n"
                 << "Enter your choice (1-6): ";
            cin >> selection;

            switch (selection) {
                case 1:
                    cout << "Median: " << findMedian() << endl;
                    break;
                case 2:
                    cout << "Minimum: " << findMin() << endl;
                    break;
                case 3:
                    cout << "Maximum: " << findMax() << endl;
                    break;
                case 4:
                    cout << "Mean: " << findMean() << endl;
                    break;
                case 5:
                    cout << "Summation: " << findSummation() << endl;
                    break;
                case 6:
                    return;
                default:
                    cout << "Invalid input! Please enter a number between 1 and 6.\n";
            }
        }
    }

    ~StatisticalCalculation() {
        delete[] data;
    }
};

int main() {
    StatisticalCalculation<int> test;
    test.inputData();
    test.displayArray();
    test.staticMenu();

    return 0;
}
