//
//  abcNode.cpp
//  base_alembic_of8_1
//
//  Created by White, Bob on 5/13/14.
//
//

#include "abcNode.h"

abcNode::abcNode(){
    
}

void abcNode::init(string abc_file, bool _doNormals) {
    
    showWireframe = true;
    
    runAbc = true;
    
    doNormals = _doNormals;
    doReport = false;
    doResetNormals = false;
    
    string path = abc_file;
	abc.open(path);
    
    cout << abc.size() << endl;
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
	material.setShininess( 128 );
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);
    
    materialColor.setHue(145);
    // the light highlight of the material //
	material.setSpecularColor(materialColor);
    
}
//------------------------------------------------------------
void abcNode::setPlayMode(bool animate, float animTime) {
    if(animate){
        this_anim = true;
        runningTime = 0.0;
    } else {
        this_anim = false;
        aTime = animTime;
    }
    
}

//------------------------------------------------------------
void abcNode::setShowWireframe(bool _showWireframe){
    showWireframe = _showWireframe;
}


//------------------------------------------------------------
void abcNode::reportOnMe(string _name){
    doReport = true;
    whoAreYou = _name;
}

//------------------------------------------------------------
void abcNode::resetNormals(){
    doResetNormals = true;
}


//------------------------------------------------------------
void abcNode::customDraw(){
	// We run the update ourselves manually. ofNode does
	//  not do this for us.
	update();
    
    
    
    
    ofPushStyle();
    
    ofSetColor(200,0,0);
    
    for (int i = 0; i < abc.size(); i++){
        
		ofMesh mesh;
        //ofxAlembic::ofMesh mesh;
        //ofxAlembic::IGeom mesh;
        
        if (abc.get(i, mesh))
        {
            
            
            
            
            if(doReport) {
                vector<ofVec3f> mesh_indices = mesh.getVertices();
                
                
                cout << whoAreYou << "-Normals: " << mesh.hasNormals() << endl;
                
                cout << whoAreYou << "-Indices: " << mesh.hasIndices() << endl;
                cout << whoAreYou << "-Num of Verts" << mesh.getNumVertices() << endl;
                cout << whoAreYou << "-Num of Indices" << mesh.getNumIndices() << endl;
                
                /*
                 for(int i=0; i<mesh_indices.size();i++){
                 cout << i << " - [" << mesh_indices[i] << "]" << endl;
                 }
                 */
                
                doReport = false;
                
            }
            
            if(doResetNormals){
                vector<ofVec3f> mesh_indices = mesh.getVertices();
                
                for(int i=0; i<mesh_indices.size();i++){
                    //this adds a normal to the top.
                    mesh.addNormal(ofVec3f(0,1,0));
                    
                }
                
                doResetNormals = false;
                
                doReport = true;
            }
            
            if(doNormals){
                
                
                
                /*
                 //not working correctly
                 
                 for(int i=0; i<mesh_indices.size();i++){
                 ofVec3f current(mesh_indices[i]);
                 ofVec3f prev(mesh_indices[i-1]);
                 ofVec3f next(mesh_indices[i+1]);
                 
                 ofVec3f previousFaceNormal = prev.crossed(current);
                 ofVec3f nextFaceNormal = current.crossed(next);
                 
                 mesh.addNormal((previousFaceNormal + nextFaceNormal).normalize());
                 
                 }
                 */
                
                
                /*
                 if(!mesh.hasNormals()){
                 cout << "this has no normals" << endl;
                 
                 for(int i=0; i<mesh_indices.size();i++){
                 //this adds a normal to the top.
                 mesh.addNormal(ofVec3f(0,1,0));
                 
                 }
                 }
                 */
                
            } else {
                
                
            }
            
            
            material.begin();
            mesh.draw();
            ofSetColor(0,255,0);
            if(showWireframe){
                mesh.drawWireframe();
            }
            //material.end();
            
            
            
            if(ofGetKeyPressed()){
                vector<ofVec3f> n = mesh.getNormals();
                vector<ofVec3f> v = mesh.getVertices();
                float normalLength = 0.5;
                
                ofDisableLighting();
                ofSetColor(0,255,0,70);
                for(unsigned int i=0; i < n.size() ;i++){
                    ofLine(v[i].x,v[i].y,v[i].z,
                           v[i].x+n[i].x*normalLength,v[i].y+n[i].y*normalLength,v[i].z+n[i].z*normalLength);
                    
                    ofLine(.98*v[i].x,.98*v[i].y,.98*v[i].z,
                           .98*v[i].x+n[i].x*normalLength*.2,.98*v[i].y+n[i].y*normalLength*.2,.98*v[i].z+n[i].z*normalLength*.2);
                    ofLine(.98*v[i].x+n[i].x*normalLength*.2,.98*v[i].y+n[i].y*normalLength*.2,.98*v[i].z+n[i].z*normalLength*.2,
                           v[i].x+n[i].x*normalLength*.2,v[i].y+n[i].y*normalLength*.2,v[i].z+n[i].z*normalLength*.2);
                }
            }else {
                ofEnableLighting();
            }
            
        }
        
    }//end for
    ofPopStyle();
    
    
    
    
    
    
}//end function

void abcNode::update(){
    runningTime = fmodf(ofGetElapsedTimef(), abc.getMaxTime());
	if(this_anim) {
        abc.setTime(runningTime);
    } else {
        abc.setTime(aTime);
    }
    
}

//NOT USED (not tested either!)
//----------------------------------------------------
//Universal function which sets normals for the triangle mesh
void setNormals( ofMesh &mesh ){
    //The number of the vertices
    int nV = mesh.getNumVertices();
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    vector<ofPoint> norm( nV ); //Array for the normals
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}