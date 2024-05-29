#include<SFML/Graphics.hpp>
#include <vector>
using namespace std;
const int HEIGHT_MAP = 380;//размер карты высота
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
void randomMapGenerate_s() {//рандомно расставляем камни
	int randomElementX = 0;//случайный элемент по горизонтали
	int randomElementY = 0;//случ эл-т по вертикали
	srand(time(0));//рандом	
	int countStone = 100;//количество камней

	while (countStone > 0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
		randomElementY = 200 + rand() % (HEIGHT_MAP - 1);//по игреку так же
		x.push_back(randomElementX);
		y.push_back(randomElementY);
		countStone--;

	}
}
void randomMapGenerate_pi() {//рандомно расставляем камни
	x.clear();
	y.clear();
	int randomElementX = 0;//случайный элемент по горизонтали
	int randomElementY = 0;//случ эл-т по вертикали
	srand(time(0));//рандом	
	int countStone = 100;//количество камней

	while (countStone > 0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
		randomElementY = 200 + rand() % (HEIGHT_MAP - 1);//по игреку так же
		x.push_back(randomElementX);
		y.push_back(randomElementY);
		countStone--;

	}
}