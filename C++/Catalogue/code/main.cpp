/*************************************************************************
                                  Main
                             -------------------
    début                : 18/11/2017
    copyright            : (C) 2017 par Loïc CASTELLON & Florian MUTIN
    e-mail               : loic.castellon@insa-lyon.fr
			   			   florian.mutin@insa-lyon.fr
*************************************************************************/
using namespace std;
#include <iostream>
#include "TrajetCompose.h"
#include "Catalogue.h"
#include <cstring>

void application();
// Mode d'emploi : lancement de l'application
// Contrat : aucun

void majuscule(char *chaine);
// Mode d'emploi : change les minuscules en majuscules (hors caractères
//     spéciaux, accents, cédilles)
// Contrat : chaine est non nul

int main (){
	application();
	return 0;
	
}

void application()
// Algorithme : un switch dans un while permet d'évoluer dans le menu 
//      puis de revenir au menu principal autant de fois que souhaité.
{
	const unsigned int NB_MAX_CHAR = 100;

	cout<<endl;
	cout<<"******************************"<<endl;
	cout<<"* Ouverture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
	cout<<"----------------------------------------------------------";
	cout<<endl<<endl;

	Catalogue catalogue;
	unsigned int saisieMenu;
	do
	{	
		cout<<"Menu :"<<endl;
		cout<<"0) quitter l'application"<<endl;
		cout<<"1) ajouter un trajet simple"<<endl;
		cout<<"2) ajouter un trajet composé"<<endl;
		cout<<"3) afficher le catalogue"<<endl;
		cout<<"4) recherche de parcours"<<endl;
		cout<<"5) recherche avancée de parcours"<<endl;
		cout<<endl;
		cout <<"Saisissez votre choix : ";
		cin>>saisieMenu;
		cout<<endl;
		switch(saisieMenu)
		{
		
			// AJOUT TRAJET SIMPLE
			case 1:
			{
				cout<<"-- ajouter un trajet simple --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char* depart = new char[NB_MAX_CHAR];
				cin >> depart;
				majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR];
				cin >> arrivee;
				majuscule(arrivee);
				cout <<"Saisissez le moyen de transport : ";
				char* moyenTransport = new char[NB_MAX_CHAR];
				cin >> moyenTransport;
				majuscule(moyenTransport);
				
				Trajet * t = new TrajetSimple(
										depart,arrivee,moyenTransport);
				if(!catalogue.Add(t))
				{
					cout<<"Ce trajet est déjà présent dans le catalogue.";
					cout<<endl;
					delete t;
				}
				
				break;
			}
			
			// AJOUT TRAJET COMPOSE
			case 2:
			{
				//saisie d'au moins un départ et une étape
				cout<<"-- ajouter un trajet composé --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char* depart = new char[NB_MAX_CHAR];
				cin >> depart;
				majuscule(depart);
				cout <<"Saisissez une ville étape : ";
				char* etape = new char[NB_MAX_CHAR];
				cin >> etape;
				majuscule(etape);
				cout <<"Saisissez le moyen de transport : ";
				char* moyenTransport = new char[NB_MAX_CHAR];
				cin >> moyenTransport;
				majuscule(moyenTransport);
				
				Trajet * td = new TrajetSimple(
											depart,etape,moyenTransport);
				
				char* etapeCopie = new char[NB_MAX_CHAR];
				strcpy(etapeCopie,etape);
				
				TrajetCompose * tc;
				bool creation = true;
				
				//saisie et ajout d'autant d'étape que souhaité
				bool continuer;
				cout << "--" <<endl;
				cout << "O) Saisir la ville d'arrivee" <<endl;
				cout << "1) Saisir une ville étape" <<endl;
				cout << "Votre choix : "; 
				cin >> continuer;
				cout << "--" <<endl;
				
				while(continuer)
				{
					//saisie de l'étape
					cout <<"Saisissez une ville étape : ";
					etape = new char[NB_MAX_CHAR];
					cin >> etape;
					majuscule(etape);
					cout <<"Saisissez le moyen de transport : ";
					moyenTransport = new char[NB_MAX_CHAR];
					cin >> moyenTransport;
					majuscule(moyenTransport);
					
					Trajet * t = new TrajetSimple(
										etapeCopie,etape,moyenTransport);
					//ajout de l'étape (création du trajet composé si 
					//nécessaire)
					if(creation)
					{
						tc = new TrajetCompose(td,t);
						creation = false;
					}
					else
					{
						tc->Add(t);
					}
					
					etapeCopie = new char[NB_MAX_CHAR];
					strcpy(etapeCopie,etape);
					
					cout << "--" <<endl;
					cout << "O) Saisir la ville d'arrivee" <<endl;
					cout << "1) Saisir une ville étape" <<endl;
					cout << "Votre choix : "; 
					cin >> continuer;
					cout << "--" <<endl;
				}
				
				//saisie de l'arrivée
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR];
				cin >> arrivee;
				majuscule(arrivee);
				cout <<"Saisissez le moyen de transport : ";
				moyenTransport = new char[NB_MAX_CHAR];
				cin >> moyenTransport;
				majuscule(moyenTransport);
				
				Trajet * ta = new TrajetSimple(
									etapeCopie,arrivee,moyenTransport);
				//ajout de l'arrivée (création du trajet composé si 
				//nécessaire)
				if(creation)
				{
					tc = new TrajetCompose(td,ta);
					creation = false;
				}
				else
				{
					tc->Add(ta);
				}
				
				catalogue.Add(tc);
				
				break;
			}
			
			
			// AFFICHAGE CATALOGUE
			case 3:
				cout<<"-- afficher le catalogue --"<<endl;
				catalogue.Affiche();
				break;
			
			
			// RECHERCHE PARCOURS
			case 4:
			{
				cout<<"-- recherche de parcours --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char* depart = new char[NB_MAX_CHAR];
				cin >> depart;
				majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR];
				cin >> arrivee;
				majuscule(arrivee);
				
				catalogue.RechercheParcours(depart,arrivee);
				
				delete[] depart;
				delete[] arrivee;
				
				break;
			}
			
			// RECHERCHE AVANCEE PARCOURS
			case 5:
			{
				cout<<"-- recherche avancée de parcours --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char* depart = new char[NB_MAX_CHAR];
				cin >> depart;
				majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR];
				cin >> arrivee;
				majuscule(arrivee);
				
				catalogue.RechercheParcoursAvancee(depart,arrivee);
				
				delete[] depart;
				delete[] arrivee;
				
				break;
			}
		}
	cout<<endl;
	cout<<"----------------------------------------------------------";
	cout<<endl<<endl;
	}
	while(saisieMenu != 0);

	
	cout<<"******************************"<<endl;
	cout<<"* Fermeture de l'application *"<<endl;
	cout<<"******************************"<<endl<<endl;
} //----- Fin de application

void majuscule(char *chaine)
// Algorithme : aucun
{
	unsigned int i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i]  >= 97 &&  chaine[i] <= 122)
			chaine[i] = chaine[i] - 32;
		i++;
	}
} //----- Fin de majuscule
