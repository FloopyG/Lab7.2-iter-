
#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void Create(int** P, const int rowCount, const int colCount, int High, int Low) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            P[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** P, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << P[i][j];
        }
        cout << endl;
    }
}

int colMax(int** P, const int rowCount, const int j, int colMaxEl) {
    for (int i = 0; i < rowCount; i++) {
        if (colMaxEl < P[i][j]) {
            colMaxEl = P[i][j];
        }
    }
    return colMaxEl;
}

void arrSearch(int** P, const int rowCount, const int colCount, int& maxEl) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if ((j + 1) % 2 != 0) {
                int colMaxEl = colMax(P, rowCount, j, P[0][j]);
                if (colMaxEl < maxEl) {
                    maxEl = colMaxEl;
                }
            }
        }
    }
}


int main()
{
    int Low = -21;
    int High = 24;

    int rowCount;
    int colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >>  colCount;

    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, High, Low);
    Print(P, rowCount, colCount);

    int maxEl = colMax(P, rowCount, 0, P[0][0]);
    arrSearch(P, rowCount, colCount, maxEl);
    cout << maxEl << endl;


    system("pause");
    cin.get();
    return 0;
}
