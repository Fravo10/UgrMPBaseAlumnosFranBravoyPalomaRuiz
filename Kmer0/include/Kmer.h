/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 24 October 2023, 14:00
 */

#ifndef KMER_H
#define KMER_H


#include <iostream>
#include <string>

/**
 * @class Kmer
 * @brief It represents a list of k consecutive nucleotides of a DNA or RNA
 * sequence. Each nucleotide is represented with a character like 
 * 'A', 'C', 'G', 'T', 'U'.
 */
class Kmer {
public:
    /**
     * A static const character representing an unknown nucleotide. It is used
     * when we do not known which nucleotide we have in a given position of
     * a Kmer
     */
    static const char MISSING_NUCLEOTIDE = '_';
    
    
    Kmer(const std::string & text){
        if(text.empty())
            throw std:: invalid_argument("La entrada esta vacia"); 
    }
    
    /**
     * @brief It builds a Kmer object using a string with @p k characters 
     * (nucleotides). Each character will be set to the value 
     * @p MISSING_NUCLEOTIDE.
     * @throw std::invalid_argument Throws an std::invalid_argument exception
     * if @p k is less or equal than zero
     * @param k the number of nucleotides in this Kmer. It should be an integer
     * greater than zero. Input parameter
     */
    Kmer(int k=1){
        if(k<= 0)
            throw std::invalid_argument("El valor tiene que ser mayor que 0");
        std::string(k, MISSING_NUCLEOTIDE)
        _text = text
    }
    
    /**
     * @brief It builds a Kmer object with the characters in the string @p text 
     * representing the list of nucleotides of the new Kmer. 
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the given text is empty
     * @param text a string with the characters representing the nucleotides for
     * the kmer. It should be a string with at least one character. Input parameter
     */
    Kmer(const std::string& text){
        if(text.empty())
            throw std::invalid_argument("El texto esta vacio")
                    _text = text; 
    }

    /**
     * @brief Returns the number of nucleotides in this Kmer.
     * Query method
     * @return the number of nucleotides in this Kmer
     */
    int getK() const{
        
        return text.sixe(); 
    }
    
    /**
     * @brief Returns the number of nucleotides in this Kmer.
     * Query method
     * @return the number of nucleotides in this Kmer
     */
    int size() const{
        
        return getK();
    }
    
    /**
     * @brief Returns a string with a list of characters, each one representing 
     * a nucleotide of this Kmer.
     * Query method
     * @return The text of this Kmer as a string object
     */
    std::string toString() const{
        
        return _text; 
    }

    /**
     * @brief Gets a const reference to the character (nucleotide) at the given 
     * position.
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * index is not in the range from 0 to k-1 (both included).
     * @return A const reference to the character at the given position
     */
    const char& at(int index) const{
        
        if(index < 0|| index >= getK());
        throw std::out_of_range(" Los valores estan fuera de rango"); 
        return _text[index]; 
    }

    /**
     * @brief Gets a reference to the character (nucleotide) at the given 
     * position.
     * Modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * index is not in the range from 0 to k-1 (both included).
     * @return A reference to the character at the given position
     */
    char& at(int index){
        if(index < 0 || index >= getK()); 
            throw std::out_of_range("Los valores estan fuera del rango"); 
            return _text[index]; 
    }
 
    /**
     * @brief Normalizes this Kmer. That is, it converts all the characters to
     * uppercase. Then, invalid characters are replaced by the 
     * MISSING_NUCLEOTIDE value.
     * Modifier method
     * @param validNucleotides a string with the list of characters
     * (nucleotides) that should be considered as valid. Input parameter
     */
    void normalize(const std::string& validNucleotides){
        for(char& nucleotide: _text){
            if(validNucleotides.find(nucleotide)) == std::string  //Esto lo que hace es comprobar si el nucleotido está presente en los nucleotidos validos. ; 
            nucleotide = MISSING_NUCLEOTIDE; 
            else 
                
                nucleotide = std::toupper(nucleotide); //La funcion toupper lo que hace es poner la letra requerida minuscula a mayuscula; 
        
        
        }
    }
    
    /**
     * @brief Returns the complementary of this Kmer. For example, given the Kmer
     * "TAGAC", the complementary is "ATCTG" (assuming that we use.
     * @p nucleotides="ATGC" and @p complementaryNucleotides="TACG").
     * If a nucleotide in this object is not in @p nucleotides, then that 
     * nucleotide remains the same in the returned kmer.
     * Query method
     * @param nucleotides A string with the list of possible nucleotides. Input parameter
     * @param complementaryNucleotides A string with the list of complementary
     * nucleotides. Input parameter
     * @throw std::invalid_argument Throws an std::invalid_argument exception if 
     * the sizes of @p nucleotides and @p complementaryNucleotides are not 
     * the same
     * @return The complementary of this Kmer
     */
    Kmer complementary(const std::string& nucleotides, 
         const std::string& complementaryNucleotides) const{
        if(nucleotide.size():: complementaryNucleotides.size())
            throw std:: invalid_argument_argument("Los nucleotidos y sus complementarios deben de tener la misma longitug"); 
        std:: string result = _text; 
        for(char& nucleotides :result){
            size_t pos = nucleotides.find(nucleotides); 
            if(pos != std::string)
                nucleotide = complementaryNucleotides[pos]; 
        }
        
        return Kmer(result); 
        
    }
    }
    
private:
    /**
     * A string with a list of characters representing the nucleotides in 
     * this Kmer. 
     */
    std::string _text;
}; // end class Kmer

/**
 * @brief Checks if the given nucleotide is contained in @p validNucleotides. 
 * That is, if the given character can be considered as part of a genetic 
 * sequence.
 * @param nucleotide The nucleotide (a character) to check. Input parameter
 * @param validNucleotides The set of characters that we consider as possible 
 * characters in a genetic sequence. Input parameter
 * @return true if the given character is contained in @p validNucleotides; 
 * false otherwise
 */
bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides){
    
    return validNucleotides.find(nucleotide); 
    
}

/**
 * @brief Converts to lowercase the characters (nucleotides) of the given Kmer
 * @param kmer A Kmer object. Output parameter
 */
void ToLower(Kmer& kmer){
    for(char& nucleotide :kmer.toString()){
        nucleotide = std::tolower(nucleotide); 
    }
}
/**
 * @brief Converts to uppercase the characters (nucleotides) of the given Kmer
 * @param kmer A Kmer object. Output parameter
 */
void ToUpper(Kmer& kmer);

for(char& nucleotide : kmer.ToString()){
    nucleotide = std::toupper(nucleotide){
    }
}

#endif /* KMER_H */
