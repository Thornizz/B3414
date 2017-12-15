/*************************************************************************
                                  Liste
                             -------------------
    début                : 22/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//----------- Interface de la classe <Liste> (fichier Liste.h) -----------
#if ! defined ( Liste_H )
#define Liste_H

//--------------------------------------------------- Interfaces utilisées
#include "ElementListe.h"

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
// Cette classe implémente une liste chainée de Trajets
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Add(const Trajet* t);
    // Mode d'emploi : ajout de t en fin de liste
    // Contrat : t est non nul

	void Affiche(const char * texte) const;
    // Mode d'emploi : affiche tout les élements du contexte appelant en
	//     affichant texte devant
    // Contrat : texte est non nul

//-------------------------------------------- Constructeurs - destructeur
	Liste ();
    // Mode d'emploi : aucun
    // Contrat : aucun

    virtual ~Liste ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

//---------------------------------------------------- Attributs publiques
	ElementListe * first;

};

#endif // Liste_H
