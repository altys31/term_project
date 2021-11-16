#include <stdio.h>
#include <windows.h>
#define CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
#include <Digitalv.h>
#include <conio.h>
#include <lmcons.h>
#include <string.h>


//사운드 재생을 위한 구조체 선언
MCI_OPEN_PARMS openBgm_1;
MCI_PLAY_PARMS playBgm_1;
MCI_OPEN_PARMS openBgm_2;
MCI_PLAY_PARMS playBgm_2;
MCI_OPEN_PARMS openBgm_3;
MCI_PLAY_PARMS playBgm_3;
MCI_OPEN_PARMS openbeepSound;
MCI_PLAY_PARMS playbeepSound;
MCI_OPEN_PARMS openbeepSound_1;
MCI_PLAY_PARMS playbeepSound_1;
MCI_OPEN_PARMS openbuttonSound;
MCI_PLAY_PARMS playbuttonSound;
MCI_OPEN_PARMS opentypingSound;
MCI_PLAY_PARMS playtypingSound;
MCI_OPEN_PARMS openinitializationSound;
MCI_PLAY_PARMS playinitializationSound;
MCI_OPEN_PARMS openrobotSound;
MCI_PLAY_PARMS playrobotSound;
MCI_OPEN_PARMS opentextSound;
MCI_PLAY_PARMS playtextSound;


//콘솔창의 크기와 제목을 정하는 함수
void SetConsoleView()  
{
	system("mode con:cols=66 lines=30");
	system("title 퍼즐");
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//콘솔창 출력색상을 나타내는 함수
void ColorSet(int backgroundcolor, int textcolor) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (backgroundcolor << 4) + textcolor);
}  




//대사나 정보를 원하는 타이밍에 넘길수 있도록 하는 함수 
void pressanykey(void) {
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //이미 입력된 버퍼지우기
	while (_getch() == 0) {
		Sleep(1);
	}
}

bool gameclear = false;
char button[5][15] = {
		{"\t-----@-----\n"},
		{"\t---+---+---\n"},
		{"\t-@---@---@-\n"},
		{"\t---+---+---\n"},
		{"\t-----@-----\n"},
};
char button_choice[5][14] = {
{"\t-----1-----\n"},
{"\t---2---3---\n"},
{"\t-4---5---6-\n"},
{"\t---7---8---\n"},
{"\t-----9-----\n"},
};

char picture_puzzle_1[8][19] = {
	{"##################"},
	{"#----------------#"},
	{"#-----+--+-------#"},
	{"#-----+--+-------#"},
	{"#-----++++++-----#"},
	{"#--------+-------#"},
	{"#--------+-------#"},
	{"##################"},
};
char picture_puzzle_2[9][18] = {
	{"#################"},
	{"#---------------#"},
	{"#-----+++++-----#"},
	{"#---------+-----#"},
	{"#-----+++++-----#"},
	{"#-----+---------#"},
	{"#-----+++++-----#"},
	{"#---------------#"},
	{"#################"},
};


// 사운드 관련 코드 
int dwID;
#define	BGM_1 "'CGI Snake' by Chris Zabriskie.mp3"
void playingBgm_1(bool on_off) {
	openBgm_1.lpstrElementName = BGM_1;
	openBgm_1.lpstrDeviceType = "mpegvideo";

	if (on_off == true) {
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_1);
		dwID = openBgm_1.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_1);
	}
	if (on_off == false) {
		dwID = openBgm_1.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_1);
	}

}
#define	BGM_2 "The Basics of the Case - Ace Attorney 6_ Spirit Of Justice OST .mp3"
void playingBgm_2(bool on_off) {
	if (on_off == true) {
		openBgm_2.lpstrElementName = BGM_2;
		openBgm_2.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_2);
		dwID = openBgm_2.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_2);
	}
	if (on_off == false) {
		openBgm_2.lpstrElementName = BGM_2;
		openBgm_2.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_2.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_2);
	}

}
#define	BGM_3 "Portal 2 OST - Overgrowth.mp3"
void playingBgm_3(bool on_off) {
	if (on_off == true) {
		openBgm_3.lpstrElementName = BGM_3;
		openBgm_3.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_3);
		dwID = openBgm_3.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_3);
	}
	if (on_off == false) {
		openBgm_3.lpstrElementName = BGM_1;
		openBgm_3.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_3.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_3);
	}

}
#define beep "blipmale.wav"
void beep_male(int time) {
	openbeepSound.lpstrElementName = beep; //파일 오픈
	openbeepSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openbeepSound);
	dwID = openbeepSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openbeepSound); //음악을 한 번 재생
	Sleep(time); //실행시간 대사의 속도를 조절하기 위함
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define beep_1 "pc_messagebox.wav"
void beep_female(int time) {
	openbeepSound_1.lpstrElementName = beep_1; //파일 오픈
	openbeepSound_1.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openbeepSound_1);
	dwID = openbeepSound_1.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openbeepSound_1); //음악을 한 번 재생
	Sleep(time); //실행시간 대사의 속도를 조절하기 위함
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define button_1 "button_sound.mp3"
void button_sound(void) {
	openbuttonSound.lpstrElementName = button_1; //파일 오픈
	openbuttonSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openbuttonSound);
	dwID = openbuttonSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openbuttonSound); //음악을 한 번 재생
	Sleep(300);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define typing "typing.wav"
