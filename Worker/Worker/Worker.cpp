#include "WORKER.hpp"

WORKER::WORKER(const char* surname, const char* init, int year) :
	surname(surname), init(init), year(year) {
	std::cout << "\nКонструктор WORKER\n";
}
WORKER::WORKER(const WORKER& w) : surname(w.surname), init(w.init), year(w.year) {
	std::cout << "\nКонструктор копирования WORKER\n";
}
WORKER::~WORKER() {}
/*геттеры и сеттеры для surname*/
void WORKER::setSurname(const std::string& str) {
	surname = str;
}
const std::string& WORKER::getSurname()const {
	return surname;
}
/*геттеры и сеттеры для init*/
void WORKER::setInit(const std::string& str) {
	init = str;
}
const std::string& WORKER::getInit()const {
	return init;
}
/*геттеры и сеттеры для year*/
void WORKER::setYear(int n) {
	year = n;
}
int WORKER::getYear()const {
	return year;
}

std::istream& operator >> (std::istream& in, WORKER& w) {
	if (!(in >> w.surname >> w.init >> w.year)) {//если некорректный ввод, выбиваем исключение
		throw Exception("Ошибка ввода");
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const WORKER& w) {
	out << "\nДанные: " << w.surname
		<< " " << w.init
		<< "\nГод: " << w.year;
	return out;
}

WORKER& WORKER::operator =(const WORKER& w) {
	if (this != &w) {//защита от самоприсваивания
		surname = w.surname;
		init = w.init;
		year = w.year;
	}
	return *this;
}