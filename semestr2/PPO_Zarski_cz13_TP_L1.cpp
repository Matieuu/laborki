#include "PPO_Zarski_L1.hpp"
#include <iostream>

Witcher::Witcher() {
	std::cout << "Nadanie wartości - konstruktor domyślny\n";
	name_ = "Geralt";
	witcher_school_ = "Wilka";
	age_ = 110;
	height_ = 180;
	weight_ = 70;
}

Witcher::~Witcher() {
	std::cout << "Likwidacja!\n";
}

void Witcher::read(void) {
	std::cout << "Podaj imię: ";
	std::getline(std::cin, name_);

	std::cout << "Podaj szkołę: ";
	std::getline(std::cin, witcher_school_);

	std::cout << "Podaj wiek: ";
	std::cin >> age_;

	std::cout << "Podaj wzrost: ";
	std::cin >> height_;

	std::cout << "Podaj wagę: ";
	std::cin >> weight_;

	std::cout << "\n";
}

void Witcher::write(void) {
	// std::printf("Wiedźmin %s (wiek: %d):\n - szkoła: %s\n - wzrost: %a\n - waga: %a\n",
	//             name_,
	//             age_,
	//             witcher_school_,
	//             height_,
	//             weight_);
	std::cout << "Wiedźmin " << name_ << " (wiek: " << age_ << "):\n";
	std::cout << " - szkoła: " << witcher_school_ << ";\n";
	std::cout << " - wzrost: " << height_ << ";\n";
	std::cout << " - waga: " << weight_ << ".\n\n";
}

/*
void wczytaj(Witcher *witcher) {
	std::cout << "Podaj imię: ";
	std::getline(std::cin, witcher->name_);

	std::cout << "Podaj szkołę: ";
	std::getline(std::cin, witcher->witcher_school_);

	std::cout << "Podaj wiek: ";
	std::cin >> witcher->age_;

	std::cout << "Podaj wzrost: ";
	std::cin >> witcher->height_;

	std::cout << "Podaj wagę: ";
	std::cin >> witcher->weight_;

	std::cout << "\n";
}

void wypisz(Witcher *witcher) {
	// std::printf("Wiedźmin %s (wiek: %d):\n - szkoła: %s\n - wzrost: %s\n - waga: %s\n",
	//             witcher->name_,
	//             witcher->age_,
	//             witcher->witcher_school_,
	//             witcher->height_,
	//             witcher->weight_);
	std::cout << "Wiedźmin " << witcher->name_ << " (wiek: " << witcher->age_ << "):\n";
	std::cout << " - szkoła: " << witcher->witcher_school_ << ";\n";
	std::cout << " - wzrost: " << witcher->height_ << ";\n";
	std::cout << " - waga: " << witcher->weight_ << ".\n\n";
}
*/

int main(void) {
	Witcher *witcher = new Witcher();
	// wczytaj(witcher);
	// wypisz(witcher);
	witcher->write();
	witcher->read();
	witcher->write();

	witcher = new Witcher("Lambert", "Wilka", 70, 180, 70);
	witcher->write();

	delete witcher;
}

//? PYTANIE: Czy stworzone przez Ciebie funkcje składowe i funkcje nie będące składowymi klasy będą nadal działać? Jeśli tak, to które i dlaczego?
//! Nie będą działać ponieważ pola są prywatne i nie mamy do nich dostępu na zewnątrz klasy

//? PYTANIE: Czy dla stworzonego obiektu zostały wyświetlone wartości, które nadałeś poprzez konstruktor?
//! Tak

//? PYTANIE: Czy zauważyłeś działanie destruktora? Czy musiałeś go wywołać jawnie?
//! Nie, trzeba go wywołać jawnie, jako jawnie mam na myśli wywołanie jej przez `delete`, czyli pośrednio

//? PYTANIE: Przetestuj i odpowiedz, w jakiej kolejności wywołają się destruktory w przypadku utworzenia obiektu za pomocą konstruktora domyślnego, a potem kolejnego za pomocą konstruktora wieloargumentowego?
//! Jeśli zostaną zapisane do tej samej zmiennej to wystarczy jedno wywołanie i zostanie usunięty obiekt stworzony za pomocą destruktora wieloargumentowego

//? PYTANIE: Wyjaśnij, dlaczego akurat przy tych funkcjach użyłeś słowa kluczowego (dodatkowo podaj jakie to słowo)?
//! `const` - w przypadku funkcji jest używane żeby oznaczyć funkcje nie wykonujące żadnych operacji na zmiennych, aka działających w czasie stałym

//? PYTANIE: Jeżeli klasa posiada konstruktor wieloargumentowy, to konieczne było zdefiniowanie konstruktora domyślnego jawnie, aby mógł on zostać wywołany? Czy gdybyś tego nie zrobił, zostałby wywołany niejawnie?
//! Nie, konstruktor domyślny jest wtedy wieloargumentowym
