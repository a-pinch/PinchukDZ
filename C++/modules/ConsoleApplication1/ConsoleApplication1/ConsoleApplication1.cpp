#include <iostream>
using namespace std;
//�������� �������.
long summa(int, ...);
void main()
{
	cout << "\n summa(2,4,6)=" << summa(2, 4, 6);

	cout << "\n summa(6,1,2,3,4,5,6)=" << summa(6, 1, 2, 3, 4, 5, 6);

}
//�������� ���������� ����������.
long summa(int k, ...)
{
	//pk �������� ����� ������������ 
	//������ ������ ����������.
	//��� ������� � ���, ��� ���������
	//������������� �� �������
	//� ����������� ������
	int *pk = &k;

	//������� �����
	//� - ���������� ����������
	long sm = 0;
	for (; k; k--)
		sm += *(++pk);

	return sm;
}