void typing_sound(void) {
	opentypingSound.lpstrElementName = typing; //파일 오픈
	opentypingSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opentypingSound);
	dwID = opentypingSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opentypingSound); //음악을 한 번 재생
	Sleep(120);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define initialization_sound "initialization_sound.mp3"
void initialization(void) {
	openinitializationSound.lpstrElementName = initialization_sound; //파일 오픈
	openinitializationSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openinitializationSound);
	dwID = openinitializationSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openinitializationSound); //음악을 한 번 재생
	Sleep(1000);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define text_robot "text_robot.wav"
void robot_sound(void) {
	openrobotSound.lpstrElementName = text_robot; //파일 오픈
	openrobotSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openrobotSound);
	dwID = openrobotSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openrobotSound); //음악을 한 번 재생
	Sleep(80);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define text "text.wav"
void text_sound(int time) {
	opentextSound.lpstrElementName =text; //파일 오픈
	opentextSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opentextSound);
	dwID = opentextSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opentextSound); //음악을 한 번 재생
	Sleep(time); //실행시간 대사의 속도를 조절하기 위함
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}

// 

// 버튼 퍼즐 관련 코드 
void button_puzzle_first_title(void) {
	printf("                 ");
	ColorSet(2, 0);
	char button_puzzle_title[] = "Object  :   Make All Green";
	for (int i = 0; i < 27; i++) {
		printf("%c", button_puzzle_title[i]);
		typing_sound();
		if (i == 8 || i == 12)
			Sleep(100);
	}
	Sleep(1000);
	ColorSet(0, 0);
	system("cls");
}
void viewbutton(void) {
	printf("                 ");
	ColorSet(2, 0);
	printf("Object  :   Make All Green\n\n");
	ColorSet(0, 0);
	for (int i = 0; i < 5; i++) {
		printf("                       ");
		for (int k = 0; k < 15; k++) {
			if (button[i][k] == '+') {
				ColorSet(2, 2);
			}
			if (button[i][k] == '-') {
				ColorSet(0, 0);
			}
			if (button[i][k] == '@') {
				ColorSet(4, 4);
			}

			printf("%c", button[i][k]);
		}

	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("                       ");
		for (int k = 0; k < 14; k++) {

			if (button_choice[i][k] == '-') {
				ColorSet(0, 0);
			}
			else {
				ColorSet(0, 7);
			}
			printf("%c", button_choice[i][k]);
		}

	}
} 
void chose_num(void) {
	char num[30];
	char error[] = "1 ~ 9의 숫자만 입력할 수 있다.";
	printf("\n\n\n'0'번을 입력해 초기화 / (type '0' for initializtion)");
	printf("\ninput num  = ");
	scanf_s("%s", num, sizeof(num));
	//숫자만 입력하는것이나 행여 실수로 문자 입력시 게임 진행이 불가능하므로 문자열 비교 함수 사용
	if (strcmp(num, "1") == 0) { 
		if (button[0][6] == '@') {
			button[0][6] = '+';
		}
		else if (button[0][6] == '+') {
			button[0][6] = '@';
		}
		if (button[1][4] == '@') {
			button[1][4] = '+';
		}
		else if (button[1][4] == '+') {
			button[1][4] = '@';
		}
		if (button[1][8] == '@') {
			button[1][8] = '+';
		}
		else if (button[1][8] == '+') {
			button[1][8] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "2") == 0) {
		if (button[1][4] == '@') {
			button[1][4] = '+';
		}
		else if (button[1][4] == '+') {
			button[1][4] = '@';
		}
		if (button[0][6] == '@') {
			button[0][6] = '+';
		}
		else if (button[0][6] == '+') {
			button[0][6] = '@';
		}
		if (button[2][2] == '@') {
			button[2][2] = '+';
		}
		else if (button[2][2] == '+') {
			button[2][2] = '@';
		}
		if (button[2][6] == '@') {
			button[2][6] = '+';
		}
		else if (button[2][6] == '+') {
			button[2][6] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "3") == 0) {
		if (button[0][6] == '@') {
			button[0][6] = '+';
		}
		else if (button[0][6] == '+') {
			button[0][6] = '@';
		}
		if (button[2][6] == '@') {
			button[2][6] = '+';
		}
		else if (button[2][6] == '+') {
			button[2][6] = '@';
		}
		if (button[1][8] == '@') {
			button[1][8] = '+';
		}
		else if (button[1][8] == '+') {
			button[1][8] = '@';
		}
		if (button[2][10] == '@') {
			button[2][10] = '+';
		}
		else if (button[2][10] == '+') {
			button[2][10] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "4") == 0) {
		if (button[2][2] == '@') {
			button[2][2] = '+';
		}
		else if (button[2][2] == '+') {
			button[2][2] = '@';
		}
		if (button[1][4] == '@') {
			button[1][4] = '+';
		}
		else if (button[1][4] == '+') {
			button[1][4] = '@';
		}
		if (button[3][4] == '@') {
			button[3][4] = '+';
		}
		else if (button[3][4] == '+') {
			button[3][4] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "5") == 0) {
		if (button[2][6] == '@') {
			button[2][6] = '+';
		}
		else if (button[2][6] == '+') {
			button[2][6] = '@';
		}
		if (button[1][4] == '@') {
			button[1][4] = '+';
		}
		else if (button[1][4] == '+') {
			button[1][4] = '@';
		}
		if (button[1][8] == '@') {
			button[1][8] = '+';
		}
		else if (button[1][8] == '+') {
			button[1][8] = '@';
		}
		if (button[3][4] == '@') {
			button[3][4] = '+';
		}
		else if (button[3][4] == '+') {
			button[3][4] = '@';
		}
		if (button[3][8] == '@') {
			button[3][8] = '+';
		}
		else if (button[3][8] == '+') {
			button[3][8] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "6") == 0) {
		if (button[2][10] == '@') {
			button[2][10] = '+';
		}
		else if (button[2][10] == '+') {
			button[2][10] = '@';
		}
		if (button[1][8] == '@') {
			button[1][8] = '+';
		}
		else if (button[1][8] == '+') {
			button[1][8] = '@';
		}
		if (button[3][8] == '@') {
			button[3][8] = '+';
		}
		else if (button[3][8] == '+') {
			button[3][8] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "7") == 0) {
		if (button[2][2] == '@') {
			button[2][2] = '+';
		}
		else if (button[2][2] == '+') {
			button[2][2] = '@';
		}
		if (button[2][6] == '@') {
			button[2][6] = '+';
		}
		else if (button[2][6] == '+') {
			button[2][6] = '@';
		}
		if (button[4][6] == '@') {
			button[4][6] = '+';
		}
		else if (button[4][6] == '+') {
			button[4][6] = '@';
		}
		if (button[3][4] == '@') {
			button[3][4] = '+';
		}
		else if (button[3][4] == '+') {
			button[3][4] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "8") == 0) {
		if (button[2][10] == '@') {
			button[2][10] = '+';
		}
		else if (button[2][10] == '+') {
			button[2][10] = '@';
		}
		if (button[2][6] == '@') {
			button[2][6] = '+';
		}
		else if (button[2][6] == '+') {
			button[2][6] = '@';
		}
		if (button[4][6] == '@') {
			button[4][6] = '+';
		}
		else if (button[4][6] == '+') {
			button[4][6] = '@';
		}
		if (button[3][8] == '@') {
			button[3][8] = '+';
		}
		else if (button[3][8] == '+') {
			button[3][8] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "9") == 0) {
		if (button[3][4] == '@') {
			button[3][4] = '+';
		}
		else if (button[3][4] == '+') {
			button[3][4] = '@';
		}
		if (button[4][6] == '@') {
			button[4][6] = '+';
		}
		else if (button[4][6] == '+') {
			button[4][6] = '@';
		}
		if (button[3][8] == '@') {
			button[3][8] = '+';
		}
		else if (button[3][8] == '+') {
			button[3][8] = '@';
		}
		button_sound();
	}
	else if (strcmp(num, "0") == 0) {
		button[0][6] = '@';
		button[1][4] = '+';
		button[1][8] = '+';
		button[2][2] = '@';
		button[2][6] = '@';
		button[2][10] = '@';
		button[3][4] = '+';
		button[3][8] = '+';
		button[4][6] = '@';
		initialization();
	}
	else{
		for (int i = 0; i < 31; i++) {
			printf("%c", error[i]);
			if ((i % 2) == 1)
				typing_sound();
		}
		Sleep(1000);

	}
}
void check_green(void) {
	int check_green;
	check_green = 0;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 15; k++) {
			if (button[i][k] == '+')
				check_green++;
		}
	}
	if (check_green == 9)
		gameclear = true;
}
void button_puzzle(void) {
	button_puzzle_first_title();
	while (gameclear == false) {
		viewbutton();
		chose_num();
		check_green();
		system("cls");
	}
	viewbutton();
}
// 


