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
int hint_count = 0;
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
int code_phase = 1;
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
	playingBgm_3(true);
	gotoxy(30, 20);
	char Script_1[] = "(.........................)";
	printf("\n\n");
	for (int i = 0; i <sizeof(Script_1); i++) {
		printf("%c", Script_1[i]);
		if (i % 2 == 0)
			beep_male(150);
		else
			Sleep(150);
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
			ColorSet(0, 6);
			Sleep(200);
		}
		if (i == 36) {
			ColorSet(0, 7);
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
	playingBgm_3(false);
}
void Script_func_color(void) {
	gotoxy(30, 20);
	char Script_1_1[] = "이상한데서 일어났는데 다짜고짜 문제를 풀으라니";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_1); i++) {
		printf("%c", Script_1_1[i]);
		if (i % 2 == 0)
			beep_male(150);
		else
			Sleep(150);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_1_2[] = "내가 꿈을 꾸고 있는건가..? 아니면 서프라이즈 파티겠지?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_2); i++) {
		printf("%c", Script_1_2[i]);
		if (i % 2 == 0)
			beep_male(150);
		else
			Sleep(150);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_1_3[] = "좋아 일단 풀어볼까?";
	printf("\n\n");
	for (int i = 0; i < sizeof(Script_1_3); i++) {
		printf("%c", Script_1_3[i]);
		if (i % 2 == 0)
			beep_male(150);
		else
			Sleep(150);
	}
	pressanykey();
	system("cls");

}
void Script_func_2(void) {
	playingBgm_3(true);
	gotoxy(30, 20);
	char Script_11[] = "() ";
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
	for (int i = 0; i < 36; i++) {
		printf("%c", Script_12[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 이봐요!");
	beep_female(1000);
	pressanykey();

	system("title 거기 들려요?");
	beep_female(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_13[] = "(으으... 피곤한지 어디선가 이상한 소리가 들린다.)";
	printf("\n\n");
	for (int i = 0; i < 50; i++) {
		printf("%c", Script_13[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();


	system("title 이쪽을 봐요 여기에요!");
	beep_female(1000);
	pressanykey();
	system("cls");
	
	gotoxy(30, 20);
	char Script_14[] = "(위쪽에서 들리는거 같기도 하고...)";
	printf("\n\n");
	for (int i = 0; i < 35; i++) {
		printf("%c", Script_14[i]);
		if (i == 1)
			ColorSet(0, 2);
		if (i == 5)
			ColorSet(0, 7);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_15[] = "(어디서 소리가 들리는지 알것같다.)";
	printf("\n\n");
	for (int i = 0; i < 35; i++) {
		printf("%c", Script_15[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}

	char Script_16[] = "(콘솔창의 제목을 확인해보자.)";
	while (check_chose) {
		gotoxy(30, 20);
		printf("\n\n\n1. 예");
		printf("\n2. 아니오\n");
		printf("선택 -> ");
	scanf_s("%d", &chose);

		switch (chose) {
		case 1:
			system("cls");
			check_chose = false;
			break;
			
		case 2:
			system("cls");
			gotoxy(30, 20);
			for (int i = 0; i < 30; i++) {
				printf("%c", Script_16[i]);
				if (i == 1) 
					ColorSet(0, 2);
				if (i == 13)
					ColorSet(0, 7);
				if (i % 2 == 0)
					beep_male(100);
			}
			pressanykey();
			system("cls");
			check_chose = false;
		default:
			break;
		}
	}

	system("title 다행이다! 그냥 지나가시는줄 알았어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	system("cls");


	gotoxy(30, 20);
	char Script_17[] = "당신은 누구죠?";
	printf("\n\n");
	for (int i = 0; i < 15; i++) {
		printf("%c", Script_17[i]);
		if (i == 7)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 저는 이곳에 잠입해 들어온 형사입니다");
	beep_female(1000);
	Sleep(1000); 
	pressanykey();

	system("title 이곳 시설이 보안이 제법이라 당신이 있는 곳까진 도달할 수 없었어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 당신과 대화를 하기위해 이곳 시설의 일부분을 해킹했어요.");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_18[] = "...역시 저는 납치당한거였어요";
	printf("\n\n");
	for (int i = 0; i < 30; i++) {
		printf("%c", Script_18[i]);
		if (i == 7)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 포기하기에는 일러요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	system("title 우선 테스트를 계속 통과해야 해요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_19[] = "이걸 계속 통과해야 한다고요? 어째서죠?";
	printf("\n\n");
	for (int i = 0; i < 39; i++) {
		printf("%c", Script_19[i]);
		if (i == 29)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 어느 테스트실은 출구와 연결되어 있어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그곳으로 나가려면 진행할 수밖에 없는 거에요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그리고 테스트를 풀지 못하면...");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_20[] = "계속 테스트를 진행하시길 바랍니다.";
	printf("\n\n");
	for (int i = 0; i < 35; i++) {
		printf("%c", Script_20[i]);
		if (i % 2 == 0)
			robot_sound();
	}

	system("title ... 다음에 말씀드릴게요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그래도 걱정 마세요 제가 테스트 푸는 걸 도와드릴 수 있어요");
	beep_female(1000);
	Sleep(1000);	
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_20_1[] = "(의심스럽긴 해도 지금 의지할건 저사람밖에 없어...)";
	printf("\n\n");
	for (int i = 0; i < 39; i++) {
		printf("%c", Script_20_1[i]);
		if (i == 29)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	playingBgm_3(false);
}
void Script_func_button_1(void) {
	ColorSet(0, 7);
	gotoxy(30, 20);
	char Script_21[] = "이 버튼들은 뭘까요?";
	printf("\n\n");
	for (int i = 0; i < 19; i++) {
		printf("%c", Script_21[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 색깔의 버튼과 아래에는 숫자들이 적혀 있네요 ");
	beep_female(1000);
	Sleep(1500);
	pressanykey();

	system("title 숫자들은 각각의 버튼의 위치와 대응되는 것처럼 보여요 ");
	beep_female(1000);
	Sleep(1500);
	pressanykey();

	system("title 우선 아무 버튼이나 눌러보시겠어요?");
	beep_female(1000);
	Sleep(1500);
	pressanykey();
	system("cls");

}
void Script_func_button_2(void) {
	gotoxy(30, 20);
	char Script_21[] = "누른 버튼 주위가 반대로 변했어요!";
	printf("\n\n");
	for (int i = 0; i < 34; i++) {
		printf("%c", Script_21[i]);

		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 그런 패턴이군요.");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 이 정도라면 혼자서 할 수 있을 거에요 ");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 도움이 필요하다면 '힌트' 를 입력해주세요 ");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

}
void Script_func_hint_1(void){

	gotoxy(30, 20);
	printf("\n");
	char Script_22[] = "많이 생각해봤는데 잘모르겠어요..";
	printf("\n\n");
	for (int i = 0; i < 33; i++) {
		printf("%c", Script_22[i]);
		if (i == 17)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();


	system("title 음... 버튼을 누를때 색깔이 대칭이 되도록 눌러보세요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 예를들어 2번을 눌렀으면 3번도 누르는거죠");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

}
void Script_func_hint_2(void) {

	gotoxy(30, 20);
	char Script_21[] = "으으... 도저히 모르겠어요";
	printf("\n\n");
	for (int i = 0; i < 33; i++) {
		printf("%c", Script_21[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();

	system("title 초록색으로 만드는게 어렵다면 반대로 해보는건 어떨까요?");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 전부 빨간색으로 만드는거죠 그렇게 생각하면 조금 쉬울거에요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
}
void Script_func_3(void) {

	playingBgm_3(true);

	gotoxy(30, 20);
	char Script_22[] = "휴.. 간신히 푼거같아요";
	printf("\n\n");
	for (int i = 0; i < 23; i++) {
		printf("%c", Script_22[i]);
		if (i == 4)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	gotoxy(30, 20);
	char Script_23[] = "그래서 아까 테스트를 못풀면 어떻게 된다고 하셨죠?";
	printf("\n\n");
	for (int i = 0; i < 50; i++) {
		printf("%c", Script_23[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title ....");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 폐기 처분당해요.");
	beep_female(1000);
	Sleep(1000);
	pressanykey();


	gotoxy(30, 20);
	char Script_24[] = ".......뭐라고요?";
	printf("\n\n");
	for (int i = 0; i < 17; i++) {
		printf("%c", Script_24[i]);
		if (i == 8)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

	system("title 그리고 테스트를 모두 풀어도...");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 살아남지 못할 거에요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 당신은 여기서 소모품이나 다름없어요.");
	beep_female(1000);
	Sleep(1000);
	pressanykey();


	gotoxy(30, 20);
	char Script_25[] = "도대체 왜...이런짓을...";
	printf("\n\n");
	for (int i = 0; i < 24; i++) {
		printf("%c", Script_25[i]);
		if (i == 7)
			Sleep(100);
		if (i == 12)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");


	system("title 이곳 설립자는 비인륜적인 범죄를 저지르는 사람이었어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그가 만든 인공지능 또한 그랬죠");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 자신이 완벽해지기 위해 무엇이든... ");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 자신에게 부족한것을 인간에게서 찾았던거죠");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그 인공지능은 사람을 납치하고 테스트를 시켰어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그리고 자신의 기준에 미달되는 사람들을 폐기시켰고...");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 그렇지 않은 사람들은 신경구조를 조사하기 위해 해부당했어요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();

	system("title 더 이상의 희생자는... 제가 막을거에요");
	beep_female(1000);
	Sleep(1000);
	pressanykey();
	

	gotoxy(30, 20);
	char Script_26[] = "정말로 당신은 절 구하러 온 게 맞는 거 같군요";
	printf("\n\n");
	for (int i = 0; i < 24; i++) {
		printf("%c", Script_26[i]);
		if (i == 7)
			Sleep(100);
		if (i == 12)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");




	playingBgm_3(false);
}
void Script_func_picture_1(void) {
	gotoxy(30, 20);
	char Script_22[] = "뭐지? 오류가 난건가요?";
	printf("\n\n");
	for (int i = 0; i < 23; i++) {
		printf("%c", Script_22[i]);
		if (i == 4)
			Sleep(100);
		if (i % 2 == 0)
			beep_male(100);
	}
	pressanykey();
	system("cls");

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
	printf("\n힌트 1");
	printf("\n힌트 2\n");
	printf("선택 (1 또는 2) -> ");
	check_chose = true;
	while (check_chose) {
		scanf_s("%d", &hint);
		switch (hint) {
		case 1:
			Script_func_hint_1();
			check_chose = false;
			break;
			
		case 2:
			Script_func_hint_2();
			check_chose = false;
			break;

		default:
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
void button_puzzle_story(void) {

	button_puzzle_first_title();
	viewbutton();
	Script_func_button_1();
	viewbutton();
	gotoxy(30, 14);
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
	Script_func_button_2();

	while (gameclear == false) {
		viewbutton();
		chose_num();
		check_green();
		system("cls");
	}
	viewbutton();
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
ColorSet(0, 0);
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
void check_picture_puzzle_answer(void) { 
	char answer[30];
	char answer_script[] = "정답입니다. 다음 테스트를 시작합니다.";
	char incorrect_script[] = "오답입니다. 다시 입력해주세요";
	
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

// 색깔 퍼즐 관련 코드
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
			robot_sound();
		}
		gameclear = false;
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
			robot_sound();
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
	gameclear = true;
	hint_count = 0;
	while (gameclear) {
		view_color_puzzle();
		check_color_puzzle_answer();
		system("cls");
	}
}
void color_puzzle_story(void) {
	playingBgm_1(true);
	color_puzzle_first_title();
	system("cls");
	gameclear = true;
	hint_count = 0;
	while (gameclear) {
		view_color_puzzle();
		check_color_puzzle_answer();
		color_puzzle_hint();
		system("cls");
	}
	playingBgm_1(false);
}
// 색깔 퍼즐 관련 코드

// 암호 해독 퍼즐 관련 코드
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
		printf(" Gdkkn (1) ");
	}
	else if (code_phase == 2) {
		gotoxy(26, 8);
		printf(" 몰?루 (1) ");
	}

	else if (code_phase == 3) {
		gotoxy(26, 8);
		printf(" Gdkkn (1) ");
	}

	else if (code_phase == 4) {
		gotoxy(26, 8);
		printf(" Gdkkn (1) ");
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
		if (strcmp(answer, "Hello") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound();
			}
			code_phase++;
		}
		else {
			printf("\n");
			for (int i = 0; i < 23; i++) {
				if (i == 12) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound();
			}
			Sleep(300);
		}
	}
	else if (code_phase == 2) {
		if (strcmp(answer, "Hello") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound();
			}
			code_phase++;
		}
		else {
			printf("\n");
			for (int i = 0; i < 23; i++) {
				if (i == 12) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound();
			}
			Sleep(300);
		}
	}
	else if (code_phase == 3) {
		if (strcmp(answer, "Hello") == 0) {
			printf("\n");
			for (int i = 0; i < 38; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound();
			}
			code_phase++;
		}
		else {
			printf("\n");
			for (int i = 0; i < 23; i++) {
				if (i == 12) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound();
			}
			Sleep(300);
		}
	}
	else if (code_phase == 4) {
		if (strcmp(answer, "Hello") == 0) {
			printf("\n");
			for (int i = 0; i < 32; i++) {
				if (i == 12) {
					Sleep(100);
				}
				printf("%c", answer_script[i]);
				robot_sound();
			}
			gameclear = false;
		}
		else {
			printf("\n");
			for (int i = 0; i < 23; i++) {
				if (i == 12) {
					Sleep(150);
				}
				printf("%c", incorrect_script[i]);
				robot_sound();
			}
			Sleep(300);
		}
	}
	system("cls");
}
void decode_puzzle_story(void) {
	playingBgm_5(true);
	code_phase = 1;
	password_puzzle_first_title();
	system("cls");
	gameclear = true;
	while (gameclear) {
		view_decode_puzzle();
		check_decode_puzzle();
	}
	playingBgm_5(false);
	
}


int main(void) {
	system("mode con:cols=85 lines=30");
	SetConsoleView();
	Script_func_1();
	color_puzzle_story();
	Script_func_2();
	SetConsoleView();
	playingBgm_2(true);
	button_puzzle_story();
	Script_func_n();
	playingBgm_2(false);
	Script_func_3();
	playingBgm_4(true);
	picture_puzzle();
	playingBgm_4(false);
	decode_puzzle_story();
	printf("미완성");
	pressanykey();
	Sleep(500000);

	return 0;
}

// ?????
																																						