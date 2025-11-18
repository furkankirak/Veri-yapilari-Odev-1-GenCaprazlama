/**
* @file Dugum.cpp
* @description Dugum Sınıfı
* @course 2-C(ikinci öğretim C şubesi)
* @assignment Birinci Odev
* @date 24.11.2024
* @author Furkan KIRAK furkan.kirak@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include <iostream>
using namespace std;

Dugum::Dugum(char veriChar)
{
    this->veriChar = veriChar;
    this->sonraki =0;
    this->onceki =0;
}

Dugum::~Dugum(){
    
}