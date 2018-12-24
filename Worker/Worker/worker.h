#pragma once#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class WORKER {
	std::string surname;//�������
	std::string init;//��������
	int year;//��� ���������� �� ������

public:
	WORKER(const char* surname = "", const char* init = "", int year = 0);
	WORKER(const WORKER& w);
	~WORKER();
	/*������� � ������� ��� surname*/
	void setSurname(const std::string& str);
	const std::string& getSurname() const;
	/*������� � ������� ��� init*/
	void setInit(const std::string& str);
	const std::string& getInit()const;
	/*������� � ������� ��� year*/
	void setYear(int n);
	int getYear()const;
	/*��������� ����� � ������*/
	friend std::istream& operator >> (std::istream& in, WORKER& t);
	friend std::ostream& operator <<(std::ostream& out, const WORKER& t);
	WORKER& operator =(const WORKER& t);//�������� ������������
};