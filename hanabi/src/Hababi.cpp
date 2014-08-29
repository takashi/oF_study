#include "Hanabi.h"
#include "Particle.h"

void Spark::draw(){
    ofCircle(pos.x, pos.y, 2);
}

void Spark::setInitalCondition(float px, float py, float vx, float vy) {
    pos.set(px, py);
    vel.set(vx, vy);
}

Hanabi::Hanabi() {}

void Hanabi::setInitialCondition(int size, float px, float py, ofColor color){
    setSize(size);
    setColor(color);
    setPosition(px, py);
    frame = 0;
    float radian = PI * 2;
    int i = 0;
    for (; i < 800; i++) {
        float angle = ofRandom(0, 1) * radian;
        float speed = ofRandom(0, 1) * 3;
        Spark p;
        p.setInitialCondition(originPos.x, originPos.y,
                              cos(angle)*speed, sin(angle)*speed);
        sparks.push_back(p);
    }
}

void Hanabi::setPosition(float px, float py) {
    this->originPos.set(px, py);
}

void Hanabi::setSize(int size) {
    this->size = size;
}

void Hanabi::setColor(ofColor color) {
    this->color = color;
}

void Hanabi::prepare() {
    int i = 0;
    for (; i < sparks.size(); i=i+1 ){
        sparks[i].resetForce();
        sparks[i].addForce(0, 0.001);
        sparks[i].update();
    }
}

void Hanabi::fire() {    
    ofSetColor(color);
    int i = 0;
    for (; i<sparks.size(); i=i+1 ){
        sparks[i].draw();
    }
}
