//
//  Particle.cpp
//  hanabi
//
//  Created by Takashi Nakagawa on 2014/08/16.
//
//

#include "Particle.h"

Particle::Particle() {
    setInitialCondition(0, 0, 0, 0);
    damping = 0.01f;
}

void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
}

void Particle::resetForce(){
    frc.set(0,0);
}

// 力を加える
void Particle::addForce(float x, float y){
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

// 抵抗力
void Particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.x * damping;
}

void Particle::update(){
    vel = vel+frc;
    pos = pos+vel;
}

void Particle::draw(){
    ofCircle(pos.x, pos.y, 1);
}
