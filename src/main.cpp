#include "ofMain.h"
#include "ofApp.h"

//========================================================================

int main(){
    // Auflšsung einstellen!
	ofSetupOpenGL(1920, 1080, OF_FULLSCREEN);
	//ofSetupOpenGL(640, 480, OF_WINDOW);
	ofRunApp(new ofApp());
}
