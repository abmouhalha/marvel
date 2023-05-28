#ifndef marvel__hpp
#define marvel__hpp

#include <string>
#include <iostream>
#include <vector> 

using namespace std;

#include <sstream>
#include <ostream>
class SUper;
class Personne {
    friend class Super;
    public:
        enum Genre{
            HOMME,
            FEMME,
            INDETERMINE,
        };
        static Personne INCONNU;

        Personne(string const p="Inconnu" , string const n="Inconnu", Genre const g=INDETERMINE);
        ~Personne();
        Genre getGenre()const ;
        string getPrenom()const;
        string getNom()const;
        void afficher(stringstream& ss);
       
    protected:
        string prenom;
        string nom;
        Genre gr;
        
};

ostream & operator<<(ostream &os, const Personne &p);
bool operator==(const Personne & p1, const Personne & p2);

class Capacite;
class Materiel;
class Physique;
class Psychique;
class Super{
    friend class Equipe;
    public :
        Super(string , Personne );
        ~Super();

        string getNom();
        void setNom(string);
        bool  estAnonyme();
        void enregistrer();
        Personne & getIdentite();
        void setIdentite(Personne p);
        void ajouter(Materiel*  c);
        void ajouter(Physique* c);
        void ajouter(Psychique* c);
        int getNiveau();
    protected:
        string nom;
        Personne per;
        bool anonyme=true;
        vector<Capacite> capacites;
};

// classe exception anonyme
class AnonymeException : public exception {
    public:
        AnonymeException();
        virtual const char* what() const throw();
};

///classe 
class Capacite{
    friend class Super;
    protected:
        string nom;
        int niveau;
    public :
        Capacite(string, int);
        virtual ~Capacite();

        virtual void utiliser(stringstream &);
        virtual Capacite * clone();

        string getNom();
        int getNiveau();

};
class Psychique: public Capacite{
    
        
    public :
        Psychique(string , int);
        ~Psychique();
        void utiliser(stringstream&) override;
        Psychique * clone() override;
        void penser(stringstream &);
        



};
class Physique: public Capacite{
    
    public :
        Physique(string , int );
        ~Physique();
        void utiliser(stringstream&) override;
        Physique * clone() override;
        void exercer(stringstream &);
         
        
        


};
class Materiel: public Capacite{
    
    public :
        Materiel(string , int);
        ~Materiel();
         void utiliser(stringstream&) override;
         Materiel * clone() override;
        void actionner(stringstream &);
};

class Equipe{
    protected:
        string nom;
        static int nombre;
        vector<Super> e;
        
    public:
        Equipe(string);
        ~Equipe();
        string getNomEquipe();
        int getNiveau();
        int getNombre();
        void ajouter(Super *s);

};

#endif
