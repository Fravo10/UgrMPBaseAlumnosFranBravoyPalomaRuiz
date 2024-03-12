/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 24 October 2023, 14:00
 */

#include "Kmer.h"
#include <string>
#include <iostream>

using namespace std; // Con esto no hace falta poner los std::

//Constructor que construye un objeto de longuitud k
//Rellena con MISSING_NUCLEOTIDE
Kmer::Kmer(int k){
  /*
  * @throw std::invalid_argument Throws an std::invalid_argument exception
  * if @p k is less or equal than zero   
  */ 
if(k<= 0){
    //Creo un string que al no ser valida k, se le concatena la frase.
    //El to_string me transforma un entero a string que es lo que le pasas por parametro
        throw invalid_argument(string("Kmer(int k):") +
                "Longuitud inválida" + to_string(k)); 
}

this ->_text = string(k,MISSING_NUCLEOTIDE);
}

// Construye un objeto mediante el paso de un string
Kmer::Kmer(const string & text){
   if(_text.empty()){
            throw invalid_argument(string ("Kmer(const string & test):") +
                    "El texto está vacio");
   }else{
                    _text = text; 
   }
}

//Método que utiliza el método size
int getK() const{
        
        return _text.size(); 
    }

//Saca el tamaño de cada kmero.
int size() const{
    int lon_kmero;
        this ->_text=lon_kmero;
                
        return lon_kmero;
    }

//Método que devuelve una cadena
std::string toString() const{
        return _text; 
    }

//Metodo que devuelve una posicion de la cadena _text del kmer
//CONST: no se modifica el char, "Está protegido"
const char& at(int index) const{
     if(index<0 || index > _text.size()){
            throw out_of_range(string ("Kmer(const char& at(int index):") +
                    "El indice está fuera de rango" + to_string(index));
     }else{
         return _text.at(index); //Devuelve el item de esa posición
     }
}

//Puede ser modificado por el método
char& at(int index){
     if(index<0 || index > _text.size()){
            throw out_of_range(string ("Kmer(const char& at(int index):") +
                    "El indice está fuera de rango" + to_string(index)););
     }else{
         return _text.at(index); //Devuelve el item de esa posición
     }
}
bool IsValidNucleotide(char nucleotide, const string& validNucleotides){
    bool valido = false;
    for( int i=0; i< validNucleotides.leght(); i++){
        if(nucleotide == validNucleotides [i]){
            valido=true;
        }
    }
    return valido;
}

void ToLower(Kmer& kmer){
    for(char& nucleotide : kmer.toString()){
        nucleotide = string tolower(nucloetide); 
    }
}

void ToUpper(Kmer& kmer){
    for(char& nucleotide :kmer.toString()){
        nucleotide = std::string toupper(nucleotide); 
    }
}
void normalize(const std::string& validNucleotides){
    for(char& nucleotide : _text){
        if(validNucleotide.find(nucleotides) == std::string posicion){
            nucleotide = MISSING_NUCLEOTIDE; 
            else 
                
                nucleotide = std::toupper(nucleotide); 
        }
    }
    
}


Kmer complementary(const std::string& nucleotides, 
         const std::string& complementaryNucleotides) const{
    
    if(nucleotides.size() != complementaryNucleotides.size())
        throw std::invalid_argument("Las cadenas deben ser del mismo tamaño")
                
        std:: string result = _text; 
    for(char& nucleotide : result){
        nucleotide = complementaryNucleotides[i]; 
    }
    
    return Kmer(result); 
}








