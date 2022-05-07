#include <windows.h>
#include <math.h>

#include "myMath.h"

#ifndef Drawing_h
#define Drawing_h

enum bs_style : int{
	bs_solid			= 0,
	bs_null				= 1,
	bs_hollow			= 1,
	bs_hatched			= 2,
	bs_pattern			= 3,
	bs_indexed			= 4,
	bs_dibpattern		= 5,
	bs_dibpatternpt		= 6,
	bs_pattern8x8		= 7,
	bs_dibpattern8x8	= 8,
	bs_monopattern		= 9
};

enum ps_style : int{
	ps_solid		= 0,
	ps_dash			= 1,       /* -------  */
	ps_dot			= 2,       /* .......  */
	ps_dashdot		= 3,       /* _._._._  */
	ps_dashdotdot	= 4,       /* _.._.._  */
	ps_null			= 5,
	ps_insideframe	= 6,
	ps_userstyle	= 7,
	ps_alternate	= 8,
	ps_style_mask   = 0x0000000F,

	ps_endcap_round	= 0x00000000,
	ps_endcap_square= 0x00000100,
	ps_endcap_flat	= 0x00000200,
	ps_endcap_mask	= 0x00000F00,

	ps_join_round	= 0x00000000,
	ps_join_bevel	= 0x00001000,
	ps_join_miter	= 0x00002000,
	ps_join_mask	= 0x0000F000,

	ps_cosmetic		= 0x00000000,
	ps_geometric	= 0x00010000,
	ps_type_mask	= 0x000F0000
};

RECT GetRect(int x,int y,UINT szer,UINT wys);

enum DrawingPointStyle : int{
	pluss,
	cross,
	box,
	circle,
	dot
};

