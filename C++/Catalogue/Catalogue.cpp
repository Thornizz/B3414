//ElementTrajetSimple à remplacer par ElementTrajet
/*************************************************************************
                                  Catalogue
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

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
//
{
	cout<<"Catalogue de trajets"<<endl<<"{"<<endl;
	if(liste == NULL)
	{
		cout << "Erreur : TrajetCompose vide"<<endl;
		return;
	}
	liste->Affiche("    ");
	cout<<"}"<<endl;
} //----- Fin de Affiche

void Catalogue::Add (const Trajet* t) const
// Algorithme : aucun
//
{
	liste->Add(t);
} //----- Fin de Add

unsigned int Catalogue::RechercheParcours(const char* depart,const char* arrivee) const
// Algorithme : aucun
//
{
	unsigned int cpt = 0;
	cout<<"resultat :"<<endl;
	cout<<"{"<<endl;
	
	ElementListe* cur = liste->first;	
	//parcours des trajets
	while(cur != NULL)
	{
		//test sur le depart et l'arrivee du trajet en cours
		bool ok = true;		
		const char* departCur = cur->trajet->GetDepart();
		const char* arriveeCur = cur->trajet->GetArrivee();
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
		//on passe au trajet suivant
		cur = cur->suivant;
	}
	cout<<"{"<<endl;
	return cpt;
} //----- Fin de RechercheParcours

void Catalogue::RechercheParcoursAvancee(const char* depart,const char* arrivee) const
// Algorithme : aucun
//
{
	// initialisation
	unsigned int nbTrajet = 0;
	ElementListe* cur = liste->first;
	while(cur != NULL)
	{
		++nbTrajet;
		cur=cur->suivant;
	}
	unsigned int * tab =  (unsigned int *) malloc(sizeof(unsigned int)*nbTrajet);
	for(unsigned int i = 0 ; i < nbTrajet ; i++)
	{
		tab[i] = 0;
	}
	
	cout<<"resultat :"<<endl;
	cout<<"{"<<endl;
	rechercheRecursive(depart,arrivee,tab,nbTrajet,1);
	cout<<"{"<<endl;
	
	free(tab);
} //----- Fin de RechercheParcoursAvancee

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ()
// Algorithme : aucun
//

{
	liste = new Liste();
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme : aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	delete liste;
} //----- Fin de ~Catalogue



//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Methodes privées

void Catalogue::rechercheRecursive(const char* depart,const char* arrivee, unsigned int* tab, const unsigned int lengthTab,const unsigned int position) const
// Algorithme : aucun
//
{		
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
	
	unsigned int numTrajet = 0;
	ElementListe* cur = liste->first;	
	//parcours des trajets
	while(cur != NULL)
	{
		//test sur le depart et l'arrivee du trajet en cours
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
		
		if(compDepart && tab[numTrajet]==0)
		{	
			tab[numTrajet]=position;
			rechercheRecursive(cur->trajet->GetArrivee(), arrivee, tab, lengthTab, position+1);
			tab[numTrajet]=0;
		}
		//on passe au trajet suivant
		++numTrajet;
		cur = cur->suivant;
	}
} //----- Fin de rechercheRecursive

