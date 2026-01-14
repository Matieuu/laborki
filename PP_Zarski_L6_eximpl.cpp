#include <iostream>
#include <string>

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

	void enqueue() {
		Node *newNode = new Node;
		std::cout << "Enter ID: ";
		std::cin >> newNode->data.id;
		std::cout << "Enter Nick: ";
		std::cin >> newNode->data.nick;
		std::cout << "Enter Level: ";
		std::cin >> newNode->data.level;
		std::cout << "Enter Gender (m/f): ";
		std::cin >> newNode->data.gender;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void dequeue() {
		if (head == nullptr) {
			std::cout << "Queue is empty!\n";
			return;
		}
		Node *temp = head;
		head = head->next;

		if (head == nullptr) tail = nullptr;

		std::cout << "Removed player: " << temp->data.nick << "\n";
		delete temp;
	}

	void display() {
		Node *current = head;
		if (!current) {
			std::cout << "Queue is empty.\n";
			return;
		}
		std::cout << "--- Queue Content ---\n";
		while (current != nullptr) {
			std::cout << "ID: " << current->data.id
			          << " | Nick: " << current->data.nick
			          << " | Lvl: " << current->data.level << "\n";
			current = current->next;
		}
		std::cout << "---------------------\n";
	}
};

int main() {
	Queue queue;
	int choice;

	do {
		std::cout << "\n1. Add Player (Enqueue)\n2. Remove Player (Dequeue)\n3. Show All\n0. Exit\nChoice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			queue.enqueue();
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			queue.display();
			break;
		case 0:
			std::cout << "Exiting...";
			break;
		default:
			std::cout << "Invalid choice.";
		}
	} while (choice != 0);

	return 0;
}