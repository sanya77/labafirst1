#pragma once#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class WORKER {
	std::string surname;//фамилия
	std::string init;//Инициалы
	int year;//год поступлени на работу

public:
	WORKER(const char* surname = "", const char* init = "", int year = 0);
	WORKER(const WORKER& w);
	~WORKER();
	/*геттеры и сеттеры для surname*/
	void setSurname(const std::string& str);
	const std::string& getSurname() const;
	/*геттеры и сеттеры для init*/
	void setInit(const std::string& str);
	const std::string& getInit()const;
	/*геттеры и сеттеры для year*/
	void setYear(int n);
	int getYear()const;
	/*операторы ввода и вывода*/
	friend std::istream& operator >> (std::istream& in, WORKER& t);
	friend std::ostream& operator <<(std::ostream& out, const WORKER& t);
	WORKER& operator =(const WORKER& t);//опиратор присваивания
};