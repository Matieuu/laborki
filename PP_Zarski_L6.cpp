#include <ctime>
#include <iostream>
#include <string>

int lastId = 0;

// Struktura przechowująca dane o graczu
struct Player {
	int id;
	std::string nick;
	int level;
	char gender;
};

// Element kolejki
struct Node {
	Player data;
	Node *next;
};

// Struktura kolejki
struct Queue {
	Node *head = nullptr;
	Node *tail = nullptr;
};

// Wypisuje menu programu
// Zwraca opcję wybraną przez użytkownika
int printMenu(void) {
	int option;
	std::cout << "=== MENU ===\n";
	std::cout << "1. Add element\n";
	std::cout << "2. Remove element\n";
	std::cout << "3. Display all elements\n";
	std::cout << "0. Exit\n";
	std::cout << "> ";
	std::cin >> option;
	std::cout << "\n";
	return option;
}

// Funkcja pomocnicza do sprawdzania czy kolejka jest pusta
bool isQueueEmpty(Queue *queue) {
	return queue->head == nullptr;
}

// Dodaje nowy element do kolejki
void addElement(Queue *queue) {
	Node *node = new Node();

	node->next = nullptr;
	node->data.id = lastId++;
	node->data.level = std::rand() % 100;

	std::cout << "Choose your nickname: ";
	std::cin >> node->data.nick;

	std::cout << "Choose your gender (m/k): ";
	std::cin >> node->data.gender;

	if (isQueueEmpty(queue)) {
		// Jeśli kolejka jest pusta to zapisz element w głowie i ogonie
		queue->head = queue->tail = node;
	} else {
		// Jeśli kolejka nie jest pusta to dodaj element na końcu
		queue->tail->next = node;
		queue->tail = node;
	}
}

// Usuwa pierwszy element, najwcześniej dodany, FIFO
void popElement(Queue *queue) {
	if (isQueueEmpty(queue)) {
		std::cout << "Queue is empty!\n";
		return;
	}

	Node *temp = queue->head;
	queue->head = queue->head->next;

	// Jeśli kolejka jest pusta to usuń wskaźnik do końca kolejki
	if (isQueueEmpty(queue)) queue->tail = nullptr;

	std::cout << "Removed player: " << temp->data.nick << "\n";
	delete temp;
}

// Wyświetla wszystkie elementy kolejki
void displayQueue(Queue *queue) {
	// Sprawdza czy kolejka jest pusta
	if (isQueueEmpty(queue)) {
		std::cout << "Queue is empty\n";
		return;
	}

	// Przetrzymuje obecnie wypisywany element
	Node *current = queue->head;

	while (current != nullptr) {
		std::cout << current->data.id << ". Player " << current->data.nick
		          << " (" << current->data.gender << ", " << current->data.level << ")\n";
		current = current->next;
	}
}

int main(void) {
	std::srand(std::time(0));
	Queue *queue = new Queue();
	int option;

	do {
		// Funkcja printMenu zwraca opcję, która została wybrana
		option = printMenu();

		switch (option) {
		case 0:
			break;

		case 1:
			addElement(queue);
			break;

		case 2:
			popElement(queue);
			break;

		case 3:
			displayQueue(queue);
			break;

		default:
			std::cout << "Invalid option!";
			break;
		}

		std::cout << "\n";
	} while (option != 0);

	std::cout << "Exiting...\n";
	// Usuwa wszystkie elementy kolejki
	while (isQueueEmpty(queue)) popElement(queue);
	delete queue;
	return 0;
}
