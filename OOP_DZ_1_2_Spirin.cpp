#include <iostream>

using namespace std;

double getDouble() {
    double a;

    do {
        if (!cin)
        {
            cout << "ERROR: INCORRECT DATA.\nINPUT CORRECT X:";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        cin >> a;

    } while (!cin);

    return a;
}

float getFloat() {
    float a;

    do {
        if (!cin)
        {
            cout << "ERROR: INCORRECT DATA.\nINPUT CORRECT X:";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        cin >> a;

    } while (!cin);

    return a;
}

template<typename N>
void func(N num) {
    if (num < 0) {
        cout << "ERROR: FOUND COMPLEX NUMBER.\n";
        return;
    }
    N tmp = (1 - num * num) / (1 + num * num) * sqrt(num);
    if (tmp == num || tmp == 0) {
        cout << "ERROR: ZERO DIVISOR.\n";
        return;
    }
    else {
        cout << "y = " << tmp << endl;
        cout << "z = " << (abs(num) + abs(tmp)) / (num - tmp) + abs(num / tmp) << endl;
    }


}



int main(){

    double dX;
    cout << "Double X:\n";
    dX = getDouble();
    func(dX);

    float fX;
    cout << "Float X:\n";
    fX = getFloat();
    func(fX);

}