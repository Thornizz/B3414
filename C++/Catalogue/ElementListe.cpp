/*************************************************************************
                                  ElementListe
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// Algorithme :
//
:trajet(t),suivant(NULL)
{
#ifdef MAP
    cout << "Appel au constructeur de <ElementListe>" << endl;
#endif
} //----- Fin de ElementListe


ElementListe::~ElementListe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElementListe>" << endl;
#endif
	delete trajet;
} //----- Fin de ~ElementListe
