/*************************************************************************
                                   Trajet
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Affiche () const
// Algorithme : aucun
//
{	
	cout<<GetDepart()<<" -> "<<GetArrivee();
} //----- Fin de Affiche

bool Trajet::IsBefore (Trajet& t) const
// Algorithme : aucun
//
{
	const char* departT = t.GetDepart();
	const char* arriveeThis = this->GetArrivee();

	if(strlen(departT) != strlen(arriveeThis))
		return false;
	else
	{
		for(unsigned int i=0 ; i<strlen(departT) ; i++)
		{
			if(departT[i] != arriveeThis[i])
				return false;
		}
	}
	return true;
} //----- Fin de IsBefore

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( )
// Algorithme : aucun
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme : aucun
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

