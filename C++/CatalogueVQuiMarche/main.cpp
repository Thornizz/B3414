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
#include <limits> 

void application();
// Mode d'emploi : lancement de l'application
// Contrat : aucun

void Majuscule(char *chaine);
// Mode d'emploi : change les minuscules en Majuscules (hors caractères
//     spéciaux, accents, cédilles)
// Contrat : chaine est non nul


bool ReadChoice( unsigned int & N, unsigned int min, unsigned int max );
// Mode d'emploi : permet de récupérer un int entre min et max
// Contrat : min est inférieur à max

int main (){	
	application();

	return 0;

}

void application()
// Algorithme : un switch dans un while permet d'évoluer dans le menu
//      puis de revenir au menu principal autant de fois que souhaité.
{
	const unsigned int NB_MAX_CHAR1 = 100;

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
		cout<<"6) changement du fichier de sauvegarde"<<endl;
		cout<<"7) chargement entière de la sauvegarde"<<endl;
		cout<<"8) chargement partielle de la sauvegarde selon le type"<<endl;
		cout<<"9) chargement partielle de la sauvegarde selon depart/arrivee"<<endl;
		cout<<"11) enregistrement entière du catalogue dans la sauvegarde"<<endl;
		cout<<"12) enregistrement du catalogue dans la sauvegarde ";
		cout<< "selon le type de trajet"<<endl;
		cout<<"13) enregistrement du catalogue dans la sauvegarde";
		cout<<" selon depart/arrivee"<<endl;
		cout<<"14) enregistrement du catalogue dans la sauvegarde";
		cout<<" selon un interval"<<endl;
		ReadChoice(saisieMenu,0,14);
		cout<<endl;
		switch(saisieMenu)
		{

			// AJOUT TRAJET SIMPLE
			case 1:
			{
				cout<<"-- ajouter un trajet simple --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				char* depart = new char[NB_MAX_CHAR1];
				cin >> depart;
				Majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR1];
				cin >> arrivee;
				Majuscule(arrivee);
				cout <<"Saisissez le moyen de transport : ";
				char* moyenTransport = new char[NB_MAX_CHAR1];
				cin >> moyenTransport;
				Majuscule(moyenTransport);

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
				char* depart = new char[NB_MAX_CHAR1];
				cin >> depart;
				Majuscule(depart);
				cout <<"Saisissez une ville étape : ";
				char* etape = new char[NB_MAX_CHAR1];
				cin >> etape;
				Majuscule(etape);
				cout <<"Saisissez le moyen de transport : ";
				char* moyenTransport = new char[NB_MAX_CHAR1];
				cin >> moyenTransport;
				Majuscule(moyenTransport);

				Trajet * td = new TrajetSimple(
											depart,etape,moyenTransport);

				char* etapeCopie = new char[NB_MAX_CHAR1];
				strcpy(etapeCopie,etape);

				TrajetCompose * tc;
				bool creation = true;

				//saisie et ajout d'autant d'étape que souhaité
				unsigned int continuer;
				cout << "--" <<endl;
				cout << "O) Saisir la ville d'arrivee" <<endl;
				cout << "1) Saisir une ville étape" <<endl;
				ReadChoice(continuer,0,1);
				cout << "--" <<endl;

				while(continuer==1)
				{
					//saisie de l'étape
					cout <<"Saisissez une ville étape : ";
					etape = new char[NB_MAX_CHAR1];
					cin >> etape;
					Majuscule(etape);
					cout <<"Saisissez le moyen de transport : ";
					moyenTransport = new char[NB_MAX_CHAR1];
					cin >> moyenTransport;
					Majuscule(moyenTransport);

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

					etapeCopie = new char[NB_MAX_CHAR1];
					strcpy(etapeCopie,etape);

					cout << "--" <<endl;
					cout << "O) Saisir la ville d'arrivee" <<endl;
					cout << "1) Saisir une ville étape" <<endl;
					ReadChoice(continuer,0,1);
					cout << "--" <<endl;
				}

				//saisie de l'arrivée
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR1];
				cin >> arrivee;
				Majuscule(arrivee);
				cout <<"Saisissez le moyen de transport : ";
				moyenTransport = new char[NB_MAX_CHAR1];
				cin >> moyenTransport;
				Majuscule(moyenTransport);

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
				char* depart = new char[NB_MAX_CHAR1];
				cin >> depart;
				Majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR1];
				cin >> arrivee;
				Majuscule(arrivee);

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
				char* depart = new char[NB_MAX_CHAR1];
				cin >> depart;
				Majuscule(depart);
				cout <<"Saisissez la ville d'arrivée : ";
				char* arrivee = new char[NB_MAX_CHAR1];
				cin >> arrivee;
				Majuscule(arrivee);

				catalogue.RechercheParcoursAvancee(depart,arrivee);

				delete[] depart;
				delete[] arrivee;

				break;
			}

			// CHANGEMENT DU FICHIER DE SAUVEGARDE
			case 6:
			{
				cout<<"-- changement du fichier de sauvegarde --"<<endl;
				string fichier;
				cout<<"Saisissez votre nom de fichier:";
				cin>>fichier;
				catalogue.SetFichierSauvegarde(fichier);
				break;
			}

			// CHARGEMENT ENTIER DE LA SAUVEGARDE
			case 7:
			{
				cout<<"-- chargement entière de la sauvegarde --"<<endl;
				catalogue.GetSauvegarde();
				break;
			}

			// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON LE TYPE
			case 8:
			{
				unsigned int continuer;
				cout <<"-- chargement partielle de la sauvegarde selon";
				cout << "le type --"<<endl;
				cout << "O) Charger uniquement les trajets composés" <<endl;
				cout << "1) Charger uniquement les trajets simples " <<endl;
				ReadChoice(continuer,0,1);
				catalogue.GetSauvegardeTypeTrajet(continuer);
				break;
			}

			// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON DEPART / ARRIVEE
			case 9:
			{
				string depart;
				cout<<"Saissisez une ville de départ (ou tapez sur entrer)";
				cin>>depart;
				string arrivee;
				cout<<"Saissisez une ville d'arrivée (ou tapez sur entrer)";
				cin>>arrivee;
				catalogue.GetSauvegardeDepartArrivee(depart,arrivee);
				break;
				
			}
	
			// CHARGEMENT ENTIERE DE LA SAUVEGARDE
			case 11:
			{
				cout << "-- enregistrement entière du catalogue";
				cout << "dans la sauvegarde --"<<endl;
				
			
				if(catalogue.GetNbTrajet() == 0)
				{
					cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
					break;
				}
				
				catalogue.Save();
				break;
			}
			
			// CHARGEMENT DE LA SAUVEGARDE SELON LE TYPE
			case 12:
			{
				cout << "-- enregistrement du catalogue";
				cout << "dans la sauvegarde selon le type--"<<endl;
				cout << "de trajet --"<<endl;
				
				if(catalogue.GetNbTrajet() == 0)
				{
					cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
					break;
				}
				
				unsigned int simple;
				cout << "O) Charger uniquement les trajets composés" <<endl;
				cout << "1) Charger uniquement les trajets simples " <<endl;
				ReadChoice(simple,0,1);
				catalogue.SaveTypeTrajet(simple);
				break;
			}
			

			// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON DEPART / ARRIVEE
			case 13:
			{
				cout<<"-- enregistrement du catalogue dans la sauvegarde";
				cout<<" selon depart/arrivee --"<<endl;
				
				if(catalogue.GetNbTrajet() == 0)
				{
					cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
					break;
				}

				unsigned int choix;
				cout << "O) Selon le départ uniquement" <<endl;
				cout << "1) Selon l'arrivée uniquement" <<endl;
				cout << "2) Selon le départ et l'arrivée uniquement" <<endl;
				ReadChoice(choix,0,2);

				string depart ="";
				string arrivee="";
				
				if(choix != 1)
				{
					cout<<"Saissisez une ville de départ : ";
					cin >> depart;
				}
				
				if(choix > 0)
				{
					cout<<"Saissisez une ville d'arrivée : ";
					cin >> arrivee;
				}
				
				catalogue.SaveDepartArrivee(depart,arrivee);
				break;
			}
			
			// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON INTERVAL
			case 14:
			{
				cout<<"-- enregistrement du catalogue dans la sauvegarde";
				cout<<" selon interval --"<<endl;

				unsigned int max = catalogue.GetNbTrajet();
				if(max == 0)
				{
					cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
					break;
				}
				
				unsigned int start;
				unsigned int end;
				
				cout<<"Saissisez le début de l'intervalle : "<<endl;
				ReadChoice(start,1,max);
				cout<<"Saissisez la fin de l'intervalle : "<<endl;
				ReadChoice(end,start,max);
				
				catalogue.SaveInterval(start,end);
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

void Majuscule(char *chaine)
// Algorithme : aucun
{
	unsigned int i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i]  >= 97 &&  chaine[i] <= 122)
			chaine[i] = chaine[i] - 32;
		i++;
	}
} //----- Fin de Majuscule

bool ReadChoice(unsigned int & N, unsigned int min, unsigned int max ) 
// Algorithme : aucun
{ 
    cout << "Entrez un chiffre entre "<< min << " et " << max <<" : ";
    while ( ! ( cin >> N ) || N < min || N > max ) 
    {  
        if ( cin.eof() ) 
        {   
            return false;  
        } 
        else if ( cin.fail() ) 
        {  
            cout << "Saisie incorrecte, recommencez : ";
            cin.clear();  
            cin.ignore( numeric_limits<streamsize>::max(), '\n' ); 
        } 
        else 
        { 
            cout << "Le chiffre n'est pas entre " << min << " et " << max << " recommencez : ";
        } 
    } 
    return true; 
} //----- Fin de ReadChoice
