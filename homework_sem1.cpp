#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));
    string filename = argv[1];
    ifstream file(filename, ios::in);

    int pwr;
    file >> pwr;
    if (pwr < 1 || pwr > 10) {
        cerr << "Некорректное значение степени уравнения." << endl;
        return -1;
    }
    for (int i = 0; i <= pwr; i++) {
        file >> coef[i];
    }

    int n = 100; //размер популяции
    short x0 = -32760, x1 = 32760;

    short* population = new short[n];
    double* f = new double[n];

    short root = genetic(x0, x1, population, f, n);
    cout << "Целый корень уравнения: " << root << endl;

    delete[] population;
    delete[] f;

    return 0;
}
