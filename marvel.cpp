#include "marvel.hpp"
#include <string>



using namespace std;

// classe peronne 
/*Personne::Personne(){

}*/
Personne Personne::INCONNU("Inconnu", "Inconnu", Personne::INDETERMINE);

Personne::Personne(string const p, string const n, Genre const g):prenom(p), nom(n), gr(g){
}

Personne::~Personne(){

}
Personne::Genre Personne::getGenre()const
{
    return gr;

}
string Personne::getNom()const
{
    return nom;
}
string Personne::getPrenom()const
{
    return prenom;
}

void Personne::afficher(stringstream& ss)
{
    if (getGenre() == 1){
        ss << getPrenom()<< " " << getNom()<< " " <<  "[FEMME]";
    }
    else if (getGenre() == 0){
        ss << getPrenom()<< " " << getNom()<< " " <<  "[HOMME]";
    }
    else {
        ss << "Inconnu Inonnu [INDETERMINE]";
    }
}



ostream & operator<<(ostream &os, const Personne &p){
    os << p.getNom() << " " << p.getPrenom() << " [";
    switch(p.getGenre()){
        case Personne::HOMME: os << "HOMME"; break;
        case Personne::FEMME: os << "FEMME"; break;
        case Personne::INDETERMINE: os << "INDETERMINE"; break;
    }
    os << "]";
    return os;
}

bool operator==(const Personne & p1, const Personne & p2){
    return (p1.getGenre() == p2.getGenre() && p1.getNom() == p2.getNom() && p1.getPrenom() == p2.getPrenom());
}

// 
Super::Super(string s, Personne p): nom(s), per(p), anonyme(true){

}
Super::~Super(){
}

bool Super::estAnonyme(){
    return anonyme;
}

string Super::getNom(){
    return nom;
}

void Super::enregistrer(){
    anonyme = false;
}
Personne & Super::getIdentite(){
    if (!estAnonyme()){
        return per;
    }
    else {
        throw AnonymeException(); // throw exception
    }
}


void Super::setIdentite(Personne p){
    per.prenom = p.getPrenom();
    per.nom = p.getNom() ;
    anonyme = true;
}  

int Super::getNiveau(){
    int i = 0;
    for (auto iter=capacites.begin();iter!=capacites.end();++iter){
        i  =  i + iter->getNiveau();
    }
    return i;
}

void Super::setNom(string s){
    nom = s;
}
void Super::ajouter(Materiel* p){
    capacites.push_back(*p);
}
void Super::ajouter(Physique* p){
    capacites.push_back(*p);
}
void Super::ajouter(Psychique *p){
    capacites.push_back(*p);
}
// exception 
AnonymeException::AnonymeException(){}
const char* AnonymeException::what() const throw() {
    return "identite anonyme";
}


/// capacite
Capacite::Capacite(string n, int niv):nom(n), niveau(niv){
}
Capacite::~Capacite(){
}
int Capacite::getNiveau(){
    return niveau;
}
string Capacite::getNom(){
    return nom;
}
void Capacite::utiliser(stringstream & ){

}
Capacite* Capacite::clone(){
    return new Capacite(*this);
}


// physique

Physique::Physique(string n, int niv):Capacite(n,niv){
    
}
Physique::~Physique(){
    
}
void Physique::exercer(stringstream & ss){
    ss << this->getNom() << " [" <<this->getNiveau() <<"]";
}
void Physique::utiliser(stringstream &ss){
    exercer(ss);
}
Physique * Physique::clone(){
    return new Physique(*this);
}
//psychique

Psychique::Psychique(string n, int niv):Capacite(n,niv){
}
Psychique::~Psychique(){  
}

void Psychique::penser(stringstream & ss){
    ss << this->getNom() << " [" <<this->getNiveau() <<"]";
}
void Psychique::utiliser(stringstream &ss){
    penser(ss);
}
Psychique * Psychique::clone(){
    return new Psychique(*this);
}

// Materiel

Materiel::Materiel(string n, int niv):Capacite(n,niv){
}
Materiel::~Materiel(){
}
void Materiel::actionner(stringstream & ss){
    ss << this->getNom() << " [" <<this->getNiveau() <<"] en action";
}
void Materiel::utiliser(stringstream &ss){
    actionner(ss);
}

Materiel * Materiel::clone(){
    return new Materiel(*this);
}
// equipe
int Equipe::nombre = 0;
Equipe::Equipe(string s): nom(s){

}
Equipe::~Equipe(){
    
}

string Equipe::getNomEquipe(){
    return nom;
}

int Equipe::getNombre(){
    return nombre;
}

int Equipe::getNiveau(){
    int i=0;
    for ( auto iter=e.begin(); iter!=e.end();++iter){
        i = i + iter->getNiveau();
    }
    return i;
}
void Equipe::ajouter(Super * s){
    e.push_back(*s);
    nombre++;
}