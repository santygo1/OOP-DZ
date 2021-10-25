#include <iostream>

using namespace std;


double medianCalc(double a,double b, double c) {

    return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
}

double read() {
    double a;
    do {
        if (!cin)
        {
            cout << "ERROR: INCORRECT DATA.\nINPUT CORRECT DATA:";
            cin.clear(); 
            cin.ignore(32767, '\n');
        }
        cin >> a;
    } while (!cin);
    return a;
}

int main()
{
    double a, b, c;

    cout << "INPUT A:";
    a = read();
    cout << "INPUT B:";
    b = read();
    cout << "INPUT C:";
    c = read();

    cout << "Ma = " << medianCalc(a, b, c) << endl;
    cout << "Mb = " << medianCalc(b, a, c) << endl;
    cout << "Mc = " << medianCalc(c, a, b) << endl;
}