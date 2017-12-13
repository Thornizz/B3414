/*************************************************************************
                                   Trajet
                             -------------------
    début                : 15/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ---------

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
{	
	cout<<GetDepart()<<" -> "<<GetArrivee();
} //----- Fin de Affiche

bool Trajet::IsBefore (const Trajet & t) const
// Algorithme : aucun
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

bool Trajet::Equals (const Trajet & t) const
// Algorithme : aucun
{
	//comparaison des moyens de transport
	const char* moyenTransport = t.GetMoyenTransport();
	const char* moyenTransportThis = this->GetMoyenTransport();
	if(moyenTransportThis == nullptr || moyenTransport == nullptr)
	{
		return false;
	}
	else
	{
		if(strlen(moyenTransport) != strlen(moyenTransportThis))
			return false;
		else
		{
			for(unsigned int i=0 ; i<strlen(moyenTransport) ; i++)
			{
				if(moyenTransport[i] != moyenTransportThis[i])
					return false;
			}
		}
	}
	
	//comparaison des départs
	const char* depart = t.GetDepart();
	const char* departThis = this->GetDepart();
	if(strlen(depart) != strlen(departThis))
		return false;
	else
	{
		for(unsigned int i=0 ; i<strlen(depart) ; i++)
		{
			if(depart[i] != departThis[i])
					return false;
		}
	}
	
	//comparaison des arrivées
	const char* arrivee = t.GetArrivee();
	const char* arriveeThis = this->GetArrivee();
	if(strlen(arrivee) != strlen(arriveeThis))
		return false;
	else
	{
		for(unsigned int i=0 ; i<strlen(arrivee) ; i++)
		{
			if(arrivee[i] != arriveeThis[i])
					return false;
		}
	}
	
	return true;
} //----- Fin de Equals

const char* Trajet::GetMoyenTransport() const
// Algorithme : aucun
{
	return nullptr;
} //----- Fin de GetMoyenTransport

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::~Trajet ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet
