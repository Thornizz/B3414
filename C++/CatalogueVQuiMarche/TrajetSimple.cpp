/*************************************************************************
                                  TrajetSimple
                             -------------------
    début                : 15/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
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
{	
	Trajet::Affiche();
	cout << " | " << moyenTransport;
} //----- Fin de Affiche

bool TrajetSimple::IsBefore (const Trajet& t) const
// Algorithme : aucun
{
	return Trajet::IsBefore (t);
} //----- Fin de IsBefore

const char* TrajetSimple::GetDepart() const{
// Algorithme : aucun
	return depart;
} //----- Fin de GetDepart

const char* TrajetSimple::GetArrivee() const{
// Algorithme : aucun
	return arrivee;
} //----- Fin de GetArrivee

const char* TrajetSimple::GetMoyenTransport() const
// Algorithme : aucun
{
	return moyenTransport;
} //----- Fin de GetMoyenTransport
    
void TrajetSimple::Save(const ofstream& ofs) const
// Algorithme : aucun
{
	cout << "METHODE TrajetSimple::Save A FAIRE"<<endl;
} //----- Fin de Save

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* d, const char* a, const char* mT)
// Algorithme : aucun
: depart(d),arrivee(a),moyenTransport(mT)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
{
	delete[] depart;
	delete[] arrivee;
	delete[] moyenTransport;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple
