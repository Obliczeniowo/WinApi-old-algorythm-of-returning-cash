#include "myMath.h"

double myMath::abs(double v) {
	return v < 0 ? -v : v;
}

double myMath::RadiansToDegrees(double AngleInRadians){
	return AngleInRadians*90/acos(0.);
}

double myMath::DegreesToRadians(double AngleInDegrees){
	return AngleInDegrees*acos(0.)/90;
}

double myMath::Dist3D(double x1,double y1,double z1,double x2,double y2,double z2){
	return pow(pow(x1-x2,2.)+pow(y1-y2,2.)+pow(z1-z2,2.),.5);
}

int myMath::Zaokr(double w){
	double w2=w-(int)w;
	int a=(int)w;
	if(abs(w2)>.5)
		if(w2>0)
			return (int)w+1;
		else
			return (int)w-1;
	else
		return (int)w;
}

double myMath::Zaokr(double w,UINT nrPoPrzecinku){
	w=Zaokr(w*pow(10.,(double)nrPoPrzecinku));
	w=w/pow(10.,(double)nrPoPrzecinku);
	return w;
}

POINT myMath::RotatePoint(int xObracany,int yObracany,int xObrotu,int yObrotu,double ktObrotu){
	POINT p;
	double dist=Dist(xObracany,yObracany,xObrotu,yObrotu);
	double ktPocz=GetAngle(xObrotu,yObrotu,xObracany,yObracany);
	p.x=Zaokr(dist*cos(ktObrotu+ktPocz))+xObrotu;
	p.y=Zaokr(dist*sin(ktObrotu+ktPocz))+yObrotu;
	return p;
}

double myMath::RayOfArc(int x1,int y1,int x2,int y2,int x3,int y3){
	double l1=Dist(x1,y1,x2,y2),l2=Dist(x1,y1,x3,y3),l3=Dist(x2,y2,x3,y3);
	double alfa,beta;
	alfa= acos((pow(l1,2.) + pow(l2,2.) - pow(l3,2.)) / (2 * l1 * l2));
	beta=4*asin(1.)-2*alfa;
	return pow(pow(l3,2.) / (2 - 2 * cos(beta)),0.5);
}

double myMath::RayOfArc(POINT p1,POINT p2,POINT p3){
	double l1=Dist(p1,p2),l2=Dist(p1,p3),l3=Dist(p2,p3);
	double alfa,beta;
	alfa= acos((pow(l1,2.) + pow(l2,2.) - pow(l3,2.)) / (2 * l1 * l2));
	beta=4*asin(1.)-2*alfa;
	return pow(pow(l3,2.) / (2 - 2 * cos(beta)),0.5);
}

POINT myMath::Bezier(double t, POINT firstPoint,POINT lastPoint,double firstAngle,double lastAngle, double firstRay,double lastRay){
	if(t < 0)
		t = 0;
	else if(t > 1)
		t = 1;
	POINT pt;
	pt.x = pow((1. - t),3.) * double(firstPoint.x)
		+ 3 * t * pow(1 - t,2.) * double(firstPoint.x + firstRay * cos(firstAngle)) 
		+ 3 * pow(t,2.) * (1 - t) * double(lastPoint.x + lastRay * cos(lastAngle))
		+ pow(t, 3.) * lastPoint.x;
	pt.y = pow((1. - t),3.) * double(firstPoint.y)
		+ 3 * t * pow(1 - t,2.) * double(firstPoint.y + firstRay * sin(firstAngle)) 
		+ 3 * pow(t,2.) * (1 - t) * double(lastPoint.y + lastRay * sin(lastAngle))
		+ pow(t, 3.) * lastPoint.y;
	return pt;
}
POINT myMath::Bezier(double t, POINT firstPoint,POINT lastPoint,POINT first,POINT last){
	if(t < 0)
		t = 0;
	else if(t > 1)
		t = 1;
	POINT pt;
	pt.x = pow((1. - t),3.) * double(firstPoint.x)
		+ 3 * t * pow(1 - t,2.) * double(first.x) 
		+ 3 * pow(t,2.) * (1 - t) * double(last.x)
		+ pow(t, 3.) * lastPoint.x;
	pt.y = pow((1. - t),3.) * double(firstPoint.y)
		+ 3 * t * pow(1 - t,2.) * double(first.y) 
		+ 3 * pow(t,2.) * (1 - t) * double(last.y)
		+ pow(t, 3.) * lastPoint.y;
	return pt;
}

