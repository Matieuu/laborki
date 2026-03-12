#include <chrono>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

// Powtarza się zapytanie więc w imię idei DRY wyciągnąłem do osobnej funkcji
void ask(int *input) {
	std::cout << "\n\nWybierz akcję:\n  1. Wprowadź dane;\n  2. Zwróć sumę elementów;\n  3. Zwróć wartość maksymalną;\n  4. Wyświetl zawartość tablicy;\n  5. Wylosuj zawartość tablicy;\n  6. Zamień liczbę na liczbę binarną;\n  7. Posortuj elementy;\n  8. Przetestuj sortowanie bombelkowe\n  0. Wyjdź.\n > ";
	std::cin >> *input;
}

// Główna funkcja do uzupełniania tablicy
void insert_data(int tab[], bool random, int size) {
	if (random) {
		// Pobiera dwie liczby oddzielone dowolnym separatorem
		int min, max;
		char comma;

		std::cout << "Podaj zakres wartości (<min><separator><max>): ";
		std::cin >> min >> comma >> max;

		// Operacje zamiany miejscami
		if (min > max) {
			min += max;      // x = x + y
			max = min - max; // y = x - y
			min -= max;      // x = x - y
		}

		// Wypełnia tablicę losowymi elementami
		for (int i = 0; i < size; i++) {
			tab[i] = min + (std::rand() % (max - min + 1));
		}
	} else {
		// Pyta użytkownika o podanie każdej liczby do zapisania w tablicy
		for (int i = 0; i < size; i++) {
			std::cout << "Liczba nr " << i + 1 << ": ";
			std::cin >> tab[i];
		}
	}
}

// Funkcje redundantne żeby nie musieć podawać wszystkich argumentów

void insert_data(int tab[], bool random) {
	insert_data(tab, random, 5);
}

void insert_data(int tab[]) {
	insert_data(tab, false, 5);
}

// Funkcja pomocnicza do obliczania potęgi liczby 2 z użyciem rekurencji
int pow_of_2(int y) {
	if (y == 0) {
		return 1;
	} else {
		return pow_of_2(y - 1) * 2;
	}
}

// Funkcja do zamiany liczby dziesiętnej na liczbę binarną
void insert_binary_number(int tab[]) {
	// Inicjalizacja liczby poza zakresem
	int number{-1};
	// Zapytanie o liczbę do zamiany
	while (number < 0 || number > 31) {
		std::cout << "Podaj liczbę (zakres 0-31): ";
		std::cin >> number;
	}

	// Zamiana liczby dziesiętnej na liczbę binarną
	for (int i = 0; i < 5; i++) {
		int pow = pow_of_2(4 - i);
		if (number >= pow) {
			tab[i] = 1;
			number -= pow;
		} else {
			tab[i] = 0;
		}
	}
}

// Funkcja do sumowania elementów tablicy
void get_sum(int tab[]) {
	int sum{0};
	for (int i = 0; i < 5; i++) {
		sum += tab[i];
	}
	std::cout << "Suma elementów wynosi " << sum;
}

// Funkcja do szukania maksymalnego elementu (za pomocą iteracji po elementach ponieważ nie korzystam z drzewa)
void get_max(int tab[]) {
	int max{INT_MIN};
	for (int i = 0; i < 5; i++) {
		if (tab[i] > max) {
			max = tab[i];
		}
	}
	std::cout << "Maksymalna wartość jest równa " << max;
}

// Funkcja do wypisania wszystkich elementów
void write_elements(int tab[]) {
	for (int i = 0; i < 5; i++) {
		std::cout << "\ntab[" << i + 1 << "] = " << tab[i];
	}
}

// Funkcja do sortowania bombelkowego
double sort(int tab[], int size) {
	auto start = std::chrono::high_resolution_clock::now();

	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size - 1; k++) {
			if (tab[k] > tab[k + 1]) {
				// Operacje zamiany miejscami
				tab[k] += tab[k + 1];             // x = x + y
				tab[k + 1] = tab[k] - tab[k + 1]; // y = x - y
				tab[k] -= tab[k + 1];             // x = x - y
			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

// Funkcja do testowania czasu potrzebnego do sortowania tablic
void test_sorting() {
	int size1, size2;
	std::cout << "Podaj rozmiary tablic\n";
	std::cout << "Tablica 1: ";
	std::cin >> size1;
	std::cout << "Tablica 2: ";
	std::cin >> size2;

	// Tworzenie tablic z dynamicznym rozmiarem
	int *tab1 = new int[size1];
	int *tab2 = new int[size2];

	insert_data(tab1, true, size1);
	insert_data(tab2, true, size2);

	double time1 = sort(tab1, size1);
	double time2 = sort(tab2, size2);

	std::cout << "Czas sortowania tablicy o rozmiarze " << size1 << " wyniósł " << time1 << "ms\n";
	std::cout << "Czas sortowania tablicy o rozmiarze " << size2 << " wyniósł " << time2 << "ms";

	// Zwolnienie pamięci przeznaczonych na tablice
	delete[] tab1;
	delete[] tab2;
}

// Główna funkcja programu
int main(void) {
	// Ustala inną losową liczbę za każdym razem kiedy program się uruchamia
	std::srand(std::time(0));

	int tab[5];
	int input;
	ask(&input);

	while (input) {
		switch (input) {
		case 1: // Wprowadzanie danych
			insert_data(tab);
			break;

		case 2: // Zwracanie sumy elementów
			get_sum(tab);
			break;

		case 3: // Zwracanie wartości maksymalnej
			get_max(tab);
			break;

		case 4: // Wyświetlanie zawartości tablicy
			write_elements(tab);
			break;

		case 5: // Losowanie zawartości tablicy
			insert_data(tab, true);
			break;

		case 6: // Zamiana liczby na binarkę
			insert_binary_number(tab);
			break;

		case 7: // Sortowanie elementów
			(void)sort(tab, 5);
			break;

		case 8: // Testowanie sortowania
			test_sorting();
			break;

		default:
			std::cout << "\nNieprawidłowa wartość!";
			break;
		}

		ask(&input);
	}

	return 0;
}
