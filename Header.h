#include<SFML/Graphics.hpp>
#include <vector>
using namespace std;
const int HEIGHT_MAP = 380;//������ ����� ������
const int WIDTH_MAP = 640; 
vector<int> x;
vector<int> y;
vector<int> xp;
vector<int> yp;
void MapGenerate_p() {
	x.clear();
	y.clear();
	int ElementX = -80;
	int ElementY = 250;
	srand(time(0));
	int countStone = 10;

	while (countStone > 0) {
		ElementX = ElementX + 80;
		ElementY = ElementY + (rand() % (50)*pow((-1),rand()%3));
		xp.push_back(ElementX);
		yp.push_back(ElementY);
		countStone--;
	
	}
}
void randomMapGenerate_s() {//�������� ����������� �����
	int randomElementX = 0;//��������� ������� �� �����������
	int randomElementY = 0;//���� ��-� �� ���������
	srand(time(0));//������	
	int countStone = 100;//���������� ������

	while (countStone > 0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
		randomElementY = 200 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��
		x.push_back(randomElementX);
		y.push_back(randomElementY);
		countStone--;

	}
}
void randomMapGenerate_pi() {//�������� ����������� �����
	x.clear();
	y.clear();
	int randomElementX = 0;//��������� ������� �� �����������
	int randomElementY = 0;//���� ��-� �� ���������
	srand(time(0));//������	
	int countStone = 100;//���������� ������

	while (countStone > 0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������� �� ���� �� 1 �� ������ �����-1, ����� �� �������� ����� ������� �����
		randomElementY = 200 + rand() % (HEIGHT_MAP - 1);//�� ������ ��� ��
		x.push_back(randomElementX);
		y.push_back(randomElementY);
		countStone--;

	}
}