//Funkcja licz¹ca odleg³oœæ miêdzy dwiema wspó³¿êdnymi
double myMath::Dist(double x1,double y1,double x2,double y2){
	return pow(double((x1-x2)*(x1-x2))+double((y1-y2)*(y1-y2)),.5);
}

double myMath::Dist(POINT p1,POINT p2){
	return Dist(p1.x,p1.y,p2.x,p2.y);
}
//Funkcje licz¹ca k¹t zawarty miêdzy dwoma punktami
double myMath::GetAngle(double x1,double y1,double x2,double y2){
	if(x1==x2 && y1==y2)
		return 0;
	double L=pow(double((x1-x2)*(x1-x2))+double((y1-y2)*(y1-y2)),0.5);
	double PI=asin(1.0)*2;
	if(y2<y1)
		return acos((x1-x2)/L);
	else
		return acos((x1-x2)/-L)+PI;
}

double myMath::GetAngle(POINT p1,POINT p2){
	return GetAngle(p1.x,p1.y,p2.x,p2.y);
}

double myMath::Silnia(int i){
	double s = 1;
	if(i <= 0)
		return 0;
	for(int j = 1; j <= i; j++){
		s *= j;
	}
	return s;
}

int myMath::Rand(int Min,int Max){
	if (Max < Min){
		return 0;
	}
	else
		return ((rand() % (Max - Min + 1)) + Min);
}

int myMath::Rand(int Max){
	if(Max > -1)
		return (rand() % (int)(abs(Max) + 1));
	return 0;
}

double myMath::RandD(){
	return ((double)(Rand (-9,9) / 10.0) + (double)(Rand(-9,9) / 100.0) + (double)(Rand(-9,9) / 1000.0));
}

double myMath::RandD(double Max,double Min){
	if(Max < Min)
		return 0;
	return (Max - Min) * RandD() + Min;
}

double myMath::log_a_b(double a/*Podstawa logarytmu*/,double b/*Zmienna logarytmowana*/){
	return log(b) / log(a);
}

int myMath::IntDivision(int dividend, int divisor){
	return dividend / divisor;
}

float myMath::IntDivision(float dividend,float divisor){
	return floor(dividend / divisor);
}

double myMath::IntDivision(double dividend,double divisor){
	return floor(dividend / divisor);
}

void StartupFile(LPSTR &startupFile,LPSTR startupFileName){
	char *path=GetCommandLine();
	char *p=strrchr(path, '\\');
	*p=NULL;
	if(path[0]==34)
		path++;
	strcat_s(path,sizeof(path),startupFileName);
	startupFile=new char[strlen(path)+1];
	strcpy_s(startupFile,sizeof(startupFile),path);
}

void StartupPath(LPSTR &startupPath){
	char *path=GetCommandLine();
	char *p=strrchr(path,'\\');
	*p=NULL;
	if(path[0]==34)
		path++;
	startupPath=new char[strlen(path)+1];
	strcpy_s(startupPath,sizeof(startupPath),path);
}

LPSTR Right(LPSTR text,UINT nr){
	char *txt;
	UINT size=(UINT)strlen(text);
	if(!size)
		return NULL;
	txt=new char[strlen(text)+1];
	strcpy_s(txt,strlen(text)+1,text);
	if((int)size-(int)nr<=0)
		return txt;
	return txt+(size-nr);
}

LPSTR Left(LPSTR text,UINT nr){
	char *txt;
	UINT size=(UINT)strlen(text);
	if(!size)
		return NULL;
	txt=new char[strlen(text)+1];
	strcpy_s(txt,strlen(text)+1,text);
	if(nr>=size)
		return txt;
	char *p=text;
	p+=nr;
	*(txt+(p-text))=NULL;
	return txt;
}

