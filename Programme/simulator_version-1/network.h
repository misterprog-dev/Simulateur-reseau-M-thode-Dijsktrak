#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>
#include "com.h"


class Node
{
    private:
        int id;
        int nbrVoiz;
        int *pred; //matrice des prédécesseur
        int * distmin; //matrice qui contient la distance min du noeud
        std::vector<Node> voiz;
        std::vector<int> voizDist;
        std::vector<std::vector<int> > rTable;

        std::vector<std::string> msgReceived;
        std::vector<std::string> msgSent;
    public:
          std::vector<std::vector<int> > aTable;

        /**
        *\brief Constructeur de la classe Node
        *\param Aucun paramètre
        */
        Node();

        /**
        *\brief Constructeur permetant d'affecter le id
        *\param id L'identifiant du noeud
        */
        Node(int );

        //Destructeur
        ~Node();


        /**
        *\brief Permet d'initialiser les attribut de la classe
        *\param Aucun paramètre
        */
        void Initialize();

        /**
        *\brief Ajout d'un nouveau voisin
        *\param newVoiz la réference du voisin a ajouter
        */

        int getId() const;

        bool addVoiz(Node& newVoiz, int distance);

        bool delVoiz(Node &noeud);

        int getNbrVoiz() const;



         std::list<int> ListeDesVoisins() ;

         std::vector<int> ListeDesCouts() ;

        void affichVoiz() const;

        bool isEgal(Node&) const;

        bool isVoiz(Node&) const;

        bool fillRTable();

        bool fillATable();

        void listChemin(int i=-1);

        void affichRTable() const;

        void affichATable()const;

        bool dijkstra(int **linkTable, int nbrNode);

        void imprimeChemin(int noeud);

        int getSrc(int noeud);

        friend std::ostream& operator<<(std::ostream& flux, Node& a);
        friend bool operator==(Node const& a, Node const& b);

};

//***********************************************************************
//**************CLASSSE GRAPHE*******************************************
//************************************************************************

class Graphe
{
    private:
        int nbrLink;
        int nbrNode;//revoir
        int **linkTable;

        std::string name;
        int mtu;
        std::string protocol;
        std::map<int,std::map<int,int> > TableDePanne;//
    public:
        //Variable public
        Node  **nodes;
        //Graphe();

        Graphe(int , int , int _mtu=1500, std::string _protocol="dijks");

        void Initialize();

        void affiche();

        void affichNiveauRuptPanne(int ) const;

        int**  getLinkTable();

        //Simuler une panne
        bool Simulerpanne(int noeud);

};




#endif // NETWORK_H_INCLUDED
