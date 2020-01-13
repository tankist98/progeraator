/**
 * Algoritmid ja andmestruktuurid (NTR0390)
 * Tallinna Tehnikaülikooli Tartu Kolledž
 * Projekt: Laevade pommitamine
 * Markel Veiko
 * 2020-01-03
 */


#include <iostream>
#include <limits>
#include <ostream>

using namespace std;

class Manguvali{
public:
	Manguvali(); // Loob 2 mõõtmelise massiivi ja täidab selle kohad '-'
	void valjasta(); // Prindib välja koordinaatidega tabeli
	int onKaotatud(); // Kontrollib, kunas saavad laevad manguväljalt otsa ja annab teada voidust voi kaotusest
	void pakkumine(char x, char y);
	void asenda(char manguvali[10][10]);
	char manguvali[10][10];
};

Manguvali::Manguvali(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			manguvali[i][j] = '-';
			}
		}
}

void Manguvali::valjasta(){
	char y[] = {'0','1','2','3','4','5','6','7','8','9'};
	cout << "X 1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 0; i < 10; i++){
		cout << y[i];
		for (int j = 0; j < 10; j++){
			cout << " " << manguvali[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Manguvali::asenda(char manguvali[10][10]){
	int x, y;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cin >> x >> y;
			manguvali[x][y] = '+';
		}
	}
	cout << manguvali[i][j] << endl;
}

/*void Manguvali::pakkumine(char y, char x) {
    int x_cord = x - '0'; //Converts char to int
    char y_[] = {'0','1','2','3','4','5','6','7','8','9'};

    //So the X cords already int. This for loop goes through y_cords[] to find the proper y value
    //because the y value is passed to the function as a letter
    for (int i = 0; i < 10; i++) {
        if (y_[i] == y) {
            if (manguvali[i][x_cord] == '~') { manguvali[i][x_cord] = '#'; } // If you guess water, show no hit
            if (manguvali[i][x_cord] == '+') { manguvali[i][x_cord] = 'X'; } // If you guess the ship, you hit!
        }
    }
    valjasta();
}

/*void Manguvali::asenda(char y, char x){
	int y_cord;
    int x_cord = x - '0';
    char y_[] = {'0','1','2','3','4','5','6','7','8','9'};

    for (int i = 0; i < 10; i++) {
        if (y_[i] == y) {
            manguvali[i][x_cord] = '+';
			}
		}
		valjasta();
}*/



int Manguvali::onKaotatud() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (manguvali[i][j] == '+') {
                return 0;
            }
        }
    }
    return 1;
}




bool soovib_uuesti() {

	char sisend;
	bool vale_sisend;
	do {
		vale_sisend = false;
		cout << "Kas soovid uuesti mangida (Y/N)? ";
		cin >> sisend;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (sisend != 'Y' && sisend != 'y' && sisend != 'N' && sisend != 'n') {
			vale_sisend = true;
			cout << "Viga! Vasta kas 'Y' voi 'N'." << endl;
		}
	} while (vale_sisend);
	return sisend == 'Y' || sisend == 'y';
}
void kirjuta_faili(string failinimi, char* manguvali1){
	ofstream valjund(failinimi, ios::app);
	valjund << manguvali << endl;
	//valjund << manguvali2 << endl;
	valjund.close();
}
int main(){
	string valjundfail = "pommitamine.txt"
	int x, y;
	do{
		Manguvali manguvali1;
		manguvali1.valjasta();
		manguvali1.asenda();

		kirjuta_faili(valjundfail, manguvali1);
	} while(soovib_uuesti());


	return 0;
}
