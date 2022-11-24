#include "zbior.h"
#include <new>
#include <random>
#include <iostream>

void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

void Zbior::wypelnijZbior()
{
	std::uniform_real_distribution<double> zakres(m_dolnaGranica, m_gornaGranica);
	std::random_device generator;
	for (int elem = 0; elem < m_liczbaElementow; elem++)
		m_elementy[elem] = zakres(generator);
}

double Zbior::sumaElZbioru() const
{
	double suma = 0.0;
	for (size_t i = 0; i < m_liczbaElementow; i++)
	{
		suma = suma + m_elementy[i];
	}
	return suma;
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	m_dolnaGranica = dGran;
	m_gornaGranica = gGran;
	wypelnijZbior();
}

void Zbior::setRozmiar(int rozmiar)
{
	if (rozmiar != m_liczbaElementow) 
	{
		if (rozmiar > 0)
		{
			double* temp = new double[rozmiar];
			if (rozmiar < m_liczbaElementow)
				memcpy(temp, m_elementy, rozmiar * sizeof(double));
			else {
				memcpy(temp, m_elementy, m_liczbaElementow * sizeof(double));
				std::uniform_real_distribution<double> zakres(m_dolnaGranica,m_gornaGranica);
				std::random_device generator;
				for (int elem = m_liczbaElementow; elem < rozmiar; elem++)
					temp[elem] = zakres(generator);
			}
			zwolnij();
			m_liczbaElementow = rozmiar;
			m_elementy = temp;
			temp = nullptr;
		}
		else zwolnij();
	}
}

void Zbior::pokazZbior()
{
	for (int i = 0; i < m_liczbaElementow; i++) {
	std::cout << m_elementy[i] << " ; ";
	}
}

bool Zbior::operator>(const Zbior& prawyOperand)
{
	return (this->sumaElZbioru() > prawyOperand.sumaElZbioru());
}
	
bool Zbior::operator<(const Zbior& prawyOperand)
{
	return (this->sumaElZbioru() < prawyOperand.sumaElZbioru());
}
// konwersja formalna
Zbior::operator double()
{
	return this->sumaElZbioru();
}
// konwersja nieformalna
Zbior Zbior::zInt(int n)
{
	return Zbior(n, 0.0, 1.0);
}


