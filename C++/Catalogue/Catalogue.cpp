/*************************************************************************
                                  Catalogue
                             -------------------
    début                : 18/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/
//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC
void Catalogue::Affiche () const
// Algorithme : aucun
{
	cout<<"Catalogue de trajets"<<endl<<"{"<<endl;
	if(liste == nullptr)
	{
		cout << "Erreur : TrajetCompose vide"<<endl;
		return;
	}
	liste->Affiche("    ");
	cout<<"}"<<endl;
} //----- Fin de Affiche

bool Catalogue::Add (const Trajet* t) const
// Algorithme : aucun
{
	ElementListe* cur = liste->first;
	while(cur != nullptr)
	{
		if(cur->trajet->Equals(*t))
		{
			return false;
		}
		cur=cur->suivant;
	}
	liste->Add(t);
	return true;
} //----- Fin de Add

unsigned int Catalogue::RechercheParcours(const char* depart,
												const char* arrivee) const
// Algorithme : aucun
{
	unsigned int cpt = 0;
	cout<<"resultat :"<<endl;
	cout<<"{"<<endl;
	
	ElementListe* cur = liste->first;	
	//parcours des trajets
	while(cur != nullptr)
	{
		//test sur le départ du trajet en cours
		bool ok = true;		
		const char* departCur = cur->trajet->GetDepart();
		if(strlen(departCur) != strlen(depart))
			ok = false ;
		else
		{
			for(unsigned int i=0 ; i<strlen(departCur) ; i++)
			{
				if(departCur[i] != depart[i])
					ok = false;
			}
		}

		//test sur l'arrivée du trajet en cours
		const char* arriveeCur = cur->trajet->GetArrivee();
		if(ok && strlen(arriveeCur) != strlen(arrivee))
			ok = false ;
		else
		{
			for(unsigned int i=0 ; i<strlen(arriveeCur) ; i++)
			{
				if(arriveeCur[i] != arrivee[i])
					ok = false;
			}
		}
		
		//conclusion
		if(ok)
		{
			cpt++;
			cur->trajet->Affiche();
			cout<<endl;
		}
		cur = cur->suivant;
	}
	cout<<"{"<<endl;
	return cpt;
} //----- Fin de RechercheParcours

void Catalogue::RechercheParcoursAvancee(const char* depart,
												const char* arrivee) const
// Algorithme : aucun
{
	// initialisation
	unsigned int nbTrajet = 0;
	ElementListe* cur = liste->first;
	while(cur != nullptr)
	{
		++nbTrajet;
		cur=cur->suivant;
	}
	unsigned int * tab = new unsigned int[nbTrajet];
	for(unsigned int i = 0 ; i < nbTrajet ; i++)
	{
		tab[i] = 0;
	}
	
	//récursivité et affichage
	cout<<"resultat :"<<endl;
	cout<<"{"<<endl;
	rechercheRecursive(depart,arrivee,tab,nbTrajet,1);
	cout<<"{"<<endl;
	
	delete[] tab;
} //----- Fin de RechercheParcoursAvancee

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ()
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	liste = new Liste();
} //----- Fin de Catalogue

Catalogue::~Catalogue ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	delete liste;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Methodes privées
void Catalogue::rechercheRecursive(const char* depart,
								const char* arrivee, unsigned int* tab, 
								const unsigned int lengthTab,
								const unsigned int position) const
// Algorithme : parcours en profondeur du catalogue de trajet
{	
	//test fin de récursivité
	bool compFin=true;
	if(strlen(arrivee) != strlen(depart))
		compFin = false ;
	else
	{
		for(unsigned int i=0 ; i<strlen(arrivee) ; i++)
		{
			if(depart[i] != arrivee[i])
				compFin = false;
		}
	}
	if(compFin)
	{
		//affichage d'une solution
		cout<<endl<<"*"<<endl;
		for(unsigned int p = 1 ; p<position ; p++)
		{
			unsigned int numTrajet = 0;
			ElementListe* cur = liste->first;
			while(tab[numTrajet]!=p)
			{
				cur=cur->suivant;
				++numTrajet;
			}
			cur->trajet->Affiche();
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	
	//recursivité
	unsigned int numTrajet = 0;
	ElementListe* cur = liste->first;	
	//parcours des trajets
	while(cur != nullptr)
	{
		//test sur le depart du trajet en cours
		bool compDepart = true;		
		const char* departCur = cur->trajet->GetDepart();
		if(strlen(departCur) != strlen(depart))
			compDepart = false ;
		else
		{
			for(unsigned int i=0 ; i<strlen(departCur) ; i++)
			{
				if(departCur[i] != depart[i])
					compDepart = false;
			}
		}
		
		//appel récursif si le depart convient et que le trajet n'est pas 
		//utilisé
		if(compDepart && tab[numTrajet]==0)
		{	
			tab[numTrajet]=position;
			rechercheRecursive(cur->trajet->GetArrivee(), arrivee, tab, 
												lengthTab, position+1);
			tab[numTrajet]=0;
		}
		//on passe au trajet suivant
		++numTrajet;
		cur = cur->suivant;
	}
} //----- Fin de rechercheRecursive
