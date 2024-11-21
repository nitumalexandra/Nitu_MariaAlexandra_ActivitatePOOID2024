#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Autobuz {
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;   
    int nrPersoaneImbarcate;
    char* producator;

public:
    Autobuz() : idAutobuz(nrAutobuze) { // constructor implicit (fara parametrii)
        nrAutobuze++;
        capacitate = 0;
        nrPersoaneImbarcate = 0;
        producator = new char[1];
        producator[0] = '\0';
    }

    // constructor cu parametrii
    Autobuz(int idAutobuz, int nrAutobuze, int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(idAutobuz) { // idAutobuz este constant si trebuie reinitializat
        nrAutobuze++;
        if (capacitate >= 0) {
            this->capacitate = capacitate;
        }

        if (nrPersoaneImbarcate <= this->capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }

        if (producator != NULL) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
    }

    ~Autobuz() { // destructor
        delete[] producator;
    }

    Autobuz(const Autobuz& a) : idAutobuz(a.idAutobuz) { // constructor de copiere
        producator = new char[strlen(a.producator) + 1];
        strcpy(producator, a.producator);
        capacitate = a.capacitate;
        nrPersoaneImbarcate = a.nrPersoaneImbarcate;
    }

    //metode accesor GET:
    int getCapacitate() {
        return capacitate;
    }

    int getNrPersoaneImbarcate() {
        return nrPersoaneImbarcate;
    }

    //metode accesor SET:
    void setCapacitate(int capacitate) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
    }

    void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
        if (nrPersoaneImbarcate < capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
    }

    Autobuz& operator=(const Autobuz& b) { // supraincarcarea operatorului =
        if (this != &b) {
            capacitate = b.capacitate;
            nrPersoaneImbarcate = b.nrPersoaneImbarcate;
            delete[] producator;
            producator = new char[strlen(b.producator) + 1];
            strcpy(producator, b.producator);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Autobuz& autobuz) { // supraincarcarea operatorului <<
        os << autobuz.idAutobuz << " " << autobuz.capacitate << " " << autobuz.nrPersoaneImbarcate << " " << autobuz.producator;
        return os;
    }

    int getNumarLocuriLibere() const { // numarul de locuri libere
        return capacitate - nrPersoaneImbarcate;
    }

    operator int() const { // supraincarcare cu operatorul de cast la int
        return nrPersoaneImbarcate;
    }

    bool operator>(const Autobuz& c) const { // supraincarcarea cu operator >
        return this->capacitate > c.capacitate;
    }
};

int Autobuz::nrAutobuze = 0; // initializarea valorii statice

int main() {
    Autobuz autobuzA(1, 1, 45, 40, "Megabus");
    Autobuz autobuzB(2, 2, 35, 20, "RegioTrans");

    Autobuz autobuzC; // constructor implicit

    cout << "Autobuzul 1: " << autobuzA << endl;
    cout << "Autobuzul 2: " << autobuzB << endl;
    cout << "Autobuzul 3: " << autobuzC << endl;

    // locurile libere
    cout << "Locuri libere in autobuzul 1: " << autobuzA.getNumarLocuriLibere() << endl;
    cout << "Locuri libere in autobuzul 2: " << autobuzB.getNumarLocuriLibere() << endl;

    // care autobuz are capacitatea mai mare
    if (autobuzA > autobuzB) {
        cout << "Primul autobuz are capacitatea mai mare " << endl;
    }
    else {
        cout << "Al doilea autobuz are capacitatea mai mare " << endl;
    }

    // testarea constructorului de copiere prin folosirea unui obiect neinitializat
    Autobuz ax = autobuzA;
    cout << "Al treilea autobuz va fi copiat dupa primul autobuz:  " << ax << endl;

    // testarea operatorului de atribuire
    Autobuz ay(4, 4, 60, 55, "RegioTrans");
    ay = autobuzB;
    cout << "Autobuzului 4 ii vor fi atribuite valorile autobuzului 2: " << ay << endl;

    return 0;
}
