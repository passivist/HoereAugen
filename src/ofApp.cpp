/*
    ToDo:

    Farbmodus
        -> Roter Modus, Gelb vs. Random Modus
        -> Farben Punkte
    Linien Modus ("Puls")
    Farben Array Modifikation
    Patterns/Marcros
    Midi Mapping

*/

#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // OF INIT
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    // Variablen
    w = ofGetWidth();
    h = ofGetHeight();

    // Sytem
    numPointsT = 15;
    numPointsR = 200;
    numPointsC = 20;
    numSteps = 4;
    numColors = 5;

    // Objects
    sizeT = 0;
    sizeR = 1;
    sizeC = h/2;
    sizeCS = 1;

    alphaC = 255;
    curveX = w/2;
    curveY = h/2;

    freq_W = 5;
    sine = 1;

    mid = ofPoint(w/2, h/2);

    drawGui = false;
    drawCircle = false;
    drawCircle_small = false;
    drawTriangle = false;
    drawRect = false;
    drawCurve = false;
    drawMetronome = true;

    aniSine = false;
    aniLine = false;
    aniStrobe = false;

    // INIT funcs:
    MIDI_init();
    objects_init();

    // Init
    ofBackground(255);
    ofSetCircleResolution(200);
    ofSetCurveResolution(200);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update()
{
    // Time
    time = ofGetElapsedTimeMillis();

    // Objects
    if(drawCircle_small == true){ updateCircle_small(); }
    if(drawRect == true){ updateRect(); }
    if(drawTriangle == true){ updateTriangle(); }

    // Animation
    if(aniSine == true){ sineFunc(1, 1); }
    if(aniLine == true){ lineFunc(1, 1); }
    // anfang der Linie verschwindet aus irgendwelchen Gruenden wie habe ich das vorher geloest?
    if(drawCurve == true){ curve(lineX, curveY ); }
    if(aniStrobe == true){ strobeFunc(1); }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    x = ofRandom(0, w);
    y = ofRandom(0, h);

    ofBackground(0, 0, 0);

    if(drawRect == true){ rectangle(); }
    if(drawCircle_small == true){ circle_small(); }
    if(drawTriangle == true){ triangle(); }
    if(drawCircle == true){ circle(sizeC * sine, alphaC); }
    if(drawColor == true){ fullColor(); }
    if(drawGui == true){ gui(); }
    if(drawMetronome){ if(time % 500 < 100){ metronome(); } }

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch(key)
    {
        case OF_KEY_TAB:
            if(drawGui == true){ drawGui = false; } else { drawGui = true; }
            break;
    }
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    if(drawCurve == true)
    {
        curve(curveX, curveY);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
