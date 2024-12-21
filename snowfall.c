#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>


void nulPole(int len, int heigh, char poleWsymb[][80], char pole[][80])
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < heigh; j++)
		{
			if (i == 1 && j == 1)
			{
				poleWsymb[i][j] = ' ';
				pole[i][j] = 'X';
			}
			else if (i == 0 || i == len - 1)
			{
				poleWsymb[i][j] = '#';
				pole[i][j] = poleWsymb[i][j];
			}
			else
			{
				if (j == 0 || j == heigh - 1)
				{
					poleWsymb[i][j] = '#';
					pole[i][j] = poleWsymb[i][j];
				}
				else
				{
					poleWsymb[i][j] = ' ';
					pole[i][j] = poleWsymb[i][j];
				}
			}
		}
	}
}

void tutorBuild()
{
	printf("Для установки/удаления стенок используйте 'enter'\n");
	printf("Для сохранение и выхода из режима создания нажмите 'q'");
}

void tutorGame()
{
	printf("Используйте стрелки клавиатуры для передвижения по полю\n");
	printf("Нажмите пробел, чтобы запустить снежинку\n");
	printf("Нажмите 'q' для выхода в главное меню\n");
}

int Menu(int choice)
{
	system("cls");
	printf("СНЕГОПАД\n\n");
	printf("%s%s\n", (choice == 1) ? "1)Создать поле <== " : "1)Создать поле  ", "");
	printf("%s%s\n", (choice == 2) ? "2)Играть <== " : "2)Играть  ", "");
	printf("%s%s\n", (choice == 3) ? "3)Выход <== " : "3)Выход  ", "");
}

void poleIsh(int len, int heigh, char pole[][80], char poleWsymb[][80])
{
	for (int i = 0; i < heigh; i++)
	{
		for (int j = 0; j < len; j++)
		{

			if (i == 1 && j == 1)
			{
				poleWsymb[i][j] = ' ';
				pole[i][j] = 'X';
				printf("%c", pole[i][j]);
			}

			else if (i == 0 || i == heigh - 1)
			{
				poleWsymb[i][j] = '#';
				pole[i][j] = poleWsymb[i][j];
				printf("%c", pole[i][j]);
			}

			else
			{
				if (j == 0 || j == len - 1)
				{
					poleWsymb[i][j] = '#';
					pole[i][j] = poleWsymb[i][j];
					printf("%c", pole[i][j]);
				}
				else {
					poleWsymb[i][j] = ' ';
					pole[i][j] = poleWsymb[i][j];
					printf("%c", pole[i][j]);
				}
			}
		}
		printf("\n");
	}
}

void poleWcurs(int len, int heigh, int posY, int posX, char pole[][80])
{
	for (int i = 0; i < heigh; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == posY && j == posX)
			{
				pole[i][j] = 'X';
				printf("%c", pole[i][j]);
			}
			else
			{
				printf("%c", pole[i][j]);
			}
		}
		printf("\n");
	}
}

void addStr(int len, int high, char poleIgr[][80])
{
	for (int i = 0; i < high + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf("%c", poleIgr[i][j]);
		}
		printf("\n");
	}
}

void poleSymb(int len, int high, char poleWsymb[][80], char poleIgr[][80])
{
	for (int i = 0; i < high + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == 0)
				poleIgr[i][j] = '#';
			else if (i == 1 && (j == 0 || j == len - 1))
				poleIgr[i][j] = '#';
			else if (i == 1 && (j > 1 && j != len - 1))
				poleIgr[i][j] = ' ';
			else if (i == 1 && j == 1)
				poleIgr[i][j] = 'X';
			else
				poleIgr[i][j] = poleWsymb[i - 1][j];
			printf("%c", poleIgr[i][j]);
		}
		printf("\n");
	}
}

void buildPole(int len, int high, int posY, int posX, char pole[][80], char poleWsymb[][80], int pos)
{
	bool flag = true;

	while (flag)
	{
		int move = _getch();
		switch (move)
		{
		case 224:
			move = _getch();
			if (move == 72)
			{
				pole[posY][posX] = poleWsymb[posY][posX];
				if (posY != 1)
				{
					posY -= 1;
				}
				else
				{
					posY = high - 2;
				}
				system("cls");
				poleWcurs(len, high, posY, posX, pole);
				tutorBuild();
			}

			if (move == 80)
			{
				pole[posY][posX] = poleWsymb[posY][posX];
				if (posY != high - 2) {
					posY += 1;
				}
				else {
					posY = 1;
				}
				system("cls");
				poleWcurs(len, high, posY, posX, pole);
				tutorBuild();
			}
			if (move == 75)
			{
				pole[posY][posX] = poleWsymb[posY][posX];
				if (posX != 1) {
					posX -= 1;
				}
				else
				{
					posX = len - 2;
				}
				system("cls");
				poleWcurs(len, high, posY, posX, pole);
				tutorBuild();
			}
			if (move == 77)
			{
				pole[posY][posX] = poleWsymb[posY][posX];
				if (posX != len - 2)
				{
					posX += 1;
				}
				else
				{
					posX = 1;
				}
				system("cls");
				poleWcurs(len, high, posY, posX, pole);
				tutorBuild();
			}
			break;
		case 13:
			if (poleWsymb[posY][posX] == '#')
			{
				poleWsymb[posY][posX] = ' ';
			}
			else if (poleWsymb[posY][posX] == ' ')
			{
				poleWsymb[posY][posX] = '#';
			}
			system("cls");
			poleWcurs(len, high, posY, posX, pole);
			tutorBuild();
			break;
		case 'q':
			flag = false;
			Menu(pos);
			break;
		}
	}
}

