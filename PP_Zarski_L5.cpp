#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string firstname;
	string surname;
	string nickname;
};

void addElement(vector<Student> &db) {
	Student student;

	cout << "\nPodaj imie: ";
	cin >> student.firstname;

	cout << "\nPodaj nazwisko: ";
	cin >> student.surname;

	cout << "\nPodaj nick: ";
	cin >> student.nickname;

	db.push_back(student);
}

bool displayDatabase(const vector<Student> &db) {
	if (db.empty()) {
		cout << "\nBaza jest pusta";
		return false;
	}

	for (unsigned int index = 0; index < db.size(); index++) {
		const Student &student = db[index];
		cout << "\n[" << index << "] " << student.firstname << " \"" << student.nickname << "\" " << student.surname;
	}

	cout << "\n";
	return true;
}

void writeToFile(const vector<Student> &db, const string &filename) {
	ofstream file(filename);

	if (!file.is_open()) {
		cerr << "\nNie udało się otworzyć pliku do zapisu\n";
		return;
	}

	for (const Student &student : db) {
		file << student.firstname << " " << student.surname << " " << student.nickname << endl;
	}

	file.close();
}

void readFromFile(vector<Student> &db, const string &filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "\nNie znaleziono pliku lub pojawił się błąd otwarcia\n";
		return;
	}

	db.clear();
	Student student;

	while (file >> student.firstname >> student.surname >> student.nickname) {
		db.push_back(student);
	}

	file.close();
}

void deleteElement(vector<Student> &db) {
	if (!displayDatabase(db)) return;

	int index;
	cout << "\nPodaj index do usunięcia: ";
	cin >> index;

	if (index < 0 || index >= db.size()) {
		cerr << "Niepoprawny index\n";
		return;
	}

	db.erase(db.begin() + index);
}

void toLower(string &value) {
	for (char &c : value) {
		if (c >= 'A' && c <= 'Z') {
			c -= 'A' - 'a';
		}
	}
}

void findElement(const vector<Student> &db) {
	string field;
	cout << "\nWybierz pole do wyszukiwania (imie, nazwisko, nick): ";
	cin >> field;

	string phrase;
	cout << "\nPodaj frazę do wyszukania: ";
	cin >> phrase;

	toLower(field);
	int index = 0;
	bool isFound = false;

	for (const Student &student : db) {
		string fieldToCheck;

		if (field == "imie") {
			fieldToCheck = student.firstname;
		} else if (field == "nazwisko") {
			fieldToCheck = student.surname;
		} else if (field == "nick") {
			fieldToCheck = student.nickname;
		} else {
			cerr << "\nNieprawidłowe pole do wyszukiwania\n";
			return;
		}

		toLower(fieldToCheck);
		toLower(phrase);

		// string::npos to "not found position"
		if (fieldToCheck.find(phrase) != string::npos) {
			cout << "\n[" << index << "] " << student.firstname << " \"" << student.nickname << "\" " << student.surname;
			isFound = true;
		}

		index++;
	}

	if (!isFound) cout << "\nNie znaleziono studentów\n";
	cout << "\n";
}

int main(void) {
	vector<Student> db;
	string filename = "studenci.txt";
	int option = 0;

	do {
		cout << "\n=== MENU ===\n";
		cout << "1. Wczytaj z pliku\n";
		cout << "2. Zapisz do pliku\n";
		cout << "3. Dodaj element\n";
		cout << "4. Wyświetl bazę\n";
		cout << "5. Usuń element\n";
		cout << "6. Wyszukaj\n";
		cout << "0. Wyjście\n";
		cout << "Wybór: ";
		cin >> option;

		switch (option) {
		case 1:
			readFromFile(db, filename);
			break;
		case 2:
			writeToFile(db, filename);
			break;
		case 3:
			addElement(db);
			break;
		case 4:
			displayDatabase(db);
			break;
		case 5:
			deleteElement(db);
			break;
		case 6:
			findElement(db);
			break;
		case 0:
			cout << "\nKoniec wykonywania programu\n";
			break;
		default:
			cout << "\nNieznana opcja\n";
			break;
		}
	} while (option != 0);

	return 0;
}
