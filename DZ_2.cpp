#include <iostream>

using namespace std;

/*
* Проверка на введенные данные
*/
int getInt() {
    int a;

    do {
        if (!cin) {
            cout << "ERROR:Incorect data.Int expected.Try again:";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        
        cin >> a;
    } while (!cin);

    return a;
}

/*
* Проверка на положительное число для столбцов и строк матрицы
*/
int getPositiveInt() {
    int a = getInt();
    while (a <= 0) {
        cout << "Error: Number must be greater then 0.Try again:";
        a = getInt();
    }
    return a;
}

/*
* Вывод седловых точек заданной матрицы
*/
void printSaddlePoints(int** matrix, int cols, int rows) {
    for (int j = 0; j < rows; j++){

        for (int k = 0, x, y; k < cols; k++){

            int aMin = 0, aMax = 0;
            for (int i = 0; i < cols; i++){
                if (matrix[j][k] > matrix[j][i] 
                    || matrix[j][k] == matrix[j][i]) {
                        aMax++; 
                        x = j;
                        y = k; 
                }else aMax--;
            }
            if (aMax == cols){

                for (int i = 0; i < rows; i++){
                    if (matrix[x][y] < matrix[i][y] 
                        || matrix[x][y] == matrix[i][y]) aMin++;
                    else aMin--; 
                }

                if (aMin == rows) 
                    cout << " a" << x + 1 << y + 1 << " = " << matrix[x][y] << " - saddle point\n"; 
            }else{
                int aMin = 0, aMax = 0;
                for (int i = 0; i < cols; i++)
                {
                    if (matrix[x][y] < matrix[x][i] || matrix[x][y] == matrix[x][i]) aMin++; 
                    else aMin--;
                }
                if (aMin == cols){

                    for (int i = 0; i < rows; i++){

                        if (matrix[x][y] > matrix[i][y] || matrix[x][y] == matrix[i][y])aMax++;
                        else aMax--;
                    }
                    if (aMax == rows) {
                        cout << " a" << x + 1 << y + 1 << " = " << matrix[x][y] << " - saddle point\n";
                    }
                }
            }
        }
    }
}


int main()
{
    int n, m;

    cout << "Enter number of rows: ";
    n = getPositiveInt();
    cout << "Enter number of columns: ";
    m = getPositiveInt();

    int** matrix = new int *[m];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    //Считываю эл-ты записываю в массив
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            cout << "a"<< i+1 << j+1 << "=";
            matrix[i][j] = getInt();
        }
    }

    //Вывод массива
    for (int i = 0; i < n; i++) {
        cout << "| ";
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<"|"<<endl;
    }

    printSaddlePoints(matrix, n, m); //вывод седловых точек
    
    //Удаляю массив из памяти
    for (int i = 0; i < n; i++) {
        delete matrix[i];
    }
    delete[] matrix;
}
