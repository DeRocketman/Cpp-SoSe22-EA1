/**
 *
 * This file is the full ESA1 in module "Grundlagen C++ SoSe22"
 * @author Dirk Stricker 333036 THL dirk.stricker@stud.th-luebeck.de
 * @version 2022.05.16
 *
 */

#include <iostream>
#include <vector>

using namespace std;


class IceCreamParlor {

    string ice[3] = {"Capri", "Nogger", "Cornetto"};
    float price[3] = {1.10, 1.60, 2.30};
    float credit = 0.0;

    void printIceCreamMenu(bool showNumber) {
        cout << "++++++++++++++++++ICE-CARD++++++++++++++++++" << endl;
        for (int i = 0; i < 3; ++i) {
            if (showNumber) {
                cout << "["<< i+1 << "]: " << ice[i] << " " << price[i] << "0 €" << endl;
            } else {
                cout << ice[i] << " " << price[i] << "0 €" << endl;
            }
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
    }

    void printOrder() {
        int userChoice = 6;
        float sum = 0.0;
        vector<string> order;
        vector<float> bill;

        cout << "Sie möchten bestellen" << endl;
        cout << "Bitte Guthaben eingeben (Format: 1.30)" << endl;
        cin >> credit;

        while(userChoice != 0 && userChoice != 5) {
            cout << "Bitte wählen Sie durch Eingabe der entsprechenden Nummer" << endl;
            printIceCreamMenu(true);
            cout << "[0] Um abzubrechen und zum Hauptmenü zurück zu kehren" << endl;
            cout << "[5] Bestellung abschließen und bezahlen" << endl;
            cout << "Ihr Guthaben beträgt: " << credit << " €" << endl;
            cout << "Ihre Auswahl: ";
            cin >> userChoice;

            if (userChoice == 0) {
                cout << "Bestellvorgang abgebrochen. Bitte Geld entnehmen." << endl;
            }  else if (userChoice >= 1 && userChoice <= 3) {
                for (int i = 0; i < 3; ++i) {
                    if (userChoice-1 == i) {
                        if (credit >= price[i]) {
                            order.push_back(ice[i]);
                            bill.push_back(price[i]);
                            credit-=price[i];
                        } else if (i==0){
                            cout << "Nicht mehr genug Guthaben für ein Eis" << endl;
                        } else {
                            cout << "Das Eis ist zu teuer. Bitte ein günstigeres als " << price[i] << "0 € wählen" << endl;
                        }
                    }
                }
            } else if (userChoice == 5) {
                cout << "Ihre Bestellung wird abgeschlossen und eine Rechnung erstellt:" << endl;
                if (order.empty()) {
                    cout << "Sie haben nichts bestellt. Bitte Geld entnehmen" << endl;
                } else {
                    for (int i = 0; i < order.size(); i++) {
                        sum += bill[i];
                        cout << i+1 << ": " << order[i]<< " für " << bill[i] <<"0 €" << endl;
                    }
                    cout << "------------------------" << endl;
                    cout << "Gesamt:   " << sum << " €" << endl;
                    cout << "Guthaben: " << credit+sum << " €" << endl;
                    cout << "------------------------" << endl;
                    cout << "Rest:     " << credit << " €" << endl;
                }
            } else {
                cout << "Ihre Eingabe war ungültig" << endl;
            }
        }
    }

public:
    void printMainMenu() {
        int userChoice = 4;

        while (userChoice!=0) {
            cout << "___---+++ICE++EIS++ICE++EIS+++ICE++EIS++ICE++EIS+++---___" << endl;
            cout << "Moin und herzlich Willkommen im iceEshop" << endl;
            cout << "Bitte wählen Sie durch Eingabe der Zahl:" << endl;
            cout << "[1]: Eiskarte anzeigen" << endl;
            cout << "[2]: Bestellung aufgeben" << endl;
            cout << "[0]: Ende" << endl;
            cout << "________________________________________________________\n" << endl;
            cout << "Ihre Auswahl: ";
            cin >> userChoice;

            if (userChoice == 0) {
                cout << "Eingabe ist nicht gültig\n" << endl;
            } else if (userChoice == 1) {
                printIceCreamMenu(false);
            } else if (userChoice == 2) {
                printOrder();
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
