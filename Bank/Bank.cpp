#include "bank.h"

Bank::Bank(std::string bankName){ // Inicjalizacja podstawowych nomina³ów
	this->bankName = bankName;
	Nominal n(500,0);
	//tNominal.push_back(n);
	n.SetNominal(200,0);
	tNominal.push_back(n);
	n.SetNominal(100,0);
	tNominal.push_back(n);
	n.SetNominal(50,0);
	tNominal.push_back(n);
	n.SetNominal(20,0);
	tNominal.push_back(n);
	n.SetNominal(10,0);
	tNominal.push_back(n);
	n.SetNominal(5,0);
	tNominal.push_back(n);
	n.SetNominal(2,0);
	tNominal.push_back(n);
	n.SetNominal(1,0);
	tNominal.push_back(n);
	n.SetNominal(0,50);
	tNominal.push_back(n);
	n.SetNominal(0,20);
	tNominal.push_back(n);
	n.SetNominal(0,10);
	tNominal.push_back(n);
	n.SetNominal(0,5);
	tNominal.push_back(n);
	n.SetNominal(0,2);
	tNominal.push_back(n);
	n.SetNominal(0,1);
	tNominal.push_back(n);
}

Bank::~Bank(){
	tNominal.clear();
}

void Bank::AddNominal(Nominal n){
	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		if(n.GetNominalInSmallUnit() == i->GetNominalInSmallUnit()){
			i->count += n.count;
			break;
		}
	}
}
void Bank::AddNominal(int bigUnit,int smallUnit,int count){
	Nominal n(bigUnit, smallUnit, count);
	AddNominal(n);
}
std::vector<Nominal> Bank::GetCashFromBank(int cashZl,int cashGr){
	std::vector<Nominal> CashFromBank;
	
	if(cashZl < 0 || cashGr < 0)
		return CashFromBank;

	int c = cashZl * 100 + cashGr;

	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		if(i->bigUnit * 100 + i->smallUnit <= c && i->bigUnit + i->smallUnit > 0){
			int nr = c / (i->bigUnit * 100 + i->smallUnit);
			if(nr > i->count){
				nr = i->count;
			}
			c = c - nr * (i->bigUnit * 100 + i->smallUnit);
			Nominal n(i->bigUnit,i->smallUnit,nr);
			CashFromBank.push_back(n);

			i->count -= nr;

			if(c == 0)
				return CashFromBank;
		}
	}

	return CashFromBank;
}

void Bank::DrawBankCash(HDC &hdc,Drawing *draw,int x,int y){
	int dy = 20;
	SetTextColor(hdc,RGB(255,255,255));
	SetBkMode(hdc,TRANSPARENT);
	char c[MAX_PATH];
	int bUnit = 0;
	int sUnit = 0;
	draw->textOut(hdc,x,y,bankName.c_str(), bankName.size());
	draw->line(hdc,x,y + dy,x + 100,y + dy,RGB(255,255,255),PS_SOLID,1);
	dy += 5;
	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		bUnit += i->bigUnit * i->count;
		sUnit += i->smallUnit * i->count;
		sprintf_s(c,MAX_PATH,"%iz³ %igr x %i",i->bigUnit,i->smallUnit,i->count);
		draw->textOut(hdc,x,y + dy,c,-1);
		dy += 20;
	}
	draw->line(hdc,x,y + dy,x + 100,y + dy,RGB(255,255,255),PS_SOLID,1);
	dy += 5;
	bUnit += (sUnit - sUnit % 100) / 100;
	sUnit = sUnit % 100;
	sprintf_s(c,MAX_PATH,"Razem: %iz³ %igr",bUnit,sUnit);
	draw->textOut(hdc,x,y + dy,c,-1);
}

int Bank::operator +=(std::vector<Nominal> &tNominal){
	int value = 0;
	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		for(std::vector<Nominal>::iterator j = this->tNominal.begin(); j < this->tNominal.end(); j++){
			if(i->GetNominalInSmallUnit() == j->GetNominalInSmallUnit()){
				j->count += i->count;
				value += i->GetNominalInSmallUnit() * i->count;
			}
		}
	}
	return value;
}

int Bank:: operator -=(std::vector<Nominal> &tNominal){
	int cash = 0;
	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		if(i->count)
			cash += i->GetNominalInSmallUnit();
	}
	GetCashFromBank(cash / 100, cash % 100);

	return cash;
}

void Bank::operator =(std::vector<Nominal> &tNominal){
	for(std::vector<Nominal>::iterator i = tNominal.begin(); i < tNominal.end(); i++){
		for(std::vector<Nominal>::iterator j = this->tNominal.begin(); j < this->tNominal.end(); j++){
			if(i->GetNominalInSmallUnit() == j->GetNominalInSmallUnit()){
				j->count = i->count;
			}
		}
	}	
}

int Bank::Transfer(Bank &toThisBank,int bigUnit,int smallUnit){
	int v = 0;
	if((v = toThisBank += this->GetCashFromBank(bigUnit,smallUnit)) != bigUnit * 100 + smallUnit){
		std::string s = "Bank ";
		s += this->bankName;
		s += " nie ma odpowiednich nomina³ów";

		MessageBox(NULL,s.c_str(),"Info",MB_OK);
	}
	return v;
}