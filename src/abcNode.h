#pragma once
#include "ofMain.h"
#include "ofxAlembic.h"

//
//  abcNode.h
//  base_alembic_of8_1
//
//  Created by White, Bob on 5/13/14.
//
//

#ifndef base_alembic_of8_1_abcNode_h
#define base_alembic_of8_1_abcNode_h

#include <iostream>

#endif

class abcNode : public ofNode {

    ofxAlembic::Reader abc;
    //ofVboMesh mesh;
    
    ofColor materialColor;
    ofMaterial material;
    
    float runningTime;
    bool this_anim;
    float aTime;
    
    bool runAbc;
    
    bool doNormals;
    bool doReport;
    bool doResetNormals;
    
    bool showWireframe;
    
    string whoAreYou;
    
public:
    
    abcNode();
    void init(string abc_file, bool _doNormals);
    void customDraw();
    void setPlayMode(bool animate, float animTime);
    void setShowWireframe(bool _showWireframe);
    
    void reportOnMe(string _name);
    
    void resetNormals();
    // we call this update function ourselves
    //  at the beginning of customDraw
    void update();
    
    void setNormals( ofMesh &mesh );
    
};