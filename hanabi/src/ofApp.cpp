#include "ofApp.h"
#include "Hanabi.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetWindowTitle("particle example");
    
    ofSetBackgroundAuto(false); //フレーム更新時に塗り潰しを無効化
    ofBackground(0, 0, 0); //背景色を黒に設定
}

//--------------------------------------------------------------
void ofApp::update(){
    int i = 0;
    for (; i < sets.size(); i++) {
        sets[i].prepare();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 30); //半透明の黒（背景色）
    ofRect(0, 0, ofGetWidth(), ofGetHeight()); //画面と同じ大きさの四角形を描画

    int i = 0;
    for (; i < sets.size(); i++) {
        sets[i].fire();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofColor c;
    c.setHsb(ofRandom(50, 255), 255, 255);
    Hanabi hanabi;
    hanabi.setInitialCondition(100, x, y, c);
    sets.push_back(hanabi);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


