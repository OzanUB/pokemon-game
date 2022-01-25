// File: proj2.cpp
// Project: CMSC 202 Project 2, Fall 2016
// Author: Ozan Ulug-Berter
// Date: 10/11/2016
// Section 3
// Email: gl95172@umbc.edu

//Description: This file uses the Accessors and Mutators from MyPokemon.h and
//makes it so that the members variables can me manipulated for the proj2.cpp

#include "MyPokemon.h"

using namespace std;

MyPokemon::MyPokemon(){
  m_Num = 0;    //
  m_Name = "";  //
  m_CP = 0;     //initializes all of the member variables
  m_HP = 0;     //
  m_Rarity = 0; //
}

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){
  m_Num = num;       //
  m_Name = name;     // 
  m_CP = cp;         // sets member variables to variables that can be used 
  m_HP = hp;         // locally in the proj2.cpp
  m_Rarity = rarity; //
}

int MyPokemon::GetCP(){
  return m_CP;
}
int MyPokemon::GetHP(){
  return m_HP;
}
int MyPokemon::GetRarity(){
  return m_Rarity;
}
string MyPokemon::GetName(){
  return m_Name;
}
int MyPokemon::GetNum(){
  return m_Num;
}

void MyPokemon::SetRarity(int newRarity){
  if (newRarity > 0 && newRarity < 6){ //simple validation to keep rarity valid
    m_Rarity = newRarity;
  }
}

void MyPokemon::SetName(string newName){
  m_Name = newName;
}
void MyPokemon::SetCP(int newCP){
  m_CP = newCP;
}

void MyPokemon::SetHP(int newHP){
  m_HP = newHP;
}

void MyPokemon::Train(){ 
  m_CP += 10; //adds 10 to CP values
}
