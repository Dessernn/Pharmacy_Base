#include <limits>
#include "pharmacy.h"
Pharmacy::Pharmacy() : name(""), price(0.0), Count_In_Pack(0), Count_On_Sclad(0), symptoms("") {}
Pharmacy::Pharmacy(std::string n, double p, int inPack, int onSclad, std::string s)
    : name(n), price(p), Count_In_Pack(inPack), Count_On_Sclad(onSclad), symptoms(s) {}
void Pharmacy::display() const {
    std::cout << "Название: " << name
              << ", Цена: " << price
              << ", Кол-во в упаковке: " << Count_In_Pack
              << ", Кол-во на складе: " << Count_On_Sclad
              << ", Симптомы: " << symptoms << std::endl;
}
std::string Pharmacy::getName() const {
    return name;
}
std::string Pharmacy::getSymptoms() const {
    return symptoms;
}
void Pharmacy::setPrice(double newPrice) {
    price = newPrice;
}
void Pharmacy::setSymptoms(const std::string& newSymptoms) {
    symptoms = newSymptoms;
}
void Pharmacy::setCountOnSclad(int count) {
    Count_On_Sclad = count;
}
std::ostream& operator<<(std::ostream& out, const Pharmacy& p) {
    out << p.name << '\n' << p.price << '\n' << p.Count_In_Pack << '\n'
        << p.Count_On_Sclad << '\n' << p.symptoms << '\n';
    return out;
}
std::istream& operator>>(std::istream& in, Pharmacy& p) {
    if (&in == &std::cin) {
        std::cout << "Введите название: ";
        std::getline(in >> std::ws, p.name);
        std::cout << "Введите цену, количество в упаковке, количество на складе (через пробел): ";
        in >> p.price >> p.Count_In_Pack >> p.Count_On_Sclad;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите симптомы: ";
        std::getline(in, p.symptoms);
    } else {
        std::getline(in >> std::ws, p.name);
        in >> p.price >> p.Count_In_Pack >> p.Count_On_Sclad;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(in, p.symptoms);
    }
    return in;
}


