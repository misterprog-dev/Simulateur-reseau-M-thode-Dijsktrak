#include "network.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <dirent.h>
#include <windows.h>
#include <fstream>


using namespace std;
///Ecriture des méthode de la classe Node

Node::Node()
{
    Node::Initialize();
}


Node::Node(int ident)
{

    Initialize();
    id=ident;
}

Node::~Node()
{

}

void Node::Initialize()
{
    id=-1;
    nbrVoiz=0;
/*
    for(int i=0;i<1;i++)
        for(int j=0;j<3;j++)
        {
            rTable[i][j]="0";
            aTable[i][j]="0";
        }
*/
    for(int i=0;i<10;i++)
    {
        msgReceived.push_back("0");
        msgSent.push_back("0");
    }
}
bool  Node::addVoiz(Node& newVoiz, int dist)
{
     voiz.push_back(newVoiz);
     voizDist.push_back(dist);
     return true;
}
//Supprimer un voisin
bool Node::delVoiz(Node &noeud)
{
    //Gérer l'existence du noeud
    bool existe(false);
    std::list<int> ListeVoiz=ListeDesVoisins();
    for(std::list<int>::iterator it=ListeVoiz.begin();it !=ListeVoiz.end();++it)
    {
        if( *it==noeud.getId())
        {
                existe=true;
        }
    }
    if(existe==true)
    {
                    std::vector<Node> Aux;
                    std::vector<int> AuxCout;

                    for(unsigned int i(0);i<voiz.size();i++)
                    {
                        if( voiz[i] == noeud)
                        {
                        }
                        else
                        {
                               Aux.push_back(voiz[i]);
                            AuxCout.push_back(voizDist[i]);
                        }
                    }
                    //Initialisation des tables voiz et coûts du noeud

                       voiz.clear();
                        voizDist.clear();

                    //Remplissage des tables voiz et coûts
                     for(unsigned int i(0);i<Aux.size();i++)
                    {
                            voiz.push_back(Aux[i]);
                            voizDist.push_back(AuxCout[i]);
                    }

                    //Confirmation de la suppression

                    return true;
        }
        else
        {
                //L'élément n'existe pas
                return false;
        }

}

/*bool Node::delVoiz(Node& oldVoiz)
{
    voiz.erase(oldVoiz.getId());
}*/


int Node::getNbrVoiz() const
{
    return voiz.size();
}

int Node::getId() const
{
    return id;
}

void Node::affichVoiz() const
{

    //map<int, Node>::iterator it;



    //cout <<"Les voisins du noeud : "<<id+1<<endl;
    cout <<"Voisin\tCout"<<endl;
    for(int i=0; i<getNbrVoiz();i++)
    {
        cout << (voiz[i].id)+1<<"\t"<<voizDist[i]<<endl;
    }

    cout <<endl;
}

ostream& operator<<(std::ostream& flux, Node& a)
{
    flux << a.getId();
}

bool operator==(Node const& a, Node const& b)
{

    if(a.getId()==b.getId())
        return true;
    else
        return false;
}

bool  Node::isVoiz(Node& a) const
{
    //map<int, Node>::iterator it=voiz.begin();

    bool rep=false;

   /* do
    {
        if(it->second==a) rep=true;
        ++it;
        if(it==voiz.end())
            if(it->second==a)
                rep=true;

    }while(rep==false && it!=voiz.end()); */

    for(int i=0; i<getNbrVoiz();i++)
    {
        if(voiz[i].id==a.id) rep=true;
    }
}
//Récupérer la liste des voisins
std::list<int> Node::ListeDesVoisins()
{
    std::list<int> Identifiants;
    for(unsigned int i(0);i<voiz.size();++i)
    {
        Identifiants.push_back(voiz[i].getId());
    }
    return Identifiants;
}
//Récupérer la liste des coûts
std::vector<int> Node::ListeDesCouts()
{
    return voizDist;
}

bool Node::dijkstra(int **g, int n)
{
//g:l'ensemble des liens et n:le nbre de noeud

    bool *disttrouve;

    distmin=new int[n];
    disttrouve=new bool[n];
    pred=new int[n];

    //copie de dijkstra
    int i,j;

    for(j=0;j<n;j++)//
    {
        distmin[j]=g[id][j];
        pred[j]=id;

    }

    disttrouve[id]=true;
    distmin[id]=0;
    pred[id]=id;

    for(i=0;i<n-1;i++)
    {
        int mind=9999;
        int v=id;

         for(j=0;j<n;j++)
            if(!disttrouve[j])
              if(distmin[j]<mind)
                {
                    v = j;
                    mind = distmin[v];
                }
            disttrouve[v] = true;
           for(j=0;j<n;j++)
                if(!disttrouve[j])
                  if(mind+g[v][j]<distmin[j])
           {
               distmin[j]=mind+g[v][j];
               pred[j]=v;
           }
    }

    //fin copie de dijkstra

    //copie Affiche
    /*for(i=0;i<n;i++)
    {
        if(i==id)
            cout<<id+1<<" "<<id+1;
        else
            imprimeChemin(i);
        /*if(distmin[i]!=9999)
           // cout<<" \tla distance minimale: "<<distmin[i]<<endl;
        else
           // cout<<"pas de chemin"<<endl;
*/

    //Fin copie affiche

    //Traitement et confection de la table d'acheminement
    int prec;
    for( i=0; i<n;i++)
    {

        aTable.push_back(vector<int>(2));
        aTable[i][0]=getSrc(i);
        aTable[i][1]=distmin[i];

    }

    return true;
}

