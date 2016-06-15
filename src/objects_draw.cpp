#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::triangle()
{
    for (int i = 0; i < numPointsT; i++)
    {
        ofSetColor(0);
        ofFill();

        if(i < numPointsT - 1 && i != 0)
        {
            ofSetColor(colorT0[i]);
            ofTriangle(pointsT0[i - 1], pointsT0[i], pointsT0[i + 1]);
        }
    }
}

//--------------------------------------------------------------
void ofApp::circle_small()
{
    ofSetCircleResolution(20);
    for (int i = 0; i < numPointsC; i++)
    {
        ofSetColor(0);
        ofFill();
        if(i < numPointsC - 1 && i != 0)
        {
            ofSetColor(colorC0[i]);
            ofCircle(pointsC0[i], 15);
        }
    }
}


//--------------------------------------------------------------
void ofApp::rectangle()
{
    for (int i = 0; i < numPointsR; i++)
    {
        ofSetColor(0);
        ofFill();
        if(i < numPointsR - 1 && i != 0)
        {
            ofSetColor(colorR0[i]);
            ofRect(pointsR0[i], 2, 2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::circle(float rad, float alpha)
{

    ofSetCircleResolution(200);
    ofFill();

    ofColor c;
    c.setHex( palette[0] );
    ofSetColor(c, alpha);
    ofCircle(w/2, h/2, rad);

}

//--------------------------------------------------------------
void ofApp::fullColor()
{
    ofSetHexColor(palette[0]);
    ofRect(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::gui()
{
    float x, y, wi, hi;
    wi = ofGetWidth();
    hi = ofGetHeight();
    x = mouseX / wi;
    y = mouseY / hi;
    ofSetColor(255, 255 ,255);
    ofDrawBitmapString("Steps: " + ofToString(numSteps), 10, 10);
    ofDrawBitmapString("Size: " + ofToString(numPointsT), 10, 21);
    ofDrawBitmapString("CC: " + ofToString(midiMessage.control) + " Value: " + ofToString(midiMessage.value), 10, 32);
    ofDrawBitmapString("MIDI: x:" + ofToString(curveX) + " y: " + ofToString(curveY), 10, 43);
    ofDrawBitmapString("Maus: x: " + ofToString(x) + " y: " + ofToString(y), 10, 54);
    ofDrawBitmapString("FPS: " + ofToString( ofGetFrameRate() ), 10, 65);
    ofDrawBitmapString("line: " + ofToString( drawCurve ), 10, 76);
}

//--------------------------------------------------------------
void ofApp::metronome()
{
    ofSetColor(100);
    ofCircle(5, h-5, 5);
}

//--------------------------------------------------------------
void ofApp::curve( float x, float y )
{
    float l0x0, l0x1, l0x2, l0y0, l0y1, l0y2, l1x1, l1x2, l1x3, l1y1, l1y2, l1y3, mx, my;
    // curve 0
    l0x0 = x * 0.25;
    l0y0 = h * 0.5;
    l0x1 = x * 0.4;
    l0y1 = h * 0.5;
    l0x2 = x * 0.4;
    l0y2 = y;
    mx =  x * 0.5;
    my = y;

    // curve 1
    l1x1 = x * 0.6;
    l1y1 = y;
    l1x2 = x * 0.6;
    l1y2 = h * 0.5;
    l1x3 = y * 0.75;
    l1y3 = h * 0.5;


    ofSetColor(255, 0, 0);
    ofNoFill();
    ofLine(0, h * 0.5, w * 0.25, h * 0.5);
    ofLine(w * 0.75, h * 0.5, w, h * 0.5);
    ofBezier( l0x0, l0y0, l0x1, l0y1, l0x2, l0y2, mx, my );
    ofBezier( mx, my, l1x1, l1y1, l1x2, l1y2, l1x3, l1y3 );

    // map triangles to points on curve:
    for(int i=0; i<numPointsT; i++)
    {
        ofPoint a, b, c, d, e, f, g;

        a = ofPoint( l0x0, l0y0 );
        b = ofPoint( l0x1, l0y1 );
        c = ofPoint( l0x2, l0y2 );
        d = ofPoint( mx, my );
        e = ofPoint( l1x1, l1y1 );
        f = ofPoint( l1x2, l1y2 );
        g = ofPoint( l1x3, l1y3 );

        // verhältnisse der Liniengrößen einbeziehen?
        if(i < numPointsT * 1/4 )
        {
            pointsT1[i] = ofPoint( i * ((w / 4) / (numPointsT / 4)), h / 2 ) + pointsRAdd[i];
        }
        else if( i < numPointsT * 2/4 )
        {
            pointsT1[i] = ofBezierPoint(a, b, c, d, i * (1 / (numPointsT / 4)) ) + pointsRAdd[i];
        }
        else if( i < numPointsT * 3/4 )
        {
            pointsT1[i] = ofBezierPoint(d, e, f, g,i * (1 / (numPointsT / 4)) ) + pointsRAdd[i];
        }
        else if(i > numPointsT * 3/4 )
        {
            pointsT1[i] = ofPoint(i * ((w / 4) / (numPointsT / 4)), h / 2 ) + pointsRAdd[i];
        }
    }
}
