#include <iomanip>
#include <iostream>
#include <string>

const unsigned int letter_count = 'z' - 'a' + 1;

void count_letters(std::string text, unsigned int letters[]) {
	for (int index = 0; index < text.length(); index++) {
		char letter = (char)text[index];                       // Dla debuggera
		if (text[index] >= 'A' && text[index] <= 'Z') {        // Jeśli wielka litera
			letters[text[index] - 'A']++;                      // Zwiększ liczbę wystąpień tej litery
		} else if (text[index] >= 'a' && text[index] <= 'z') { // Jeśli mała litera
			letters[text[index] - 'a']++;                      // Zwiększ liczbę wystąpień tej litery
		}
	}
}

int main(void) {
	unsigned int letters[letter_count] = {0};
	std::string text;

	std::cout << "Podaj tekst do sprawdzenia: ";
	std::getline(std::cin, text);
	count_letters(text, letters);

	for (int index = 0; index < letter_count; index++) {
		if (letters[index]) {
			std::cout << "\n"
			          << (char)(index + 'a') << " ";
			for (int iter = 0; iter < letters[index]; iter++) {
				std::cout << "#";
			}
		}
	}
}