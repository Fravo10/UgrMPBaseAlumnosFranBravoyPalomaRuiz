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

using namespace std;


Kmer::Kmer(int k){
    
if(k<= 0)
        throw std::invalid_argument("El valor tiene que ser mayor que 0");
for( k, k>0, k--){
    _text.push_back (MISSING_NUCLEOTIDES);
}
    
}

Kmer::Kmer(*this);

Kmer::Kmer(const std::string& text){
   if(_text.empty()){
            throw std::invalid_argument("El texto esta vacio")
   }else{
                    _text = text; 
   }
}
int getK() const{
        
        return _text.size(); 
    }
int size() const{
        
        return getK();
    }
std::string toString() const{
        return _text; 
    }
const char& at(int index) const{
     if(index<0 || index > _text.size()){
            throw std::out_of_range("Fuera de rango");
     }else{
         return _text.at(index); //Devuelve el item de esa posición
     }
}
char& at(int index){
     if(index<0 || index > _text.size()){
            throw std::out_of_range("Fuera de rango");
     }else{
         return _text.at(index); //Devuelve el item de esa posición
     }
}
bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides){
    bool valido = false;
    for( int i=0; i< validNucleotides.leght(); i++){
        if(nucleotide == validNucleotides [i]){
            valido=true;
        }
    }
    return valido;
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





void ToLower(Kmer& kmer){
    for(char& nucleotide : kmer.toString()){
        nucleotide = std::string tolower(nucloetide); 
    }
}


void ToUpper(Kmer& kmer){
    for(char& nucleotide :kmer.toString()){
        nucleotide = std::string toupper(nucleotide); 
    }
}