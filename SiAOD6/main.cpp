#include <iostream>
#include "List.cpp"

using namespace std;

void F(int n, int i); // ����-����� ������������������ n ����� �����

template<typename T>
void inputList(List<T>& l); // ���� ������ � ����������

template<typename T>
void createNew(List<T>& L1, List<T>& L2, int i); // ������������ ������ �� �������� �������� ���������

template<typename T>
void outList(List<T>& L); // ����� ������



int main() {
	setlocale(LC_ALL, "rus");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, n;
	List<int> L1;
	List<int> L2;

	while (flag)
	{
		system("cls");
		cout << "������������ ������ �6 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"������� 1\n"
			"����\n"
			"1) ����-����� ������������������ n ����� �����, � ����������� ��������.\n"
			"2) ���������� ��������� ����������������� ������.\n"
			"3) ������������ ����� ������ �� �������� �������� ���������.\n"
			"4) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cin >> n;
			F(n, 0);
			system("pause");
			break;
		case 2:
			inputList(L1);
			system("pause");
			break;
		case 3:
			createNew(L1, L2, 0);
			outList(L2);
			system("pause");
			break;
		case 4:
			cout << "�������, �� ��������!" << stop;
			flag = 0;
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

void F(int n, int i) {
	int x;
	cin >> x;
	n = n - 1;
	i = i + 1;
	cout << i << ": ";
	cout << x << endl;
	if (n != 0) {
		F(n, i);
	}
}

template<typename T>
void inputList(List<T>& L){
	size_t size;
	T currentVal;
	cout << "������� ���������� �������� �����: ";
	cin >> size;
	cout << "������� " << size << " ��������: ";
	for (size_t i = 0; i < size; i++){
		cin >> currentVal;
		L.pushBack(currentVal);
	}
}

template<typename T>
void createNew(List<T>& L1, List<T>& L2, int i) {
	size_t size = L1.getSize();
	if (i < size) {
		if (((L1[i]) % 2) != 0) {
		L2.pushBack(L1[i]);
		i = i + 1;
		createNew(L1, L2, i);
	}
		else {
			i = i + 1;
			createNew(L1, L2, i);
		}
	}
}

template<typename T>
void outList(List<T>& L)
{
	if (L.getSize())
	{
		size_t size = L.getSize();
		for (size_t i = 0; i < size; i++)
		{
			cout << L[i] << " ";
		}
	}
	else
	{
		cout << "����o" << endl;
	}
}