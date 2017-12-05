/*************************************************************************
                                  TrajetSimple
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Affiche () const
// Algorithme : aucun
//
{	
	Trajet::Affiche();
	cout << " | " << moyenTransport;
} //----- Fin de Affiche

bool TrajetSimple::IsBefore (const Trajet& t) const
// Algorithme : aucun
//
{
	return Trajet::IsBefore (t);
} //----- Fin de IsBefore


const char* TrajetSimple::GetDepart() const{
	return depart;
}


const char* TrajetSimple::GetArrivee() const{
	return arrivee;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* d, const char* a, const char* mT)
// Algorithme :
//
: depart(d),arrivee(a),moyenTransport(mT)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
	
	free((char*) depart);
	free((char*) arrivee);
	free((char*) moyenTransport);
	
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple
