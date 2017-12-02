/*************************************************************************
                                  Liste
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Liste> (fichier Liste.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Liste.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Liste::Affiche(const char * texte)
{
	ElementListe *cur=first;
	unsigned int i=1;
	while(cur!=NULL)
	{
		cout<<texte<<i<<") ";
		cur->trajet->Affiche();
		cout<<endl;
		cur = cur->suivant;
		++i;
	}
}


void Liste::Add(Trajet* t)
// Algorithme :
//
{
	ElementListe* e = new ElementListe(t);
	if(first==NULL){
		first=e;
		return;
	}
	ElementListe* cur = first;
	ElementListe* next = cur->suivant;
	while(next!=NULL){
		cur = next;
		next = cur->suivant;
	}
	cur->suivant = e;
} //----- Fin de Add

//-------------------------------------------- Constructeurs - destructeur
Liste::Liste ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
first = NULL;
} //----- Fin de Liste


Liste::~Liste ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
	ElementListe *cur=first;
	ElementListe *next;
	while(cur!=NULL)
	{
		next = cur->suivant;
		delete cur;
		cur = next;
	}
} //----- Fin de ~Liste
