#include "CheckFunctions.h"

bool CheckFunctions::PtInRay(int xC,int yC,UINT Ray,int dRay,POINT pt){
	if(dRay<=0)
		dRay=1;
	return (PtInCircle(xC,yC,Ray+dRay/2,pt) && !PtInCircle(xC,yC,Ray-dRay/2,pt))?true:false;
}

bool CheckFunctions::PtInCircle(POINT CentralPoint,double Ray,POINT pt){
	UINT l=(UINT)pow(pow((double)(CentralPoint.x-pt.x),2.)+pow((double)(CentralPoint.y-pt.y),2.),0.5);
	if(l>Ray)
		return false;
	return true;
}

bool CheckFunctions::PtInCircle(int xC,int yC,double Ray,POINT pt){
	double l=pow(pow((double)(xC-pt.x),2.)+pow((double)(yC-pt.y),2.),0.5);
	if(l>Ray)
		return false;
	return true;
}

bool CheckFunctions::LiczbaPierwsza(int liczba){
	if(liczba < 2){
		return false;
	}
	int i=2;
	while(i<=liczba / i){
		if(!(liczba % i)){
			return false;
		}
		i++;
	}
	return true;
}