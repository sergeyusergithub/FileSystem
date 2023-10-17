#include <iostream>
#include <fstream> // библиотека, описывающая классы для работы с файловой
// системой устройства
#include <string>

const char _stat_path[] = "stats.txt";

bool statistic(const std::string str);

void print_file();
bool clear();

int main() {
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251> null"); // вместо setlocale чтобы вводить на русском языке
	int n;
	std::string path = "file.txt";

	// класс ofstream

	/*
	std::ofstream out; // метод создания объекта и открытия файла для записи данных std::ofstream out(path);

	// out.open(path); // открытие файла с режимом по умолчанию std::ios::out

	out.open(path, std::ios::app); // открыти файла для записи данных с добавлением данных в конец

	if (out.is_open()) {
		std::cout << "Файл открыт для записи.\n";
		std::string msg;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, msg);
		out << msg << '\n'; // добавление строки в файл!!

	}
	else
		std::cout << "Ошибка открытия файла.\n";


	out.close();

	// возможные причины ошибки при открытии файла
	// с помощью ofstream
	// 1. Нет доступа к файлу;
	// 2. Некорректный путь к файлу;
	// 3. Файл открыт другим объектом или программой

	*/

	// класс ifstream

	/*
	std::ifstream in;

	in.open(path);

	if (in.is_open()) {
		std::cout << "Содержимое файла:\n";
		std::string file;
		// 1. Посимвольное считывание
		//char sym;
		//while (in.get(sym))
		//	file += sym;
		//std::cout << file << std::endl;

		// 2. Пословное считывание
		//while (!in.eof()) {
		//	std::string str;
		//	in >> str;
		//	file += str + '\n';
		//}
		//std::cout << file << std::endl;

		// 3. Построчное считывание
		std::string str;
		while (std::getline(in, str))
			file += str + '\n';
		std::cout << file;
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	in.close();


	// возможные причины ошибки при открытии файла 
	// с помощью ifstream
	// 1. Файла не существует
	// 2. Некорректный путь к файлу
	// 3. Нет доступа к файлу

	*/
	
	// удаление файла
	
	/*
	//remove(path.c_str()); // простой вариант использования функции remove

	if (remove(path.c_str()) == 0) // правильный вариант использования функции remove
		std::cout << "Файл удален.\n";
	else
		std::cout << "Ошибка удаления файла.\n";

	// Возможные причины ошибки при удалении файла:
	// 1. Файла не существует
	// 2. Нет доступа к файлу
	// 3. Файл открыт
	// 4. Некорректный путь к файлу

	*/


	// Задача 1. Статистика

	std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);

	if (statistic(str1))
		std::cout << "Запись добавлена в файл.\n\n";
	else
		std::cout << "Ошибка!!!\n\n";


	// Задача 2. дополнения к задаче 1

	std::cout << "Содержимое файла: \n";

	print_file();

	if (clear())
		std::cout << "Файл отчищен!!\n\n";
	else
		std::cout << "Файл не отчищен!!!\n\n";
	
	return 0;
}

bool clear() {
	static std::ofstream out;

	out.open(_stat_path);
	if (out.is_open()) {
		out.close();
		return true;
	}

	return false;
}

void print_file() {
	static std::ifstream in;
	in.open(_stat_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;

		in.close();
	}
}

bool statistic(const std::string str) {
	static std::ofstream out;
	out.open(_stat_path, std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	
	
	return false;
}