LPSTR WytnijTekst(LPSTR text,UINT nrPocz,UINT szer){
	return Right(Left(text,nrPocz+szer),szer);
}

LPSTR ZastTekst(LPSTR text,LPSTR textZ,UINT nrPocz,UINT szer){
	char *txt;
	UINT tSize=(UINT)strlen(text);
	UINT tzSize=(UINT)strlen(textZ);
	if(!tSize || !tzSize || nrPocz+szer>=tSize)
		return text;
	txt=Left(text,nrPocz);
    strcat(txt,textZ);
	strcat(txt,Right(text,tSize-nrPocz-szer));
	return txt;
}

LPSTR FindX(LPSTR fu,double x){
	char xStr[20];
	_gcvt_s(xStr,sizeof(xStr),x,10);
	UINT size=(UINT)strlen(fu);
	if(!size)
		return fu;
	for(UINT i=0;i<size-1;i++){
		if(strcmp(WytnijTekst(fu,i,1),"x")==0){
			fu=ZastTekst(fu,xStr,i,1);
			size=(UINT)strlen(fu);
		}
	}
	return fu;
}

int SprNaw(LPSTR fu){
	int ilN=0;
	UINT size=(UINT)strlen(fu);
	if(!size) return 0;
	for(char* p=fu;p<fu+size;p++){
		if(*p=='(')
			ilN++;
		else if(*p==')'){
			ilN--;
			if(ilN<0)
				return ilN;
		}
	}
	return ilN;
}

void FindNaw(LPSTR fu,UINT &pocz,UINT &kon){
	pocz=kon=0;
	int ilN=0;
	for(char *p=fu;p<fu+strlen(fu);p++){
		if(*p=='('){
			ilN++;
			if(ilN==1)
				pocz=(UINT)(p-fu);
		}else if(*p==')'){
			ilN--;
			if(ilN==0){
				kon=(UINT)(p-fu);			
				break;
			}
		}
	}
}

double LiczFu(LPSTR fu,double x){
	fu=FindX(fu,x);
	if(!SprNaw(fu)) return 0;
	UINT poczN,konN;
    FindNaw(fu,poczN,konN);
	char liczba[20];
	while(!poczN && !konN){
		if((int)poczN-3>=0){
			if(strcmp(WytnijTekst(fu,poczN-3,3),"sin")==0){
				_gcvt_s(liczba,sizeof(liczba),sin(LiczFu(WytnijTekst(fu,poczN+1,konN-poczN-1),x)),10);
				ZastTekst(fu,liczba,poczN,konN-poczN+1);
			}else if(strcmp(WytnijTekst(fu,poczN-3,3),"cos")==0){
				_gcvt_s(liczba,sizeof(liczba),cos(LiczFu(WytnijTekst(fu,poczN+1,konN-poczN-1),x)),10);
				ZastTekst(fu,liczba,poczN,konN-poczN+1);
			}else if(strcmp(WytnijTekst(fu,poczN-3,3),"tan")==0){
				_gcvt_s(liczba,sizeof(liczba),tan(LiczFu(WytnijTekst(fu,poczN+1,konN-poczN-1),x)),10);
				ZastTekst(fu,liczba,poczN,konN-poczN+1);
			}else if(!strcmp(WytnijTekst(fu,poczN-1,1),"*") || !strcmp(WytnijTekst(fu,poczN-1,1),"/") || !strcmp(WytnijTekst(fu,poczN-1,1),"^") || !strcmp(WytnijTekst(fu,poczN-1,1),"+") || !strcmp(WytnijTekst(fu,poczN-1,1),"-")){
				_gcvt_s(liczba,sizeof(liczba),LiczFu(WytnijTekst(fu,poczN+1,konN-poczN-1),x),10);
				ZastTekst(fu,liczba,poczN,konN-poczN+1);
			}
		}
	}	
	return 0;
}