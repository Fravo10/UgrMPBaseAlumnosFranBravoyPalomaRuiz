/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Paloma Ruiz Molina, <palomaruiz2005@correo.ugr.es>
 * @author Francisco Bravo Díez, <franbravodiez@correo.ugr.es>
 * 
 */

#include "Kmer.h"
#include <iostream>
#include <string>


using namespace std; // Con esto no hace falta poner los std::

//Constructor que construye un objeto de longuitud k
//Rellena con MISSING_NUCLEOTIDE
// Se pone Kmer:: para indicar que es una funcion de esa clase
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

  _text = string(k,MISSING_NUCLEOTIDE);
}

// Construye un objeto mediante el paso de un string
Kmer::Kmer(const string & text){
   /*if( _text.empty()){
            throw invalid_argument(string ("Kmer(const string & test):") + "El texto está vacio");
   }else{*/
       _text = text; 
   }
   


//Método que utiliza el método size
int Kmer::getK() const{
        
        return size(); 
    }

//Saca el tamaño de cada kmero.
int Kmer::size() const{
        return _text.size();
    }

//Método que devuelve una cadena
string Kmer::toString() const{
        return _text; 
    }

//Metodo que devuelve una posicion de la cadena _text del kmer
//CONST: no se modifica el char, "Está protegido"
const char& Kmer::at(int index) const{
   
     if(index < 0 || index >= _text.size()){
            throw out_of_range(string ("Kmer(const char& at(int index):") +
                    "El indice está fuera de rango" + to_string(index));
     }else{
        const int num = _text.at(index); //Si quiero acceder al elemento const
                                         //Necesito devolver un const
         return num; //Devuelve el item de esa posición
     }
}


//Puede ser modificado por el método
char& Kmer::at(int index){
     if(index < 0 || index >= _text.size()) //Acordarse de controlar bein los límites
            throw out_of_range(string ("Kmer(const char& at(int index):") +
                    "El indice está fuera de rango" + to_string(index));
     //cuando se hace una excepcion se para
         return this ->_text.at(index); //Devuelve el item de esa posición
     
}

/**
     * @brief Normalizes this Kmer. That is, it converts all the characters to
     * uppercase. Then, invalid characters are replaced by the 
     * MISSING_NUCLEOTIDE value.
     * Modifier method
     * @param validNucleotides a string with the list of characters
     * (nucleotides) that should be considered as valid. Input parameter
     */
void Kmer::normalize(const string& validNucleotides){
    
    ToUpper(*this);// Ese this sirve para hacer referencia al propio objeto de la clase
    
    for(int i = 0; i< size() ; i++){
        if(IsValidNucleotide( _text.at(i),validNucleotides)==false){//Si no es válido...
             _text=MISSING_NUCLEOTIDE;
        }
    }
    
}

// Cuando pasamos un valor por referencia se modifica la celda de memoria
//Cuando pasamos por valor hay que hacer un return, pq es como si hicieramos una copia
Kmer Kmer::complementary(const string& Validnucleotides, 
         const string& complementaryNucleotides) const{
    
    if(Validnucleotides.size() != complementaryNucleotides.size())
        throw invalid_argument("Las cadenas deben ser del mismo tamaño");
    
    
    string mycomplementary;
    int pos;          
    for(int i=0; i < mycomplementary.size(); i++)
    {
        pos= Validnucleotides.find(Validnucleotides.at(i));
        mycomplementary.push_back(complementaryNucleotides.at(pos));
        }
    
    return Kmer(mycomplementary); 
}

//Función externa a nuestra clase
// El objeto this hace referencia al kmer[0].IsValis... que llamaremos en el main
// Utilizamos la funcion find que encuentra en la cadena lo del this 
// Nos devuelve una pos

bool IsValidNucleotide(char nucleotide, const string& validNucleotides){
    bool valido;
    
        if(validNucleotides.find(nucleotide) == string::npos){ // para acceder a la constante npos de la clase string
          valido=false;                        // tenemos que utilizar :: para avisar de que vamos a acceder
                                              //  npost es un valor de posicion, para cuando no se encuentra nada coincidente
        }else{
         valido = true; 
        }
        
    return valido;
}

//No llevan const porqque se va a modificar el array.
//Como el this hace referencia a un objeto del array 
//la idea es llamarl dentro de un bucle en el main, para que recorra todos los objetos
void ToLower(Kmer& Kmer){
    for(int i=0; i< Kmer.size();i++){
        Kmer.at(i) = tolower(Kmer.at(i));
    }
}

void ToUpper(Kmer& Kmer){
    for(int i=0; i< Kmer.size(); i++){
     Kmer.at(i) = toupper(Kmer.at(i)); 
    }
}
