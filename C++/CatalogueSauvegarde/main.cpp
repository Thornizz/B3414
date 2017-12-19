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
#include <locale>  

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

string MajusculeString(string s);
// Mode d'emploi : retourne le string avec des majuscules
// Contrat : aucun


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
		cout<<"0) Quitter l'application"<<endl;
		cout<<"1) Ajouter un trajet simple"<<endl;
		cout<<"2) Ajouter un trajet composé"<<endl;
		cout<<"3) Afficher le catalogue"<<endl;
		cout<<"4) Recherche de parcours"<<endl;
		cout<<"5) Recherche avancée de parcours"<<endl;
		cout<<"6) Changement du fichier de sauvegarde"<<endl;
		cout<<"7) Chargement de la sauvegarde"<<endl;
		cout<<"8) Enregistrement du catalogue dans la sauvegarde"<<endl;
		ReadChoice(saisieMenu,0,8);
		cout<<endl;
		switch(saisieMenu)
		{

			// AJOUT TRAJET SIMPLE
			case 1:
			{
				cout<<"-- Ajouter un trajet simple --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				string departS ="";
				std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
				getline(cin,departS);
				departS=MajusculeString(departS);
				char* depart = new char[NB_MAX_CHAR1];
				strcpy(depart,departS.c_str());
				cout <<"Saisissez la ville d'arrivée : ";
				string arriveeS ="";
				getline(cin,arriveeS);
				arriveeS=MajusculeString(arriveeS);
				char* arrivee = new char[NB_MAX_CHAR1];
				strcpy(arrivee,arriveeS.c_str());
				cout <<"Saisissez le moyen de transport : ";
				string moyenTransportS ="";
				getline(cin,moyenTransportS);
				moyenTransportS=MajusculeString(moyenTransportS);
				char* moyenTransport = new char[NB_MAX_CHAR1];
				strcpy(moyenTransport,moyenTransportS.c_str());

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
				cout<<"-- Ajouter un trajet composé --"<<endl;
				cout <<"Saisissez la ville de départ : ";
				string departS ="";
				std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
				getline(cin,departS);
				departS=MajusculeString(departS);
				char* depart = new char[NB_MAX_CHAR1];
				strcpy(depart,departS.c_str());
				cout <<"Saisissez la ville étape : ";
				string etapeS ="";
				getline(cin,etapeS);
				etapeS=MajusculeString(etapeS);
				char* etape = new char[NB_MAX_CHAR1];
				strcpy(etape,etapeS.c_str());
				cout <<"Saisissez le moyen de transport : ";
				string moyenTransportS ="";
				getline(cin,moyenTransportS);
				moyenTransportS=MajusculeString(moyenTransportS);
				char* moyenTransport = new char[NB_MAX_CHAR1];
				strcpy(moyenTransport,moyenTransportS.c_str());

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
					string etapeS ="";
					std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
					getline(cin,etapeS);
					etapeS=MajusculeString(etapeS);
					char* etape = new char[NB_MAX_CHAR1];
					strcpy(etape,etapeS.c_str());
					cout <<"Saisissez le moyen de transport : ";
					string moyenTransportS ="";
					getline(cin,moyenTransportS);
					moyenTransportS=MajusculeString(moyenTransportS);
					char* moyenTransport = new char[NB_MAX_CHAR1];
					strcpy(moyenTransport,moyenTransportS.c_str());

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
				cout<<"-- Ajouter un trajet composé --"<<endl;
				
				cout <<"Saisissez la ville d'arrivée : ";
				string arriveeS ="";
				std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
				getline(cin,arriveeS);
				arriveeS=MajusculeString(arriveeS);
				char* arrivee = new char[NB_MAX_CHAR1];
				strcpy(arrivee,arriveeS.c_str());
				cout <<"Saisissez le moyen de transport : ";
				string moyenTransportS2 ="";
				getline(cin,moyenTransportS2);
				moyenTransportS2=MajusculeString(moyenTransportS2);
				char* moyenTransport2 = new char[NB_MAX_CHAR1];
				strcpy(moyenTransport2,moyenTransportS2.c_str());

				Trajet * ta = new TrajetSimple(
									etapeCopie,arrivee,moyenTransport2);
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
				cout<<"-- Afficher le catalogue --"<<endl;
				catalogue.Affiche();
				break;


			// RECHERCHE PARCOURS
			case 4:
			{
				cout<<"-- Recherche de parcours --"<<endl;
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
				cout<<"-- Recherche avancée de parcours --"<<endl;
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
				cout<<"-- Changement du fichier de sauvegarde --"<<endl;
				string fichier;
				cout<<"Saisissez votre nom de fichier : ";
				cin>>fichier;
				catalogue.SetFichierSauvegarde(fichier);
				break;
			}

			// CHARGEMENT DE LA SAUVEGARDE
			case 7:
			{
				cout<<endl;
				cout<<"-- Chargement de la sauvegarde --"<<endl;
				cout<<"0) Retour au Menu"<<endl;			
				cout<<"1) Chargement entier de la sauvegarde"<<endl;
				cout<<"2) Chargement partiel de la sauvegarde selon le type"<<endl;
				cout<<"3) Chargement partiel de la sauvegarde selon depart/arrivee"<<endl;
				cout<<"4) Chargement partiel de la sauvegarde selon un intervalle"<<endl;
				unsigned int choixChargement;
				ReadChoice(choixChargement,0,4);
				
				switch(choixChargement)
				{
				
					// CHARGEMENT ENTIER DE LA SAUVEGARDE
					case 1:
					{
								
						cout<<"-- Chargement entier de la sauvegarde --"<<endl;
						catalogue.GetSauvegarde();
						break;
					}
				
					// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON LE TYPE
					case 2:
					{
						unsigned int continuer;
						cout <<"-- Chargement partiel de la sauvegarde selon";
						cout << " le type --"<<endl;
						cout << "O) Charger uniquement les trajets composés" <<endl;
						cout << "1) Charger uniquement les trajets simples " <<endl;
						ReadChoice(continuer,0,1);
						catalogue.GetSauvegardeTypeTrajet(continuer);
						break;
					}
				
					// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON DEPART / ARRIVEE
					case 3:
					{
	
						unsigned int choix;
						cout <<"-- chargement partiel de la sauvegarde :"<<endl;
						cout << "O) Selon le départ uniquement" <<endl;
						cout << "1) Selon l'arrivée uniquement" <<endl;
						cout << "2) Selon le départ et l'arrivée " <<endl;
						ReadChoice(choix,0,2);

						string depart ="null";
						string arrivee="null";
						std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

						if(choix != 1)
						{
							cout<<"Saissisez une ville de départ : ";
							getline(cin,depart);
							depart=MajusculeString(depart);
						
						}

						if(choix > 0)
						{
							cout<<"Saissisez une ville d'arrivée : ";
							getline(cin,arrivee);
							arrivee=MajusculeString(arrivee);
						}
						catalogue.GetSauvegardeDepartArrivee(depart,arrivee);
						break;
				
					}
				
					// CHARGEMENT PARTIEL DE LA SAUVEGARDE SELON UN INTERVALLE
					case 4:
					{
						cout <<"-- Chargement partiel de la sauvegarde selon";
						cout << " un intervalle --"<<endl;
						int NbTrajet=catalogue.GetNbTotalDeTrajet();
				
						if(NbTrajet<0)
						{
							break;
						}
						else
						{
							cout << "Voici le contenu de la sauvegarde : ";
							catalogue.AfficheSauvegarde();
						}		
					
						unsigned int start;
						unsigned int end;
						cout<<"Saissisez le début de l'intervalle : "<<endl;
						ReadChoice(start,1,NbTrajet);
						cout<<"Saissisez la fin de l'intervalle : "<<endl;
						ReadChoice(end,start,NbTrajet);
						catalogue.GetSauvegardeDelta(start,end);
							
						break;
					}
				}
				break;
				
			}

			// ENREGISTREMENT DE LA SAUVEGARDE
			case 8:
			{ 
				cout<<endl;
				cout<<"-- Enregistrement de la sauvegarde --"<<endl;
				cout<<"0) Retour au Menu"<<endl;
				cout<<"1) Enregistrement entier du catalogue dans la sauvegarde"<<endl;
				cout<<"2) Enregistrement du catalogue dans la sauvegarde ";
				cout<< " selon le type de trajet"<<endl;
				cout<<"3) Enregistrement du catalogue dans la sauvegarde";
				cout<<" selon depart/arrivee"<<endl;
				cout<<"4) Enregistrement du catalogue dans la sauvegarde";
				cout<<" selon un intervalle"<<endl;
				
				unsigned int choixEnregistrement;
				ReadChoice(choixEnregistrement,0,4);
				
				switch(choixEnregistrement)
				{
	
					// ENREGISTREMENT ENTIER DU CATALOGUE
					case 1:
					{
						cout << "-- Enregistrement entier du catalogue";
						cout << " dans la sauvegarde --"<<endl;
				
			
						if(catalogue.GetNbTrajet() == 0)
						{
							cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
							break;
						}
				
						catalogue.Save();
						break;
					}
			
					// ENREGISTREMENT DU CATALOGUE SELON LE TYPE
					case 2:
					{
						cout << "-- Enregistrement du catalogue";
						cout << " dans la sauvegarde selon le type --"<<endl;
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
			

					// ENREGISTREMENT PARTIEL DU CATALOGUE SELON DEPART / ARRIVEE
					case 3:
					{
						cout<<"-- Enregistrement du catalogue dans la sauvegarde";
						cout<<" selon depart/arrivee --"<<endl;
				
						if(catalogue.GetNbTrajet() == 0)
						{
							cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
							break;
						}

						unsigned int choix;
						cout << "O) Selon le départ uniquement" <<endl;
						cout << "1) Selon l'arrivée uniquement" <<endl;
						cout << "2) Selon le départ et l'arrivée " <<endl;
						ReadChoice(choix,0,2);

						string depart ="";
						string arrivee="";
						std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
				
						if(choix != 1)
						{
							cout<<"Saissisez une ville de départ : ";
							getline(cin,depart);
							depart=MajusculeString(depart);
					
						}
				
						if(choix > 0)
						{
							cout<<"Saissisez une ville d'arrivée : ";
							getline(cin,arrivee);
							arrivee=MajusculeString(arrivee);
						}
				
						catalogue.SaveDepartArrivee(depart,arrivee);
						break;
					}
			
					// ENREGISTREMENT PARTIEL DU CATALOGUE SELON INTERVALLE
					case 4:
					{
						cout<<"-- Enregistrement du catalogue dans la sauvegarde";
						cout<<" selon intervalle --"<<endl;

						unsigned int max = catalogue.GetNbTrajet();
						if(max == 0)
						{
							cout << "Le catalogue est vide, il n'y rien à sauvegarder." << endl;
							break;
						}
						else
						{
							catalogue.Affiche();
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

string MajusculeString(string s)
// Algorithme : aucun
{
	std::locale loc;
	string S="";
 	for (std::string::size_type i=0; i<s.length(); ++i)
    	S+= std::toupper(s[i],loc);
    return S;

} //----- Fin de MajusculeString

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
