#pragma once // 重複したheaderファイルの読み込みを無視

#include "ofMain.h"
#include "Particle.h"

class Spark: public Particle{
public:
    bool fade;
    int distance;
    ofVec2f origin;

    Spark(): Particle(){
        distance = 0;
    };
    virtual ~Spark(){};
    virtual void draw();
    virtual void setInitalCondition(float px, float py, float vx, float vy);
};

class Hanabi {
public:
    ofVec2f originPos;
    int size;
    int frame;
    ofColor color;
    
    Hanabi();
    virtual ~Hanabi(){};  // descractor
    void setInitialCondition(int size, float px = ofGetWidth()/2, float py = ofGetHeight()/2, ofColor color = ofColor::white);
    void setPosition(float px, float py);
    void setColor(ofColor color);
    void setSize(int size);
    void prepare();
    void fire();
    
    vector <Spark> sparks;
};
