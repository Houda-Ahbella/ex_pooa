// ex1_pooa.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include "Personne.h"
#include <unordered_map>
using namespace std;

template<class T>
void printStack(stack<T> & mystack)
{


	while (!mystack.empty())
	{
		cout << mystack.top() ;
		mystack.pop();
	}
	cout << "\n";
}
template<class T>
void printVect(vector<T> & vect)
{

	for (int i = 0;i < vect.size();i++)
		cout << vect[i];
	cout << "\n";
}
template<class T>
bool phrase_palindrome(vector<T>& vect, stack<T>& mystack)
{

	for (int i = 0;i < vect.size();i++)
	{ if(!mystack.empty())
	  {
		if (vect[i] != mystack.top())
			return false;
		mystack.pop();
	   }
		
	}
	return true;
}
void palindrome()
{
	stack<char> mystack;
	char lettre;
	vector<char> myvect;
	cout << "donner la phrase\n";
	while ((lettre = getchar()) != '\n')
	{
		if (lettre != ' ' && lettre != '\t' && lettre != ',' &&lettre != '.' && lettre != '-')
		{
			mystack.push(lettre);
			myvect.push_back(lettre);
		}
	}

	if (phrase_palindrome(myvect, mystack))
	
		cout << "is palindrome\n";
	
	else
	
		
		cout << "is not palindrome\n";
	

}
int main()
{
	// a ----->
	cout << "Exercice 1" << endl;
	cout << "a---->" << endl;
	deque<string> dec;
	list<string> lst;
	dec.push_back("Houda");
	dec.push_back("Zineb");
	dec.push_back("Hajar");
	dec.push_back("Ali");
	for (auto c : dec)
		lst.push_back(c);

	lst.sort();

	for (auto c : lst)
		cout << c << " ";

	cout << "\n";
	

	// b----> phrase palindrome
	cout << "a---->" << endl;
	palindrome();

	// c------>
	cout << "*********C**************" << endl;
	int nmbr;
	
	priority_queue<string> q;

	cout << "donner le nombre de mot\n";
	cin >> nmbr;
	cout << "donner les mots \n";
	string mot;
	for (int i = 0;i < nmbr;i++)
	{
		cin >> mot;
		q.push(mot);
	}
	cout << "la file\n";
	while (!q.empty()) 
	{
		std::cout << q.top() << ' ';
		q.pop();
	}
	  cout << '\n';

	


	cout << "********Exercice2********" << endl;
	int n;
	string m;
	list<string> l;
	cout << "donner le nombre de mot\n";
	cin >> n;
	cout << "donner les mots\n";
	// a----->
	for (int i = 0;i < n;i++)
	{
		cin >> m;
		l.push_back(m);
	}
	list <string> copie(l.size());
	list <string> copie1(l.size());
	// b--->
	transform(l.begin(), l.end(), copie.begin(), [](string c)
		{
			for (int i = 0; i < c.size(); i++)
			{
				if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'u' || c[i] == 'y' || c[i] == 'o') c[i] = '*';
			}
			return c;
		});
	
	cout << "1 ere transformation\n";
	for (auto i : copie)
	
		cout << i << " ";
	cout << "\n";
	
	// c---->
	transform(l.begin(), l.end(), copie1.begin(), [](string c)
		{
			for (int i = 0; i < c.size(); i++)
			{
				c[i] = toupper(c[i]);
			}
			return c;
		});
	cout << "2 eme transformation\n";
	for (auto i : copie1)
	
		cout << i << " ";

	cout << "\n";

	cout << "***********Exercice3***********\n";
	Personne p1("houda","0630935619","a1");Personne p2("zineb","0644935619","a2");
	unordered_multimap<string, Personne> un;
	un.insert(make_pair("houda",p1));
	un.insert(make_pair("zineb",p2));
	string nom;
	int choix;
	cout << "donner le nom\n";
	cin >> nom;
	cout << "donner le choix 0 pour afficher le numero du tele et 1 pour l adrress\n";
	cin >> choix;
	for (auto i : un)
	{
		if(i.first==nom)
		if (i.second.recherche(nom, choix) != "")
		{ 
			cout <<"resultat :" << i.second.recherche(nom, choix) << endl;
			break;
		}
	}
	cout << "Fin du programme!!!" << endl;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
