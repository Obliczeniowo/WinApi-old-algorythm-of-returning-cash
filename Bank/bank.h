#ifndef BANK_H
#define BANK_H

#include <Windows.h>
#include "Drawing.h"
#include "Nominal.h"
#include <string>
#include <vector>

class Bank{
	std::vector<Nominal> tNominal;
public:
	std::string bankName;
	Bank(std::string bankName);
	~Bank();

	void AddNominal(Nominal n);
	void AddNominal(int bigUnit,int smallUnit, int count);

	std::vector<Nominal> GetCashFromBank(int cashZl,int cashGr);

	void DrawBankCash(HDC &hdc,Drawing *draw,int x,int y);

	int Transfer(Bank &toThisBank,int bigUnit,int smallUnit);

	void operator =(std::vector<Nominal> &tNominal);
	int operator +=(std::vector<Nominal> &tNominal);
	int operator -=(std::vector<Nominal> &tNominal);
};

#endif