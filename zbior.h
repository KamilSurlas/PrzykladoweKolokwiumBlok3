#pragma once
class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
	void wypelnijZbior();
	double sumaElZbioru() const;
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { 	zwolnij(); }
	void setRozmiar(int rozmiar);
	void pokazZbior();	
	bool operator>(const Zbior& prawyOperand);
	bool operator<(const Zbior& prawyOperand);
	//konwersja formalna
	explicit operator double();
	//konwersja nieformalna
	static Zbior zInt(int n);
};

