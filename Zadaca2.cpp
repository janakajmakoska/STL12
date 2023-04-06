#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

class Inventar {
public:
    int id;
    int kolicestvo;
    double cena;

    Inventar(int id, int kolicestvo, double cena) {
        this->id = id;
        this->kolicestvo = kolicestvo;
        this->cena = cena;
    }

    double getVrednost() const {
        return kolicestvo * cena;
    }

    friend bool operator<(const Inventar& a, const Inventar& b) {
        return a.id < b.id;
    }

    friend ostream& operator<<(ostream& out, const Inventar& i) {
        out << i.id << " " << i.kolicestvo << " " << i.cena;
        return out;
    }
};

int main() {
    vector<Inventar> inventar;

    ifstream inFile("Inventar.txt");
    if (!inFile) {
        throw runtime_error("Datotekata ne mozhe da se otvori");
    }

    int id, kolicestvo;
    double cena;
    while (inFile >> id >> kolicestvo >> cena) {
        Inventar i(id, kolicestvo, cena);
        inventar.push_back(i);
    }

    inFile.close();

    double vkupnaVrednost = accumulate(inventar.begin(), inventar.end(), 0.0,
        [](double sum, const Inventar& i) {
            return sum + i.getVrednost();
        });

    cout << "Vkupna vrednost na site artikli: " << vkupnaVrednost << endl;

    cout << "Artikli so kolicestvo pomalo od 10: " << endl;
    for_each(inventar.begin(), inventar.end(),
        [](const Inventar& i) {
            if (i.kolicestvo < 10) {
                cout << i << endl;
            }
        });

    return 0;
}
