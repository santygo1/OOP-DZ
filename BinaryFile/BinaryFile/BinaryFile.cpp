#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

struct Notebook {

    // Размер модели (мм.)
    struct Size {
        float x;
        float y;
        float z;
    };

    string model = "";
    Size size = {0,0,0};
    float weight = 0;   // Вес (кг.)
    int price = 0;      // Цена (руб.)
    float hddSpace = 0; // Объем жесткого диска (гб.)

    // Функция конвертации Обьекта структуры в строку для вывода в консоль 
    string toInput() {
        stringstream strFormat;
        strFormat << std::fixed << std::setprecision(2); // Округление до 2 знаков всех float переменных
        strFormat << "Модель: " << model << endl;
        strFormat << "       -Ширина: " << size.x << " мм." << endl;
        strFormat << "       -Глубина: " << size.y << " мм." << endl;
        strFormat << "       -Высота: " << size.z << " мм." << endl;
        strFormat << "       -Вес: " << weight << " кг." << endl;
        strFormat << "       -Стоимость: " << price << " руб." <<endl;
        strFormat << "       -Обьем жесткого диска: " << hddSpace << " ГБ";
        return strFormat.str();
    }
};


Notebook* notebooks;
int notebooks_size;

void writeNoteInFile() {

}


string* split(string s, const char delimetr) {
    string* splited;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == delimetr) count++;
    }
    splited = new string[count + 1];

    for (int i = 0; i < count ; i++) {
        size_t pos = s.find_first_of(delimetr);
        splited[i] = s.substr(0,pos);
        s = s.substr(pos + 1);
    }
    splited[count] = s;

    return splited;
}

Notebook* getNotesFromFile(string filePath) {
    Notebook* notes;

    ifstream in(filePath);
    if (in.is_open()) {

        string line;
        getline(in, line);
        notebooks_size = stoi(line);
        notes = new Notebook[notebooks_size];
        int currentNote = 0;

        while (getline(in, line)) {
            string* splited = split(line, '/');
            notes[currentNote].model = splited[0];
            notes[currentNote].size.x = stof(splited[1]);
            notes[currentNote].size.y = stof(splited[2]);
            notes[currentNote].size.z = stof(splited[3]);
            notes[currentNote].weight = stof(splited[4]);
            notes[currentNote].price = stoi(splited[5]);
            notes[currentNote].hddSpace = stof(splited[6]);
            delete[] splited;
            currentNote++;
        }
        in.close();
        return notes;
    }
    in.close();
    return NULL;
}

void writeNoteInBinaryFile(Notebook notebook, string filePath) {
    
    fstream binaryWriter(filePath, ios::binary | ios::in | ios::out | ios::ate);

    if (binaryWriter.is_open()) {

        //Запись числа записей в файле
        int noteCount = 0;

        binaryWriter.seekg(0, ios_base::end); //Устанавливаем курсор в конец
        if (binaryWriter.tellg() >= 4) {
            binaryWriter.seekg(0, ios_base::beg); //Устанавливаем курсор в начало
            binaryWriter.read((char*)&noteCount,4);
        }
        noteCount++;
        binaryWriter.seekg(0, ios_base::beg);
        binaryWriter.write((char*)&noteCount, 4);

        //Запись записи в файл
        binaryWriter.seekg(0, ios_base::end);

        size_t len = notebook.model.length()+1; // Длина с нулевым байтом
        binaryWriter.write((char*)&len,sizeof(len));// Запись длины
        binaryWriter.write(notebook.model.c_str(), len); // Запись данных


        binaryWriter.write((char*)&notebook.size.x, sizeof(notebook.size.x));
        binaryWriter.write((char*)&notebook.size.y, sizeof(notebook.size.y));
        binaryWriter.write((char*)&notebook.size.z, sizeof(notebook.size.z));
        binaryWriter.write((char*)&notebook.weight, sizeof(notebook.weight));
        binaryWriter.write((char*)&notebook.price, sizeof(notebook.price));
        binaryWriter.write((char*)&notebook.hddSpace, sizeof(notebook.hddSpace));
    }
    binaryWriter.close();
}

