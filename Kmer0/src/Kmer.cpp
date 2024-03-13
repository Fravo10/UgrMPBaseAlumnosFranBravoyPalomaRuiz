/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Paloma Ruiz Molina, <palomaruiz2005@correo.ugr.es>
 * @author Francisco Bravo
 * 
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
if(k< 1){
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

//Función externa a nuestra clase
// El objeto this hace referencia al kmer[0].IsValis... que llamaremos en el main
// Utilizamos la funcion find que encuentra en la cadena lo del this 
// Nos devuelve una pos
bool IsValidNucleotide(char nucleotide, const string& validNucleotides){
    bool valido = false;
    int pos;
    
    pos= validNucleotide.find((*this)-> _text);
    
    if(pos != -1){
        valido = true;
    }
        
    return valido;
}

//No llevan const porqque se va a modificar el array.
//Como el this hace referencia a un objeto del array 
//la idea es llamarl dentro de un bucle en el main, para que recorra todos los objetos
void ToLower(Kmer& kmer){
    tolower((*this)-> _text) 
    }

void ToUpper(Kmer& kmer){
    toupper((*this)-> _text) 
    }
}

/**
     * @brief Normalizes this Kmer. That is, it converts all the characters to
     * uppercase. Then, invalid characters are replaced by the 
     * MISSING_NUCLEOTIDE value.
     * Modifier method
     * @param validNucleotides a string with the list of characters
     * (nucleotides) that should be considered as valid. Input parameter
     */
void normalize(const string& validNucleotides){
    
    if(IsValidNucleotide((*this)->_text, validNucleotides)){
        
        }
    }
    
}


Kmer complementary(const string& nucleotides, 
         const string& complementaryNucleotides) const{
    
    if(nucleotides.size() != complementaryNucleotides.size())
        throw invalid_argument("Las cadenas deben ser del mismo tamaño")
                
       string result = _text; 
    for(char& nucleotide : result){
        nucleotide = complementaryNucleotides[i]; 
    }
    
    return Kmer(result); 
}








