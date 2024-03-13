/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   main.cpp
 * @author Paloma Ruiz Molina, <palomaruiz2005@correo.ugr.es>
 * @author Francisco Bravo
 */

#include <iostream>
#include <string>

#include "Kmer.h"

using namespace std;

/**
 * This program first reads from the standard input an integer k (length of Kmer)
 * and a string with a genetic sequence. Then, it obtains from the genetic 
 * sequence, the list of kmers (of length k) and saves them in the array kmers. 
 * Then, the kmers are normalized. After that, the complementary kmers, 
 * converted to lowercase, are saved in the array complementaryKmers. Finally 
 * the kmers in the arrays kmers and complementaryKmers are shown in the 
 * standard output.
 * See the next example:
 * 
 * Running example:
 * > kmer0 < data/easyDNA5_missing.k0in
6
GCGCC<-->cgcgg
CGCCC<-->gcggg
GCCC_<-->cggg_
CCC_G<-->ggg_c
CC_G_<-->gg_c_
C_G_G<-->g_c_c
 */
int main(int argc, char* argv[]) {
    // This string contains the list of nucleotides that are considered as
    // valid within a genetic sequence. The rest of characters are considered as
    // unknown nucleotides 
    const string VALID_NUCLEOTIDES = "ACGT";
    
    // This string contains the list of complementary nucleotides for each
    // nucleotide in validNucleotides
    const string COMPLEMENTARY_NUCLEOTIDES = "TGCA";

    // This is a constant with the dimension of the array kmers
    const int DIM_ARRAY_KMERS = 100; //El tamaño del array siempre va como constante;
    
    // This is the array where the kmers of the input genetic sequence will be
    // saved
    // Aqui es donde se guardan en grupos de k letras en cada posición del array
    Kmer kmers[DIM_ARRAY_KMERS]; //Array de objeto kmer.
    
    // This is the array where the complementary kmers will be
    // saved
    Kmer complementaryKmers[DIM_ARRAY_KMERS];
    
    int k, kmers, index;
    string inputstring; //Lista de nucleótidos de entrada
    
    // Read K (integer) and a string with the input nucleotides list
    cin >> k;
    getline(cin,inputstring); //Lee linea completa de texto y lo almacena en un string
    
    

    // Obtain the kmers: find the kmers in the input string and put them in an array of Kmers
    
    kmer::Kmer(k);
    
    kmer::kmer (inputstring);
    
    // Normalize each Kmer in the array

    // Obtain the complementary kmers and turn them into lowercase

    // Show the list of kmers and complementary kmers as in the example
    
    return 0;
}

// La funciones importantes es normalize, que se encarga de en los valores que no haya complementario pone una _
// Y la funcion complementario la cual se encarga de cambiar por los complementerios.
//Los vectores se pasan por referencia (&), estos se cambian, pero seguimos teniendo el original en el main
// nombrefuncion( int&v == int [v])
// El const es como una proteccion que le doy a mi vector, para asegurarme de que ese vector no va a ser modificado dentro de la funcion.
//Esto puede servir para imprimir un valor