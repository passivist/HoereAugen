#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::objects_init()
{
    // Vectors
    pointsT0.resize(numPointsT);
    pointsT1.resize(numPointsT);
    colorT0.resize(numPointsT);
    colorT1.resize(numPointsT);

    pointsR0.resize(numPointsR);
    pointsR1.resize(numPointsR);
    colorR0.resize(numPointsR);
    colorR1.resize(numPointsR);
    pointsRAdd.resize(numPointsR);

    pointsC0.resize(numPointsC);
    pointsC1.resize(numPointsC);
    colorC0.resize(numPointsC);
    colorC1.resize(numPointsC);
    pointsCAdd.resize(numPointsC);


    colorMode(0);
    newPoints(numPointsT);

    // First Array:
    // Triangle
    for(int i = 0; i < numPointsT; i++)
    {
        ofColor c;
        int rand = ofRandom( 4 );
        c.setHex(palette[ rand ], 200);
        float x = ofRandom(w);
        float y = ofRandom(h);
        pointsT0[i] = ofPoint(x, y);
        colorT0[i] = c;
    }

    // Circle Small
    for(int i = 0; i < numPointsC; i++)
    {
        ofColor c;
        int rand = ofRandom( 4 );
        c.setHex(palette[ rand ], 200);
        float x = ofRandom(0, w);
        float y = ofRandom(0, h);
        pointsC0[i] = ofPoint(x, y);
        colorC0[i] = c;
    }

    // Rectangle Small
    for(int i = 0; i < numPointsR; i++)
    {
        ofColor c;
        int rand = ofRandom( 4 );
        c.setHex(palette[ rand ], 200);
        float x = ofRandom(0, w);
        float y = ofRandom(0, h);
        pointsR0[i] = ofPoint(x, y);
        colorR0[i] = c;
    }
}

