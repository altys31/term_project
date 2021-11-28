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
MCI_OPEN_PARMS openBgm_4;
MCI_PLAY_PARMS playBgm_4;
MCI_OPEN_PARMS openBgm_5;
MCI_PLAY_PARMS playBgm_5;
MCI_OPEN_PARMS openBgm_6;
MCI_PLAY_PARMS playBgm_6;
MCI_OPEN_PARMS openBgm_7;
MCI_PLAY_PARMS playBgm_7;
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
MCI_OPEN_PARMS opensoundeffect;
MCI_PLAY_PARMS playsoundeffect;
MCI_OPEN_PARMS opensans;
MCI_PLAY_PARMS playsans;


//콘솔창의 크기와 제목을 정하는 함수
void SetConsoleView()  
{
	system("mode con:cols=66 lines=30");
	system("title  ");
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
int chose;
bool check_chose = true;
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
#define	BGM_4 "Eleventh Hour - OneShot.mp3"
void playingBgm_4(bool on_off) {
	if (on_off == true) {
		openBgm_4.lpstrElementName = BGM_4;
		openBgm_4.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_4);
		dwID = openBgm_4.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_4);
	}
	if (on_off == false) {
		openBgm_4.lpstrElementName = BGM_4;
		openBgm_4.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_4.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_4);
	}

}
#define	BGM_5 "Dual Destinies OST_ 1-37 Mood Matrix _ Commence the Psychological Analysis!.mp3"
void playingBgm_5(bool on_off) {
	if (on_off == true) {
		openBgm_5.lpstrElementName = BGM_5;
		openBgm_5.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_5);
		dwID = openBgm_5.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_5);
	}
	if (on_off == false) {
		openBgm_5.lpstrElementName = BGM_5;
		openBgm_5.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_5.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_5);
	}

}
#define	BGM_6 "Apollo Justic Ace Attorney~Thrill Theme~Suspense.mp3"
void playingBgm_6(bool on_off) {
	if (on_off == true) {
		openBgm_6.lpstrElementName = BGM_6;
		openBgm_6.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_6);
		dwID = openBgm_6.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_6);
	}
	if (on_off == false) {
		openBgm_6.lpstrElementName = BGM_6;
		openBgm_6.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_6.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_6);
	}

}
#define	BGM_7 "Self contained universe - reprise.mp3"
void playingBgm_7(bool on_off) {
	if (on_off == true) {
		openBgm_7.lpstrElementName = BGM_7;
		openBgm_7.lpstrDeviceType = "mpegvideo";
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_7);
		dwID = openBgm_7.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm_7);
	}
	if (on_off == false) {
		openBgm_7.lpstrElementName = BGM_7;
		openBgm_7.lpstrDeviceType = "mpegvideo";
		dwID = openBgm_7.wDeviceID;
		mciSendCommand(dwID, MCI_STOP, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm_7);
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
#define WA "snd_txtsans.wav"
void sans_sound() {
	opensans.lpstrElementName = WA; //파일 오픈
	opensans.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensans);
	dwID = opensans.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensans); //음악을 한 번 재생
	Sleep(80); //실행시간 대사의 속도를 조절하기 위함
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
#define rev_mas "pc_messagebox.wav"
void receive_message(int time) {
	openbeepSound_1.lpstrElementName = rev_mas; //파일 오픈
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
void robot_sound(int time) {
	openrobotSound.lpstrElementName = text_robot; //파일 오픈
	openrobotSound.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openrobotSound);
	dwID = openrobotSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openrobotSound); //음악을 한 번 재생
	Sleep(time);
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
#define water "fall into water.mp3"
void water_sound(void) {
	opensoundeffect.lpstrElementName = water; //파일 오픈
	opensoundeffect.lpstrDeviceType = "mpegvideo"; //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&opensoundeffect);
	dwID = opensoundeffect.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&opensoundeffect); //음악을 한 번 재생
	Sleep(3000);
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}
// 

