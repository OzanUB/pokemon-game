// File: proj2.cpp
// Project: CMSC 202 Project 2, Fall 2016
// Author: Ozan Ulug-Berter
// Date: 10/11/2016
// Section 3
// Email: gl95172@umbc.edu

//Description: This file uses the Accessors and Mutators from Pokemon.h and
//makes it so that the members variables can me manipulated for the proj2.cpp

#include "Pokemon.h"

using namespace std;


Pokemon::Pokemon(){
  m_Num = 0;   //
  m_Name = ""; //
  m_MinCP = 0; //initializes all of the member functions
  m_MaxCP = 0; //
  m_Rarity = 0;//
}
Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity){
  m_Num = num;       //
  m_Name = name;     //
  m_MinCP = cpMin;   //sets member variables to variables to can be used
  m_MaxCP = cpMax;   //locally in the proj2.cpp
  m_Rarity = rarity; //
}

int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
}

int Pokemon::GetRarity(){
  return m_Rarity;
}

string Pokemon::GetName(){
  return m_Name;
}

int Pokemon::GetNum(){
  return m_Num;
}

void Pokemon::SetRarity(int newRarity){
  if (newRarity > 0 && newRarity < 6){ //simple validation to keep rarity valid
    m_Rarity = newRarity;
  }
}

void Pokemon::SetName(string newName){
   m_Name = newName;
}

void Pokemon::SetCP(int newCP){
  //leave empty
}
