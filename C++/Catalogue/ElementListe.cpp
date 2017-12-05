/*************************************************************************
                                  ElementListe
                             -------------------
    début                : 22/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <ElementListe> (fichier ElementListe.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ElementListe.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeurs - destructeur
ElementListe::ElementListe (const Trajet* t)
// Algorithme : aucun
:trajet(t),suivant(nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur de <ElementListe>" << endl;
#endif
} //----- Fin de ElementListe

ElementListe::~ElementListe ( )
// Algorithme : aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <ElementListe>" << endl;
#endif
	delete trajet;
} //----- Fin de ~ElementListe
