#include <iostream>
#include <fstream>
#include <limits>
#include "pharmacy.h"
Pharmacy* loadFromFile(const std::string& filename, int& size);
void saveToFile(const std::string& filename, Pharmacy* arr, int size);
void addItem(Pharmacy*& arr, int& size);
void printAll(Pharmacy* arr, int size);
void deleteItem(Pharmacy*& arr, int& size);
void editItem(Pharmacy* arr, int size);
void searchItem(Pharmacy* arr, int size);
int main() {
    Pharmacy* database = nullptr;
    int size = 0;
    database = loadFromFile("data.txt", size);
    while (true) {
        std::cout << "\n1. Вывести товары\n2. Добавить товар\n3. Удалить товар\n4. Редактировать товар\n5. Поиск по названию или симптомам\n6. Выйти\nВведите номер: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) printAll(database, size);
        else if (choice == 2) addItem(database, size);
        else if (choice == 3) deleteItem(database, size);
        else if (choice == 4) editItem(database, size);
        else if (choice == 5) searchItem(database, size);
        else if (choice == 6) {
            saveToFile("data.txt", database, size);
            delete[] database;
            break;
        } else {
            std::cout << "Неверный ввод\n";
        }
    }
    return 0;
}
Pharmacy* loadFromFile(const std::string& filename, int& size) {
    std::ifstream in(filename);
    if (!in) return nullptr;
    size = 0;
    Pharmacy temp;
    Pharmacy* arr = nullptr;
    while (in >> temp) {
        Pharmacy* newArr = new Pharmacy[size + 1];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        newArr[size] = temp;
        delete[] arr;
        arr = newArr;
        size++;
    }
    return arr;
}
void saveToFile(const std::string& filename, Pharmacy* arr, int size) {
    std::ofstream out(filename);
    for (int i = 0; i < size; ++i)
        out << arr[i];
}
void addItem(Pharmacy*& arr, int& size) {
    Pharmacy newPharmacy;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> newPharmacy;
    Pharmacy* newArr = new Pharmacy[size + 1];
    for (int i = 0; i < size; ++i)
        newArr[i] = arr[i];
    newArr[size] = newPharmacy;
    delete[] arr;
    arr = newArr;
    ++size;
}
void printAll(Pharmacy* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i].display();
}
void deleteItem(Pharmacy*& arr, int& size) {
    std::string name;
    std::cout << "Введите название товара для удаления: ";
    std::cin >> name;
    int index = -1;
    for (int i = 0; i < size; ++i)
        if (arr[i].getName() == name)
            index = i;
    if (index == -1) {
        std::cout << "Товар не найден\n";
        return;
    }
    Pharmacy* newArr = new Pharmacy[size - 1];
    for (int i = 0, j = 0; i < size; ++i)
        if (i != index)
            newArr[j++] = arr[i];
    delete[] arr;
    arr = newArr;
    --size;
    std::cout << "Товар удален.\n";
}
void editItem(Pharmacy* arr, int size) {
    std::string name;
    std::cout << "Введите название товара для редактирования: ";
    std::cin >> name;
    for (int i = 0; i < size; ++i) {
        if (arr[i].getName() == name) {
            double newPrice;
            std::string newSymptoms;
            int newCount;
            std::cout << "Введите новую цену: ";
            std::cin >> newPrice;
            arr[i].setPrice(newPrice);
            std::cout << "Введите новое количество на складе: ";
            std::cin >> newCount;
            arr[i].setCountOnSclad(newCount);
            std::cin.ignore();
            std::cout << "Введите новые симптомы: ";
            std::getline(std::cin, newSymptoms);
            arr[i].setSymptoms(newSymptoms);
            std::cout << "Товар обновлен.\n";
            return;
        }
    }
    std::cout << "Товар не найден.\n";
}
void searchItem(Pharmacy* arr, int size) {
    std::string keyword;
    std::cout << "Введите ключевое слово для поиска: ";
    std::cin.ignore();
    std::getline(std::cin, keyword);
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i].getName().find(keyword) != std::string::npos ||
            arr[i].getSymptoms().find(keyword) != std::string::npos) {
            arr[i].display();
            found = true;
        }
    }
    if (!found)
        std::cout << "Ничего не найдено по запросу.\n";
}

