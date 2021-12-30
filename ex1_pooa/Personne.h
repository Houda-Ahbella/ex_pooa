#pragma once
#include <iostream>
using namespace std;
class Personne
{
private:
	string nom;
	string num_tel;
	string adress;
public:
	Personne(string n, string num, string a)
	{

		this->nom = n;
		this->num_tel = num;
		this->adress = a;
	}
	string recherche(string chaine, int choix)
	{
		if (choix == 0)
		{
			 return this->num_tel;
		}
		if (choix == 1)
		{
			 return this->adress;
		}
		return "";

	}

};

