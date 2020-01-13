/**
 * Algoritmid ja andmestruktuurid (NTR0390)
 * Tallinna Tehnikaülikooli Tartu Kolledž
 * Projekt: Laevade pommitamine
 * Markel Veiko
 * 2020-01-03
 */


#include <iostream>
#include <limits>

using namespace std;

class Manguvali{
public:
	Manguvali(); // Loob 2 mõõtmelise massiivi ja täidab selle kohad '-'
	void valjasta(); // Prindib välja koordinaatidega tabeli
	int onKaotatud(); // Kontrollib, kunas saavad laevad manguväljalt otsa ja annab teada voidust voi kaotusest
private:
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

class Laevad{
public:
	void asetaLaevad();
	void pakkumine();
private:
	int laevaSuurused[] = {5,4,3,3,2};
};















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

int main(){

do{
	Manguvali manguvali1;
	manguvali1.valjasta();
} while(soovib_uuesti());


	return 0;
}
//Initialize default variables
  //Create game board

  //Loop till all ships are placed
    //Draw board
    //A player places ships
    // Toggle to next player

  //Game Loop Start
    //Player X inputs valid attack grid
    // Check to see if attack is a hit
    // Remove/add damage to hit ships
    // Redraw game board
    // Check to see if game is over
        // If game over - exit loop/end program
    // Toggle next player's turn
  //Game Loop Return
