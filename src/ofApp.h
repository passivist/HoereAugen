#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

#include <algorithm>
#include <vector>
#include <iostream>

class ofApp : public ofBaseApp, public ofxMidiListener
{

public:
    // OF Main funcs:
    void setup();
    void update();
    void draw();

    // INIT funcs:

    void MIDI_init();
    void objects_init();

    // Update:
    void updateCircle_small();
    void updateRect();
    void updateTriangle();
    void colorMode(int which);

    void newPoints(int num);
    void updateCloud(int num, int freq, int amt, float width, bool who);
    void sortieren(int dir);
    void tauschen(int num);
    void ausbreiten();

    //Draw
    void triangle();
    void rectangle();
    void circle(float rad, float alpha);
    void circle_small();
    void fullColor();
    void curve(float x, float y);
    void gui();
    void metronome();

    // Animationen
    bool aniSine;
    float sine;
    void sineFunc(float freq, float size);

    bool aniLine;
    float lineX;
    void lineFunc(float freq, float size);

    bool aniStrobe;
    void strobeFunc(float freq);

    // Add-Remove:
    void addPoint();
    void removePoint();
    void randomPoints();

    // Variablen:
    int h, w, x, y, numPointsT, numPointsR, numPointsC, numSteps, numColors, time, freq_W;
    // Objects:
    float sizeT, sizeR, sizeCS, sizeC;
    float alphaC, curveX, curveY;
    bool drawGui, drawCircle, drawCircle_small, drawTriangle, drawColor, drawRect, drawCurve, drawMetronome;

    ofPoint mid;

    // Vectors:
    vector<ofPoint> pointsT0;
    vector<ofPoint> pointsT1;
    vector<ofColor> colorT0;
    vector<ofColor> colorT1;

    vector<ofPoint> pointsR0;
    vector<ofPoint> pointsR1;
    vector<ofPoint> pointsRAdd;
    vector<ofColor> colorR0;
    vector<ofColor> colorR1;

    vector<ofPoint> pointsC0;
    vector<ofPoint> pointsC1;
    vector<ofPoint> pointsCAdd;
    vector<ofColor> colorC0;
    vector<ofColor> colorC1;

    vector<int> palette;


    // MIDI
    stringstream text;

    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;

    void midiMapping();
    void newMidiMessage(ofxMidiMessage& eventArgs);

    // OF Funcs:
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
