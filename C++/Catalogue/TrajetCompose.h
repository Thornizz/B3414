/*************************************************************************
                                TrajetCompose
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Liste.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <TrajetCompose>
// Permet d'implémenter les trajets composés
//
//------------------------------------------------------------------------ 

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Affiche()const;
    // Mode d'emploi : affiche les caractéristiques du trajet
    //
    // Contrat :
    //

	bool Add(Trajet* t);
	// Mode d'emploi : permet d'ajouter un trajet à la suite de l'actuel, renvoie true si cela est possible sinon false
	//
	// Contrat :
	//

	bool IsBefore(Trajet& t)const;
	// Mode d'emploi : retourne true si le départ de t correspond à l'arrivée du contexte appelant. Sinon retourne false.
	//
	// Contrat :
	//

	const char* GetDepart()const;
	// Mode d'emploi : renvoie le départ du trajet
	//
	// Contrat :
	//

	const char* GetArrivee()const;
	// Mode d'emploi : renvoie l'arrivée du trajet
	//
	// Contrat :
	//    

//-------------------------------------------- Constructeurs - destructeur
      TrajetCompose (Trajet* t1, Trajet* t2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//---------------------------------------------------------------- PROTEGE

protected:
//----------------------------------------------------- Attributs protégés
	Liste * liste;
};

//----------------------------------------- Types dépendants de <TrajetCompose>

#endif // TrajetCompose_H