void readNotesFromBinaryFile(string filePath) {
    
    ifstream binaryReader(filePath, ios::binary);

    if (binaryReader.is_open()) {
        
        binaryReader.seekg(0, ios_base::end);

        if (binaryReader.tellg() >= 4) {
            binaryReader.seekg(0, ios_base::beg);

            int noteCount = 0;
            binaryReader.read((char*)&noteCount, 4);
            cout << "Кол-во записей: " << noteCount << endl;
            for (int i = 0; i < noteCount; i++) {

                Notebook notebook;
                size_t len;
                binaryReader.read((char*)&len, sizeof(len));
                char *buf = new char[len];
                binaryReader.read(buf, len);
                notebook.model = buf;
                delete[] buf;

                binaryReader.read((char*)&notebook.size.x, sizeof(notebook.size.x));
                binaryReader.read((char*)&notebook.size.y, sizeof(notebook.size.y));
                binaryReader.read((char*)&notebook.size.z, sizeof(notebook.size.z));
                binaryReader.read((char*)&notebook.weight, sizeof(notebook.weight));
                binaryReader.read((char*)&notebook.price, sizeof(notebook.price));
                binaryReader.read((char*)&notebook.hddSpace, sizeof(notebook.hddSpace));

                cout << notebook.toInput() << endl;
            }
        }

    }
    binaryReader.close();
}

Notebook* getSortedAndSmallSpaceHDD(Notebook* notes) {

    if(notes == NULL){
        return NULL;
    }

    Notebook*  notesWithSmallHDD;
    int count = 0;

    for (int i = 0; i < notebooks_size; i++) {
        if (notes[i].hddSpace < 1) {
            count++;
        }
    }
    notesWithSmallHDD = new Notebook[count];
    int j = 0;
    for (int i = 0; i < notebooks_size; i++) {
        if (notes[i].hddSpace < 1) {
            notesWithSmallHDD[j] = notes[i];
            j++;
        }
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i+1; j<count; j++) {
            if (strcmp(notesWithSmallHDD[i].model.c_str(), notesWithSmallHDD[j].model.c_str())>0) {
                Notebook tmp = notesWithSmallHDD[i];
                notesWithSmallHDD[i] = notesWithSmallHDD[j];
                notesWithSmallHDD[j] = tmp;
            }
        }
    }

    notebooks_size = count;
    return notesWithSmallHDD;
    
}

void clearFile(string filePath) {
    ofstream ofs;
    ofs.open(filePath, ofstream::out | ofstream::trunc);
    ofs.close();
}


int main()
{
    setlocale(LC_ALL, "rus");

    //Получение записей ноутбуков из файла
    notebooks = getNotesFromFile("note.txt");

    //Очистка бинарного файла
    clearFile("notebooks.bin");

    //Вывод того что считалось из текстового файла и запись в бинарный файл
    cout << "=====ПРОЧИТАЛ С ТЕКСТОВОГО ФАЙЛА=====" << endl;
    for (int i = 0; i < notebooks_size; i++) {
        cout << i+1 << " "<< notebooks[i].toInput() << endl;;
        writeNoteInBinaryFile(notebooks[i], "notebooks.bin");
    }

    //Чтение с бинарного файла файла
    cout << endl << "=====ЧТЕНИЕ БИНАРНОГО ФАЙЛА=====" << endl;
    readNotesFromBinaryFile("notebooks.bin");

    //Очистка бинарного файла
    clearFile("notebooks.bin");
    cout << "Бинарный файл очищен" << endl;
    
    cout << endl << "=====СОРТИРОВКА И ЗАПИСЬ В БИНАРНЫЙ ФАЙЛ=====" << endl;
    notebooks = getSortedAndSmallSpaceHDD(notebooks); //Получаем сортированный массив из ноутбуков(HHD <1ГБ)
    for (int i = 0; i < notebooks_size; i++) {
        writeNoteInBinaryFile(notebooks[i], "notebooks.bin"); // запись сортированного в бинарный файл
    }

    cout << endl << "=====ЧТЕНИЕ С БИНАРНОГО ФАЙЛА=====" << endl;
    readNotesFromBinaryFile("notebooks.bin");

    delete[] notebooks;
    return 0;
}