void Script_func_n(void) {
	char Script_n[] = "정답입니다. 다음 테스트를 시작합니다.";
	printf("\n\n");
	for (int i = 0; i < 38; i++) {
		if (i == 12) {
			Sleep(200);
		}
		printf("%c", Script_n[i]);
		robot_sound();
	}
	pressanykey();
	system("cls");
	
}
void Script_func_1(void) {
	gotoxy(30, 20);
	char Script_1[] = "(........)";
	printf("\n\n");
	for (int i = 0; i <sizeof(Script_1); i++) {
		if (i == 8) {
			Sleep(200);
		}
		printf("%c", Script_1[i]);
		if (i % 2 == 0)
			beep_male(200);
		else
			Sleep(200);
	}
	Sleep(500);
	
	printf("\n[아무키나 입력]");
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_2[] = "(..........여기가 어디지?)";
	printf("\n\n");
	for (int i = 0; i < 27; i++) {
		if (i == 12) {
			Sleep(300);
		}
		printf("%c", Script_2[i]);
		if ( i <= 11)
			beep_male(150);
		else if( i > 11)
			beep_male(90);
		else
			Sleep(150);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_3[] = "인공지능 강화 센터의 테스트에 “자원” 해주신분들에게 감사의 말씀을 드립니다.";
	printf("\n\n");
	for (int i = 0; i < 78; i++) {
		if (i == 8) {
			Sleep(200);
		}
		if (i == 32) {
			Sleep(200);
		}
		if (i == 38) {
			Sleep(200);
		}
		printf("%c", Script_3[i]);
		if (i % 2 == 0)
			robot_sound();
	}
	pressanykey();
	system("cls");


	gotoxy(30, 20);
	char Script_4[] = "잠시 휴식을 취하시는 동안 편안하셨기를 바랍니다.";
	printf("\n\n");
	for (int i = 0; i < 49; i++) {
		if (i == 27) {
			Sleep(200);
		}
		printf("%c", Script_4[i]);
		if (i % 2 == 0)
			robot_sound();
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_5[] = "(무슨소리를 하는거지... 머릿속이 뒤죽박죽이다....)";
	printf("\n\n");
	for (int i = 0; i < 51; i++) {
		if (i == 24) {
			Sleep(200);
		}
		printf("%c", Script_5[i]);
		if (i % 2 == 0)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_6[] = "잠시후 테스트가 시작될 예정입니다.";
	printf("\n\n");
	for (int i = 0; i < 35; i++) {
		printf("%c", Script_6[i]);
		if (i % 2 == 0)
			robot_sound();
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_7[] = "저기... 저는 왜 여기 있는거죠?";
	printf("\n\n");
	for (int i = 0; i < 31; i++) {
		if (i == 8) {
			Sleep(200);
		}
		printf("%c", Script_7[i]);
		if (i % 2 == 0)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_8[] = "원활한 테스트 환경을 위해 본 인공지능은 피실험자와 상호작용을 최소화 하고 있습니다.";
	printf("\n\n");
	for (int i = 0; i < 84; i++) {
		if (i == 25) {
			Sleep(200);
		}
		printf("%c", Script_8[i]);
		if (i % 2 == 0)
			robot_sound();
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_9[] = "(지금 말하고 있는게... 인공지능이라고?)";
	printf("\n\n");
	for (int i = 0; i < 40; i++) {
		if (i == 22) {
			Sleep(200);
		}
		printf("%c", Script_9[i]);
		if (i % 2 == 0)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_10[] = "지금부터 테스트를 시작하겠습니다.";
	printf("\n\n");
	for (int i = 0; i < 34; i++) {
		printf("%c", Script_10[i]);
		if (i % 2 == 0)
			robot_sound();
	}
	pressanykey();
	system("cls");

	Sleep(1500);

}


// 그림 퍼즐 관련 코드
void picture_puzzle_first_title(void){
printf("                 ");
ColorSet(4, 7);
char button_puzzle_title[] = "Object  :   Find password";
for (int i = 0; i < 27; i++) {
	printf("%c", button_puzzle_title[i]);
	typing_sound();
	if (i == 8 || i == 12)
		Sleep(100);
}
printf("\n\n");
Sleep(1000);
ColorSet(0, 0);
}
void view_picture_puzzle(void) {
	printf("                 ");
	ColorSet(4, 7);
	printf("Object  :   Find password");
	ColorSet(0, 0);
	printf("\n\n");
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 18; k++) {
				if (picture_puzzle_1[i][k] == '+') {
					ColorSet(2, 2);
				}
				if (picture_puzzle_1[i][k] == '-') {
					ColorSet(7, 7);
				}
				if (picture_puzzle_1[i][k] == '#') {
					ColorSet(1, 1);
				}
				printf("%c", picture_puzzle_1[i][k]);
			}
		}
		ColorSet(0, 7);
		printf("\n\n");
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 18; k++) {
				if (picture_puzzle_2[i][k] == '+') {
					ColorSet(3, 3);
				}
				if (picture_puzzle_2[i][k] == '-') {
					ColorSet(7, 7);
				}
				if (picture_puzzle_2[i][k] == '#') {
					ColorSet(1, 1);
				}
				printf("%c", picture_puzzle_1[i][k]);
			}
		}
		ColorSet(0, 7);

}
void check_picture_puzzle_answer(void) { 
	char answer[30];
	char answer_script[] = "정답입니다. 다음 테스트를 시작합니다.";
	char incorrect_script[] = "오답입니다. 다시 입력해주세요";
	printf("\n\n\n\n password :");
	scanf_s("%s",answer,sizeof(answer));
	//답은 숫자지만 문자를 입력할경우 버그발생 때문에 문자열 비교함수 사용 
	if (strcmp(answer,"42")==0) { 
		printf("\n");
		for (int i = 0; i < 38; i++) {
			if (i == 12) {
				Sleep(100);
			}
			printf("%c", answer_script[i]);
			robot_sound();
		}
	gameclear = true;
	system("cls");
}
	else {
		printf("\n");
	for (int i = 0; i < 30; i++) {
		if (i == 12) {
			Sleep(150);
		}
		printf("%c", incorrect_script[i]);
		robot_sound();
	}
	Sleep(300);
	system("cls");
	}
}
void picture_puzzle(void) {
	picture_puzzle_first_title();
	gameclear = false;
	while (gameclear == false) {
		SetConsoleView();
		view_picture_puzzle();
		check_picture_puzzle_answer();
		system("cls");
	}
}
// 그림 퍼즐 관련 코드




int main(void) {
	system("mode con:cols=85 lines=30");
	playingBgm_3(true);
	Script_func_1();
	SetConsoleView();
	playingBgm_3(false);
	playingBgm_1(true);
	button_puzzle();
	Script_func_n();
	picture_puzzle();

	printf("미완성");
	pressanykey();



	return 0;
}

// ?????
void 하나(void)
{
#define  three
	printf("4");
	bool blue  = false;
}