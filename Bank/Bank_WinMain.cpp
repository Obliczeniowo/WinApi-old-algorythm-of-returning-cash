#include <windows.h>
#include <math.h>

#define _USE_MATH_DEFINES

#include <vector>
#include <fstream>

#include "Drawing.h"
Drawing *RYS=new Drawing;

#include "Bank.h"

//Zmienne globalne
HWND okno;
HINSTANCE hInst;

LPSTR BelkaTyt = "Bank";
LPSTR NazwaKlasy = "Bank";

Bank felek((std::string)"Felek");
Bank ziutek((std::string)"Ziótek");

HWND hEdit;
HWND toFelekButton;
HWND toZiutekButton;

//Funkcje globalne
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam){
	static HBITMAP tlo;
	static COLORREF kTla=RGB(0,0,0);
	static POINT MousePos;
	static RECT WndSize;
	static UINT MK;
	int n;
	switch(msg){
		case WM_CREATE:
			{
				hEdit = CreateWindow("EDIT","1688,87",WS_CHILD|WS_VISIBLE,400,10,100,20,hWnd,(HMENU)10000,hInst,NULL);
				toFelekButton = CreateWindow("BUTTON","Ziótek do Felka",WS_CHILD|WS_VISIBLE,500,0,200,20,hWnd,(HMENU)10001,hInst,NULL);
				toZiutekButton = CreateWindow("BUTTON","Felek do Ziótka",WS_CHILD|WS_VISIBLE,500,20,200,20,hWnd,(HMENU)10002,hInst,NULL);

				felek.AddNominal(200, 0, 50);
				felek.AddNominal(100, 0, 50);
				felek.AddNominal(50, 0, 50);
				felek.AddNominal(20, 0, 50);
				felek.AddNominal(10, 0, 50);
				felek.AddNominal(5, 0, 50);
				felek.AddNominal(2, 0, 50);
				felek.AddNominal(1, 0, 50);
				felek.AddNominal(0, 50, 50);
				felek.AddNominal(0, 20, 50);
				felek.AddNominal(0, 10, 50);
				felek.AddNominal(0, 5, 50);
				felek.AddNominal(0, 2, 50);
				felek.AddNominal(0, 1, 50);

				felek.Transfer(ziutek, 1688,87);
			}
			break;
		case WM_COMMAND:
			{
				int wNotifyCode	= HIWORD(wParam); 
				int wID			= LOWORD(wParam); 
				HWND hwndCtl	= (HWND) lParam;
				switch(wID){
					case 10000:
						{
							switch(wNotifyCode){
								case EN_CHANGE:
									//MessageBox(hWnd,"Coœ siê pomienia³o","INFO",MB_OK);
									break;
							}
						}
						break;
					case 10001:
						{
							switch(wNotifyCode){
								case BN_CLICKED:
									{
										char bufor[MAX_PATH];
										GetWindowText(hEdit,bufor,MAX_PATH);
										int bUnit = 0;
										int sUnit = 0;
										sscanf(bufor,"%i,%i",&bUnit,&sUnit);
										ziutek.Transfer(felek,bUnit,sUnit);
										InvalidateRect(hWnd,NULL,false);
									}
									break;
							}
						}
						break;
					case 10002:
						{
							switch(wNotifyCode){
								case BN_CLICKED:
									{
										char bufor[MAX_PATH];
										GetWindowText(hEdit,bufor,MAX_PATH);
										int bUnit = 0;
										int sUnit = 0;
										sscanf(bufor,"%i,%i",&bUnit,&sUnit);
										felek.Transfer(ziutek,bUnit,sUnit);
										InvalidateRect(hWnd,NULL,false);
									}
									break;
							}
						}
						break;
				}
			}
			break;
		case WM_SIZE:
			{
				GetClientRect(hWnd,&WndSize);
				HDC hdc=GetDC(NULL);
				DeleteObject(tlo);
				tlo=CreateCompatibleBitmap(hdc,WndSize.right,WndSize.bottom);
				DeleteDC(hdc);
			}
			break;
		case WM_LBUTTONDOWN:
			{
				MK=MK_LBUTTON;
				InvalidateRect(hWnd,NULL,false);
			}
			break;
		case WM_RBUTTONDOWN:
			{
				MK=MK_RBUTTON;
			}
			break;
		case WM_RBUTTONUP:
			MK=NULL;
			break;
		case WM_LBUTTONUP:
			MK=NULL;
			break;
		case WM_MOUSEMOVE:
			MK=(UINT)wParam;
			MousePos.x=LOWORD(lParam);
			MousePos.y=HIWORD(lParam);
			break;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc=BeginPaint(hWnd,&ps);
				HDC mem=CreateCompatibleDC(hdc);
				SelectObject(mem,tlo);
				RYS->rectangle(mem,WndSize,RGB(0,0,0),PS_SOLID,1,RGB(0,0,0));
				felek.DrawBankCash(mem,RYS,0,0);
				ziutek.DrawBankCash(mem,RYS,200,0);
				BitBlt(hdc,0,0,WndSize.right,WndSize.bottom,mem,0,0,SRCCOPY);
				DeleteDC(mem);
				EndPaint(hWnd,&ps);
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE ,LPSTR cmdLine,int styl){
	hInst=hInstance;

	WNDCLASS wnd;

	wnd.cbClsExtra		= NULL;
	wnd.cbWndExtra		= NULL;
	wnd.hbrBackground	= NULL;
	wnd.hCursor			= LoadCursor(NULL,IDC_ARROW);
	wnd.hIcon			= LoadIcon(NULL,IDI_APPLICATION);
	wnd.hInstance		= hInstance;
	wnd.lpfnWndProc		= WndProc;
	wnd.lpszClassName	= TEXT(NazwaKlasy);
	wnd.lpszMenuName	= NULL;
	wnd.style			= CS_VREDRAW|CS_HREDRAW;

	if(!RegisterClass(&wnd)) return 0;

	okno = CreateWindow(NazwaKlasy,BelkaTyt,WS_OVERLAPPEDWINDOW,0,0,800,600,NULL,NULL,hInstance,NULL);

	ShowWindow(okno,styl);
	UpdateWindow(okno);

	MSG msg;

	while(GetMessage(&msg,NULL,NULL,NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}