void Snowfall(int len, int high, int posY, int posX, char poleIgr[][80], int pos);

void game(int len, int high, int posY, int posX, char poleIgr[][80], int pos)
{
	bool flag2 = true;

	while (flag2)
	{
		int moveGame = _getch();
		switch (moveGame)
		{
		case 224:
			moveGame = _getch();

			if (moveGame == 75) //лево
			{
				poleIgr[posY][posX] = ' ';
				if (posX != 1)
				{
					posX -= 1;
				}
				else
				{
					posX = len - 2;
				}
				poleIgr[posY][posX] = 'X';
			}

			if (moveGame == 77)//право
			{
				poleIgr[posY][posX] = ' ';
				if (posX != len - 2)
				{
					posX += 1;
				}
				else
				{
					posX = 1;
				}
				poleIgr[posY][posX] = 'X';
			}
			Snowfall(len, high, posY, posX, poleIgr, pos);
			break;
		case 32:
			if (poleIgr[posY + 1][posX] == ' ')
				poleIgr[posY + 1][posX] = '*';
			Snowfall(len, high, posY, posX, poleIgr, pos);
			break;
		case 'q':
			flag2 = false;
			Menu(pos);
			break;
		default:
			Snowfall(len, high, posY, posX, poleIgr, pos);
		}
	}
}

void Snowfall(int len, int high, int posY, int posX, char poleIgr[][80], int pos)
{
	bool flag3 = true;

	while (flag3)
	{
		int existCount = 0;
		system("cls");
		addStr(len, high, poleIgr);
		tutorGame();
		for (int i = high - 2; i > 0; i--)
		{
			for (int j = 1; j < len - 1; j++) 
			{
				if (poleIgr[i][j] == '*')
				{
					if (poleIgr[i + 1][j] == ' ')
					{
						poleIgr[i][j] = ' ';
						poleIgr[i + 1][j] = '*';
						existCount += 1;
					}
					else if (poleIgr[i + 1][j] != ' ')
					{
						if (poleIgr[i][j - 1] == ' ' && poleIgr[i + 1][j - 1] == ' ' && poleIgr[i + 2][j - 1] == ' ')
						{
							poleIgr[i][j] = ' ';
							poleIgr[i + 1][j - 1] = '*';
							existCount += 1;
						}
						else if (poleIgr[i][j + 1] == ' ' && poleIgr[i + 1][j + 1] == ' ' && poleIgr[i + 2][j + 1] == ' ')
						{
							poleIgr[i][j] = ' ';
							poleIgr[i + 1][j + 1] = '*';
							existCount += 1;
						}
					}
				}
			}
		}
		Sleep(100);
		if (existCount == 0)
			flag3 = false;

		if (_kbhit())
		{
			break;
			game(len, high, posY, posX, poleIgr, pos);
		}
	}
}


int main()
{
	int choice = 1;

	char poleWsymb[25][80];
	char pole[25][80];
	char poleIgr[26][80];
	int posY = 1;
	int posX = 1;
	int length = 80;
	int height = 25;

	nulPole(height, length, poleWsymb, pole);

	setlocale(LC_ALL, "Rus");

	while (1)
	{
		Menu(choice);
		int arr = _getch();

		if (arr >= '1' && arr <= '3')
		{
			choice = arr - '1';
		}
		else if (arr == 224)
		{
			switch (_getch())
			{
			case 72:
				choice = (choice > 1) ? choice - 1 : 3;
				break;
			case 80:
				choice = (choice < 3) ? choice + 1 : 1;
				break;
			}
		}

		else if (arr == '\r')
		{
			switch (choice)
			{
			case 1:
				system("cls");
				poleIsh(length, height, pole, poleWsymb);
				tutorBuild();
				buildPole(length, height, posY, posX, pole, poleWsymb, choice);
				break;
			case 2:
				system("cls");
				poleSymb(length, height, poleWsymb, poleIgr);
				tutorGame();
				game(length, height, posY, posX, poleIgr, choice);
				break;
			case 3:
				exit();
				break;
			}
		}
		else if (arr == 27)
		{
			exit();
		}
	}
}






