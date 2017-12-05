/*************************************************************************
                                   Trajet
                             -------------------
    début                : 15/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( Trajet_H )
#define Trajet_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe est construite comme la classe mère des classes 
// TrajetSimple et TrajetCompose.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    virtual void Affiche() const;
    // Mode d'emploi : affiche les attributs du contexte appelant
    // Contrat : aucun
    
	virtual bool IsBefore(const Trajet& t) const;
    // Mode d'emploi : retourne true si le départ de t correspond à 
	//     l'arrivée du contexte appelant. Sinon retourne false
    // Contrat : aucun
    
	virtual bool Equals(const Trajet& t) const;
    // Mode d'emploi : retourne true si l'on compare un trajet simple à 
	//     un autre trajet simple identique, sinon retourne false
    // Contrat : aucun

	virtual const char* GetDepart() const = 0;
    // Mode d'emploi : renvoi le depart du trajet
    // Contrat : aucun
    
	virtual const char* GetArrivee() const = 0;
    // Mode d'emploi : renvoi l'arrivée du trajet
    // Contrat : aucun
    
	virtual const char* GetMoyenTransport() const;
    // Mode d'emploi : renvoi le moyen de transport s'il existe sinon nul
    // Contrat : aucun

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

    virtual ~Trajet ( );
    // Mode d'emploi : aucun
    // Contrat : aucun

};

#endif // Trajet_H
