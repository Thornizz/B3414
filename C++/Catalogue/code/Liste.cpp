/*************************************************************************
                                  Liste
                             -------------------
    début                : 22/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//--------- Réalisation de la classe <Liste> (fichier Liste.cpp) ---------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Liste.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Liste::Affiche(const char * texte) const
// Algorithme : aucun
{
	ElementListe *cur=first;
	unsigned int i=1;
	while(cur!=nullptr)
	{
		cout<<texte<<i<<") ";
		cur->trajet->Affiche();
		cout<<endl;
		cur = cur->suivant;
		++i;
	}
} //----- Fin de Affiche

void Liste::Add(const Trajet* t)
// Algorithme : aucun
{
	ElementListe* e = new ElementListe(t);
	if(first==nullptr){
		first=e;
		return;
	}
	ElementListe* cur = first;
	ElementListe* next = cur->suivant;
	while(next!=nullptr){
		cur = next;
		next = cur->suivant;
	}
	cur->suivant = e;
} //----- Fin de Add

//-------------------------------------------- Constructeurs - destructeur
Liste::Liste ()
// Algorithme : aucun
:first(nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
} //----- Fin de Liste


Liste::~Liste ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
	ElementListe *cur=first;
	ElementListe *next;
	while(cur!=nullptr)
	{
		next = cur->suivant;
		delete cur;
		cur = next;
	}
} //----- Fin de ~Liste
