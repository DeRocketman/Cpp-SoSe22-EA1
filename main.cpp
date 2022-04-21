#include <iostream>

using namespace std;


class IceCreamParlor {

    string ice[3] = {"Capri", "Nogger", "Cornetto"};
    float price[3] = {1.10, 1.60, 2.30};

    public:
        void printIceCreamMenu() {
            for (int i = 0; i < 3; ++i) {
                cout << ice[i] << " " << price[i] << "0 €" << endl;
            }
        }

        int printMainMenu() {
            int userChoice = 4;

            cout << "Moin und herzlich Willkommen im IceShop" << endl;
            cout << "Bitte wählen Sie durch eingabe der Zahl:" << endl;
            cout << "[1]: Eiskarte anzeigen" << endl;
            cout << "[2]: Bestellung aufgeben" << endl;
            cout << "[3]: Automatische Schnellwahl für mutige" << endl;
            cout << "[0]: Ende" << endl;
            cin >> userChoice;
            return userChoice;
        }
};


int main() {
    IceCreamParlor parlor;
    parlor.printMainMenu();

}
