/*************************************************************************
                                 ElementListe
                             -------------------
    début                : 22/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ElementListe> (fichier ElementListe.h) ----
#if ! defined ( ElementListe_H )
#define ElementListe_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <ElementListe>
// Cette classe implémente les éléments de la classe Liste.
//------------------------------------------------------------------------

class ElementListe
{
//----------------------------------------------------------------- PUBLIC
public:
//-------------------------------------------- Constructeurs - destructeur
	ElementListe (const Trajet* t);
    // Mode d'emploi : aucun
    // Contrat : t est non nul

    virtual ~ElementListe ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

//---------------------------------------------------- Attributs publiques
	const Trajet * trajet;
	ElementListe * suivant;

};

#endif // ElementListe_H
