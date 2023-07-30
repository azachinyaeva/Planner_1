#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>

bool is_empty(const std::list<std::string>& planner) {
	return planner.empty();
}

void print(const std::list<std::string>& planner) {
	
	if (is_empty(planner))
	{
		std::cout << "������ ����! \n";
	}
	else {
		int number = 1;
		for (const auto& task : planner) {
			
			std::cout << number << ". " << task << '\n';
			++number;
		}
	}
}

void main_menu() {
	std::cout << std::endl;
	std::cout << "1. �������� ������ ������ \n";
	std::cout << "2. �������� ������� ������ \n";
	std::cout << "3. �������� ������ ����� \n";
	std::cout << "4. �������� ������ ����������� \n";
	std::cout << "5. �������� ����� ������ ������ \n";
	std::cout << "6. �������� ������ ����� \n";
	std::cout << "��� ������ ������� 0 \n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int ans = 0;
	std::list <std::string> planner;
	std::string task;
	auto iter = planner.begin();
	std::cout << "������ \n";
	std::cout << "�������� ��������: \n";
	do {
		main_menu();
		std::cin >> ans;
		system("cls");
		switch (ans) {
		case 0:
			std::cout << "�� ��������! \n";
			break;
		case 1:
			std::cout << "������� ������: " << '\n';
			std::cin.ignore();
			getline(std::cin, task);
			planner.push_front(task);
			break;
		case 2:
			std::cout << "������� ������: ";
			std::cin.ignore();
			getline(std::cin, task);
			planner.push_back(task);
			break;
		case 3:
			print(planner);
			break;
		case 4:
			print(planner);
			if (!(is_empty(planner))) {
				int num;
				std::cout << "������� ����� ������: ";
				std::cin >> num;
				iter = planner.begin();
				advance(iter, num - 1);
				iter = planner.erase(iter);
				break;
			}
			else {
				break;
			}
		case 5:
			if (is_empty(planner))
			{
				std::cout << "������ ����! \n";
			}
			else {
				iter = planner.begin();
				std::cout << "����� ������ ������: " << *iter << '\n';
			}
			break;
		case 6:
			if (is_empty(planner))
			{
				std::cout << "������ ����! \n";
			}
			else {
				planner.clear();
			}
			break;
		default:
			std::cout << "������ �������� ���. ����������, ��������� ���� \n";
		}
	} while (ans != 0);

}