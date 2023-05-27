#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using namespace sf;

void rate(int score, struct tm* timeinfo) { //функция для заполнения рейтинга в топе
	//подключение файлов с записями трех прошлых рекордов для их извлечения
	ifstream record("C://Users//admin//Desktop//game//record.txt");
	ifstream date("C://Users//admin//Desktop//game//date.txt");
	int record1, record2, record3;
	string date1, date2, date3;
	record >> record1; record >> record2; record >> record3;
	getline(date, date1); getline(date, date2); getline(date, date3);
	record.close();
	date.close();
	if (record1 < score) {
		//меняем рекорды местами, если текущий счет претендует на 1 место
		record3 = record2; date3 = date2;
		record2 = record1; date2 = date1;
		//подключение файлов с записями трех прошлых рекордов и их дат для записи новых
		ofstream record, date;
		record.open("C://Users//admin//Desktop//game//record.txt");
		date.open("C://Users//admin//Desktop//game//date.txt");
		record << score << " " << record2 << " " << record3;
		date << asctime(timeinfo) << date2 << "\n" << date3;
		record.close();
		date.close();
	}
	else if (record2 < score) {
		//меняем рекорды местами, если текущий счет претендует на 2 место
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
		//записываем текущий счет и дату на третье место, если он больше прошлого значения
		ofstream record, date;
		record.open("C://Users//admin//Desktop//game//record.txt");
		date.open("C://Users//admin//Desktop//game//date.txt");
		record << record1 << " " << record2 << " " << score;
		date << date1 << "\n" << date2 << "\n" << asctime(timeinfo);
		record.close();
		date.close();
	}
}
void top(RenderWindow& window) { //функция для вывода топа в отдельном разделе меню
	setlocale(LC_ALL, "Ru");
	//заполнение заднего фона
	Texture menuBackground;
	menuBackground.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Sprite menuBg(menuBackground);
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(2.5, 3);
	//подключение шрифта и настройка текста
	Font font;
	font.loadFromFile("C://Users//admin//Desktop//game//CyrilicOld.ttf");
	Text score1, score2, score3, score4, score5, text, exit;
	text.setFont(font); exit.setFont(font);  score1.setFont(font); score2.setFont(font); score3.setFont(font); 
	text.setPosition(300, 50); exit.setPosition(100, 420); score1.setPosition(80, 100); score2.setPosition(80, 150); score3.setPosition(80, 200);
	text.setFillColor(Color::Red); exit.setFillColor(Color::Red); score1.setFillColor(Color::Red); score2.setFillColor(Color::Red); score3.setFillColor(Color::Red);
	text.setString("ТОП");
	//подключение файлов со счетом и датой рекордов, выод на экран
	ifstream record("C://Users//admin//Desktop//game//record.txt");
	ifstream date("C://Users//admin//Desktop//game//date.txt");
	string strrecord, strdate;
	record >> strrecord;
	getline(date,strdate);
	score1.setString("Первое место  " + strrecord + "  " + strdate);
	record >> strrecord;
	getline(date, strdate);
	score2.setString("Второе место " + strrecord + "  " + strdate);
	record >> strrecord;
	getline(date, strdate);
	score3.setString("Третье место " + strrecord + "  " + strdate);
	date.close(); record.close();
	exit.setString("Нажмите клавишу escape для выхода");
	//показ всех элементов, пока не будет нажата клавиша escape
	window.draw(menuBg);
	window.draw(text);  window.draw(exit); window.draw(score1); window.draw(score2); window.draw(score3); 
	window.display(); 
	while (!Keyboard::isKeyPressed(Keyboard::Escape));
}
int skin(RenderWindow& window) { //функция для выбора скина
	//загрузка необходимых пунктов в меню, их расположение
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
			//подсветка пунктов красным цветов при наводе курсора
			if (IntRect(250, 100, 300, 50).contains(Mouse::getPosition(window))) { skin1.setColor(Color::Red); skinNum = 1; }
			if (IntRect(250, 160, 300, 50).contains(Mouse::getPosition(window))) { skin2.setColor(Color::Red); skinNum = 2; }
			if (IntRect(250, 220, 300, 50).contains(Mouse::getPosition(window))) { skin3.setColor(Color::Red); skinNum = 3; }
			if (Mouse::isButtonPressed(Mouse::Left)) //при нажатии на один из пунктов возвращается номер скина
			{
				if (skinNum == 1) { return 1; }
				if (skinNum == 2) { return 2; }
				if (skinNum == 3) { return 3; }
			}
			//вывод всех объектов на экран
			window.draw(menuBg);
			window.draw(about);
			window.draw(skin1);
			window.draw(skin2);
			window.draw(skin3);
			window.display();
		}
	}
}
void menu(RenderWindow& window) { //функция для окна меню
	//загрузка необходимых пунктов в меню, их расположение
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
			//подсветка пунктов красным цветов при наводе курсора
			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
				if (menuNum == 2) { top(window); }
			}
			//вывод всех объектов на экран
			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.display();
		}
	}
}
bool startgame(){ //функция, описывающая логику игры
	//задание значений переменных (координат, скорости, счета)
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
	//создание окна с игрой
	RenderWindow window(VideoMode(700, 504), "Flappy Bird");
	window.setFramerateLimit(FPS);
	menu(window); //вывод меню
	int skinn = skin(window); //получение номера скина
	Texture hero_texture;
	switch (skinn) { //в зависимости от номера скина, загрузка соответствующего файла
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
	//настройка счета
	Font font;
	font.loadFromFile("C://Users//admin//Desktop//game//score.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(10, 10);
	text.setFillColor(Color::Red);
	//загрузка остальных объектов
	Texture backGround_Texture;
	backGround_Texture.loadFromFile("C://Users//admin//Desktop//game//ff.png");
	Texture pipe_texture;
	pipe_texture.loadFromFile("C://Users//admin//Desktop//game//Pipe.png");
	Texture tab_texture;
	tab_texture.loadFromFile("C://Users//admin//Desktop//game//tab.png");
	Texture gameover_texture;
	gameover_texture.loadFromFile("C://Users//admin//Desktop//game//gameover.png");

	Sprite hero, background, background1, pipe, pipe1, tab(tab_texture), gameover(gameover_texture);
	//расположение труб, заднего фона
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
	//начальное расположение героя
	hero.setTexture(hero_texture);
	hero.setPosition(x, y);
	hero.setScale(0.4, 0.4);
	//создание переменной со временем начала игры
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);                        
	timeinfo = localtime(&rawtime);
	rsm -= 10;
	Event ev;
	while (window.isOpen())
	{
		while (window.pollEvent(ev)) //обработка событий
		{
			if (ev.type == Event::Closed) //закрытие окна на крестик
				window.close();
			if (ev.type == Event::KeyPressed) 
			{
				if (ev.key.code == Keyboard::Space) //движение героя на пробел
					spF = -7.5;

			}
			if (ev.type == Event::KeyReleased)
			{
				if (ev.key.code == Keyboard::R)
				{//движение остальных объектов
					is_new_game_time_start = false;
					hero.setPosition(x, y);
					pipe1.setPosition(x2, y2);
					pipe.setPosition(x1, y1);
					background.setPosition(0, 0);
					background1.setPosition(700, 0);

				}
			}

		}
		type = rand() % 3 + 1; //рандомный выбор расположения будущих труб
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
		spp += 0.005; //увеличение скорости
		background.move(-0.4, 0);
		background1.move(-0.4, 0);
		if (background.getPosition().x <= -700)
			background.setPosition(700, 0);
		if (background1.getPosition().x <= -700)
			background1.setPosition(700, 0);
		x_p = pipe1.getPosition().x;
		if (x_p < 0)
		{
			//добавление новой трубы, увеличение счета
			pipe.setPosition(x1, y1);
			pipe1.setPosition(x2, y2);
			score++;
		}
		if ((hero.getPosition().y <= 0) or (hero.getPosition().y >= 432) or (is_new_game_time_start) or ((hero.getGlobalBounds().intersects(pipe.getGlobalBounds()) or (hero.getGlobalBounds().intersects(pipe1.getGlobalBounds())))))
		{ //условия проигрыша
			rate(score, timeinfo); //запись в топ
			//обнуление счета и возвращение в начальную точку
			score = 0;
			spp = 2.5;
			window.clear();
			background.setPosition(0, 0);
			window.draw(background);
			tab.setPosition(40, 140);
			window.draw(tab);
			gameover.setPosition(100, 200);
			window.draw(gameover);
			is_new_game_time_start = true; //выход из цикла и окончание игры
			window.display();

		}
		else
		{ //вывод всех объектов на экран
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
		//перезагрузка при нажатии tab,выход при нажатии escape
		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; };
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; };

	}
}
void Gamerunning() { //функция для реализации рестарта игры на tab
	if (startgame()) { Gamerunning(); }
}
int main()
{
	Gamerunning();
	return 0;
}