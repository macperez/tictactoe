#include <iostream>
#include "Enemy.h"

Enemy::Enemy(std::string name, int lives, int damage):
    name_(name), lives_(lives), damage_(damage){

    }

void Enemy::Attack(Enemy &e) const {
    std::cout << name_ << " attacks" << e.name_ << std::endl;
    e.lives_--;
}