//--------------------------------------------------------------
void ofApp::updateTriangle()
{
    // Triangle
    //sizeT = ofMap( mouseX, 0, w, 0, 1 );
    for (int i = 0; i < numPointsT; i++)
    {
        ofPoint dist = pointsT1[i] - pointsT0[i];

        if(pointsT0[i] != pointsT1[i])
        {
            pointsT0[i] = pointsT0[i] + (dist / numSteps);
        }

        pointsT0[i].x = ofMap(sizeT, 0, mid.x / pointsT0[i].x, 1, mid.x / pointsT0[i].x) * pointsT0[i].x;
        pointsT0[i].y = ofMap(sizeT, 0, mid.y / pointsT0[i].y, 1, mid.y / pointsT0[i].y) * pointsT0[i].y;
        // Was funktioniert hier noch nicht richtig? Fehler accumuliert zu weiß?
        if(colorT0[i] != colorT1[i])
        {
            //colorT0[i] = colorT0[i] + ((colorT1[i] - colorT0[i]) / numSteps);
            colorT0[i] = colorT1[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::updateCircle_small()
{
    // Circle Small
    //sizeCS = ofMap( mouseX, 0, w, 0, 1 );
    updateCloud(numPointsC, freq_W, 1, 0.5, true);
    for (int i=0; i<numPointsC; i++)
    {
        ofPoint dist = pointsC1[i] - pointsC0[i];

        if(pointsC0[i] != pointsC1[i])
        {
            pointsC0[i] = pointsC0[i] + (dist / numSteps);
        }

        pointsC0[i].x = ofMap(sizeCS, 0, mid.x / pointsC0[i].x, 1, mid.x / pointsC0[i].x) * pointsC0[i].x;
        pointsC0[i].y = ofMap(sizeCS, 0, mid.y / pointsC0[i].y, 1, mid.y / pointsC0[i].y) * pointsC0[i].y;

        if(colorC0[i] != colorC1[i])
        {
            //colorT0[i] = colorT0[i] + ((colorT1[i] - colorT0[i]) / numSteps);
            colorC0[i] = colorC1[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::updateRect()
{
    // Rectangle Small
    //sizeR = ofMap( mouseX, 0, w, 0, 1 );
    updateCloud(numPointsR, freq_W / 2, 10, 0.2, false);
    for (int i=0; i<numPointsR; i++)
    {
        ofPoint dist = pointsR1[i] - pointsR0[i];

        if(pointsR0[i] != pointsR1[i])
        {
            pointsR0[i] = pointsR0[i] + (dist / numSteps);
        }

        pointsR0[i].x = ofMap(sizeR, 0, mid.x / pointsR0[i].x, 1, mid.x / pointsR0[i].x) * pointsR0[i].x;
        pointsR0[i].y = ofMap(sizeR, 0, mid.y / pointsR0[i].y, 1, mid.y / pointsR0[i].y) * pointsR0[i].y;


        if(colorR0[i] != colorR1[i])
        {
            //colorT0[i] = colorT0[i] + ((colorT1[i] - colorT0[i]) / numSteps);
            colorR0[i] = colorR1[i];
        }

    }
}

//--------------------------------------------------------------
void ofApp::updateCloud(int num, int freq, int amt,float width, bool who)
{
    if (time % freq == 0)
    {
        for(int i=0; i<amt; i++)
        {
            int randP, randC;
            float x, y;
            randP = ofRandom(num);
            randC = ofRandom(5);
            ofColor c;
            c.setHex( palette[randC], 200 );
            x = ofRandom( w/2, -w/2 ) * width;
            y = ofRandom( h/2, -w/2 ) * width;

            if( who == true)
            {
                x = ofClamp( pointsC1[randP].x + x, 0, w );
                y = ofClamp( pointsC1[randP].y + y, 0, h );
                pointsC1[randP] = ofPoint(x, y);
                colorC1[randP] = c;
            }
            else
            {
                x = ofClamp( pointsR1[randP].x + x, 0, w );
                y = ofClamp( pointsR1[randP].y + y, 0, h );
                pointsR1[randP] = ofPoint(x, y);
                colorR1[randP] = c;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::randomPoints()
{
    pointsRAdd.resize(numPointsT);

    for(int i=0; i<numPointsT; i++)
    {
        pointsRAdd[i] = ofPoint( ofRandom( -20, 20), ofRandom(-20, 20) );
    }
}

//--------------------------------------------------------------
void ofApp::newPoints(int num)
{
    // triangle
    for(int i=0; i<numPointsT; i++)
    {
        int rand = ofRandom(5);
        ofColor c;
        c.setHex( palette[rand], 200 );
        float x = ofRandom( w );
        float y = ofRandom( h );
        pointsT1[i] = ofPoint(x, y);
        colorT1[i] = c;
    }

    // rectangle
    for(int i=0; i<numPointsR; i++)
    {
        int rand = ofRandom(5);
        ofColor c;
        c.setHex( palette[rand], 200 );
        float x = ofRandom( w );
        float y = ofRandom( h );
        pointsR1[i] = ofPoint(x, y);
        colorR1[i] = c;
    }

    // circle small
    for(int i=0; i<numPointsC; i++)
    {
        int rand = ofRandom(5);
        ofColor c;
        c.setHex( palette[rand], 200 );
        float x = ofRandom( w );
        float y = ofRandom( h );
        pointsC1[i] = ofPoint(x, y);
        colorC1[i] = c;
    }
}

//--------------------------------------------------------------
void ofApp::addPoint()
{
    // Hier noch einige Probleme
    float x, y;
    int rand = ofRandom(5);
    ofColor c;
    c.setHex(palette[rand], 200);
    x = ofRandom(w);
    y = ofRandom(h);

    // Triangle
    pointsT0.push_back(ofPoint(x, y));
    pointsT1.push_back(ofPoint(x, y));
    colorT0.push_back(c);
    colorT1.push_back(c);

    numPointsT++;

    pointsRAdd.resize(numPointsT);

    newPoints(numPointsT);
}

//--------------------------------------------------------------
void ofApp::removePoint()
{
    pointsT0.erase(pointsT0.end());
    pointsT1.erase(pointsT1.end());
    colorT0.erase(colorT0.end());
    colorT1.erase(colorT1.end());

    numPointsT--;

    pointsRAdd.resize(numPointsT);

    newPoints(numPointsT);
}

//--------------------------------------------------------------
void ofApp::sortieren(int dir)
{
    vector<float> inter;
    inter.resize(numPointsT);
    if (dir == 0)
    {
        // X Pos:
        for(int i=0; i<numPointsT; i++)
        {
            inter[i] = pointsT1[i][0];
        }

        sort( inter.begin(), inter.end() );

        for(int i=0; i<numPointsT; i++)
        {
            pointsT1[i][0] = inter[i];
        }
    }
    else
    {
        // Y Pos:
        for(int i=0; i<numPointsT; i++)
        {
            inter[i] = pointsT1[i][1];
        }

        sort(inter.begin(), inter.end());

        for(int i=0; i<numPointsT; i++)
        {
            pointsT1[i][1] = inter[i];
        }
    }

}

//--------------------------------------------------------------
void ofApp::tauschen(int num)
{
    vector<ofPoint> inter;
    inter.resize(numPointsT);
    inter = pointsT0;
    ofRandomize(inter);
    pointsT1 = inter;
}

//--------------------------------------------------------------
void ofApp::ausbreiten()
{
    vector<ofPoint> edge;
    vector<ofPoint> inter;
    vector<float> dist;
    int edgeSize;
    edgeSize = (numPointsT / 4) + 4;

    edge.resize(edgeSize);
    edge[0] = ofPoint( 0, 0 );
    edge[1] = ofPoint( w, 0 );
    edge[2] = ofPoint( w, h );
    edge[3] = ofPoint( 0, h );

    for(int i = 4; i < edgeSize; i++)
    {
        int side, rx, ry;

        side = ofRandom( 0, 3 );
        rx = ofRandom(10, w - 10);
        ry = ofRandom(10, h - 10);

        switch(side)
        {
        case 0:
            edge[i] = ofPoint( 0, ry );
            break;
        case 1:
            edge[i] = ofPoint( rx, 0 );
            break;
        case 2:
            edge[i] = ofPoint( w, ry );
            break;
        case 3:
            edge[i] = ofPoint( rx, h );
            break;

        }
    }

    for(int i = 0; i < edge.size(); i ++)
    {
        pointsT1[i] = edge[i];
    }

}

//--------------------------------------------------------------
void ofApp::colorMode(int which)
{
    palette.clear();
    switch(which)
    {

        case 0:
        // Random 1:
        palette.push_back(0x0F3147);
        palette.push_back(0x57605E);
        palette.push_back(0xECE3AC);
        palette.push_back(0xC47C69);
        palette.push_back(0xBF4141);
        break;
        // Rot
        case 1:
        palette.push_back(0xFF0000);
        palette.push_back(0xAF0000);
        palette.push_back(0xBB0000);
        palette.push_back(0xCF0000);
        palette.push_back(0x9C1818);
        break;
        // Blau
        case 2:
        palette.push_back(0x0010FF);
        palette.push_back(0xA398CA);
        palette.push_back(0x6440E7);
        palette.push_back(0x8872DC);
        palette.push_back(0x7457DF);
        break;
        //Lila
        case 3:
        palette.push_back(0xC119B6);
        palette.push_back(0xDB2793);
        palette.push_back(0xBF2B84);
        palette.push_back(0xAE4484);
        palette.push_back(0xC673A5);
        break;
        //Gelb
        case 4:
        palette.push_back(0xFFF500);
        palette.push_back(0xEACB3D);
        palette.push_back(0xD9BA2A);
        palette.push_back(0xE2EA54);
        palette.push_back(0xCCC51C);
        break;
        //Weiß
        case 5:
        palette.push_back(0xFFFFFF);
        palette.push_back(0xE3E3E3);
        palette.push_back(0xC7C7C7);
        palette.push_back(0xA9A7A7);
        palette.push_back(0x999797);
        break;
        //Pink
        case 6:
        palette.push_back(0xFF3179);
        palette.push_back(0xFFA0C2);
        palette.push_back(0xFF7DAA);
        palette.push_back(0xFF4E8C);
        palette.push_back(0xFFBCD3);
        break;
    }

    // First Array:
    // Triangle
    for(int i = 0; i < numPointsT; i++)
    {
        ofColor c;
        int rand = ofRandom( 5 );
        c.setHex(palette[ rand ], 200);
        colorT1[i] = c;
        colorT0[i] = c;
    }

    // Circle Small
    for(int i = 0; i < numPointsC; i++)
    {
        ofColor c;
        int rand = ofRandom( 5 );
        c.setHex(palette[ rand ], 200);
        colorC1[i] = c;
        colorC0[i] = c;

    }

    // Rectangle Small
    for(int i = 0; i < numPointsR; i++)
    {
        ofColor c;
        int rand = ofRandom( 5 );
        c.setHex(palette[ rand ], 200);
        colorR1[i] = c;
        colorR0[i] = c;
    }
}
