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
//
//
//------------------------------------------------------------------------ 

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Affiche()const;
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Add(Trajet* t);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool IsBefore(Trajet& t)const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	const char* GetDepart()const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	const char* GetArrivee()const;
	// Mode d'emploi :
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
