#ifndef CheckFunctions_h
#define CheckFunctions_h

#include <windows.h>
#include <math.h>

class CheckFunctions{
public:
	static bool LiczbaPierwsza(int liczba);
	static bool PtInCircle(POINT CentralPoint,double Ray,POINT pt);
	static bool PtInCircle(int xC,int yC,double Ray,POINT pt);
	static bool PtInRay(int xC,int yC,UINT Ray,int dRay,POINT pt);
};
#endif