class Drawing : public myMath
{
	HPEN hPen;
	HBRUSH hBrush;
	void Pion(HDC &hdc,int dx,int dy,COLORREF kolor,double skala);
	void Poziom(HDC &hdc,int dx,int dy,COLORREF kolor,double skala);
public:
	//Konstruktor
	Drawing(void);
	// Rysowanie puktu
	void drawPoint(HDC hdc,int x,int y,enum DrawingPointStyle dps);
	//Rysowanie prostok¹ta:
		//z wype³nieniem i ramk¹
	void rectangle(HDC &hdc,RECT rect);
	void rectangle(HDC &hdc,int xLeft,int yTop,int xRight,int yBottom);
	void rectangle(HDC &hdc,int xLeft,int yTop,int xRight,int yBottom,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void rectangle(HDC &hdc,int x,int y,UINT szer,UINT wys);
	void rectangle(HDC &hdc,RECT rect,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void rectangle(HDC &hdc,int x,int y,UINT szer,UINT wys,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
		//z wype³nieniem i bez ramki
	void fillRectangle(HDC &hdc,int x,int y,UINT szer,UINT wys);
	void fillRectangle(HDC &hdc,RECT rect);
	void fillRectangle(HDC &hdc,int x1,int y1,int x2,int y2);
	void fillRectangle(HDC &hdc,int x,int y,UINT szer,UINT wys,COLORREF kBrush);
	void fillRectangle(HDC &hdc,int x1,int y1,int x2,int y2,COLORREF kBrush);
	void fillRectangle(HDC &hdc,RECT rect,COLORREF kBrush);
		//z ramk¹ i bez wype³nienia
	void frameRectangle(HDC &hdc,int x,int y,UINT szer,UINT wys);
	void frameRectangle(HDC &hdc,RECT rect);
	void frameRectangle(HDC &hdc,int x,int y,UINT szer,UINT wys,COLORREF kPen,int Styl,int Gr);
	void frameRectangle(HDC &hdc,RECT rect,COLORREF kPen,int Styl,int Gr);
	//Rysowanie okrêgu:
		//z ramk¹ i wype³nieniem
	void circle(HDC &hdc,int xS,int yS,UINT Ray);
	void circle(HDC &hdc,int xS,int yS,UINT Ray,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	//Rysowanie okrêgu:
		//z wype³nieniem i bez ramki
	void fillCircle(HDC &hdc,int xS,int yS,UINT Ray);
	void fillCircle(HDC &hdc,int xS,int yS,UINT Ray,COLORREF kBrush);
		//z ramk¹ i bez wype³nienia
	void frameCircle(HDC &hdc,int xS,int yS,UINT Ray);
	void frameCircle(HDC &hdc,int xS,int yS,UINT Ray,COLORREF kPen,int Styl,int Gr);
	//Rysowanie elipsy:
		//z ramk¹ i wype³nieniem
	void ellipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay);
	void ellipse(HDC &hdc,RECT rect);
	void ellipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void ellipse(HDC &hdc,RECT rect,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
		//bez ramki i z wype³nieniem
	void fillEllipse(HDC &hdc,RECT rect);
	void fillEllipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay);
	void fillEllipse(HDC &hdc,RECT rect,COLORREF kBrush);
	void fillEllipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,COLORREF kBrush);
		//z ramk¹ i bez wype³nienia
	void frameEllipse(HDC &hdc,RECT rect);
	void frameEllipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay);
	void frameEllipse(HDC &hdc,RECT rect,COLORREF kPen,int Styl,int Gr);
	void frameEllipse(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr);
	//Rysowanie prostok¹ta z zaokr¹glonymi naro¿nikami:
		//z wype³nieniem i ramk¹
	void roundRect(HDC &hdc,RECT rect,UINT Ray);
	void roundRect(HDC &hdc,RECT rect,UINT xRay,UINT yRay);
	void roundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT Ray);
	void roundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT xRay,UINT yRay);
	void roundRect(HDC &hdc,RECT rect,UINT Ray,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void roundRect(HDC &hdc,RECT rect,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void roundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT Ray,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void roundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
		//bez ramki i z wype³nieniem
	void fillRoundRect(HDC &hdc,RECT rect,UINT Ray,COLORREF kBrush);
	void fillRoundRect(HDC &hdc,RECT rect,UINT xRay,UINT yRay,COLORREF kBrush);
	void fillRoundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT Ray,COLORREF kBrush);
	void fillRoundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT xRay,UINT yRay,COLORREF kBrush);
		//z ramk¹ i bez wype³nienia
	void frameRoundRect(HDC &hdc,RECT rect,UINT Ray,COLORREF kPen,int Styl,int Gr);
	void frameRoundRect(HDC &hdc,RECT rect,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr);
	void frameRoundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT Ray,COLORREF kPen,int Styl,int Gr);
	void frameRoundRect(HDC &hdc,int x,int y,UINT szer,UINT wys,UINT xRay,UINT yRay,COLORREF kPen,int Styl,int Gr);
	//Rysowanie linii
	void line(HDC &hdc,POINT p1,POINT p2);
	void line(HDC &hdc,int x1,int y1,int x2,int y2);
	void line(HDC &hdc,int X,int Y,int kt,UINT R);
	void line(HDC &hdc,int X,int Y,double kt,UINT R);
	void line(HDC &hdc,POINT p1,POINT p2,COLORREF kPen,int Styl,int Gr);
	void line(HDC &hdc,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void line(HDC &hdc,int X,int Y,int kt,UINT R,COLORREF kPen,int Styl,int Gr);
	void line(HDC &hdc,int X,int Y,double kt,UINT R,COLORREF kPen,int Styl,int Gr);
	void lineR(HDC &hdc,int x1,int y1,int x2,int y2,int xObrotu,int yObrotu,double kt);
	//Rysowanie wycinków ko³a (³uków)
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2);
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2);
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2);
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void circleArc(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	//Rysowanie wycinków elipsy (³uków eliptycznych)
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2);
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2);
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2);
	void ellipseArc(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2);
	void ellipseArc(HDC &hdc,RECT rect,int kt1,int kt2);
	void ellipseArc(HDC &hdc,RECT rect,double kt1,double kt2);
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseArc(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseArc(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipseArc(HDC &hdc,RECT rect,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseArc(HDC &hdc,RECT rect,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
// Rysowanie okrêgu œciêtego ciêciw¹
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2);
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2);
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2);
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void circleChord(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2);
	void ellipseChord(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2);
	void ellipseChord(HDC &hdc,RECT rect,int kt1,int kt2);
	void ellipseChord(HDC &hdc,RECT rect,double kt1,double kt2);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,RECT rect,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipseChord(HDC &hdc,RECT rect,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void circlePie(HDC &hdc,int xS,int yS,UINT Ray,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2);
	void ellipsePie(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2);
	void ellipsePie(HDC &hdc,RECT rect,int kt1,int kt2);
	void ellipsePie(HDC &hdc,RECT rect,double kt1,double kt2);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,int xS,int yS,UINT xRay,UINT yRay,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,RECT rect,int x1,int y1,int x2,int y2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,RECT rect,int kt1,int kt2,COLORREF kPen,int Styl,int Gr);
	void ellipsePie(HDC &hdc,RECT rect,double kt1,double kt2,COLORREF kPen,int Styl,int Gr);
	void polyline(HDC &hdc,CONST POINT* Punkty,int ilP);
	void polyline(HDC &hdc,CONST POINT* Punkty,int ilP,COLORREF kPen,int Styl,int Gr);
	void polygon(HDC &hdc,CONST POINT* Punkty,int ilP);
	void polygon(HDC &hdc,CONST POINT* Punkty,int ilP,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void framePolygon(HDC &hdc,CONST POINT* Punkty,int ilP);
	void framePolygon(HDC &hdc,CONST POINT* Punkty,int ilP,COLORREF kPen,int Styl,int Gr);
	void fillPolygon(HDC &hdc,CONST POINT* Punkty,int ilP,COLORREF kBrush);
	void fillPolygon(HDC &hdc,CONST POINT* Punkty,int ilP);
	void polyPolygon(HDC &hdc,CONST POINT* Punkty,CONST INT *ilP,int ilW);
	void polyPolygon(HDC &hdc,CONST POINT* Punkty,CONST INT *ilP,int ilW,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void wielForemny(HDC &hdc,int xS,int yS,UINT ilBokow,UINT R,int ktPrzes);
	void wielForemny(HDC &hdc,int xS,int yS,UINT ilBokow,UINT R,double ktPrzes);
	void wielForemny(HDC &hdc,int xS,int yS,UINT ilBokow,UINT R,int ktPrzes,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void wielForemny(HDC &hdc,int xS,int yS,UINT ilBokow,UINT R,double ktPrzes,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void Wektor(HDC &hdc,int X,int Y,double Kat,int dlWektora,bool Arrow);
	void Wektor(HDC &hdc,int x1,int y1,int x2,int y2,bool Arrow);
	void Wektor(HDC &hdc,int X,int Y,double Kat,int dlWektora,bool Arrow,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void Wektor(HDC &hdc,int x1,int y1,int x2,int y2,bool Arrow,COLORREF kPen,int Styl,int Gr,COLORREF kBrush);
	void frameWektor(HDC &hdc,int x1,int y1,int x2,int y2,bool Arrow);
	void frameWektor(HDC &hdc,int x1,int y1,int x2,int y2,bool Arrow,COLORREF kPen,int Styl,int Gr);
	void textOut(HDC &hdc,int x,int y,LPCSTR tekst,int dlTekstu);
	void textOut(HDC &hdc,int x,int y,int liczba,int ilCyfr);
	void textOut(HDC &hdc,int x,int y,double liczba,int ilCyfr);
	void textOut(HDC &hdc,int x,int y,LPCSTR tekst,int dlTekstu,COLORREF kTekstu,int bkMode);
	void textOut(HDC &hdc,int x,int y,int liczba,int ilCyfr,COLORREF kTekstu,int bkMode);
	void textOut(HDC &hdc,int x,int y,double liczba,int ilCyfr,COLORREF kTekstu,int bkMode);
	void drawText(HDC &hdc,LPCSTR tekst,int dlTekstu,RECT *rect,UINT uFormat);
	void drawText(HDC &hdc,LPCSTR tekst,int dlTekstu,int x,int y,UINT szer,UINT wys,UINT uFormat);
	void drawText(HDC &hdc,int liczba,int ilCyfr,int x,int y,UINT szer,UINT wys,UINT uFormat);
	void drawText(HDC &hdc,double liczba,int ilCyfr,int x,int y,UINT szer,UINT wys,UINT uFormat);
	void CyfryWysEl(HBITMAP &hBitmap,UINT nrLiczby/*0-11 (0 - zero, 1 - jeden .... 10 - -*/,COLORREF kTla,COLORREF On,COLORREF Off,double skala);
	void bitBltBmpOnHdc(HDC &hdc,HBITMAP hBmp,int x,int y,UINT szer,UINT wys,int ropStyle);
	void bitBltBmpOnHdc(HDC &hdc,HBITMAP hBmp,int x,int y,int ropStyle);
	void bitBltBmpOnHdc(HDC &hdc,HBITMAP hBmp,int x,int y,UINT szer,UINT wys,int xPocz,int yPocz,int ropStyle);
	void stretchBltBmpOnHdc(HDC &hdc,HBITMAP hBmp,int x,int y,UINT szer,UINT wys,int ropStyle);
	void stretchBltBmpOnHdc(HDC &hdc,HBITMAP hBmp,int x,int y,UINT szer,UINT wys,int bmpX,int bmpY,int bmpWidth,int BmpHeight,int ropStyle);
	void MaskBmp(HDC hdc,int x,int y,int szer,int wys,HBITMAP Image,HBITMAP Mask);
	void MaskBmp(HDC hdc,int x,int y,int szer,int wys,int xPocz,int yPocz,HBITMAP Image,HBITMAP Mask);
	void StretchMaskBmp(HDC hdc,int x,int y,int szer,int wys,HBITMAP Image,HBITMAP Mask);
	HBITMAP CreateMask(HBITMAP hBmp,COLORREF kMaski);
	void SetBrush(HDC &hdc,COLORREF kBrush);
	void SetBrush(HDC &hdc,HBRUSH _hBrush);
	void SetPen(HDC &hdc,COLORREF kPen,int Styl,int Gr);
	void SetPen(HDC &hdc,HPEN _hPen);
	PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd,HBITMAP hBmp);
	void CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi,HBITMAP hBMP, HDC hDC);
	HBITMAP GetBitmapFile(PTSTR szFileName);
	void frame(HDC &hdc,RECT fr);
	void frame(HDC &hdc,int xLeft,int yTop,int xRight,int yBottom);
};
#endif