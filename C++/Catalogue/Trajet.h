/*************************************************************************
                                   Trajet
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe est construite comme la classe mère des classes TrajetSimple, TrajetCompose et ElementTrajet.
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void Affiche() const;
    // Mode d'emploi : affiche les attributs du contexte appelant
    //
    // Contrat : aucun
    //
    
	virtual bool IsBefore(Trajet& t) const;
    // Mode d'emploi : retourne true si le départ de t correspond à l'arrivée du contexte appelant. Sinon retourne false.
    //
    // Contrat : aucun
    //

	virtual const char* GetDepart() const = 0;
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //
    
	virtual const char* GetArrivee() const = 0;
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur

    Trajet ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

    virtual ~Trajet ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

