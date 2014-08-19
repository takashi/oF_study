#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); // base color of window
    ofEnableSmoothing(); // generate graphic edge and gradient more smooth

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    // set width and height of movie that will be captured.
    camWidth = 480;
    camHeight = 320;
    
    //    grabber.setVerbose(true); disabled from 0.0.6. use ofSetLogLevel(OF_LOG_VERBOSE)
    ofSetLogLevel(OF_LOG_VERBOSE);
    grabber.initGrabber(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    grabber.draw(20, 20);
    // there is two way to get pixels data from captured image.
    //    drawWithPixels();
    drawWithPixelRef();
}

void ofApp::drawWithPixels() {
    unsigned char * pixels = grabber.getPixels();
    //  画像を10ピクセルごとにスキャン
    for (int i = 0; i < camWidth; i+=10){
        for (int j = 0; j < camHeight; j+=10){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * camWidth + i)*3];
            unsigned char g = pixels[(j * camWidth + i)*3+1];
            unsigned char b = pixels[(j * camWidth + i)*3+2];
            cout << (float)r << (float)g << (float)b << endl;
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)b/255.0);
        }
    }
}

void ofApp::drawWithPixelRef() {
    ofPixelsRef pixelsRef = grabber.getPixelsRef();
    //    scan image by every 10px
    for (int i = 0; i < camWidth; i+=10) {
        for (int j = 0; j < camHeight; j+=10) {
            ofColor color = pixelsRef.getColor(i,j);
            unsigned char r = color.r;
            unsigned char g = color.g;
            unsigned char b = color.b;
            cout << (float)r << (float)g << (float)b << endl;
            ofSetColor(255, 0, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(camWidth+40 + i,20+j,20.0*(float)b/255.0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // video settings is not suported in 10.7+
    if (key == 's' || key == 'S'){
        grabber.videoSettings();
    }
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