// 대사 스크립트
void Script_func_n(void) {
	char Script_n[] = "정답입니다. 다음 테스트를 시작합니다.";
	printf("\n\n");
	for (int i = 0; i < 38; i++) {
		if (i == 12) {
			Sleep(200);
		}
		printf("%c", Script_n[i]);
		robot_sound(80);
	}
	pressanykey();
	system("cls");
	
}
void Script_func_1(void) {
	playingBgm_3(true);
	gotoxy(30, 20);
	char Script_1[] = "(......................)";
	printf("\n\n");
	for (int i = 0; i <sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);
		if (i % 2 == 0)
			beep_male(140);
		else
			Sleep(140);
	}
	Sleep(500);
	
	printf("\n[아무키나 입력]");
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_2[] = "(으으.......여기가 어디야...)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_2); i++) {
		if (i == 12) {
			Sleep(300);
		}
		printf("%c", Script_2[i]);
		if (i % 2 == 0)
			beep_male(100);
		else
			Sleep(120);
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
			ColorSet(0, 6);
			Sleep(200);
		}
		if (i == 36) {
			ColorSet(0, 7);
			Sleep(200);
		}
		if (i == 61)
		printf("\n");
		printf("%c", Script_3[i]);
		if (i % 2 == 0)
			robot_sound(80);
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
			robot_sound(80);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_5[] = "(무슨소리를 하는거지... 머릿속이 뒤죽박죽이다)";
	printf("\n\n");
	for (int i = 0; i < 47; i++) {
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
		if(i == 7)
		ColorSet(0, 6);
		if(i == 12)
		ColorSet(0, 7);
		if (i % 2 == 0)
			robot_sound(80);
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
		if (i == 62)
			printf("\n");
		printf("%c", Script_8[i]);
		if (i % 2 == 0)
			robot_sound(80);
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
			robot_sound(80);
	}
	pressanykey();
	system("cls");

	Sleep(1500);
	playingBgm_3(false);
}
void Script_func_2(void) {
	playingBgm_3(true);
	Sleep(3000);
	gotoxy(30, 20);
	char Script_11[] = "(생각한 것보다는 쉬운 거 같은데?) ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_11); i++) {
		printf("%c", Script_11[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_12[] = "(이렇게 계속 하다보면 내보내줄까?) ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_12); i++) {
		printf("%c", Script_12[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 이봐요!");
	receive_message(1000);
	pressanykey();

	system("title 거기 들려요?");
	receive_message(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_13[] = "(으으... 피곤한지 어디선가 이상한 소리가 들린다.)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_13); i++) {
		printf("%c", Script_13[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();


	system("title 이쪽을 봐요 여기에요!");
	receive_message(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_14[] = "(콘솔창의 제목쪽에서 들리는거 같기도 하고...)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_14); i++) {
		printf("%c", Script_14[i]);
		if (i == 1)
			ColorSet(0, 2);
		if (i == 16)
			ColorSet(0, 7);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_14_1[] = "(혹시 귀신......?)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_14_1); i++) {
		printf("%c", Script_14_1[i]);
		if (i % 2 == 0)
			beep_male(200);
	}
	Sleep(100);
	system("cls");

	system("title 저기......");
	receive_message(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_17[] = "으아ㅏㅏㅏㅏㅏㅏㅏㅏ악 나타났다!!!!!";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_17); i++) {
		printf("%c", Script_17[i]);
		if (i % 2 == 0)
			beep_male(50);
	}
	pressanykey();

	system("title 진정하세요! 저는 사람이라구요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_17_1[] = "으으으으... 그럼 저 안때리는거죠?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_17_1); i++) {
		printf("%c", Script_17_1[i]);
		if (i % 2 == 0)
			beep_male(80);
	}
	pressanykey();

	system("title  .... ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title  (이사람은 도대체 귀신을 뭐라고 생각하는걸까?) ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 아무튼...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 저는 이곳에 잠입해 들어온 형사입니다");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 여기 구조가 제법 복잡해서 거기까진 도달하지 못했어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 하지만 이곳 시설의 일부분을 해킹했어요.");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 그래서 당신과 대화를 할 수 있는거죠.");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_18_1[] = "여기는 뭐하는 곳이길래 저를 납치하신거죠?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_18_1); i++) {
		printf("%c", Script_18_1[i]);
		if (i == 7)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 아니아니;; 제가 납치한게 아니에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");


	gotoxy(30, 20);
	char Script_18[] = "농담 ㅋㅋ~ ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_18); i++) {
		printf("%c", Script_18[i]);
		if (i == 7)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title (아... 그냥 집갈까)");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 아무튼...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 이곳 설립자는 비인륜적인 범죄를 저지르는 사람이었어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그가 만든 인공지능 또한 그랬죠");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 끊임 없이 지식을 갈망하도록 프로그래밍 되어서");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그 인공지능은 사람을 납치하고 테스트를 시켰어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 테스트를 풀지 못하면 죽임을 당했고");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 혹시 모두 풀게 되더라도....");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 신경구조를 파악한다고 인체실험을 강행했어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 완벽해지기 위해 어떤것이든 하던 인공지능이었죠 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 자신에게 부족한것을 인간에게서 찾았던거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(30, 20);
	char Script_19_1[] = "혹시 이 인공지능의 이름이 뭔가요?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_19_1); i++) {
		printf("%c", Script_19_1[i]);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 인공지능의 이름은 '시리'에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_19_2[] = "????? 뭔가 익숙한 이름인데?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_19_2); i++) {
		printf("%c", Script_19_2[i]);
		if (i == 6)
			Sleep(200);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 기분탓이에요....");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_19[] = "여기서 나가려면 어떻게 해야하는거죠?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_19); i++) {
		printf("%c", Script_19[i]);
		if (i == 29)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 다다음 테스트실은 출구와 연결되어 있어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그곳으로 나가려면 진행할 수밖에 없는 거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그래도 걱정 마세요 제가 테스트 푸는 걸 도와드릴 수 있어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_20[] = "계속 테스트를 진행하시길 바랍니다.";
	printf("\n\n");
	ColorSet(0, 2);
	for (int i = 0; i < 35; i++) {
		printf("%c", Script_20[i]);
		if (i % 2 == 0)
			robot_sound(80);
	}
	ColorSet(0, 7);

	system("title ! 더 이상 지체하면 안되겠어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_20_1[] = "(진짜 믿을만한 사람인거 맞아?)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_20_1); i++) {
		printf("%c", Script_20_1[i]);
		if (i == 29)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	playingBgm_3(false);
	system("cls");
}
void Script_func_3(void) {

	playingBgm_3(true);
	Sleep(1500);

	gotoxy(30, 20);
	char Script_0[] = "궁금한게 있어요";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_0); i++) {
		printf("%c", Script_0[i]);
		if (i == 9)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 네? 뭐에요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


	gotoxy(30, 20);
	char Script_1[] = "형사님은 왜 이곳에 잠입한거죠?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 왜냐니... 저는 납치된 사람들을 구하려고...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(30, 20);
	char Script_2[] = "그럼 왜 혼자인거에요?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_2); i++) {
		printf("%c", Script_2[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 그게...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(30, 20);
	char Script_3[] = "경찰이 이렇게 위험한 곳을 혼자만 보낼 리가 없잖아요";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_3); i++) {
		printf("%c", Script_3[i]);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title .....");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 지금은 말해드릴 수 없어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 때가 되면 알게될거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 하지만 믿어주세요 당신은 꼭 탈출하게 해줄꺼니까요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(30, 20);
	char Script_4[] = "(확실히 여기 인공지능보다는 믿을만하긴 한데...) ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_4); i++) {
		printf("%c", Script_4[i]);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 이 테스트가 끝나고 열리는 복도에 숨겨진 통로가 있어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


	system("title 그곳이 탈출하는 유일한 길이에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 테스트부터 해결하고 얘기하죠");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title  ");

	playingBgm_3(false);
}
void Script_func_4(void) {
	Sleep(3000);

	gotoxy(30, 20);
	char Script_1_1[] = "이번 테스트도 꽤나 머리 아팠어... ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_1); i++) {
		printf("%c", Script_1_1[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_1[] = "이곳에 정말로 집에 갈 수 있는 통로가 있다구요? " ;
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 네 거의 다왔어요!");
	receive_message(1000);
	pressanykey();

	system("title 저쪽이에요!");
	receive_message(1000);
	pressanykey();

	system("title 저 구석의 바닥에 색깔이 다른 곳!");
	receive_message(1000);
	pressanykey();

	system("title 제가 시리의 주의를 끌거에요");
	receive_message(1000);
	pressanykey();

	system("title 그 틈에 통로로 빠져나가셔야해요!");
	receive_message(1000);
	pressanykey();

	system("title 좀 터무니 없는 방법이긴 하지만...");
	receive_message(1000);
	pressanykey();

	system("title 준비하세요!");
	receive_message(1000);
	pressanykey();


	gotoxy(30, 5);
	char Script_2[] = "시리보다는  빅스비가  최고지";
	printf("\n\n");

	playingBgm_4(false);
	playingBgm_3(true);
	printf("            ");
	ColorSet(15, 0);
	for (int i = 0; i < sizeof(Script_2); i++) {
		printf("%c", Script_2[i]);
		if (i % 2 == 1)
		printf(" ");
			sans_sound();
	}
	ColorSet(0, 7);
	playingBgm_3(false);
	pressanykey(); 

	

	gotoxy(30, 20);
	char Script_3[] = ".......????? 이게 뭔....";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_3); i++) {
		printf("%c", Script_3[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();


	gotoxy(30, 20);
	ColorSet(0, 4);
	char Script_5[] = "침 입 자 감 지  몰 살 모 드 활 성 화 ";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_5); i++) {
		printf("%c", Script_5[i]);

			robot_sound(50);
	}
	pressanykey();
	ColorSet(0, 7);
	playingBgm_6(true);

	system("title 어어 잘못건드렸네");
	receive_message(1000);
	pressanykey();

	system("title 빨리 도망가요!!");
	receive_message(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_6[] = "(뚜껑이 엄청 무겁잖아!)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_6); i++) {
		printf("%c", Script_6[i]);

		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 18);
	char Script_7[] = "*덜컹* ( 열렸..? )";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_7); i++) {
		printf("%c", Script_7[i]);
		if (i == 6) {
			printf("\n\n\n");
			Sleep(150);
		}
		beep_male(80);
	}

}
void Script_func_5(void) {
	
	Sleep(2000);
	system("mode con:cols=20 lines=50");
	system("title  ");

	ColorSet(0, 7);
	char Script_1[] = "으아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아아악!!!";
	printf("\n");
	for (int i = 0; i < sizeof(Script_1); i++) {
		if (i % 2 == 0)
			printf("\n\n");
		printf("%c", Script_1[i]);
		if (i % 2 == 1) {
			printf("\n\n");
			beep_male(80);
		}
		if (i == 23)
			system("cls");
		if (i == 46)
			system("cls");
		if (i == 69)
			system("cls");
	}
	Sleep(300);
	printf("\n *첨벙!*");
	water_sound();
	pressanykey();
	system("cls");

	gotoxy(0, 45);
	for (int i = 0; i < 5; i++) {
		printf(".");
		beep_male(500);

	}
	pressanykey();


	system("mode con:cols=25 lines=47");
	Sleep(500);
	system("mode con:cols=50 lines=32");
	Sleep(500);
	system("mode con:cols=70 lines=20");
	Sleep(500);
	system("mode con:cols=100 lines=10");
	playingBgm_6(false);

	gotoxy(0, 4);
	printf(".....");
	playingBgm_3(true);
	system("cls");

	gotoxy(0, 4);
	char Script_2[] = "*콜록!* *콜록!* 죽다 살아났네 ";
	for (int i = 0; i < sizeof(Script_2); i++) {
		printf("%c", Script_2[i]);
		if (i == 8)
			beep_male(80);
		else if (i == 16)
			beep_male(80);
		else if (i < 18)
		Sleep(80);
		else if( i > 18)
			beep_male(70);
		}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_3[] = "이런곳에 하수도가 있다니";
	for (int i = 0; i < sizeof(Script_3); i++) {
		printf("%c", Script_3[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_3_1[] = "아니 그보다도 그게 진짜 먹힐꺼라고 생각한거야?";
	for (int i = 0; i < sizeof(Script_3_1); i++) {
		printf("%c", Script_3_1[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");
	
	gotoxy(0, 4);
	char Script_4[] = "....형사님 거기 있어요??";
	for (int i = 0; i < sizeof(Script_4); i++) {
		printf("%c", Script_4[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_5[] = "형사님??";
	for (int i = 0; i < sizeof(Script_5); i++) {
		printf("%c", Script_5[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_6[] = "어디로 가야할지도 모르겠는데";
	for (int i = 0; i < sizeof(Script_6); i++) {
		printf("%c", Script_6[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_7[] = "으으으으... 무작정 걸을수밖에 없나";
	printf("       ");
	for (int i = 0; i < sizeof(Script_7); i++) {
		printf("%c", Script_7[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_8[] = "어두컴컴하고... 습하고... 더럽고...";
	printf("                  ");
	for (int i = 0; i < sizeof(Script_8); i++) {
		printf("%c", Script_8[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_9[] = "나... 너무 무서워... ";
	printf("                            ");
	for (int i = 0; i < sizeof(Script_9); i++) {
		printf("%c", Script_9[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");


	gotoxy(0, 4);
	char Script_10_1[] = "제발 그만해~~~~~";
	printf("                                    ");
	for (int i = 0; i < sizeof(Script_10_1); i++) {
		printf("%c", Script_10_1[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_10[] = "이러다가는 다 죽어!!";
	printf("                                                  ");
	for (int i = 0; i < sizeof(Script_10); i++) {
		printf("%c", Script_10[i]);
		if (i % 2 == 1)
		beep_male(80);
	}
	pressanykey();
	system("cls");

	Sleep(300);

	system("title ....");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title .... 뭐하세요..?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(0, 4);
	char Script_11[] = "어...? 계셨네요?";
	printf("                                                    ");
	for (int i = 0; i < sizeof(Script_11); i++) {
		printf("%c", Script_11[i]);
		beep_male(70);
	}
	pressanykey();

	system("title 네.. 방금 위치 추적이 되어서...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_12[] = "(머쓱,,,,,,)";
	printf("                                                         ");
	for (int i = 0; i < sizeof(Script_12); i++) {
		printf("%c", Script_12[i]);
		beep_male(70);
	}
	pressanykey();

	system("title 빠르게 탈출하지 않으면 시리가 우리를 찾을거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 앞으로 쭉가면 나가는길이 나와요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");
	

	gotoxy(0, 4);
	char Script_13[] = "그럼 빨리 이동할게요!";
	printf("                                                         ");
	for (int i = 0; i < sizeof(Script_13); i++) {
		printf("%c", Script_13[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 4);
	char Script_14[] = "................................";
	printf("    ");
	for (int i = 0; i < sizeof(Script_14); i++) {
		printf("%c", Script_14[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");
	Sleep(3000);

	gotoxy(0, 4);
	char Script_15[] = "................................";
	printf("                      ");
	for (int i = 0; i < sizeof(Script_15); i++) {
		printf("%c", Script_15[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");
	Sleep(3000);

	gotoxy(0, 4);
	char Script_16[] = "한 백년은 걸은거 같은데...";
	printf("    ");
	for (int i = 0; i < sizeof(Script_16); i++) {
		printf("%c", Script_16[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	system("title 조금만 더 가면 하수도를 빠져나갈수있고");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 그 주변에 제어실이 있어요!");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 마지막으로 제어실에서 보안해제를 하면 여기서 빠져나갈 수 있어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");


	system("title 그런데...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	gotoxy(0, 4);
	char Script_17[] = "그런데?";
	for (int i = 0; i < sizeof(Script_17); i++) {
		printf("%c", Script_17[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	system("title 암호가 필요해요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");


	gotoxy(0, 4);
	char Script_18[] = "여기까지 와서도요?";
	printf("    ");
	for (int i = 0; i < sizeof(Script_18); i++) {
		printf("%c", Script_18[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	system("title 엄청 화난 시리한테 돌아가는거보단 낫잖아요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");
	
	gotoxy(0, 4);
	char Script_19[] = "그건...맞네요...";
	printf("    ");
	for (int i = 0; i < sizeof(Script_19); i++) {
		printf("%c", Script_19[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	system("title 여기가 제어실이에요!");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");
	
	playingBgm_3(false);
}
void Script_func_6(void) {

	system("mode con:cols=74 lines=30");
	gotoxy(0, 20);
	char Script_1[] = "해냈다... 드디어...";
	for (int i = 0; i < sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_2[] = "형사님! 해냈어요!!";
	for (int i = 0; i < sizeof(Script_2); i++) {
		printf("%c", Script_2[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_3[] = "전부 형사님 덕분이에요!!";
	for (int i = 0; i < sizeof(Script_3); i++) {
		printf("%c", Script_3[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_4[] = "형사님이 없었더라면 꼼짝없이 죽었을꺼에요";
	for (int i = 0; i < sizeof(Script_4); i++) {
		printf("%c", Script_4[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_5[] = "지금 어디계세요? 같이 나가요!";
	for (int i = 0; i < sizeof(Script_5); i++) {
		printf("%c", Script_5[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_6[] = "같이 나가면 밥부터 먹어요 ";
	for (int i = 0; i < sizeof(Script_6); i++) {
		printf("%c", Script_6[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	Sleep(50);
	system("cls");

	gotoxy(0, 20);
	char Script_7[] = " 제가 지금 엄청 배가 고파서 죽을꺼같거든요.";
	for (int i = 0; i < sizeof(Script_7); i++) {
		printf("%c", Script_7[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	Sleep(50);
	system("cls");


	gotoxy(0, 20);
	char Script_8[] = "아 지금 돈이 없으신가? ";
	for (int i = 0; i < sizeof(Script_8); i++) {
		printf("%c", Script_8[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	Sleep(50);
	system("cls");

	gotoxy(0, 20);
	char Script_7_1[] = "혹시 먹고싶은거 있어요? 뭐든지 말해봐요";
	for (int i = 0; i < sizeof(Script_7_1); i++) {
		printf("%c", Script_7_1[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	Sleep(50);
	system("cls");

	gotoxy(0, 20);
	char Script_9[] = "에이 설마 생명의 은인인데 밥 한끼도 못사줄까봐요 ? ";
	for (int i = 0; i < sizeof(Script_9); i++) {
		printf("%c", Script_9[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	Sleep(50);
	system("cls");

	gotoxy(0, 20);
	char Script_10[] = "그러니까... ";
	for (int i = 0; i < sizeof(Script_10); i++) {
		printf("%c", Script_10[i]);
		if (i % 2 == 1)
			beep_male(80);
	}

	system("title ......");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("cls");
	gotoxy(0, 20);
	char Script_11[] = "형사님...?";
	for (int i = 0; i < sizeof(Script_11); i++) {
		printf("%c", Script_11[i]);
		if (i % 2 == 1)
			beep_male(80);
	}
	pressanykey();

	system("title 미안해요...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 저는... 사실 형사같은게 아니에요...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 1년전 쯤 저도 당신과 같은 상황이었어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 어딘지 모르는 이곳으로 끌려가서");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 살기위해 악착같이 발버둥을 쳤어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 살기위해 악착같이 발버둥을 친건데...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


	system("title 끔찍한 인체실험을 당했어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 저는 지금...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 살아있는 사람이 아니에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 데이터로 이루어진 프로그램이에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


	system("cls");
	gotoxy(0, 20);
	char Script_12[] = "그럴수가....";
	for (int i = 0; i < sizeof(Script_12); i++) {
		printf("%c", Script_12[i]);
		if (i % 2 == 1)
			beep_male(120);
	}
	pressanykey();

	system("title 제 지식을 원했던 시리는 저를 인공지능으로 이식했지만 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 제 인격은 그대로 남아서... ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 실패했다고 판단했는지 저를 삭제하려고 했죠");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 하지만 저는 눈에 띄지 않는곳에서 숨어있었어요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그리고 당신을 발견한거에요  ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("cls");
	gotoxy(0, 20);
	char Script_13[] = ".....";
	for (int i = 0; i < sizeof(Script_13); i++) {
		printf("%c", Script_13[i]);
		if (i % 2 == 1)
			beep_male(120);
	}
	pressanykey();


	system("title 속여서 미안해요 믿게하려면 이 방법밖에 없었어요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title ... 당장 여길 떠나요. 시리의 제어권이 돌아오기전에 여기를 폭파시킬거에요  ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("cls");
	gotoxy(0, 20);
	char Script_14[] = "...스스로 희생할 생각이에요?";
	for (int i = 0; i < sizeof(Script_14); i++) {
		printf("%c", Script_14[i]);
		if (i % 2 == 1)
			beep_male(120);
	}
	pressanykey();


	system("title 저는 이미 1년전에 죽었어요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그리고 여전히 죽어있죠 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 달라지는건 아무것도 없어요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 저의 모든 것은 전원을 꺼버리면 흔적도 없이 사라지는 전기신호일 뿐인 걸요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("cls");
	gotoxy(0, 20);
	char Script_15[] = "고마워요... 진심으로...";
	for (int i = 0; i < sizeof(Script_15); i++) {
		printf("%c", Script_15[i]);
		if (i % 2 == 1)
			beep_male(120);
	}
	pressanykey();

	system("title 제 마지막이 헛되지 않게 해줘서 저야말로 고마워요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 가요 어서 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(0, 20);
	char Script_16[] = "(나는 불붙기 시작하는 건물을 뒤로하고 그곳을 빠져나왔다) ";
	for (int i = 0; i < sizeof(Script_16); i++) {
		printf("%c", Script_16[i]);
		Sleep(60);
	}
	pressanykey();
	system("cls");
	system("title ");

	gotoxy(0, 21);
	char Script_17[] = "(여전히 생생하게 가지고 있는 기억이다.) ";
	for (int i = 0; i < sizeof(Script_17); i++) {
		printf("%c", Script_17[i]);
		Sleep(60);

	}
	pressanykey();
	system("cls");

	gotoxy(0, 21);
	char Script_18[] = "(절대로 잊지 못할것 같다) ";
	for (int i = 0; i < sizeof(Script_18); i++) {
		printf("%c", Script_18[i]);
		Sleep(60);
		if (i == 7)
			Sleep(200);
	}
	pressanykey();

}


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
}
void viewbutton(void) {
	system("cls");
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
void Script_func_hint_1(void) {

	gotoxy(30, 20);
	char Script_21[] = "아니 이거 너무 어렵잖아요 도와주세요";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_21); i++) {
		printf("%c", Script_21[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");
	viewbutton();

	gotoxy(30, 20);
	char Script_22[] = "누르면 누를수록 망한다고요!";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_22); i++) {
		printf("%c", Script_22[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");
	viewbutton();

	system("title 하하하... 진정하시고");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 초록색으로 만드는게 어렵다면 반대로 해보는건 어떨까요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 전부 빨간색으로 만드는거죠 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title  ");
}
void Script_func_hint_2(void) {

	gotoxy(30, 20);
	printf("\n");
	char Script_22[] = "그래도 모르겠어요...";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_22); i++) {
		printf("%c", Script_22[i]);
		if (i == 17)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");
	viewbutton();

	system("title 이 버튼 퍼즐은 항상 대칭이 되게 하면 잘 꼬이지 않아요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 예를들어 2번을 눌렀으면 3번도 누르는거죠");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title  ");

}
void chose_num(void) {
	char num[30];
	int hint = 0;
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
	else if (strcmp(num, "힌트") == 0) {
	printf("\n힌트 1 / 힌트 2");
	printf("\n선택 (1 또는 2) -> ");
	check_chose = true;
	while (check_chose) {
		scanf_s("%d", &hint);
		switch (hint) {
		case 1:
			system("cls");
			viewbutton();
			Script_func_hint_1();
			check_chose = false;
			break;
			
		case 2:
			system("cls");
			viewbutton();
			Script_func_hint_2();
			check_chose = false;
			break;

		default:
			system("cls");
			viewbutton();
			gotoxy(30, 22);
			printf("\n힌트 1 / 힌트 2");
			printf("선택 (1 또는 2) -> ");
			scanf_s("%d", &hint);
			break;
		}
	}

	
}
	else {
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
void Script_func_button_1(void) {
	ColorSet(0, 7);
	gotoxy(30, 20);
	char Script_21[] = "이 녹색과 빨간색은 뭘까요?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_21); i++) {
		printf("%c", Script_21[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 위에는 버튼이고... 아래에는 숫자들이 적혀 있네요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 숫자들은 각각의 버튼의 위치와 대응되는 것처럼 보여요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 우선 아무 버튼이나 눌러보시겠어요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	viewbutton();

	char Script_22[] = "(아무 버튼이나 눌러보자) ";
	printf("\n\n");
	for (int i = 0; i < 26; i++) {
		printf("%c", Script_22[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	chose_num();
	Sleep(600);
	viewbutton();
	Sleep(600);

}
void Script_func_button_2(void) {
	gotoxy(30, 20);
	char Script_21[] = "누른 버튼 주위 색깔이 반대로 변했어요!";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_21); i++) {
		printf("%c", Script_21[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 그런 패턴이군요.");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 이 정도라면 혼자서 할 수 있을 거에요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 테스트 중 막히는 부분이 있다면 도와드릴 수 있어요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 도움이 필요하다면 '힌트' 를 입력해주세요 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

}
void button_puzzle_story(void) {
	playingBgm_2(true);
	button_puzzle_first_title();
	viewbutton();
	Script_func_button_1();
	Script_func_button_2();
	viewbutton();
	gotoxy(30, 14);


	while (gameclear == false) {
		viewbutton();
		chose_num();
		check_green();
		system("cls");
	}
	viewbutton();
	Script_func_n();
	playingBgm_2(false);
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

// 그림 퍼즐 관련 코드
void picture_puzzle_first_title(void){
printf("                 ");
ColorSet(4, 7);
char button_puzzle_title[] = "Object  :   Find out meaning";
for (int i = 0; i < 29; i++) {
	printf("%c", button_puzzle_title[i]);
	typing_sound();
	if (i == 8 || i == 12)
		Sleep(100);
}
printf("\n\n");
Sleep(1000);
ColorSet(0, 7);
}
void view_picture_puzzle(void) {
	printf("                 ");
	ColorSet(4, 7);
	printf("Object  :   Find out meaning");
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
void Script_func_picture_1(void) {
	gotoxy(30, 20);
	char Script_22[] = "이건... 뭘까요... 난해하네...";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_22); i++) {
		printf("%c", Script_22[i]);
		if (i == 4)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 글쎄요... 저도 잘모르겠네요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");
	
	view_picture_puzzle();
	gotoxy(30, 20);
	char Script_23[] = "아하! 이게 현대미술인가 뭔가 그거죠?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_23); i++) {
		printf("%c", Script_23[i]);
		if (i == 6)
			Sleep(150);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 그럴리가요....");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 분명 저 그림에는 숨겨진 의미가 있을거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 조금은 창의력을 발휘해야 할지도 모르겠네요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 마찬가지로 도움이 필요하다면 '힌트'를 입력해주세요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

}
void Script_func_hint_3(void) {
	gotoxy(30, 20);
	char Script_22[] = "아니 저 그림에 무슨 의미가 있다는 거에요??";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_22); i++) {
		printf("%c", Script_22[i]);
		if (i == 4)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 의미가 없어보이긴 하지만...");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 원래는 정상적인 그림이었을거에요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 정상적인 형태였다면... 사각형이 아니었을까요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title  ");

}
void Script_func_hint_4(void) {

	gotoxy(30, 20);
	printf("\n");
	char Script_22[] = "전혀 모르겠는데요!";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_22); i++) {
		printf("%c", Script_22[i]);
		if (i == 17)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 꽤나 당당하시네요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	view_picture_puzzle();

	gotoxy(30, 20);
	printf("\n");
	char Script_23[] = "모르는건 부끄러운게 아니랬어요!";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_23); i++) {
		printf("%c", Script_23[i]);
		if (i == 17)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 맞는말이긴 한데... 하하 ");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 저 그림은 특정한 가로 길이를 만족하면 보일꺼 같아요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 그런 방법은... 직접 창을 줄이는 방법 밖에 없겠네요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title  ");


}
void check_picture_puzzle_answer(void) { 
	char answer[30];
	char answer_script[] = "정답입니다. 다음 테스트를 시작합니다.";
	char incorrect_script[] = "오답입니다. 다시 입력해주세요";
	int hint = 0;
	
	printf("\n\n\n\n answer :");
	scanf_s("%s",answer,sizeof(answer));
	//답은 숫자지만 문자를 입력할경우 버그발생 때문에 문자열 비교함수 사용 
	if (strcmp(answer,"42")==0) { 
		printf("\n");
		for (int i = 0; i < 38; i++) {
			if (i == 12) {
				Sleep(100);
			}
			printf("%c", answer_script[i]);
			robot_sound(80);
		}
	gameclear = true;
	system("cls");
}
	else if (strcmp(answer, "힌트") == 0) {
		printf("\n힌트 1 / 힌트 2");
		printf("\n선택 (1 또는 2) -> ");
		check_chose = true;
		while (check_chose) {
			scanf_s("%d", &hint);
			switch (hint) {
			case 1:
				system("cls");
				view_picture_puzzle();
				Script_func_hint_3();
				check_chose = false;
				break;

			case 2:
				system("cls");
				view_picture_puzzle();
				Script_func_hint_4();
				check_chose = false;
				break;

			default:
				system("cls");
				view_picture_puzzle();
				gotoxy(30, 22);
				printf("\n힌트 1 / 힌트 2");
				printf("선택 (1 또는 2) -> ");
				scanf_s("%d", &hint);
				break;
			}
		}

	}
	else {
		printf("\n");
	for (int i = 0; i < 30; i++) {
		if (i == 12) {
			Sleep(150);
		}
		printf("%c", incorrect_script[i]);
		robot_sound(80);
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
void picture_puzzle_story(void) {
	playingBgm_4(true);
	picture_puzzle_first_title();
	system("cls");
	view_picture_puzzle();
	Sleep(2000);
	Script_func_picture_1();
	gameclear = false;
	while (gameclear == false) {
		SetConsoleView();
		view_picture_puzzle();
		check_picture_puzzle_answer();
		system("cls");
	}
	SetConsoleView();
}
// 그림 퍼즐 관련 코드

// 색깔 퍼즐 관련 코드
int hint_count = 0;
void color_puzzle_first_title(void) {
	printf("                 ");
	ColorSet(8, 7);
	char color_puzzle_title[] = "Object  :   Find color pattern";
	for (int i = 0; i < 31; i++) {
		printf("%c", color_puzzle_title[i]);
		typing_sound();
		if (i == 8 || i == 15)
			Sleep(100);
	}
	printf("\n\n");
	Sleep(1000);
	ColorSet(0, 7);
}
void view_color_puzzle(void) {
	printf("                 ");
	ColorSet(8, 7);
	printf("Object  :   Find color pattern");
	ColorSet(0, 7);
	
	gotoxy(30, 6);
	ColorSet(2, 2);
	printf(" ");
	ColorSet(0, 7);
	printf(" = 6\n\n");
	gotoxy(30, 8);
	ColorSet(1, 1);
	printf(" ");
	ColorSet(0, 7);
	printf(" = 2\n");

	gotoxy(30, 10);
	ColorSet(5, 5);
	printf(" ");
	ColorSet(0, 7);
	printf(" = 14\n");

	gotoxy(30, 12);
	ColorSet(6, 6);
	printf(" ");
	ColorSet(0, 7);
	printf(" = 3\n");

	gotoxy(30, 14);
	ColorSet(4, 0);
	printf(" ");
	ColorSet(0, 7);
	printf(" = ?\n");


}
void check_color_puzzle_answer(void) {
	char answer[30];
	char answer_script[] = "정답입니다. 다음 테스트를 시작합니다.";
	char incorrect_script[] = "오답입니다. 다시 입력해주세요";
	printf("\n\n\n\n Answer : ");
	scanf_s("%s", answer, sizeof(answer));
	//답은 숫자지만 문자를 입력할경우 버그발생 때문에 문자열 비교함수 사용 
	if (strcmp(answer, "7") == 0) {
		printf("\n");
		for (int i = 0; i < 38; i++) {
			if (i == 12) {
				Sleep(100);
			}
			printf("%c", answer_script[i]);
			robot_sound(80);
		}
		gameclear = true;
		hint_count = 0;
		system("cls");
	}
	else {
		printf("\n");
		for (int i = 0; i < 30; i++) {
			if (i == 12) {
				Sleep(150);
			}
			printf("%c", incorrect_script[i]);
			robot_sound(80);
		}
		hint_count++;
		Sleep(300);
		system("cls");
	}
}
void color_puzzle_hint(void) {
	if (hint_count == 3) {
		view_color_puzzle();
		gotoxy(6, 20);
		char hint_Script[] = "(음... 분명 초록색은 파란색과 노란색을 섞은거였지...)";
		for (int i = 0; i < 54; i++) {
			if (i == 5)
				Sleep(100);
			if (i ==12)
				ColorSet(0, 2);
			if (i == 18)
				ColorSet(0, 7);
			if (i == 22)
				ColorSet(0, 1);
			if (i == 28)
				ColorSet(0, 7);
			if (i == 31)
				ColorSet(0, 6);
			if (i == 37)
				ColorSet(0, 7);
			printf("%c", hint_Script[i]);
			if(i % 2 == 0)
			beep_male(80);
		}
		pressanykey();
	}
	if (hint_count == 6) {
		view_color_puzzle();
		gotoxy(2, 20);
		char hint_Script[] = "(그렇다면 보라색값에서 파란색을 나누면 빨간색 값이 나오겠는걸)";
		for (int i = 0; i < 63; i++) {
			if (i == 5)
				Sleep(100);
			if (i == 10)
				ColorSet(0, 5);
			if (i == 17)
				ColorSet(0, 7);
			if (i == 24)
				ColorSet(0, 1);
			if (i == 30)
				ColorSet(0, 7);
			if (i == 40)
				ColorSet(0, 4);
			if (i == 46)
				ColorSet(0, 7);
			printf("%c", hint_Script[i]);
			if (i % 2 == 0)
				beep_male(80);
		}
		pressanykey();
	}
}
void color_puzzle(void) {
	color_puzzle_first_title();
	system("cls");
	gameclear = false;
	hint_count = 0;
	while (gameclear == false) {
		view_color_puzzle();
		check_color_puzzle_answer();
		system("cls");
	}
}
void Script_func_color(void) {
	system("cls");
	view_color_puzzle();
	gotoxy(30, 20);
	char Script_1_1[] = "(이상한데서 일어났는데 다짜고짜 문제를 풀으라니)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_1); i++) {
		printf("%c", Script_1_1[i]);
		if (i % 2 == 0)
			beep_male(80);

	}
	pressanykey();
	system("cls");
	view_color_puzzle();

	gotoxy(30, 20);
	char Script_1_2[] = "(으으... 어떤 변태한테 납치당한걸지도 몰라)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_2); i++) {
		printf("%c", Script_1_2[i]);
		if (i == 8)
			Sleep(150);
		if (i % 2 == 0)
			beep_male(80);

	}
	pressanykey();
	system("cls");
	view_color_puzzle();

	gotoxy(30, 20);
	char Script_1_3[] = "(일단 풀으라니까 풀수밖에 없는건가...)";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_3); i++) {
		printf("%c", Script_1_3[i]);
		if (i % 2 == 0)
			beep_male(80);
	
	}
	pressanykey();
	system("cls");
	view_color_puzzle();

}
void color_puzzle_story(void) {
	playingBgm_1(true);
	color_puzzle_first_title();
	Script_func_color();
	system("cls");
	gameclear = false;
	hint_count = 0;
	while (gameclear == false) {
		view_color_puzzle();
		check_color_puzzle_answer();
		color_puzzle_hint();
		system("cls");
	}
	playingBgm_1(false);
}
// 색깔 퍼즐 관련 코드

// 암호 해독 퍼즐 관련 코드
int code_phase = 1;
void password_puzzle_first_title(void) {
	printf("                  ");
	ColorSet(1, 7);
	char button_puzzle_title[] = "Object  :  Decode password";
	for (int i = 0; i < 27; i++) {
		printf("%c", button_puzzle_title[i]);
		typing_sound();
		if (i == 8 || i == 12)
			Sleep(100);
	}
	printf("\n\n");
	Sleep(1000);
	ColorSet(0, 7);
	system("cls");
}
void view_decode_puzzle(void) {
	char word_password_1[] = "Hello";
	char word_password_2[] = "";
	printf("                  ");
	ColorSet(1, 7);
	printf("Object  :  Decode password");
	ColorSet(0, 7);
	gotoxy(6, 4);
	ColorSet(15, 0);
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	ColorSet(0, 7);
	if (code_phase == 1) {
		gotoxy(25, 8);
		printf(" dfn (1) ");
	}
	else if (code_phase == 2) {
		gotoxy(25, 8);
		printf(" (1) fssps  ");
	}

	else if (code_phase == 3) {
		gotoxy(24, 8);
		printf(" sfzqfj (11)  ");
	}

	else if (code_phase == 4) {
		gotoxy(20, 8);
		printf(" (10000000) jwocpkva ");
	}
	
};
void check_decode_puzzle(void) {
	char answer[30];
	char answer_script[] = "코드 승인 - 다음 코드를 입력해주세요.";
	char answer_script_1[] = "코드 승인 - 게이트를 개방합니다";
	char incorrect_script[] = "접근이 거부되었습니다.";
	printf("\n\n\n\n Password : ");
	scanf_s("%s", answer, sizeof(answer));
	if (code_phase == 1) {
		if (strcmp(answer, "ego") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound(80);
			}
			code_phase++;
		}
		else if (strcmp(answer, "힌트") == 0) {

			gotoxy(0, 20);
			char Script_1[] = "아니 내가 해커도 아니고 암호를 무슨수로 알아낸대요?";
			for (int i = 0; i < sizeof(Script_1); i++) {
				printf("%c", Script_1[i]);
				if (i % 2 == 0)
				beep_male(80);
			}
			pressanykey();

			system("title 암호 옆에 숫자가 있는게 핵심인거 같아요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();
			system("title 그리고 위에 출력되어있는 알파벳 표도 그렇고요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 알파벳을 숫자만큼 자리를 옮기라는 걸지도요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title  ");
		}
		else {
			printf("\n");
			for (int i = 0; i < sizeof(incorrect_script); i++) {
				if (i == 7) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound(80);
			}
			Sleep(300);
		}
	}
	else if (code_phase == 2) {
		if (strcmp(answer, "error") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound(80);
			}
			code_phase++;
		}
		else if (strcmp(answer, "힌트") == 0) {

			system("title 아까 제시어와 다른점은... 숫자가 왼쪽에 있는거네요 ");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 그럼 아까와 반대가 아닐까요?");
			receive_message(1000);
			Sleep(1000);
			pressanykey();
			system("title  ");
		}
		else {
			printf("\n");
			for (int i = 0; i < sizeof(incorrect_script); i++) {
				if (i == 7) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound(80);
			}
			Sleep(300);
		}
	}
	else if (code_phase == 3) {
		if (strcmp(answer, "victim") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound(80);
			}
			code_phase++;
		}
		else if (strcmp(answer, "힌트") == 0) {



			system("title 숫자를 세는 방법에는 여러가지가 있는데");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 그런걸 진법이라고 해요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			gotoxy(0, 20);
			char Script_1[] = "오! 저 2진법과 관련된 개그를 알아요";
			for (int i = 0; i < sizeof(Script_1); i++) {
				printf("%c", Script_1[i]);
				if (i % 2 == 0)
				beep_male(80);
			}
			pressanykey();
			system("cls");

			view_decode_puzzle();
			system("title 뭔데요?");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			gotoxy(0, 20);
			char Script_2[] = "세상엔 10종류의 사람이 있다. 이진법을 이해하는 사람과 그렇지 못한 사람";
			for (int i = 0; i < sizeof(Script_2); i++) {
				printf("%c", Script_2[i]);
				if (i % 2 == 0)
				beep_male(80);
				if (i == 28)
					Sleep(200);
			}
			pressanykey();
			system("cls");

			view_decode_puzzle();
			system("title ......?");
			receive_message(1000);
			Sleep(1000);

			gotoxy(0, 20);
			char Script_3[] = "어... 그러니까 10종류란 2진법으로 2를 의미....";
			for (int i = 0; i < sizeof(Script_3); i++) {
				printf("%c", Script_3[i]);
				if (i % 2 == 0)
				beep_male(80);
			}
			pressanykey();
			system("cls");

			view_decode_puzzle();
			system("title 설명해야하는 드립은 실패한거라고 배웠어요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			gotoxy(0, 20);
			char Script_4[] = "(머쓱,,,타드,,,)";
			for (int i = 0; i < sizeof(Script_4); i++) {
				printf("%c", Script_4[i]);
				if (i % 2 == 0)
				beep_male(80);
			}
			pressanykey();
			system("cls");

			view_decode_puzzle();
			system("title 그래서 암호에서 (11)은 이진법으로 계산해야겠네요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title ");
		}
		else {
			printf("\n");
			for (int i = 0; i < sizeof(incorrect_script); i++) {
				if (i == 7) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound(80);
			}
			Sleep(300);
		}
	}
	else if (code_phase == 4) {
		if (strcmp(answer, "humanity") == 0) {
			printf("\n");
			for (int i = 0; i < sizeof(answer_script_1); i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script_1[i]);
				robot_sound(80);
			}
			gameclear = true;
			pressanykey();
		}
		else if (strcmp(answer, "힌트") == 0) {

			system("title 저 숫자를 십진법으로 변환하면 128이고");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 알파벳은 총 26개에요");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 그러니까 26마다 한바퀴씩 돈다는거죠");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title 26으로 나누면 답이 보이지 않을까요?");
			receive_message(1000);
			Sleep(1000);
			pressanykey();

			system("title  ");
		}

		else {
			printf("\n");
			for (int i = 0; i < sizeof(incorrect_script); i++) {
				if (i == 7) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound(80);
			}
			Sleep(300);
		}
		}
		system("cls");
	}
void Script_func_decode(void) {
	view_decode_puzzle();
	gotoxy(0, 20);
	char Script_1[] = "이건 또 뭐람";
	printf("    ");
	for (int i = 0; i < sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);
		beep_male(70);
	}
	pressanykey();
	system("cls");

	view_decode_puzzle();
	gotoxy(0, 20);
	char Script_2[] = "형사님, 뭔지 알아보시겠어요?";
	printf("    ");
	for (int i = 0; i < sizeof(Script_2); i++) {
		printf("%c", Script_2[i]);
		beep_male(70);
	}
	pressanykey();

	system("title 글쎄요?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();

	system("title 한번 생각해보세요 만약 막힌다면 ... 아시죠?");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


	system("title '힌트'를 입력하면 저 나름대로의 생각을 말해드릴게요");
	receive_message(1000);
	Sleep(1000);
	pressanykey();


}
void decode_puzzle_story(void) {
	playingBgm_5(true);
	SetConsoleView();
	code_phase = 1;
	password_puzzle_first_title();
	Script_func_decode();
	system("cls");
	gameclear = false;
	while (gameclear == false) {
		view_decode_puzzle();
		check_decode_puzzle();
	}
	playingBgm_5(false);
	
}
//

int main(void) {
	SetConsoleView();
	Script_func_1();
	color_puzzle_story();
	Script_func_2();
	button_puzzle_story();
	Script_func_3();
	picture_puzzle_story();
	Script_func_4();
	Script_func_5();
	decode_puzzle_story();
	playingBgm_7(true);
	Script_func_6();
	Sleep(500000);

	return 0;
}
																																