#include "Nominal.h"

Nominal::Nominal(int bigUnit,int smallUnit,UINT count){
	this->bigUnit	= bigUnit;
	this->smallUnit	= smallUnit;
	this->count		= count;
}

void Nominal::SetNominal(int bigUnit,int smallUnit){
	this->bigUnit	= bigUnit;
	this->smallUnit	= smallUnit;
}

int Nominal::GetNominalInSmallUnit(){
	return bigUnit * 100 + smallUnit;
}

Nominal::Nominal(int bigUnit,int smallUnit){
	this->bigUnit	= bigUnit;
	this->smallUnit	= smallUnit;
	this->count		= 0;	
}