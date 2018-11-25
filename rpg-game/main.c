/*
## �������� RPG ���� ##
ĳ���� �̵����� ������ �ʿ��� ���͸� ��ų� ��ȭ�� ���
���� ���� ��ȭ�� ���� ����� �¸��ϴ� �����Դϴ�.
1�ο� �����̸�, ģ����� �Բ� ������ ���⸦ �� �� �ֽ��ϴ�.
��ȭ�� �����ϰ� ���޵Ǹ�, �ݰų�, ���͸� �����߷��� �� ���� �� �ֽ��ϴ�.
���ΰ��� ü���� 0 ���ϰ� �� ��, ������ ����Ǹ� ���� ��ȭ ������ Ȯ���� �� �ֽ��ϴ�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// �� ����
typedef struct _Mob {
	double dHp;
	double dAtt;
	double dDef;
} Mob;

// �� ����
int map[20][44] = {
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,3,5,5,5,9,
9,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,3,5,5,5,3,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,3,3,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,9,
9,5,5,5,5,5,3,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,9,
9,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,3,5,5,3,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,9,
9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,5,5,5,5,5,5,5,5,3,5,5,5,9,
9,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
};

// x, y�� �̵��ϴ� �Լ�
void gotoxy(int x, int y) {
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

// �ܼ�â Ŀ�� ����� �Լ�
void clearCursor() {
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

// Ÿ��Ʋ ����� �Լ�
void clearTitle() {
	gotoxy(30, 15);
	printf("                                 ");
}

// �޴�â ����� �Լ�
void clearMenu() {
	gotoxy(60, 31);
	printf("                             ");
	gotoxy(60, 32);
	printf("                             ");
	gotoxy(60, 33);
	printf("                             ");
	gotoxy(60, 34);
	printf("                             ");
}

// ��ȭâ ����� �Լ�
void clearTextbox() {
	gotoxy(2, 32);
	printf("                                                 ");
	gotoxy(2, 33);
	printf("                                                 ");
	gotoxy(2, 34);
	printf("                                                 ");
	gotoxy(2, 35);
	printf("                                                 ");
	gotoxy(2, 36);
	printf("                                                 ");
	gotoxy(2, 37);
	printf("                                                 ");
}

// ȭ�� ���� �Լ�
void drawScreenLine() {
	// ���� ����
	gotoxy(3, 0);
	printf("\t\t\t�������� RPG ����\n");
	printf("---------------------------------------------------------------");

	// �Ʒ��� ����
	gotoxy(0, 30);
	printf("---------------------------------------------------------------");
}

// �� �׸��� �Լ�
void drawMap() {
	int iIndexX = 0, iIndexY = 0;

	// �� �׸���
	for (iIndexY = 0; iIndexY < 20; iIndexY++) {
		gotoxy(6, 6 + iIndexY);
		for (iIndexX = 0; iIndexX < 44; iIndexX++) {
			if (map[iIndexY][iIndexX] == 9) {
				printf("#"); // �׵θ�
			}
			else if (map[iIndexY][iIndexX] == 3) {
				printf(" "); // �̺�Ʈ �߻� ��ġ
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// �� ����� �Լ�
void clearMap() {
	int iIndexX = 0, iIndexY = 0;

	// �� �����
	for (iIndexY = 0; iIndexY < 20; iIndexY++) {
		gotoxy(6, 6 + iIndexY);
		for (iIndexX = 0; iIndexX < 44; iIndexX++) {
			printf(" ");
		}
		printf("\n");
	}
}

// ���� ��ġ�� map�� �̺�Ʈ ��ġ ���Ͽ� event �߻� ���θ� �˷��ִ� �Լ�
int GetEventFromMap(int iCurrentX, int iCurrentY) {
	int iEventOk = -1;

	// ���� OR ��ȭ OR �ƹ��͵� ���� �� ���� �̺�Ʈ ��ġ ��
	if (map[iCurrentX - 6][iCurrentY - 6] == 3) {
		iEventOk = 0;
	}

	return iEventOk;
}

// �������� Ȯ������ ��ȯ�ϴ� �Լ�
int RPGRandom(int iPercent) {
	int iRand = 0, iRandomResult = 0;
	srand(time(NULL));
	iRand = rand();

	iRandomResult = iRand % iPercent;
	return iRandomResult;
}

// A�� B�� �����ϴ� �Լ�
int AttackAtoB(int iAttA, int iDefB, int iHpB, int iCurrentY) {
	int iDamage = 0;
	// ������ ���
	iDamage = iDefB - iAttA;
	if (iDamage < 0) {
		iHpB += iDamage;

		gotoxy(2, iCurrentY + 1);
		printf("���ظ� %d �������ϴ�.", iDamage);
		gotoxy(2, iCurrentY + 2);
		printf("���� ü�� : %d", iHpB);
	}
	else {
		clearTextbox();
		gotoxy(2, iCurrentY + 1);
		printf("���ݿ� �����Ͽ����ϴ�.");
	}
	return iHpB;
}

// ��ȭ ������ �ܼ�â�� �����ִ� �Լ�
void displayCoin(int coin) {
	gotoxy(60, 0);
	printf("��ȭ : %2d", coin);
}

void title() {
	while (1) {
		gotoxy(10, 10);
		printf("�������� RPG���ӿ� ���� ���� ȯ���մϴ�!");
		gotoxy(10, 12);
		printf("�� RPG������ ĳ���� �̵����� ������ �ʿ��� ���͸� ��ų� ��ȭ�� ���");
		gotoxy(10, 13);
		printf("���� ���� ��ȭ�� ���� ����� �¸��ϴ� �����Դϴ�.");
		gotoxy(10, 14);
		printf("1�ο� �����̸�, ģ����� �Բ� ������ ���⸦ �� �� �ֽ��ϴ�.");
		gotoxy(10, 15);
		printf("��ȭ�� �����ϰ� ���޵Ǹ�, �ݰų�, ���͸� �����߷��� �� ���� �� �ֽ��ϴ�.");
		gotoxy(10, 16);
		printf("���ΰ��� ü���� 0 ���ϰ� �� ��, ������ ����Ǹ�");
		gotoxy(10, 17);
		printf("���� ��ȭ ������ Ȯ���� �� �ֽ��ϴ�.");
		gotoxy(10, 19);
		printf("������ �����Ϸ��� �ƹ� Ű�� ��������!");
		gotoxy(10, 20);
		printf("���� ������ �����ϰ� �����ôٸ� ESCŰ�� �����ּ���.");
		if (_kbhit()) {
			_getch();
			system("cls");
			break;
		} 
		else if (_getch() == 27) {
			exit(1);
		}
	}
}

int main() {
	// ��ȭ����
	int iCoin = 0;

	// �޴� ���� �Է� ����
	int iMenu = -1;

	// ���ΰ� �̵� Ű���� �Է°� ����
	char cPosition;

	// ��ġ �� �̺�Ʈ ��ġ �� ����
	int iCenterX = 7, iCenterY = 7, iExit = 0, iEvent = -1;

	// ���ΰ� ����
	int iHeroHp = 120, iHeroAtt = 10, iHeroDef = 4;

	// �� ����
	Mob zombie, spider, skeleton, mob;

	// mop1
	zombie.dHp = 100;
	zombie.dAtt = 8;
	zombie.dDef = 4;

	// mop2
	spider.dHp = 80;
	spider.dAtt = 9;
	spider.dDef = 3;

	// mop3
	skeleton.dHp = 50;
	skeleton.dAtt = 12;
	skeleton.dDef = 5;

	// �ܼ�â ��������
	system("mode con:cols=90 lines=50");

	// �ܼ�â���� Ŀ�� ����
	clearCursor();
	
	// ���� ���� �� Ÿ��Ʋ ȭ��
	title();

	// ȭ�� ����
	drawScreenLine();

	// ���� ��ȭ ǥ��
	displayCoin(iCoin);

	// Ÿ��Ʋ
	gotoxy(30, 15);
	printf("�������� RPG ����\n");

	restart: // �ٽ��ϱ⸦ ������ ó������ �ٽ� ����
	while (1) {
		// �޴� ȭ��
		gotoxy(60, 31);
		printf("## ���� �޴� ##");
		gotoxy(60, 32);
		printf("�� ����(0)");
		gotoxy(60, 33);
		printf("���� ����(��Ÿ)");

		scanf("%d", &iMenu);

		if (iMenu == 0) { // �� ����
			// Ÿ��Ʋ
			clearTitle();
			gotoxy(30, 15);
			printf("�� ����");

			while (1) {
				// ���� �޴� ȭ��
				clearMenu();
				gotoxy(60, 31);
				printf("## ���� �޴� ##");
				gotoxy(60, 32);
				printf("��������(0)");
				gotoxy(60, 33);
				printf("������(��Ÿ)");

				scanf("%d", &iMenu);

				if (iMenu == 0) { // ���� ����
					// Ÿ��Ʋ
					clearTitle();
					// gotoxy(30, 15);
					// printf("���� ����");
					drawMap();

					while (1) {
						// ���� �޴� ȭ��
						clearMenu();
						gotoxy(60, 31);
						printf("## ���� �޴� ##");
						gotoxy(60, 32);
						printf("�̵�(����Ű ���)");
						gotoxy(60, 33);
						printf("������(1)");

						// scanf("%d", &iMenu);

						// ���ΰ� ������
						gotoxy(iCenterX, iCenterY);
						printf("*");

						while (1) {
							if (_kbhit()) {
								// ĳ���� ���� ��ġ �����
								gotoxy(iCenterX, iCenterY);
								printf(" ");

								cPosition = _getch();

								// ĳ���� �̵�
								switch (cPosition) {
								case UP:
									iCenterY--;
									break;
								case DOWN:
									iCenterY++;
									break;
								case LEFT:
									iCenterX--;
									break;
								case RIGHT:
									iCenterX++;
									break;
								case '1':
									iExit = 1;
									break;
								}

								// �� ũ�� ����
								if (iCenterX <= 6) {
									iCenterX++;
								}
								if (iCenterX >= 49) {
									iCenterX--;
								}
								if (iCenterY <= 6) {
									iCenterY++;
								}
								if (iCenterY >= 25) {
									iCenterY--;
								}

								gotoxy(iCenterX, iCenterY);
								printf("*");
								// Sleep(10);
							}

							// ���� ��ġ�� map�� �̺�Ʈ �߻� ��ġ ��
							iEvent = GetEventFromMap(iCenterX, iCenterY);

							if (iEvent == 0) {
								iMenu = 0;
								iCenterX++; // ���� �̺�Ʈ ����
								break;
							}

							// ���� ������
							if (iExit == 1) {
								iMenu = 1;
								break;
							}
						}

						if (iMenu == 0) { // �̵�
							int iRandomMove = 0;
							// return���� 0~9�� ���� �Լ�
							iRandomMove = RPGRandom(10);

							int iRandomCoin = 0;
							iRandomCoin = RPGRandom(10);

							if (iRandomMove < 3) { // �̺�Ʈ �߻�
								// ��ȭ �հ�
								iCoin += iRandomCoin;

								clearTextbox();
								gotoxy(2, 32);
								printf("��ȭ�� %d�� ȹ���Ͽ����ϴ�.", iRandomCoin);

								// ���� ��ȭ ǥ��
								displayCoin(iCoin);
							}
							else if (iRandomMove > 6) { // �׳� �̵�
								clearTextbox();
								gotoxy(2, 32);
								printf("�ƹ� �ϵ� �Ͼ�� �ʾҽ��ϴ�.");
								

							}
							else { // ���͸� ���� ����
								int iRandomMob = 0;
								// return���� 0~2�� ���� �Լ�
								iRandomMob = RPGRandom(3);

								// ���� ����
								if (iRandomMob == 0) {
									mob = zombie;
									clearTextbox();
									gotoxy(2, 32);
									printf("���� �������ϴ�!");

									clearMap();
									gotoxy(30, 15);
									printf("����� ���� ����");
								}
								else if (iRandomMob == 1) {
									mob = spider;
									clearTextbox();
									gotoxy(2, 32);
									printf("�����̴��� �������ϴ�!");

									clearMap();
									gotoxy(30, 15);
									printf("�����̴��� ���� ����");
								}
								else {
									mob = skeleton;
									clearTextbox();
									gotoxy(2, 32);
									printf("���̷����� �������ϴ�!");

									clearMap();
									gotoxy(30, 15);
									printf("���̷���� ���� ����");
								}

								while (1) { // ���� ����
									// ���� �޴� ȭ��
									clearMenu();
									gotoxy(60, 31);
									printf("## ���� �޴� ##");
									gotoxy(60, 32);
									printf("����(0)");
									gotoxy(60, 33);
									printf("���(1)");
									gotoxy(60, 34);
									printf("����(��Ÿ)");

									scanf("%d", &iMenu);

									// ���� : ���ΰ��� ���� 1ȸ, ���Ͱ� �ݰ� 1ȸ
									// ��� : ���ΰ��� ���(���� 2 ����), ���� �ݰ� 1ȸ
									// ���� : ���� �ݰ�(���ݷ� 2 ����) 1ȸ

									// ������ ���� ����
									// ���� - ���ݷ�

									if (iMenu == 0) { // ����
										clearTextbox();
										gotoxy(2, 32);

										// ���ΰ� ���� 1ȸ, ���� �ݰ� 1ȸ
										printf("���ΰ��� ���͸� �����մϴ�.");
										mob.dHp = AttackAtoB(iHeroAtt, mob.dDef, mob.dHp, 32);

										gotoxy(2, 35);
										printf("���Ͱ� �ݰ��մϴ�.");
										iHeroHp = AttackAtoB(mob.dAtt, iHeroDef, iHeroHp, 35);
									}
									else if (iMenu == 1) { // ���
										clearTextbox();
										gotoxy(2, 32);

										// ���ΰ��� ���(���� 2 ����), ���� �ݰ� 1ȸ
										printf("���ΰ��� ����ڼ��� ���մϴ�.");

										gotoxy(2, 34);
										printf("���Ͱ� �����մϴ�.");
										iHeroHp = AttackAtoB(mob.dAtt, iHeroDef + 2, iHeroHp, 34);
									}
									else { // ����
										clearTextbox();
										gotoxy(2, 32);

										// ���� �ݰ�(���ݷ� 2 ����) 1ȸ
										printf("���ΰ��� �����ϴٰ� ���Ϳ��� ���ظ� �Ծ����ϴ�.");

										gotoxy(2, 34);
										printf("���Ͱ� �ݰ��մϴ�.");
										iHeroHp = AttackAtoB(mob.dAtt - 2, iHeroDef, iHeroHp, 34);

										Sleep(1500);

										clearMap();
										drawMap();

										clearTextbox();
										gotoxy(2, 32);
										printf("�������� �̵��մϴ�.");
										break;
									}
									// ���� �ǰ� ������ ���� �¸�
									if (mob.dHp <= 0) {
										clearMap();
										drawMap();

										clearTextbox();
										gotoxy(2, 32);
										printf("������ �¸��Ͽ����ϴ�.");

										int iRandomCoin = 0;
										iRandomCoin = RPGRandom(50);

										// ��ȭ �հ�
										iCoin += iRandomCoin;
										gotoxy(2, 33);
										printf("�¸� ������� ��ȭ�� %d�� ȹ���Ͽ����ϴ�.", iRandomCoin);

										// ���� ��ȭ ǥ��
										displayCoin(iCoin);
										break;
									}
									// ���ΰ��� �ǰ� ������ ���� ����
									if (iHeroHp <= 0) {
										clearTextbox();
										clearTitle();
										gotoxy(30, 15);
										printf("���� ����");
										gotoxy(30, 16);
										printf("���� �� ��ȭ : %2d��", iCoin);

										clearMenu();
										gotoxy(60, 31);
										printf("## ���� ���� ##");
										gotoxy(60, 32);
										printf("�ٽ��Ͻðڽ��ϱ�? �ٽ��ϱ�(0)");
										gotoxy(60, 33);
										printf("�����Ͻðڽ��ϱ�? ����(��Ÿ)");

										scanf("%d", &iMenu);

										if (iMenu == 0) {
											clearMap();
											clearTextbox();
											clearMenu();
											iHeroHp = 120;
											iCoin = 0;
											displayCoin(iCoin);
											goto restart; // goto���� �̿��� �ٽ��ϱ� ����
										}
										else {
											exit(1);
										}
									}
								}
							}
						}
						else {
							clearMap();
							gotoxy(30, 15);
							printf("���� �޴�");

							clearTextbox();
							gotoxy(2, 32);
							printf("���� �޴��� �̵��մϴ�.");
							break;
						}
					}
				}
				else {
					clearMap();
					gotoxy(30, 15);
					printf("���� �޴�");

					clearTextbox();
					gotoxy(2, 32);
					printf("���� �޴��� �̵��մϴ�.");
					break;
				}
			}
		}
		else {
			clearMap();
			gotoxy(30, 15);
			printf("Bye~ Bye~");

			clearTextbox();
			gotoxy(2, 32);
			printf("������ �����մϴ�.");
			break;
		}
	}
}