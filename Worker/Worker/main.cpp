#include "WORKER.hpp"
#include <algorithm>

using namespace std;

int compare(const void *a, const void* b) {
	return ((WORKER*)a)->getSurname() > ((WORKER*)b)->getSurname();
}

int main() {
	setlocale(LC_ALL, "");
	const int w_count = 5;//количество рабочих
	WORKER workers[w_count];
	int a;
	//меню
	while (true) {
		cout << "\n1. Выход\n2. Считать сотрудников\n3. Поиск\n";
		if (!(cin >> a)) {//если некорректный ввод, то пропускаем всё
			continue;
		}
		if (a == 1) {
			return 0;
		}
		else if (a == 2) {
			//считываем данные о поездах
			cout << "Фамилия инициалы год\n";
			for (int i = 0; i < w_count; ++i) {
				try {
					cin >> workers[i];
				}	  //обрабатываем исключение
				catch (const Exception& e) {
					cout << "\n" << e.what() << "\n";
					--i;//откатываем i назад для повторного ввода
				}
			}
			/*сортируем пузырьком по фамилиям\*/
			qsort(workers, w_count, sizeof(workers[0]), compare);
		}
		else if (a == 3) {
			cout << "Выслуга лет: ";
			if (!(cin >> a)) {
				cout << "ошибка ввода";
				continue;
			}
			int i = 0;
			int f = 0;
			for (; i < w_count; ++i) {
				if (workers[i].getYear() > a) {
					cout << workers[i] << '\n';
					f = 1;
				}
			}
			if (f == 0) {
				cout << "Не найдено!";
			}
		}
	}

}