void Node::affichATable() const
{
     int n=aTable.size();
     cout << "Affichage de la table d'acheminement du noeud "<<id+1<<endl;
     cout <<"Dest \t Pass \t Cout"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<aTable[i][0]+1<<"\t"<<aTable[i][1]<<endl;
    }

     cout<<"\n\n";
}

void Node::listChemin(int i)
{
    if(i==-1) imprimeChemin(id);
    else if(i>=0) imprimeChemin(i);
    else cout <<"Impossible d'afficher le chemin du noeud "<<i<<endl;
}

int Node::getSrc(int noeud)
{
    if(pred[noeud]==id)
    {
        return noeud;
    }
    else
    {
        getSrc(pred[noeud]);
    }
}


void Node::imprimeChemin(int noeud)
{
    if(noeud==id)
        cout<<noeud+1<<" ";
    else
    {
        imprimeChemin(pred[noeud]);
        cout<<noeud+1<<" ";
    }
}


//***************************************************************************
//***************************************************************************
//**************************************************************************
//Implementation du graphe



Graphe::Graphe(int _nbrNode, int _nbrLink, int _mtu, std::string _protocol)
{
    //cout <<"Nous somme dans graph\nDebut deds initialisation des variale"<<endl;
    nbrNode=_nbrNode;
    nbrLink=_nbrLink;
    mtu=_mtu;
    protocol=_protocol;
    //cout <<"Fin init var\nDebut void Init"<<endl;
    Initialize();
    //cout <<"Fin void Init\nDebut read link"<<endl;
    cout << "Entrer sans repetition reverse en separant par des espace: noeud voisin distance"<<endl;
    while(nbrLink--)
    {
     cout << "\nEntrer le lien\n";
    int u = 0, v = 0, w=0;
    scanf("%d %d %d", &u, &v, &w);
    /* Puisque c'est un graphe non orienté, il faut indiquer que
    ... */
    u--;v--;
    nodes[u]->addVoiz(*nodes[v],w) ;// u est  v aussi est connecté à u
    nodes[v]->addVoiz(*nodes[u],w) ;
    linkTable[u][v]= linkTable[v][u]=w;

    }

    string nom_doss="dossierCom/";
    string nom_fichier;
    string f;
    cout << "Communication entre les noeuds du reseau.\n" << endl;
    //system("mkdir dossierCom");

    DIR *rep = NULL;

    rep = opendir("dossierCom");
    if(rep==NULL)
        system("mkdir dossierCom");

    //creation des fichier de chaque noeuds.
    for(int i=0;i<nbrNode;i++)
    {
        char *m;
        m=int_str(i);
      //  cout << "affichage du string"<<endl;
       // printf("%s\n",m);

        string f(m);
        //cout << f<<endl;

        nom_fichier=nom_doss+f+".txt";
       // string nomFichier(strcat(strcat("dossierCom/",m),".txt"));
        //cout << strcat(strcat("dossierCom/",m),".txt")<<endl;
         ofstream ecrire(nom_fichier.c_str());
    }
}


void Graphe::Initialize()
{
    //cout <<"nous sommes dans void Init\nDebut reservation des Noeuds"<<endl;
    nodes= new Node*[nbrNode];
    linkTable=new int*[nbrNode];
    //cout <<"Fin reservation des noeuds\nDebut Init des noeuds"<<endl;
    for(int i=0;i<nbrNode;i++)
    {
        //cout <<"dans la boucle. i="<<i<<endl;
        nodes[i]=new Node(i);
        linkTable[i]= new int[nbrNode];
    }

    for(int i=0;i<nbrNode;i++)
    {
        for(int j=0;j<nbrNode;j++)
        {
            if(i==j) linkTable[i][j]=0;
            else linkTable[i][j]=9999;
        }
    }
}

void Graphe::affiche()
{
    for( int i=0; i< nbrNode; i++)
    {
        cout << "noeud "<<i+1<<endl;
        //cout <<"Voisins :";
        nodes[i]->affichVoiz();

    }
}

void Graphe::affichNiveauRuptPanne(int noeud) const
{
    for( int i=0; i< nbrNode; i++)
    {
        if( i != noeud-1)
        {
            cout << "noeud "<<i+1<<endl;
            nodes[i]->affichVoiz();
        }
    }
}

int** Graphe::getLinkTable()
{
    return linkTable;
}
//Fonction de simulation de panne sur noeud donné en paramètre
bool Graphe::Simulerpanne(int noeud)
{

    //Liste des noeuds et des coûts
    std::vector<int>  CoutsAux;
    std::list<int>  VoizAux;
    CoutsAux=nodes[noeud-1]->ListeDesCouts();
    VoizAux=nodes[noeud-1]->ListeDesVoisins();

    std::map<int,int> tabInfoVoiz;
    int j(0);
    for(std::list<int>::iterator it=VoizAux.begin();it!=VoizAux.end();++it)
    {
        tabInfoVoiz[*it]=CoutsAux[j];
        j++;
    }
    //Insertion  en mémoire de la table des pannes
    TableDePanne[noeud]=tabInfoVoiz;

    //Mise à jour de la table des liens
    for( unsigned int i(0);i<VoizAux.size();i++)
    {
        linkTable[nodes[noeud-1]->getId()][i]=linkTable[i][nodes[noeud-1]->getId()]=9999;
    }
    //Mise à jour de la table des voisins au niveau des coûts et des voisins
    for(std::list<int>::iterator it=VoizAux.begin();it!=VoizAux.end();++it)
    {
        nodes[*it]->delVoiz(*nodes[noeud-1]);
    }

    return true;
}
