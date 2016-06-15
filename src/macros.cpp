#include "ofApp.h"
#include "math.h"

void ofApp::sineFunc(float freq, float size)
{
    int length = 1000;
    float step = ofMap( (time % length), 0, length, 0, PI);
    float result = sin( step );
    sine = result;
}

void ofApp::lineFunc(float freq, float size)
{
    int length = 4000;
    lineX = ((time % length) / 4000.0) * w * 3;

}

void ofApp::strobeFunc(float freq)
{
    if(time % 50 < 30){ drawColor = true; } else { drawColor = false; };
}
