#include <iostream>
#include <string>

int lastId = 0;

struct Player {
	int id;
	std::string nick;
	int level;
	char gender;
};

struct Node {
	Player data;
	Node *next;
};

struct Queue {
	Node *head = nullptr;
	Node *tail = nullptr;
};

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

void addElement(Queue *queue) {
	Node *node = new Node();

	node->next = nullptr;
	node->data.id = lastId++;

	std::cout << "Choose your nickname: ";
	std::cin >> node->data.nick;

	std::cout << "Choose your gender (m/k): ";
	std::cin >> node->data.gender;

	if (queue->head == nullptr) {
		queue->head = queue->tail = node;
	} else {
		queue->tail->next = node;
		queue->tail = node;
	}
}

void popElement(Queue *queue) {
	if (queue->head == nullptr) {
		std::cout << "Queue is empty!\n";
		return;
	}

	Node *temp = queue->head;
	queue->head = queue->head->next;

	if (queue->head == nullptr) queue->tail = nullptr;

	std::cout << "Removed player: " << temp->data.nick << "\n";
	delete temp;
}

void displayQueue(Queue *queue) {
	Node *current = queue->head;

	if (current == nullptr) {
		std::cout << "Queue is empty\n";
		return;
	}

	int count = 1;
	while (current != nullptr) {
		std::cout << count << ". Player " << current->data.nick
		          << " (" << current->data.gender << ", " << current->data.level << ")\n";

		count++;
		current = current->next;
	}
}

int main(void) {
	Queue *queue = new Queue();
	int option;

	do {
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
	while (queue->head != nullptr) popElement(queue);
	delete queue;
	return 0;
}
