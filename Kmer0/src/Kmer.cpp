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


Kmer::Kmer(int k=1){
    
if(k<= 0)
        throw std::invalid_argument("El valor tiene que ser mayor que 0");
        std::string(k, MISSING_NUCLEOTIDE)
        _text = text  
    
}
Kmer::Kmer(const std::string& text){
   if(text.empty())
            throw std::invalid_argument("El texto esta vacio")
                    _text = text; 
}
int getK() const{
        
        return text.sixe(); 
    }
int size() const{
        
        return getK();
    }
std::string toString() const{
        `
        return _text; 
    }
