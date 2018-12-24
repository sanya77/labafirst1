#include "WORKER.hpp"
#include <algorithm>

using namespace std;

int compare(const void *a, const void* b) {
	return ((WORKER*)a)->getSurname() > ((WORKER*)b)->getSurname();
}

int main() {
	setlocale(LC_ALL, "");
	const int w_count = 5;//���������� �������
	WORKER workers[w_count];
	int a;
	//����
	while (true) {
		cout << "\n1. �����\n2. ������� �����������\n3. �����\n";
		if (!(cin >> a)) {//���� ������������ ����, �� ���������� ��
			continue;
		}
		if (a == 1) {
			return 0;
		}
		else if (a == 2) {
			//��������� ������ � �������
			cout << "������� �������� ���\n";
			for (int i = 0; i < w_count; ++i) {
				try {
					cin >> workers[i];
				}	  //������������ ����������
				catch (const Exception& e) {
					cout << "\n" << e.what() << "\n";
					--i;//���������� i ����� ��� ���������� �����
				}
			}
			/*��������� ��������� �� ��������\*/
			qsort(workers, w_count, sizeof(workers[0]), compare);
		}
		else if (a == 3) {
			cout << "������� ���: ";
			if (!(cin >> a)) {
				cout << "������ �����";
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
				cout << "�� �������!";
			}
		}
	}

}
