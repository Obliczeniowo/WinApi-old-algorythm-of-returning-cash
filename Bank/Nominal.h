#ifndef NOMIMAL_H
#define NOMINAL_H

#include <windows.h>

class Nominal{
public:
	int bigUnit, smallUnit;
	int count;

	Nominal(int bigUnit,int smallUnit,UINT count);
	Nominal(int bigUnit,int smallUnit);

	void SetNominal(int bigUnit,int smallUnit);

	int GetNominalInSmallUnit();
};

#endif