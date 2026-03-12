#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Student {
	int id;
	string nick;
	int level;
	char sex;
};

void addElement(vector<Student> &db) {
	Student student;

	cout << "\nPodaj nick: ";
	cin >> student.nick;

	cout << "Podaj level: ";
	cin >> student.level;

	cout << "Podaj płeć: ";
	cin >> student.sex;

	student.id = db.size() + 1;

	db.push_back(student);
}

bool displayDatabase(const vector<Student> &db) {
	if (db.empty()) {
		cout << "\nBaza jest pusta";
		return false;
	}

	for (unsigned int index = 0; index < db.size(); index++) {
		const Student &student = db[index];
		cout << "\n[" << index << "] "
		     << student.id << ". "
		     << student.nick << " "
		     << student.level << " "
		     << student.sex;
	}

	cout << "\n";
	return true;
}

void writeToFile(const vector<Student> &db, const string &filename) {
	fstream file;
	file.open(filename, ios::out);

	if (!file.is_open()) {
		cerr << "\nNie udało się otworzyć pliku do zapisu\n";
		return;
	}

	file << "# [index] id. nick level płeć";
	unsigned int index = 0;
	for (const Student &student : db) {
		file << "\n[" << index << "] "
		     << student.id << ". "
		     << student.nick << " "
		     << student.level << " "
		     << student.sex;
		index++;
	}

	file.close();
}

void readFromFile(vector<Student> &db, const string &filename) {
	fstream file;
	file.open(filename, ios::in);

	if (!file.is_open()) {
		cerr << "\nNie znaleziono pliku lub pojawił się błąd otwarcia\n";
		return;
	}

	db.clear();
	string line;
	Student student;

	file.seekg(0, file.end);
	unsigned long long length = file.tellg();
	file.seekg(0, file.beg);

	while (getline(file, line)) {
		if (line.empty()) continue;
		if (line.substr(0, 1) == "#") continue;

		int temp;
		char buffer[255];
		int varsFound = sscanf(line.c_str(), "[%d] %d. %s %d %c", &temp, &student.id, buffer, &student.level, &student.sex);

		if (varsFound == 5) {
			student.nick = buffer;
			db.push_back(student);
		}
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
	cout << "\nWybierz pole do wyszukiwania (id, nick, level, plec): ";
	cin >> field;

	string phrase;
	cout << "\nPodaj frazę do wyszukania: ";
	cin >> phrase;

	toLower(field);
	int index = 0;
	bool isFound = false;

	for (const Student &student : db) {
		string fieldToCheck;

		if (field == "id") {
			fieldToCheck = student.id;
		} else if (field == "nick") {
			fieldToCheck = student.nick;
		} else if (field == "level") {
			fieldToCheck = student.level;
		} else if (field == "plec") {
			fieldToCheck = student.sex;
		} else {
			cerr << "\nNieprawidłowe pole do wyszukiwania\n";
			return;
		}

		toLower(fieldToCheck);
		toLower(phrase);

		// string::npos to "not found position"
		if (fieldToCheck.find(phrase) != string::npos) {
			cout << "[" << index << "] "
			     << student.id << ". "
			     << student.nick << " "
			     << student.level << " "
			     << student.sex << " ";
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
