#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using namespace sf;

void rate(int score, struct tm* timeinfo) { //������� ��� ���������� �������� � ����
	//����������� ������ � �������� ���� ������� �������� ��� �� ����������
	ifstream record("C://Users//admin//Desktop//game//record.txt");
	ifstream date("C://Users//admin//Desktop//game//date.txt");
	int record1, record2, record3;
	string date1, date2, date3;
	record >> record1; record >> record2; record >> record3;
	getline(date, date1); getline(date, date2); getline(date, date3);
	record.close();
	date.close();
	if (record1 < score) {
		//������ ������� �������, ���� ������� ���� ���������� �� 1 �����
		record3 = record2; date3 = date2;
		record2 = record1; date2 = date1;
		//����������� ������ � �������� ���� ������� �������� � �� ��� ��� ������ �����
		ofstream record, date;
		record.open("C://Users//admin//Desktop//game//record.txt");
		date.open("C://Users//admin//Desktop//game//date.txt");
		record << score << " " << record2 << " " << record3;
		date << asctime(timeinfo) << date2 << "\n" << date3;
		record.close();
		date.close();
	}
	else if (record2 < score) {
		//������ ������� �������, ���� ������� ���� ���������� �� 2 �����
		record3 = record2; date3 = date2;
		ofstream record, date;
		record.open("C://Users//admin//Desktop//game//record.txt");
		date.open("C://Users//admin//Desktop//game//date.txt");
		record.clear();
		date.clear();
		record << record1 << " " << score << " " << record3;
		date << date1 << "\n" << asctime(timeinfo) << date3;
		record.close();
		date.close();
	}
		else if (record3 < score) {
		//���������� ������� ���� � ���� �� ������ �����, ���� �� ������ �������� ��������
		ofstream record, date;
		record.open("C://Users//admin//Desktop//game//record.txt");
		date.open("C://Users//admin//Desktop//game//date.txt");
		record << record1 << " " << record2 << " " << score;
		date << date1 << "\n" << date2 << "\n" << asctime(timeinfo);
		record.close();
		date.close();
	}
}
void top(RenderWindow& window) { //������� ��� ������ ���� � ��������� ������� ����
	setlocale(LC_ALL, "Ru");
	//���������� ������� ����
	Texture menuBackground;
	menuBackground.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Sprite menuBg(menuBackground);
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(2.5, 3);
	//����������� ������ � ��������� ������
	Font font;
	font.loadFromFile("C://Users//admin//Desktop//game//CyrilicOld.ttf");
	Text score1, score2, score3, score4, score5, text, exit;
	text.setFont(font); exit.setFont(font);  score1.setFont(font); score2.setFont(font); score3.setFont(font); 
	text.setPosition(300, 50); exit.setPosition(100, 420); score1.setPosition(80, 100); score2.setPosition(80, 150); score3.setPosition(80, 200);
	text.setFillColor(Color::Red); exit.setFillColor(Color::Red); score1.setFillColor(Color::Red); score2.setFillColor(Color::Red); score3.setFillColor(Color::Red);
	text.setString("���");
	//����������� ������ �� ������ � ����� ��������, ���� �� �����
	ifstream record("C://Users//admin//Desktop//game//record.txt");
	ifstream date("C://Users//admin//Desktop//game//date.txt");
	string strrecord, strdate;
	record >> strrecord;
	getline(date,strdate);
	score1.setString("������ �����  " + strrecord + "  " + strdate);
	record >> strrecord;
	getline(date, strdate);
	score2.setString("������ ����� " + strrecord + "  " + strdate);
	record >> strrecord;
	getline(date, strdate);
	score3.setString("������ ����� " + strrecord + "  " + strdate);
	date.close(); record.close();
	exit.setString("������� ������� escape ��� ������");
	//����� ���� ���������, ���� �� ����� ������ ������� escape
	window.draw(menuBg);
	window.draw(text);  window.draw(exit); window.draw(score1); window.draw(score2); window.draw(score3); 
	window.display(); 
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}
int skin(RenderWindow& window) { //������� ��� ������ �����
	//�������� ����������� ������� � ����, �� ������������
	Texture skinTexture1, skinTexture2, skinTexture3, aboutskinTexture, menuBackground;
	skinTexture1.loadFromFile("C://Users//admin//Desktop//game//skin1.png");
	skinTexture2.loadFromFile("C://Users//admin//Desktop//game//skin2.png");
	skinTexture3.loadFromFile("C://Users//admin//Desktop//game//skin3.png");
	aboutskinTexture.loadFromFile("C://Users//admin//Desktop//game//aboutskin.png");
	menuBackground.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Sprite skin1(skinTexture1), skin2(skinTexture2), skin3(skinTexture3), about(aboutskinTexture), menuBg(menuBackground);
	bool isskin = 1;
	int skinNum = 0;
	about.setPosition(200, 30);
	skin1.setPosition(250, 100);
	skin2.setPosition(250, 160);
	skin3.setPosition(250, 220);
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(2.5, 3);
	while (isskin)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			skin1.setColor(Color::White);
			skin2.setColor(Color::White);
			skin3.setColor(Color::White);
			skinNum = 0;
			window.clear(Color(129, 181, 221));
			//��������� ������� ������� ������ ��� ������ �������
			if (IntRect(250, 100, 300, 50).contains(Mouse::getPosition(window))) { skin1.setColor(Color::Red); skinNum = 1; }
			if (IntRect(250, 160, 300, 50).contains(Mouse::getPosition(window))) { skin2.setColor(Color::Red); skinNum = 2; }
			if (IntRect(250, 220, 300, 50).contains(Mouse::getPosition(window))) { skin3.setColor(Color::Red); skinNum = 3; }
			if (Mouse::isButtonPressed(Mouse::Left)) //��� ������� �� ���� �� ������� ������������ ����� �����
			{
				if (skinNum == 1) { return 1; }
				if (skinNum == 2) { return 2; }
				if (skinNum == 3) { return 3; }
			}
			//����� ���� �������� �� �����
			window.draw(menuBg);
			window.draw(about);
			window.draw(skin1);
			window.draw(skin2);
			window.draw(skin3);
			window.display();
		}
	}
}
void menu(RenderWindow& window) { //������� ��� ���� ����
	//�������� ����������� ������� � ����, �� ������������
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("C://Users//admin//Desktop//game//new.png");
	menuTexture2.loadFromFile("C://Users//admin//Desktop//game//pop.png");
	menuBackground.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 50);
	menu2.setPosition(100, 120);
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(2.5, 3);
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			menu1.setColor(Color::White);
			menu2.setColor(Color::White);
			menuNum = 0;
			window.clear(Color(129, 181, 221));
			//��������� ������� ������� ������ ��� ������ �������
			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) isMenu = false;//���� ������ ������ ������, �� ������� �� ���� 
				if (menuNum == 2) { top(window); }
			}
			//����� ���� �������� �� �����
			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.display();
		}
	}
}
bool startgame(){ //�������, ����������� ������ ����
	//������� �������� ���������� (���������, ��������, �����)
	srand(static_cast<unsigned int>(time(0)));
	const float FPS = 60.0f;
	int x = 100, y = 150;
	int x1 = 700, y1 = 375, x2 = 838, y2 = 127;
	float spF = 0;
	int x_p;
	int type = 0;
	float spp = 2.5;
	float rsm = 0;
	auto score = 0;
	bool is_new_game_time_start = false;
	//�������� ���� � �����
	RenderWindow window(VideoMode(700, 504), "Flappy Bird");
	window.setFramerateLimit(FPS);
	menu(window); //����� ����
	int skinn = skin(window); //��������� ������ �����
	Texture hero_texture;
	switch (skinn) { //� ����������� �� ������ �����, �������� ���������������� �����
	case (1): {
		hero_texture.loadFromFile("C://Users//admin//Desktop//game//duck.png");
		break;
	}
	case (2): {
		hero_texture.loadFromFile("C://Users//admin//Desktop//game//cat.png");
		break;
	}
	case (3): {
		hero_texture.loadFromFile("C://Users//admin//Desktop//game//pryanik.png");
		break;
	}
	}
	//��������� �����
	Font font;
	font.loadFromFile("C://Users//admin//Desktop//game//score.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(10, 10);
	text.setFillColor(Color::Red);
	//�������� ��������� ��������
	Texture backGround_Texture;
	backGround_Texture.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Texture pipe_texture;
	pipe_texture.loadFromFile("C://Users//admin//Desktop//game//Pipe.png");
	Texture tab_texture;
	tab_texture.loadFromFile("C://Users//admin//Desktop//game//tab.png");
	Texture gameover_texture;
	gameover_texture.loadFromFile("C://Users//admin//Desktop//game//gameover.png");

	Sprite hero, background, background1, pipe, pipe1, tab(tab_texture), gameover(gameover_texture);
	//������������ ����, ������� ����
	pipe1.setTexture(pipe_texture);
	pipe.setTexture(pipe_texture);
	pipe1.setRotation(180);
	pipe1.setPosition(x2, y2);
	pipe.setPosition(x1, y1);

	background.setTexture(backGround_Texture);
	background.setPosition(0, 0);
	background.setScale(2.5, 3);
	background1.setTexture(backGround_Texture);
	background1.setPosition(700, 0);
	background1.setScale(2.5, 3);
	//��������� ������������ �����
	hero.setTexture(hero_texture);
	hero.setPosition(x, y);
	hero.setScale(0.4, 0.4);
	//�������� ���������� �� �������� ������ ����
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);                        
	timeinfo = localtime(&rawtime);
	rsm -= 10;
	Event ev;
	while (window.isOpen())
	{
		while (window.pollEvent(ev)) //��������� �������
		{
			if (ev.type == Event::Closed) //�������� ���� �� �������
				window.close();
			if (ev.type == Event::KeyPressed) 
			{
				if (ev.key.code == Keyboard::Space) //�������� ����� �� ������
					spF = -7.5;

			}
			if (ev.type == Event::KeyReleased)
			{
				if (ev.key.code == Keyboard::R)
				{//�������� ��������� ��������
					is_new_game_time_start = false;
					hero.setPosition(x, y);
					pipe1.setPosition(x2, y2);
					pipe.setPosition(x1, y1);
					background.setPosition(0, 0);
					background1.setPosition(700, 0);

				}
			}

		}
		type = rand() % 3 + 1; //��������� ����� ������������ ������� ����
		if (type == 1)
		{
			y2 = 202 - rsm;
			y1 = 440 + rsm;
		}
		if (type == 2)
		{
			y2 = 127 - rsm;
			y1 = 375 + rsm;
		}
		if (type == 3)
		{
			y2 = 62 - rsm;
			y1 = 300 + rsm;
		}
		spF += 0.5;
		hero.move(0, spF);
		hero.setRotation(static_cast<int>(spF - 2.5) % 90);
		pipe.move(spp * -1, 0);
		pipe1.move(spp * -1, 0);
		spp += 0.005; //���������� ��������
		background.move(-0.4, 0);
		background1.move(-0.4, 0);
		if (background.getPosition().x <= -700)
			background.setPosition(700, 0);
		if (background1.getPosition().x <= -700)
			background1.setPosition(700, 0);
		x_p = pipe1.getPosition().x;
		if (x_p < 0)
		{
			//���������� ����� �����, ���������� �����
			pipe.setPosition(x1, y1);
			pipe1.setPosition(x2, y2);
			score++;
		}
		if ((hero.getPosition().y <= 0) or (hero.getPosition().y >= 432) or (is_new_game_time_start) or ((hero.getGlobalBounds().intersects(pipe.getGlobalBounds()) or (hero.getGlobalBounds().intersects(pipe1.getGlobalBounds())))))
		{ //������� ���������
			rate(score, timeinfo); //������ � ���
			//��������� ����� � ����������� � ��������� �����
			score = 0;
			spp = 2.5;
			window.clear();
			background.setPosition(0, 0);
			window.draw(background);
			tab.setPosition(40, 140);
			window.draw(tab);
			gameover.setPosition(100, 200);
			window.draw(gameover);
			is_new_game_time_start = true; //����� �� ����� � ��������� ����
			window.display();

		}
		else
		{ //����� ���� �������� �� �����
			text.setString("Score " + to_string(score));
			window.clear();
			window.draw(background1);
			window.draw(background);
			window.draw(pipe);
			window.draw(pipe1);
			window.draw(hero);
			window.draw(text);
			window.display();
		}
		//������������ ��� ������� tab,����� ��� ������� escape
		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; };
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; };

	}
}
void Gamerunning() { //������� ��� ���������� �������� ���� �� tab
	if (startgame()) { Gamerunning(); }
}
int main()
{
	Gamerunning();
	return 0;
}