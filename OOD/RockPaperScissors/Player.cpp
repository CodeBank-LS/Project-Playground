#include"Player.h"
#include<iostream>
#include<stdlib.h>
using namespace std;



Player::Player(){
    pMove='\0';
    player_id=0;
    player_index=0;
}
Player::Player(int a){
    pMove='\0';
    player_id=a;
}
void Player::setID(int n){
    player_id=n;
}
int Player::getID(){
    return player_id;
}

void Player::makeMove(){}

void Player::resetIndex(int a){
    player_index=a;
}

//char Player::getMove(){}

Player::~Player(){

}
