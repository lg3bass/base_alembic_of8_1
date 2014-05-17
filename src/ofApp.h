#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAlembic.h"
#include "abcNode.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void myButtonPressed();
    void resetNormalsPressed();
    
    ofEasyCam cam;
    
    ofLight light;
    
    ofVec3f center;
    
    //custom ofNode, used to scale the scene.
    abcNode myABC_1, myABC_2, myABC_3, myABC_4;
    
    
    //gui
    bool bHide;
    ofxToggle animP;
    ofxToggle toggleWire;
    ofxFloatSlider timeP;
    ofxButton myButton;
    ofxButton testBut;
    
    
    
    
    ofxPanel gui;
		
};
