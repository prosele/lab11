#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <deque>
using namespace std;

void ContAlg() {
    list<int> myList;
    list <int> add = {66, 23, 98, -5, 632, 1, 17};
    int temp;
    cout << "Введите 10 чисел: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    list<int>::iterator it = myList.begin();
    
    // добавление элемента в середину списка
    advance(it, 5);
    myList.insert(it, 0);
    --it; // it = [5] (хочу, чтобы итератор указывал на добавленный элемент)
    
    // удаление элемента из середины списка
    advance(it, -3);
    it = myList.erase(it); // it = [2]
    
    // переносит элементы из одного списка в другой с указанной позиции (второй список становиться пустым)
    advance(it, 5);
    myList.splice(it, add); // it = [14]
    
    
    // вывести список
    cout << "Список: [ ";
    for (list<int>::iterator i = myList.begin(); i != myList.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    cout << "________________________________________________" << endl;
}

void AdapterIter() {
    vector <int> myVector;
    list<int> myList;
    for (int i = 1; i <= 10; i++) {
        myVector.push_back(i);
    }
    cout << "Элементы изначального вектора: [";
    for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    
    // fill_n() присваивает count элементам из диапазона [first,first+count) значение value.
    // добавляем в вектор три элемента в конец
    fill_n(back_inserter(myVector), 3, 0);
    cout << "Элементы вектора после добавления трёх '0' в конец: [";
    for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    
    // копируем элементы из вектора в список, при этом первым элементом в списке будет последний элемент из вектора, так как при front_inserter добавляем в начало
    copy(myVector.begin(), myVector.end(), front_inserter(myList));
    cout << "Элементы списка после копирования из вектора с конца: [";
    for (list<int>::iterator i = myList.begin(); i != myList.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    
    // добавляем 3 элемента в начало списка
    fill_n(front_inserter(myList), 3, 1000);
    cout << "Элементы списка после добавления трёх '1000' в начало: [";
    for (list<int>::iterator i = myList.begin(); i != myList.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    list<int>::iterator forlist = myList.begin();
    advance(forlist, 10);
    
    //добавляем 2 элемента в середину списка
    fill_n(inserter(myList, forlist), 2, -1);
    // под десятым элементом имеется в виду число 6
    cout << "Элементы списка после добавления двух '-1' перед десятым элементом: [";
    for (list<int>::iterator i = myList.begin(); i != myList.end(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
    cout << "________________________________________________" << endl;
}

void Files() {
    // чтение из файла
    vector <string> myVector;
    ifstream file("/Users/kseniaprokopovic/Downloads/test.txt");
    copy(istream_iterator<string>(file), istream_iterator<string>(),back_inserter(myVector));
    file.close();
    cout << "Прочтенный из файла вектор: [";
    // copy создает потоковый итератор вывода, который записывает string в выходной поток данных cout, вызывая оператор << для каждого элемента
    copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, " "));
    cout << "]" << endl;
    
    //запись в файл
    vector <string> myVector2 = {"67", "345", "12", "-45", "0", "-7"};
    ofstream file2;
    file2.open("/Users/kseniaprokopovic/Downloads/test2.txt");
    copy(myVector2.begin(), myVector2.end(), ostream_iterator<string>(file2, " "));
    file2.close();
    cout << "________________________________________________" << endl;
}

void IterComp() {
    vector <int> myVector = {6, -6, 7, -7, 8, -8, 9, -9, 10, -10, 1, -1};
    deque<int> myDeck;
    copy(myVector.begin(), myVector.end(), back_inserter(myDeck));
    cout << "Элементы вектора: [ ";
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "Элементы дека: [ ";
    copy(myDeck.begin(), myDeck.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "________________________________________________" << endl;
}

void ReverseIter() {
    list<int> myList;
    int temp;
    cout << "Введите 10 чисел: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    cout << "Список в обратном порядке: [ ";
    for (list<int>::const_reverse_iterator i = myList.crbegin(); i != myList.crend(); ++i) {
        cout << *i << " ";
    }
    //copy(myList.rbegin(), myList.rend(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
}

int main() {
    cout << "1. Контейнерные алгоритмы" << endl;
    ContAlg();
    cout << "2. Итераторы-адаптеры" << endl;
    AdapterIter();
    cout << "3. Файловый ввод-вывод с итераторами" << endl;
    Files();
    cout << "4. Совместимость итераторов" << endl;
    IterComp();
    cout << "5. Обратные итераторы" << endl;
    ReverseIter();
    return 0;
}
