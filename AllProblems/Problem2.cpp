#include <iostream>
#include <fstream>

using namespace std;

void displayPoly(ofstream &output, int *poly, int order, int rhs) {
    bool first = true;
    for (int i = order; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!first) output << " ";
            if (poly[i] > 0 && !first) output << "+ ";
            if (poly[i] < 0) output << "- ";
            if (abs(poly[i]) != 1 || i == 0) output << abs(poly[i]);
            if (i > 0) output << "x";
            if (i > 1) output << "^" << i;
            first = false;
        }
    }
    if (first) output << "0";
    output << " = " << rhs << endl;
}

int* addPoly(int* poly1, int order1, int* poly2, int order2, int& resultOrder) {
    resultOrder = max(order1, order2);
    int* result = new int[resultOrder + 1]{};
    for (int i = 0; i <= order1; i++) result[i] += poly1[i];
    for (int i = 0; i <= order2; i++) result[i] += poly2[i];
    return result;
}

int* subtractPoly(int* poly1, int order1, int* poly2, int order2, int& resultOrder) {
    resultOrder = max(order1, order2);
    int* result = new int[resultOrder + 1]{};
    for (int i = 0; i <= order2; i++) result[i] += poly2[i];
    for (int i = 0; i <= order1; i++) result[i] -= poly1[i];
    return result;
}

int main() {
    ifstream inputFile("testCase.txt");
    ofstream outputFile("results.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int testCases;
    inputFile >> testCases;
    outputFile << "Processing " << testCases << " test cases...\n\n";

    for (int t = 1; t <= testCases; t++) {
        int orderOne, orderTwo, rhsOne, rhsTwo;

        inputFile >> orderOne >> rhsOne;
        int* poly1 = new int[orderOne + 1];
        for (int i = 0; i <= orderOne; i++) inputFile >> poly1[i];

        inputFile >> orderTwo >> rhsTwo;
        int* poly2 = new int[orderTwo + 1];
        for (int i = 0; i <= orderTwo; i++) inputFile >> poly2[i];

        outputFile << "Test Case #" << t << ":\n";
        outputFile << "First polynomial: ";
        displayPoly(outputFile, poly1, orderOne, rhsOne);

        outputFile << "Second polynomial: ";
        displayPoly(outputFile, poly2, orderTwo, rhsTwo);

        int sumOrder, diffOrder;
        int* sum = addPoly(poly1, orderOne, poly2, orderTwo, sumOrder);
        int* diff = subtractPoly(poly1, orderOne, poly2, orderTwo, diffOrder);

        outputFile << "Sum of polynomial: ";
        displayPoly(outputFile, sum, sumOrder, rhsOne + rhsTwo);

        outputFile << "Difference of polynomial: ";
        displayPoly(outputFile, diff, diffOrder, rhsTwo - rhsOne);

        outputFile << "-----------------------------------\n";

        delete[] poly1;
        delete[] poly2;
        delete[] sum;
        delete[] diff;
    }

    inputFile.close();
    outputFile.close();

    cout << "Processing complete. Check results.txt for output.\n";
    return 0;
}
