// Homework6(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	//-1
	int summ;
	int num1 = 0;
	for (int i = 0; i <= 10; i++) {
		num1 += 2;

		summ = num1 + (num1 + 1);


	}
	cout << summ << "\n";
	//-4
	//int number;
	//int result = 0;
	//cout << "Print your factorial";
	//cin >> number;
	//for (int a = 0; a <= number; a++) {
	//	result = number * (number + 2);


	//}
	//cout << result << "\n";
	//-5
	int number1;
	int result = 1;
	bool is_easy = false;
	cout << "Print your number";
	cin >> number1;
	cout << boolalpha;
	for (int i = 0; i <= number1; i++) {
		if (number1 % result == 0 &&  result !=1 && result!=number1) {
			is_easy = false;
			break;
		}
		result ++;
	}
	cout << is_easy<<"\n";
	//-6
	int mynum;
	int del = 1;
	cout << "Print your number";
	cin >> mynum;
	for (int c = 0; c <= mynum; c++) {
		if (mynum % del == 0) {
			cout << del<<"\n";
		}
		del += 1;
	}
	//-10
	cout << "Guess the number,print yes or no\n";
	srand(time(0));
	int bot = rand() % 100;
	string choice;
	bool game = false;
	while (game == false) {
		cout << "The number is " << bot << "?\n";
		cin >> choice;
		if (choice =="yes") {
			break;
		}
		else {
			bot = rand() % 100;
		}

	}
	//-12
	int xp;
	int damage;
	int dragonxp;
	int dragondamage;
	int coins = 100;
	bool win = false;
	int spearman;
	cout << "Hello,print damage(max:50):\n ";//-стоимость копейщика это будет сумма хп и здоровья
	cin >> damage;
	cout << "Print health(max:50):\n ";
	cin >> xp;
	cout << "Print damage dragon(max:25)\n ";//-если мы возьмем копейщика с максимальными характеристиками то дракон убет с одного удара а так копейщик будет стоит все сто то  и мы проиграем
	cin >> dragondamage;
	cout << "Print health(max:90):\n ";//-чтобы копейщик не смог убить с первого же удара
	cin >> dragonxp;
	//-проверка по здоровью и урону если превышает то все заново
	if (damage > 50) {
		cout << "Maxmimum 50 damage!\n";
		main();
	}
	else if (xp > 50) {
		cout << "Maxmimum 50 xp!\n";
		main();
	}
	else if (dragondamage > 25) {
		cout << "Maxmimum 25 damage!\n";
		main();
	}
	else if (dragonxp > 90) {
		cout << "Maxmimum 100 xp!\n";
		main();
	}
	//-начало игры 
	cout << "Hello, you must kil dragon!\n";
	cout << "How many spearman do you want?\n"<<"(the max you can buy is"<<coins/(damage+xp)<<")";//-написал сколько масимум ведь всего 100 монет
	cin >> spearman;
	//- если копейщики будут превышать стоимость
	if (spearman * (damage + xp) != coins) {
		cout << "You have only 100 coins!";
		main();
	}
	while (win == false) {
		//-атака копейщиков
		cout << "*Spearmans attacking("<<damage<<")*\n";
		dragonxp = dragonxp - (spearman * damage);
		cout << "Dragons health:" << dragonxp<<"\n" << "Spearmans:" << spearman << "\n";
		//-проверка хп
		if (dragonxp <= 0) {
			cout << "You win!";
			break;
		}
		//-атака дракона
		cout << "*Dragon  attacking*(" << dragondamage << ")\n";
		xp = xp-dragondamage;
		//-если атака равняеться хп копейщика
		 if (xp == 0) {
			spearman--;
			cout << "Spearmans:" << spearman;
		}
		//-если атака больше хп
		else if (xp < 0) {
			spearman--;
			xp = dragondamage - xp;
			cout << "Spearmans:" << spearman<<"( the dragon damage is killed spearman and injured another, he has "<<xp<<")\n";
		}
		cout << "Dragons health:" << dragonxp <<"\n" << "Spearmans:" << spearman << "\n";
		if (spearman == 0) {
			cout << "You lose((";
			break;
		 }

		
	}



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
