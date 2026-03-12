#include <cstring>
#include <iostream>
#include <limits>

void insert_text(char text[], const unsigned int text_len) {
	std::string inserted_text;

	do {
		// Wyczyść bufor żeby newline nie pobierał starego \n
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wpisz tekst: ";
		std::getline(std::cin, inserted_text); // Pobierz linię tekstu
		if (inserted_text.empty()) continue;   // Jeśli tekst jest pusty - pobierz jeszcze raz
	} while (inserted_text.length() >= text_len); // Jeśli tekst jest za długi - pobierz jeszcze raz

	std::snprintf(text, text_len, "%s", inserted_text.c_str());
}

void display_text(char text[], const unsigned int text_len) {
	for (int index = 0; index < text_len; index++) {
		if (text[index] == '\0'     // Jeśli to znak kończący linię
		    || text[index] == '\n') // Lub znak nowej linii
			return;                 // Zakończ wypisywanie
		std::cout << text[index];   // Wypisz literę
	}
}

int count_len(char text[]) {
	int index = 0;
	while (text[index] != '\0'       // Jeśli to nie jest znak kończący linię
	       && text[index] != '\n') { // Ani znak zaczynający nową linię
		index++;                     // Powiększ rozmiar tekstu o jeden
	}
	return index;
}

void replace_characters_size(char text[], const unsigned int text_len) {
	const int size_diff = 'A' - 'a';                           // Jaka jest różnica między małymi a wielkimi literami
	for (int index = 0; index < text_len; index++) {           // Dla każdego znaku
		if (text[index] >= 'a' && text[index] <= 'z') {        // Jeśli mieści się w przedziale małych liter
			text[index] += size_diff;                          // Dodaj różnicę między znakami w celu zamiany litery na wielką
		} else if (text[index] >= 'A' && text[index] <= 'Z') { // Jeśli mieści się w przedziale wielkich liter
			text[index] -= size_diff;                          // Odejmij różnicę między znakami w celu zamiany litery na małą
		}
	}
}

int main(void) {
	const unsigned int text_len = 15;
	char text[text_len] = {0};
	insert_text(text, text_len);

	std::cout << "Twój tekst to: ";
	display_text(text, text_len);

	std::cout << "\nDługość Twojego tekstu jest równa " << count_len(text);

	replace_characters_size(text, text_len);
	std::cout << "\nTwój tekst po zamianie rozmiarów znaków: ";
	display_text(text, text_len);
}
