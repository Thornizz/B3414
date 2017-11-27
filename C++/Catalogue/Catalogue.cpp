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
	cout << endl;
	liste->Affiche();
	cout<<"}"<<endl;
} //----- Fin de Affiche

void Catalogue::Add (Trajet* t)
// Algorithme : aucun
//
{
	liste->Add(t);
} //----- Fin de Add

unsigned int Catalogue::RechercheParcours(const char* depart,const char* arrivee)
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

unsigned int Catalogue::RechercheParcoursAvancee(const char* depart,const char* arrivee)
// Algorithme : aucun
//
{
	unsigned int cpt = 0;
	cout<<"resultat :"<<endl;
	cout<<"{"<<endl;

	//ALGO A FAIRE

	cout<<"{"<<endl;
	return cpt;
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

