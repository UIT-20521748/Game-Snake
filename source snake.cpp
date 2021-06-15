#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <ctime>
#define consoleWidth 25
#define consoleHeight 25
using namespace std;
void  TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor_an_Pos);
}
struct ToaDo {
	int x;
	int y;
};
struct Moi {
	ToaDo td;
};
int Random() {
	srand(time(NULL));
	int x = rand() % 23 + 3;
	return x;
}
void KhoitaoMoi(Moi& moi) {
	moi.td.x = Random();
	moi.td.y = Random();
}
class Snake {
protected:
	ToaDo diem[101];
	int n;
	int tt;
public:
	Snake() {
		n = 4;
		diem[0].x = 3; diem[0].y = 3;
		diem[1].x = 4; diem[1].y = 3;
		diem[2].x = 5; diem[2].y = 3;
		diem[2].x = 5; diem[2].y = 4;
		tt = 2;
	}
	void Ve();
	void DieuKhien();
	int Xuly(int&, Moi& moi);
};
void Snake::Ve() {
	system("cls");
	TextColor(13);
	gotoxy(diem[0].x, diem[0].y);
	putchar(219);
	for (int i = 1; i < n; i++) {
		gotoxy(diem[i].x, diem[i].y);
		putchar(254);
	}
}
void Snake::DieuKhien() {
	for (int i = n - 1; i > 0; i--) {
		diem[i] = diem[i - 1];
	}
	if (_kbhit()) {
		int key = _getch();
		// 
		if (key == 'a' || key == 'A')
			tt = 1;//left
		else
			if (key == 'w' || key == 'W')
				tt = 5;//up
			else
				if (key == 's' || key == 'S')
					tt = 2;//down
				else
					if (key == 'd' || key == 'D')
						tt = 3;//right
	}
	if (tt == 5)//up
		diem[0].y--;
	else	if (tt == 2)//down
		diem[0].y++;
	else	if (tt == 1)//left
		diem[0].x--;
	else	if (tt == 3)//right
		diem[0].x++;
}
int Snake::Xuly(int& thoigian, Moi& moi) {
	for (int i = 1; i < n; i++)
		if (diem[0].x == diem[i].x && diem[0].y == diem[i].y)
			return -1;
	return 1;
	if (diem[0].x == moi.td.x && diem[0].y == moi.td.y) {
		diem[0] = moi.td;
		n++;
		KhoitaoMoi(moi);
		if (thoigian > 50)
			thoigian -= 10;
	}
}
int main() {
	int ma;
	int thoigian = 100;
	srand(time(NULL));
	Snake snake;
	Moi moi;
	cout << "\n Xin chao cac ban! :)))\n Bang dieu khien: a,w,s,d nha.";
	_getch();
	while (1) {
		//ve
		snake.Ve();
		gotoxy(35, 2);
		//dieu khien
		snake.DieuKhien();
		// xu ly
		ma = snake.Xuly(thoigian, moi);
		// thua,thang
		if (ma == -1) {
			gotoxy(consoleWidth + 1, 10);
			cout << ("\nBan da thua roi!!! ga` ga` ga` :)))\n+++++Thank you ! Enter de thoat game+++++");
			while (_getch() != 13);
			break;
		}
		// toc do game
		Sleep(thoigian);
	}

	return 0;
}