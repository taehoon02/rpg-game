/*
## 태훈이의 RPG 게임 ##
캐릭터 이동으로 랜덤한 맵에서 몬스터를 잡거나 금화를 모아
가장 많은 금화를 모은 사람이 승리하는 게임입니다.
1인용 게임이며, 친구들과 함께 간단한 내기를 할 수 있습니다.
금화는 랜덤하게 지급되며, 줍거나, 몬스터를 쓰러뜨렸을 때 얻을 수 있습니다.
주인공의 체력이 0 이하가 될 때, 게임이 종료되며 모은 금화 개수를 확인할 수 있습니다.
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

// 몹 정의
typedef struct _Mob {
	double dHp;
	double dAtt;
	double dDef;
} Mob;

// 맵 정의
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

// x, y로 이동하는 함수
void gotoxy(int x, int y) {
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

// 콘솔창 커서 지우는 함수
void clearCursor() {
	CONSOLE_CURSOR_INFO c = { 0 };
	c.dwSize = 1;
	c.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

// 타이틀 지우는 함수
void clearTitle() {
	gotoxy(30, 15);
	printf("                                 ");
}

// 메뉴창 지우는 함수
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

// 대화창 지우는 함수
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

// 화면 구분 함수
void drawScreenLine() {
	// 위쪽 라인
	gotoxy(3, 0);
	printf("\t\t\t태훈이의 RPG 게임\n");
	printf("---------------------------------------------------------------");

	// 아래쪽 라인
	gotoxy(0, 30);
	printf("---------------------------------------------------------------");
}

// 맵 그리는 함수
void drawMap() {
	int iIndexX = 0, iIndexY = 0;

	// 맵 그리기
	for (iIndexY = 0; iIndexY < 20; iIndexY++) {
		gotoxy(6, 6 + iIndexY);
		for (iIndexX = 0; iIndexX < 44; iIndexX++) {
			if (map[iIndexY][iIndexX] == 9) {
				printf("#"); // 테두리
			}
			else if (map[iIndexY][iIndexX] == 3) {
				printf(" "); // 이벤트 발생 위치
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// 맵 지우는 함수
void clearMap() {
	int iIndexX = 0, iIndexY = 0;

	// 맵 지우기
	for (iIndexY = 0; iIndexY < 20; iIndexY++) {
		gotoxy(6, 6 + iIndexY);
		for (iIndexX = 0; iIndexX < 44; iIndexX++) {
			printf(" ");
		}
		printf("\n");
	}
}

// 현재 위치와 map의 이벤트 위치 비교하여 event 발생 여부를 알려주는 함수
int GetEventFromMap(int iCurrentX, int iCurrentY) {
	int iEventOk = -1;

	// 몬스터 OR 금화 OR 아무것도 없음 에 대한 이벤트 위치 비교
	if (map[iCurrentX - 6][iCurrentY - 6] == 3) {
		iEventOk = 0;
	}

	return iEventOk;
}

// 랜덤으로 확률값을 반환하는 함수
int RPGRandom(int iPercent) {
	int iRand = 0, iRandomResult = 0;
	srand(time(NULL));
	iRand = rand();

	iRandomResult = iRand % iPercent;
	return iRandomResult;
}

// A가 B를 공격하는 함수
int AttackAtoB(int iAttA, int iDefB, int iHpB, int iCurrentY) {
	int iDamage = 0;
	// 데미지 계산
	iDamage = iDefB - iAttA;
	if (iDamage < 0) {
		iHpB += iDamage;

		gotoxy(2, iCurrentY + 1);
		printf("피해를 %d 입혔습니다.", iDamage);
		gotoxy(2, iCurrentY + 2);
		printf("남은 체력 : %d", iHpB);
	}
	else {
		clearTextbox();
		gotoxy(2, iCurrentY + 1);
		printf("공격에 실패하였습니다.");
	}
	return iHpB;
}

// 금화 개수를 콘솔창에 보여주는 함수
void displayCoin(int coin) {
	gotoxy(60, 0);
	printf("금화 : %2d", coin);
}

void title() {
	while (1) {
		gotoxy(10, 10);
		printf("태훈이의 RPG게임에 오신 것을 환영합니다!");
		gotoxy(10, 12);
		printf("이 RPG게임은 캐릭터 이동으로 랜덤한 맵에서 몬스터를 잡거나 금화를 모아");
		gotoxy(10, 13);
		printf("가장 많은 금화를 모은 사람이 승리하는 게임입니다.");
		gotoxy(10, 14);
		printf("1인용 게임이며, 친구들과 함께 간단한 내기를 할 수 있습니다.");
		gotoxy(10, 15);
		printf("금화는 랜덤하게 지급되며, 줍거나, 몬스터를 쓰러뜨렸을 때 얻을 수 있습니다.");
		gotoxy(10, 16);
		printf("주인공의 체력이 0 이하가 될 때, 게임이 종료되며");
		gotoxy(10, 17);
		printf("모은 금화 개수를 확인할 수 있습니다.");
		gotoxy(10, 19);
		printf("게임을 시작하려면 아무 키나 누르세요!");
		gotoxy(10, 20);
		printf("만약 게임을 종료하고 싶으시다면 ESC키를 눌러주세요.");
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
	// 금화개수
	int iCoin = 0;

	// 메뉴 선택 입력 변수
	int iMenu = -1;

	// 주인공 이동 키보드 입력값 변수
	char cPosition;

	// 위치 및 이벤트 위치 비교 변수
	int iCenterX = 7, iCenterY = 7, iExit = 0, iEvent = -1;

	// 주인공 정의
	int iHeroHp = 120, iHeroAtt = 10, iHeroDef = 4;

	// 몹 정의
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

	// 콘솔창 리사이즈
	system("mode con:cols=90 lines=50");

	// 콘솔창에서 커서 제거
	clearCursor();
	
	// 게임 시작 전 타이틀 화면
	title();

	// 화면 구분
	drawScreenLine();

	// 현재 금화 표시
	displayCoin(iCoin);

	// 타이틀
	gotoxy(30, 15);
	printf("태훈이의 RPG 게임\n");

	restart: // 다시하기를 누르면 처음부터 다시 실행
	while (1) {
		// 메뉴 화면
		gotoxy(60, 31);
		printf("## 메인 메뉴 ##");
		gotoxy(60, 32);
		printf("새 게임(0)");
		gotoxy(60, 33);
		printf("게임 종료(기타)");

		scanf("%d", &iMenu);

		if (iMenu == 0) { // 새 게임
			// 타이틀
			clearTitle();
			gotoxy(30, 15);
			printf("새 게임");

			while (1) {
				// 게임 메뉴 화면
				clearMenu();
				gotoxy(60, 31);
				printf("## 게임 메뉴 ##");
				gotoxy(60, 32);
				printf("던전입장(0)");
				gotoxy(60, 33);
				printf("나가기(기타)");

				scanf("%d", &iMenu);

				if (iMenu == 0) { // 던전 입장
					// 타이틀
					clearTitle();
					// gotoxy(30, 15);
					// printf("던전 입장");
					drawMap();

					while (1) {
						// 던전 메뉴 화면
						clearMenu();
						gotoxy(60, 31);
						printf("## 던전 메뉴 ##");
						gotoxy(60, 32);
						printf("이동(방향키 사용)");
						gotoxy(60, 33);
						printf("나가기(1)");

						// scanf("%d", &iMenu);

						// 주인공 시작점
						gotoxy(iCenterX, iCenterY);
						printf("*");

						while (1) {
							if (_kbhit()) {
								// 캐릭터 이전 위치 지우기
								gotoxy(iCenterX, iCenterY);
								printf(" ");

								cPosition = _getch();

								// 캐릭터 이동
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

								// 맵 크기 설정
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

							// 현재 위치와 map의 이벤트 발생 위치 비교
							iEvent = GetEventFromMap(iCenterX, iCenterY);

							if (iEvent == 0) {
								iMenu = 0;
								iCenterX++; // 무한 이벤트 방지
								break;
							}

							// 던전 나가기
							if (iExit == 1) {
								iMenu = 1;
								break;
							}
						}

						if (iMenu == 0) { // 이동
							int iRandomMove = 0;
							// return값이 0~9인 랜덤 함수
							iRandomMove = RPGRandom(10);

							int iRandomCoin = 0;
							iRandomCoin = RPGRandom(10);

							if (iRandomMove < 3) { // 이벤트 발생
								// 금화 합계
								iCoin += iRandomCoin;

								clearTextbox();
								gotoxy(2, 32);
								printf("금화를 %d원 획득하였습니다.", iRandomCoin);

								// 현재 금화 표시
								displayCoin(iCoin);
							}
							else if (iRandomMove > 6) { // 그냥 이동
								clearTextbox();
								gotoxy(2, 32);
								printf("아무 일도 일어나지 않았습니다.");
								

							}
							else { // 몬스터를 만나 전투
								int iRandomMob = 0;
								// return값이 0~2인 랜덤 함수
								iRandomMob = RPGRandom(3);

								// 몬스터 구분
								if (iRandomMob == 0) {
									mob = zombie;
									clearTextbox();
									gotoxy(2, 32);
									printf("좀비를 만났습니다!");

									clearMap();
									gotoxy(30, 15);
									printf("좀비와 전투 시작");
								}
								else if (iRandomMob == 1) {
									mob = spider;
									clearTextbox();
									gotoxy(2, 32);
									printf("스파이더를 만났습니다!");

									clearMap();
									gotoxy(30, 15);
									printf("스파이더와 전투 시작");
								}
								else {
									mob = skeleton;
									clearTextbox();
									gotoxy(2, 32);
									printf("스켈레톤을 만났습니다!");

									clearMap();
									gotoxy(30, 15);
									printf("스켈레톤과 전투 시작");
								}

								while (1) { // 전투 시작
									// 전투 메뉴 화면
									clearMenu();
									gotoxy(60, 31);
									printf("## 전투 메뉴 ##");
									gotoxy(60, 32);
									printf("공격(0)");
									gotoxy(60, 33);
									printf("방어(1)");
									gotoxy(60, 34);
									printf("후퇴(기타)");

									scanf("%d", &iMenu);

									// 공격 : 주인공이 공격 1회, 몬스터가 반격 1회
									// 방어 : 주인공이 방어(방어력 2 증가), 몬스터 반격 1회
									// 후퇴 : 몬스터 반격(공격력 2 감소) 1회

									// 데미지 계산식 정의
									// 방어력 - 공격력

									if (iMenu == 0) { // 공격
										clearTextbox();
										gotoxy(2, 32);

										// 주인공 공격 1회, 몬스터 반격 1회
										printf("주인공이 몬스터를 공격합니다.");
										mob.dHp = AttackAtoB(iHeroAtt, mob.dDef, mob.dHp, 32);

										gotoxy(2, 35);
										printf("몬스터가 반격합니다.");
										iHeroHp = AttackAtoB(mob.dAtt, iHeroDef, iHeroHp, 35);
									}
									else if (iMenu == 1) { // 방어
										clearTextbox();
										gotoxy(2, 32);

										// 주인공이 방어(방어력 2 증가), 몬스터 반격 1회
										printf("주인공이 방어자세를 취합니다.");

										gotoxy(2, 34);
										printf("몬스터가 공격합니다.");
										iHeroHp = AttackAtoB(mob.dAtt, iHeroDef + 2, iHeroHp, 34);
									}
									else { // 후퇴
										clearTextbox();
										gotoxy(2, 32);

										// 몬스터 반격(공격력 2 감소) 1회
										printf("주인공이 후퇴하다가 몬스터에게 피해를 입었습니다.");

										gotoxy(2, 34);
										printf("몬스터가 반격합니다.");
										iHeroHp = AttackAtoB(mob.dAtt - 2, iHeroDef, iHeroHp, 34);

										Sleep(1500);

										clearMap();
										drawMap();

										clearTextbox();
										gotoxy(2, 32);
										printf("던전으로 이동합니다.");
										break;
									}
									// 몹의 피가 없으면 전투 승리
									if (mob.dHp <= 0) {
										clearMap();
										drawMap();

										clearTextbox();
										gotoxy(2, 32);
										printf("전투에 승리하였습니다.");

										int iRandomCoin = 0;
										iRandomCoin = RPGRandom(50);

										// 금화 합계
										iCoin += iRandomCoin;
										gotoxy(2, 33);
										printf("승리 기념으로 금화를 %d원 획득하였습니다.", iRandomCoin);

										// 현재 금화 표시
										displayCoin(iCoin);
										break;
									}
									// 주인공의 피가 없으면 게임 오버
									if (iHeroHp <= 0) {
										clearTextbox();
										clearTitle();
										gotoxy(30, 15);
										printf("게임 오버");
										gotoxy(30, 16);
										printf("모은 총 금화 : %2d개", iCoin);

										clearMenu();
										gotoxy(60, 31);
										printf("## 게임 오버 ##");
										gotoxy(60, 32);
										printf("다시하시겠습니까? 다시하기(0)");
										gotoxy(60, 33);
										printf("종료하시겠습니까? 종료(기타)");

										scanf("%d", &iMenu);

										if (iMenu == 0) {
											clearMap();
											clearTextbox();
											clearMenu();
											iHeroHp = 120;
											iCoin = 0;
											displayCoin(iCoin);
											goto restart; // goto문을 이용한 다시하기 구현
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
							printf("게임 메뉴");

							clearTextbox();
							gotoxy(2, 32);
							printf("게임 메뉴로 이동합니다.");
							break;
						}
					}
				}
				else {
					clearMap();
					gotoxy(30, 15);
					printf("메인 메뉴");

					clearTextbox();
					gotoxy(2, 32);
					printf("메인 메뉴로 이동합니다.");
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
			printf("게임을 종료합니다.");
			break;
		}
	}
}