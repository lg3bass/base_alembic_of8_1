#include "ofMain.h"
#include "ofApp.h"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    ofAppGLFWWindow window;
    window.setNumSamples(16);
    
	// <-------- setup the GL context
    ofSetupOpenGL(640,360,OF_WINDOW);
    //ofSetupOpenGL(1280,720,OF_WINDOW);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
    
}
