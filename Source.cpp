#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>

bool is_empty(const std::list<std::string>& planner) {
	return planner.begin() == planner.end();
}

void print(const std::list<std::string>& planner) {
	if (is_empty(planner))
	{
		std::cout << "Список пуст! \n";
	}
	else {
		for (const auto& task : planner) {
			auto pos = std::find(planner.begin(), planner.end(), task);
			std::cout << std::distance(planner.begin(), pos) + 1 << ". " << task << '\n';
		}
	}
}

void main_menu() {
	std::cout << std::endl;
	std::cout << "1. Добавить важную задачу \n";
	std::cout << "2. Добавить обычную задачу \n";
	std::cout << "3. Получить список задач \n";
	std::cout << "4. Отметить задачу выполненной \n";
	std::cout << "5. Показать самую важную задачу \n";
	std::cout << "6. Очистить список задач \n";
	std::cout << "Для выхода нажмите 0 \n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int ans = 0;
	std::list <std::string> planner;
	std::string task;
	auto iter = planner.begin();
	std::cout << "Планер \n";
	std::cout << "Выберите действие: \n";
	do {
		main_menu();
		std::cin >> ans;
		system("cls");
		switch (ans) {
		case 0:
			std::cout << "До свидания! \n";
			break;
		case 1:
			std::cout << "Введите задачу: " << '\n';
			std::cin.ignore();
			getline(std::cin, task);
			planner.push_front(task);
			break;
		case 2:
			std::cout << "Введите задачу: ";
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
				std::cout << "Введите номер задачи: ";
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
				std::cout << "Список пуст! \n";
			}
			else {
				iter = planner.begin();
				std::cout << "Самая важная задача: " << *iter << '\n';
			}
			break;
		case 6:
			if (is_empty(planner))
			{
				std::cout << "Список пуст! \n";
			}
			else {
				planner.erase(planner.begin(), planner.end());
			}
			break;
		default:
			std::cout << "Такого варианта нет. Пожалуйста, повторите ввод \n";
		}
	} while (ans != 0);

}