#ifndef PHARMACY_H
#define PHARMACY_H
#include <iostream>
#include <string>
class Pharmacy {
private:
    std::string name;
    double price;
    int Count_In_Pack;
    int Count_On_Sclad;
    std::string symptoms;
public:
    Pharmacy();
    Pharmacy(std::string n, double p, int inPack, int onSclad, std::string s);
    void display() const;
    std::string getName() const;
    std::string getSymptoms() const;
    void setPrice(double newPrice);
    void setSymptoms(const std::string& newSymptoms);
    void setCountOnSclad(int count);
    friend std::ostream& operator<<(std::ostream& out, const Pharmacy& p);
    friend std::istream& operator>>(std::istream& in, Pharmacy& p);
};
#endif

