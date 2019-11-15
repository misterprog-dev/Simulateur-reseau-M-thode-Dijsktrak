#include<cctype>
#include <iostream>
#include <fstream>
#include <list>
#include<stdlib.h>
#include<conio.h>
#include<ctime>

#include "network.h"
#include "com.h"

using namespace std;

void GuideDeBase();
void  Envoyer_message(Graphe &graph,int noeudSource,int noeudDest);
void attent(){cout  << "Appuyer sur une touche pour continuer"<<endl;}

int main()
{

     std::cout<<"\tBIENVENUE DANS LE SIMULATEUR RESEAU NOMME SI_NETWORKSIMULATOR_214 \n\n\n";

    GuideDeBase();
    attent();
    getch();
   system("cls");

    int nbrNoeud, nbrLink,i;
    char RevenirAuDebut;
    do
    {

                        //Saisie des liens du graphe

                        std::cout<<"Veuillez entrez le nombre  de Noeuds : ";
                        cin>>nbrNoeud;
                        std::cout<<"Veuillez entrez le nombre de liens : ";
                        cin>>nbrLink;
                        //Saisie des éléments du graphe
                        cout<<"\n\nEntrez les informations noeud voisin cout telles qu'elles sont decrits dans le guide base:\n ";
                        Graphe graph(nbrNoeud, nbrLink);

                         attent();
                        getch();
                        system("cls");

                       char RevenirAuMenu;
                       do
                       {

                                       //Menu pour les opérations
                                       cout<<"operations possibles:\n\n";
                                       cout<<"1-Resaisir le graphe\t\t\t2-Afficher le graphe\n  ";
                                       cout<<"3-Afficher la table d'acheminement de tous les noeuds  4-Operations sur un noeud particulier\n";
                                       cout<<"5-Envoyer un message a partir du graphe  6-Simuler une panne sur le graphe  \n";
                                        cout<<"7-Quitter";
                                        int choix;
                                        cout<<"\n\nFaites votre choix :";
                                        cin>>choix;

                                        switch (choix)
                                        {
                                                case 1:
                                                {
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                           do
                                                           {
                                                                  cout<<"Voulez vous ressaisir  le graphe?\n   O: pour oui      N: pour non\n    "  ;
                                                                  cin>>RevenirAuDebut;
                                                           }while(toupper(RevenirAuDebut) !='O'  && toupper(RevenirAuDebut)  !='N');
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                            if(toupper(RevenirAuDebut)=='O')
                                                            {
                                                                     GuideDeBase();
                                                                     RevenirAuMenu='N';
                                                            }


                                                    break;
                                                }

                                                case 2:
                                                {
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                    cout<<"\n\t//***********   AFFICHAGE DE LA TABLE DE BASE DES DIFFERENTS NOEUDS DU GRAPHE   ***********\\\n\n";
                                                     graph.affiche();
                                                     //Boucle pour revenir au menu principal
                                                         do
                                                           {
                                                                  cout<<"\n\nVoulez vous revenir au menu principale ?\nO: pour oui      N: pour non\n "  ;
                                                                  cin>>RevenirAuMenu;
                                                           }while(toupper(RevenirAuMenu) !='O'  && toupper(RevenirAuMenu)  !='N');
                                                             if(toupper(RevenirAuMenu)=='O')
                                                             {
                                                                     attent();
                                                                    getch();
                                                                    system("cls");
                                                             }

                                                    break;
                                                }

                                                case 3:
                                                {
                                                    char RevenirSousMenu;
                                                    do
                                                    {
                                                           attent();
                                                            getch();
                                                            system("cls");


                                                        cout<<"\n\t//*********  TABLE D'ACHEMINEMENT DES DIFFERENTS NOEUDS  *********\\\n\n";
                                                         int ChoixSousMenu;
                                                        cout<<"1- Construire les tables d'acheminements par la methode de Dijkstra\n2-Afficher les differentes tables d'acheminement\n\n";
                                                        cout<<"Faites votre choix   :   ";
                                                        cin>>ChoixSousMenu;
                                                        switch (ChoixSousMenu)
                                                        {
                                                                case 1:
                                                                {
                                                                    //int tempsConvergence(0);
                                                                    //int tempsInitial,tempsFinal;
                                                                    bool EtatDeConvergence=false;
                                                                   // tempsInitial=time(0);
                                                                    for( i=0;i<nbrNoeud;i++)
                                                                    {
                                                                            EtatDeConvergence=graph.nodes[i]->dijkstra(graph.getLinkTable(),nbrNoeud);
                                                                    }
                                                                   // tempsFinal=time(0);
                                                                   // tempsConvergence=tempsFinal-tempsInitial;
                                                                    if(EtatDeConvergence==true)
                                                                    {
                                                                            cout<<"\n\nLa convergence est verifiee pour la methode de DIJKSTRA\n";
                                                                    //        cout<<"\nLe temps de convergence est  :   "<<tempsConvergence<<"  s\n\n";
                                                                    }
                                                                    else
                                                                    {
                                                                        cout<<"Pas de convergence!!!!!!!";
                                                                    }

                                                                    //Pour revenir au sous menu
                                                                          do
                                                                           {
                                                                                  cout<<"\n\nVoulez vous revenir au sous menu ?\nO: pour oui    N: pour non\n    "  ;
                                                                                  cin>>RevenirSousMenu;
                                                                           }while(toupper(RevenirSousMenu) !='O'  && toupper(RevenirSousMenu)  !='N');
                                                                             if(toupper(RevenirSousMenu)=='O')
                                                                             {
                                                                                    attent();
                                                                                    getch();
                                                                                    system("cls");
                                                                             }

                                                                    break;
                                                                }
                                                                case 2:
                                                                {

                                                                    cout<<"/*******  Affichage des tables d'Acheminement  *******\\n\n";
                                                                    for(int i(0);   i!=nbrNoeud;++i)
                                                                    {
                                                                                graph.nodes[i]->affichATable();
                                                                                cout<<"\n\n";
                                                                    }

                                                                 //Pour revenir au sous menu
                                                                           do
                                                                           {
                                                                                  cout<<"\n\nVoulez vous revenir au sous menu  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                  cin>>RevenirSousMenu;
                                                                           }while(toupper(RevenirSousMenu) !='O'  && toupper(RevenirSousMenu)  !='N');
                                                                             if(toupper(RevenirSousMenu)=='O')
                                                                             {
                                                                                      attent();
                                                                                    getch();
                                                                                        system("cls");
                                                                             }

                                                                    break;
                                                                }
                                                                default:
                                                                {
                                                                        cout<<"\nAucun choix n'a ete fait!!!!!!";

                                                                }
                                                        }


                                                        }while(toupper(RevenirSousMenu)=='O');
                                                    break;
                                                }

                                                case 4:
                                                {
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                char retourSousMenu4;
                                                do
                                                {
                                                        cout<<"Entrez le nom du noeud    :  ";
                                                        int nomDuNoeud;
                                                        cin>>nomDuNoeud;
                                                        //Gérer les exceptions sur les noeuds en vérifiant  leurs existence
                                                         //vérifier la validité du noeud
                                                        if(nomDuNoeud<1 || nomDuNoeud>nbrNoeud)
                                                        {
                                                                cout<<"Le noeud n'existe pas!!!!";
                                                                 //Pour revenir au sous menu
                                                                           do
                                                                           {
                                                                                  cout<<"Voulez vous ressayer a niveau  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                  cin>>retourSousMenu4;
                                                                           }while(toupper(retourSousMenu4) !='O'  && toupper(retourSousMenu4)  !='N');
                                                                             if(toupper(retourSousMenu4)=='O')
                                                                             {
                                                                                     attent();
                                                                                    getch();
                                                                                    system("cls");
                                                                             }
                                                        }
                                                        else
                                                        {
                                                                char RevenirSM;
                                                                do
                                                                {

                                                                            cout<<"\t1-  Afficher ses voisins\n\t2-  Afficher sa table de routage\n\t3-  Envoyer un message a un noeud du graphe\n\n";
                                                                            cout<<"Faites votre choix   :   ";
                                                                            int ChoixSousMenu;
                                                                            cin>>ChoixSousMenu;
                                                                                switch (ChoixSousMenu)
                                                                                {
                                                                                        case 1:
                                                                                        {
                                                                                            cout<<"/******* Affichage de la liste de voisins  *******\\n\n";
                                                                                            graph.nodes[nomDuNoeud]->affichVoiz();
                                                                                            //Gérer boucle sur sous menu
                                                                                            //Pour revenir au sous menu
                                                                                            cout<<"\n\n\n";
                                                                                           do
                                                                                           {
                                                                                                  cout<<"Voulez vous revenir au sous menu  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                                  cin>>RevenirSM;
                                                                                           }while(toupper(RevenirSM) !='O'  && toupper(RevenirSM)  !='N');

                                                                                             if(toupper(RevenirSM)=='O')
                                                                                             {
                                                                                                    attent();
                                                                                                    getch();
                                                                                                    system("cls");
                                                                                             }
                                                                                            break;
                                                                                        }
                                                                                        case 2:
                                                                                        {
                                                                                            cout<<"/******* Affichage de la table de routage du noeud saisit  *******\\n\n";
                                                                                                bool EtatDeConvergence=false;
                                                                                                // tempsInitial=time(0);
                                                                                                for( int i(0);i<nbrNoeud;i++)
                                                                                                {
                                                                                                        EtatDeConvergence=graph.nodes[i]->dijkstra(graph.getLinkTable(),nbrNoeud);
                                                                                                }
                                                                                            graph.nodes[nomDuNoeud]->affichATable();
                                                                                              //Gérer boucle sur sous menu
                                                                                            cout<<"\n\n\n";
                                                                                           do
                                                                                           {
                                                                                                  cout<<"Voulez vous revenir au sous menu  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                                  cin>>RevenirSM;
                                                                                           }while(toupper(RevenirSM) !='O'  && toupper(RevenirSM)  !='N');

                                                                                             if(toupper(RevenirSM)=='O')
                                                                                             {
                                                                                                    attent();
                                                                                                    getch();
                                                                                                    system("cls");
                                                                                             }
                                                                                            break;
                                                                                        }
                                                                                        case 3:
                                                                                        {
                                                                                            cout<<"/******* Envoi de message a un noeud du graphe  *******\\n\n";
                                                                                            int noeudReceveur;
                                                                                             cout<<"Entrez le noeud receveur : ";
                                                                                             cin>>noeudReceveur;
                                                                                             cout<<"\n\n";
                                                                                             Envoyer_message(graph,nomDuNoeud,noeudReceveur);
                                                                                            //Gérer boucle sur sous menu
                                                                                             cout<<"\n\n\n";
                                                                                               do
                                                                                               {
                                                                                                      cout<<"Voulez vous revenir au sous menu  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                                      cin>>RevenirSM;
                                                                                               }while(toupper(RevenirSM) !='O'  && toupper(RevenirSM)  !='N');

                                                                                                 if(toupper(RevenirSM)=='O')
                                                                                                 {
                                                                                                          attent();
                                                                                                            getch();
                                                                                                            system("cls");
                                                                                                 }

                                                                                            break;
                                                                                        }
                                                                                        default:
                                                                                        {

                                                                                                cout<<"\nAucun choix n'a ete fait!!!!!!";
                                                                                                //Gérer boucle sur sous menu
                                                                                                cout<<"\n\n\n";
                                                                                               do
                                                                                               {
                                                                                                      cout<<"Voulez vous revenir au menu  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                                      cin>>RevenirSM;
                                                                                               }while(toupper(RevenirSM) !='O'  && toupper(RevenirSM)  !='N');

                                                                                                 if(toupper(RevenirSM)=='O')
                                                                                                 {
                                                                                                        attent();
                                                                                                        getch();
                                                                                                        system("cls");
                                                                                                 }

                                                                                        }

                                                                                }

                                                                    }while(toupper(RevenirSM)=='O');

                                                                        //Revenir au départ dans le case en cous
                                                                         do
                                                                           {
                                                                                  cout<<"Voulez-vous ressayer pour un autre noeud  ?\n   O: pour oui      N: pour non\n    "  ;
                                                                                  cin>>retourSousMenu4;
                                                                           }while(toupper(retourSousMenu4) !='O'  && toupper(retourSousMenu4)  !='N');
                                                                             if(toupper(retourSousMenu4)=='O')
                                                                             {
                                                                                      attent();
                                                                                    getch();
                                                                                    system("cls");
                                                                             }
                                                         }

                                                      }while(toupper(retourSousMenu4) =='O');

                                                    break;
                                                }

                                                case 5:
                                                {
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                     char RetourMenu5;
                                                     do
                                                     {
                                                             cout<<"\n\t//*********  ENVOI DE MESSAGE A UN NOEUD DU GRAPHE  *********\\\n\n";
                                                             int noeudSource,noeudReceveur;
                                                             cout<<"Entrez le noeud source : ";
                                                             cin>>noeudSource;
                                                             cout<<"Entrez le noeud receveur : ";
                                                             cin>>noeudReceveur;
                                                             if((noeudSource<1 || noeudSource>nbrNoeud) ||(noeudReceveur<1 || noeudReceveur>nbrNoeud))
                                                             {
                                                                    cout<<"L'un de ces noeuds n'existe pas  !!!!!";

                                                             }
                                                             else
                                                             {

                                                                     cout<<"\n\n";
                                                                     Envoyer_message(graph,noeudSource,noeudReceveur);
                                                            }

                                                            do
                                                            {
                                                                    cout<<"Voulez-vous recommencer cette operation d'envoi de message ?\nO:oui    N:non";
                                                                    cin>>RetourMenu5;
                                                            }while(toupper(RetourMenu5)!='O' || toupper(RetourMenu5)!='N' );
                                                            if(toupper(RetourMenu5)=='O')
                                                            {
                                                                  attent();
                                                                    getch();
                                                                    system("cls");
                                                            }

                                                        }while(toupper(RetourMenu5=='O'));

                                                    break;
                                                }
                                                 case 6:
                                                {
                                                            attent();
                                                            getch();
                                                            system("cls");
                                                     char RetourMenu6;
                                                     do
                                                     {
                                                     cout<<"\n\t//********* SIMULER UNE PANNE SUR UN NOEUD DU GRAPHE  *********\\\n\n";

                                                     cout<<"\nEntrez le noeud en question :";
                                                     int NoeudEnpanne;
                                                    cin>>NoeudEnpanne;
                                                    //vérifier la validité du noeud
                                                    if(NoeudEnpanne<1 || NoeudEnpanne>nbrNoeud)
                                                    {
                                                            cout<<"Le noeud n'existe pas!!!!";
                                                    }
                                                    else
                                                    {

                                                            graph.Simulerpanne(NoeudEnpanne);
                                                            cout<<"\nVerification de la panne dans les tables de base des differents noeuds:\n\n";
                                                            graph.affichNiveauRuptPanne(NoeudEnpanne);
                                                    }
                                                        //Gérer boucle sur  menu
                                                           do
                                                            {
                                                                    cout<<"Voulez-vous recommencer cette operation de simuation ?\nO:oui    N:non\n";
                                                                    cin>>RetourMenu6;
                                                            }while(toupper(RetourMenu6)!='O' && toupper(RetourMenu6)!='N' );

                                                            if(toupper(RetourMenu6)=='O')
                                                            {
                                                                      attent();
                                                                    getch();
                                                                    system("cls");
                                                            }

                                                    }while(toupper(RetourMenu6)=='O');

                                                    break;
                                                }
                                                case 7:
                                                {
                                                   // RevenirAuDebut='N';
                                                   // RevenirAuMenu='N';
                                                    exit(EXIT_SUCCESS);
                                                }


                                                default:
                                                {
                                                    cout<<"\nAucun choix n'a ete fait!!!!!!";
                                                            attent();
                                                            getch();
                                                            system("cls");

                                                }
                            }

                     }while(toupper(RevenirAuMenu) =='O' );

         }while(toupper(RevenirAuDebut) =='O' );





return 0;
}

