#include <iostream>
#include <vector>

using namespace std;


class IceCreamParlor {

    string ice[3] = {"Capri", "Nogger", "Cornetto"};
    float price[3] = {1.10, 1.60, 2.30};

    void printIceCreamMenu() {
        cout << "++++++++++++++++++ICE-CARD++++++++++++++++++" << endl;
        for (int i = 0; i < 3; ++i) {
                cout << ice[i] << " " << price[i] << "0 €" << endl;
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
    }

    void printOrder() {
        int userChoice = 5;
        float credit = 0.0;
        vector<string> order;
        vector<float> bill;

        cout << "" << endl;
    }

    void printRandomOrder() {

    }

public:

    void printMainMenu() {
        int userChoice = 4;

        while (userChoice!=0) {
            cout << "___---+++ICE++EIS++ICE++EIS+++ICE++EIS++ICE++EIS+++---___" << endl;
            cout << "Moin und herzlich Willkommen im iceEshop" << endl;
            cout << "Bitte wählen Sie durch eingabe der Zahl:" << endl;
            cout << "[1]: Eiskarte anzeigen" << endl;
            cout << "[2]: Bestellung aufgeben" << endl;
            cout << "[3]: Automatische Schnellwahl für mutige Eisliebhaber :)" << endl;
            cout << "[0]: Ende" << endl;
            cout << "________________________________________________________\n" << endl;
            cout << "Ihre Auswahl: ";
            cin >> userChoice;

            if (userChoice > 3) {
                cout << "Eingabe ist nicht gültig" << endl;
                cout << "Weiter mit Eingabe" << endl;
            } else if (userChoice == 1) {
                printIceCreamMenu();
            } else if (userChoice == 2) {
                printOrder();
            } else if (userChoice == 3) {
                printRandomOrder();
            } else {
                cout << "Vielen Dank für ihren Besuch...Tschüss!" << endl;
            }
        }
    }
};


int main() {
    IceCreamParlor parlor;
    parlor.printMainMenu();
}