void GuideDeBase(void   )
{
    cout<<"***************GUIDE DE BASE***************\n\n\n";
   cout<<"Avant toute manipulation, il faut saisir le graphe\nc'est a dire enregistrer les differents noeuds et les voisins\nainsi que le cout entre ces deux noeuds.\n ";
   cout<<"Les noeuds sont representes par des entiers ainsi que les couts\n";
   cout<<"\nExemple de saisie:   noeud voisin cout\n";
   cout<<"5 4 2 ---> 5 a pour voisin 4 et 4 pour voisin 5 et  la distance(cout) les separant est 2\n";
   cout<<"Donc pour 5 4 2 on deja un lien, sachant que 5 a pour voisin 4 et\n 4 pour voisin 5 et la distance(cout) les separant est 2\n\n";
}

void  Envoyer_message(Graphe &graph,int noeudSource,int noeudDest)
{
     //Envoie de message
    string nom_doss="dossierCom/";
    string nom_fichier;
    string f;
    cout << "\nCommunication entre les noeuds du reseau.\n" << endl;

    int idenvw(noeudSource), idrecevw(noeudDest);
    char *s;

     idenvw--;
     idrecevw--;

     s=int_str(idrecevw);
     //cout<<s;
     string si(s);
     nom_fichier=nom_doss+si+".txt";
      ofstream ecrire(nom_fichier.c_str());
      cout <<"\nEntrer votre message: \n"<<endl;
      string msg;
     cin >> msg;

     ecrire<<si<<":"<<msg<<endl;
     cout <<"Message envoye avec succes au noeud "<<idrecevw+1<<endl;

    /*
    char fg[100];
    strcpy(fg,msg.c_str());

    cout <<"La valeur intiere est : " << chr_int(fg)<<endl;
    */

    cout <<"\n\nRecuperation du message par le noeud "<<idrecevw+1<<endl;

    ifstream lecture(nom_fichier.c_str());
     string msgLu;

     lecture>> msgLu;
     cout <<"\nDans mon fichier il y avait le msg :\n"<<msgLu<<endl;
    //***********************
    //*************************
    //Fin envoie de msgs
    cout << "\nle chemin utilise est :\n";
    graph.nodes[idenvw]->imprimeChemin(idrecevw);

    cout <<"\nTemps d'envoie du message : "<<graph.nodes[idenvw]->aTable[idrecevw][1]*100<<"ms"<<endl;
}

