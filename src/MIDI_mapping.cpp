#include "ofApp.h"

void ofApp::MIDI_init()
{
    // Midi Stuff
    //ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetLogLevel(OF_LOG_SILENT);
    // print input ports to console
    midiIn.listPorts(); // via instance
    //ofxMidiIn::listPorts(); // via static as well

    // open port by number (you may need to change this)
    //midiIn.openPort(1);
    midiIn.openPort("Akai MPK49 Port 1"); // by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port

    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);

    // add testApp as a listener
    midiIn.addListener(this);

    // print received messages to the console
    midiIn.setVerbose(true);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg)
{
    // make a copy of the latest message
    midiMessage = msg;
    
    
    std::cout   << "MIDI CC: "   << msg.control
                << " MIDI VAL: " << msg.value
                << " NOTE: "     << msg.pitch
                << " VEL: "      << msg.velocity
                << std::endl;
    
    
    /*****************************
     *          FADER
     ****************************/
    switch (msg.control)
    {
        // Circle
        // Fader
        case 20:
            sizeC = ofMap( msg.value, 0, 127, 0, h );
            break;
        case 21:
            alphaC = ofMap( msg.value, 0, 127, 0, 255 );
            break;
        // Button
        //case 28:
        //    if( msg.value == 127 ){ drawCircle = true; } else { drawCircle = false; }
        //    break;
        //case 29:
        //    if( msg.value == 127 ){ aniSine = true; } else { aniSine = false; sine = 1; }
        //    break;

        // Triangles
        // Fader
        case 22:
            sizeT = ofMap( msg.value, 0, 127, 1, 0 );
            break;
        case 23:
            curveY = ofMap( msg.value, 0, 127, h/2, 0 );
            break;
        // Button
        //case 30:
        //   if( msg.value == 127 ){ drawTriangle = true; } else { drawTriangle = false; }
        //    break;
        //case 31:
        //    if( msg.value == 127 ){ newPoints(numPointsT); }
        //    break;
        //case 35:
        //    if( msg.value == 127 ){ aniLine = true; drawCurve = true; randomPoints(); } else { aniLine = false; drawCurve = false; }
        //    break;

        // Circle Small
        // Fader
        case 25:
            sizeCS = ofMap( msg.value, 0, 127,  0, 1 );
            break;

        //Button
        //case 41:
        //    if(msg.value == 127){ drawCircle_small = true; } else { drawCircle_small = false; }
        //    break;
    };
    
    /*****************************
     *          KEYS
     ****************************/
    int thresh = 0;
    switch (msg.pitch) {
        case 72:
            if( msg.velocity > thresh ){ drawCircle = true; } else { drawCircle = false; }
            break;
            
        case 74:
            if( msg.velocity  > thresh ){ aniSine =  true; } else { aniSine = false; sine = 1; }
            break;
            
        case 77:
            if( msg.velocity > thresh ){ drawTriangle = true; } else { drawTriangle = false; }
            break;
        case 79:
            if( msg.velocity > thresh ){ newPoints(numPointsT); }
            break;
        case 81:
            if( msg.velocity > thresh ){ aniLine = true; drawCurve = true; randomPoints(); } else { aniLine = false; drawCurve = false; }
            break;
        case 84:
            if(msg.velocity > thresh ){ drawCircle_small = true; } else { drawCircle_small = false; }
            break;
          
        // Fullscreen
        case 73:
            if(msg.velocity > thresh) {
                aniStrobe = true;
            } else {
                aniStrobe = false;
                drawColor = false;
            }
            break;
        case 75:
            if( msg.velocity > thresh ){
                drawColor = true;
            } else {
                drawColor = false;
            }
            break;
            
        // FARBEN:
        case 60:
            if( msg.velocity > thresh ) colorMode(0);
            break;
        case 62:
            if( msg.velocity > thresh ) colorMode(1);
            break;
        case 64:
            if( msg.velocity > thresh ) colorMode(2);
            break;
        case 65:
            if( msg.velocity > thresh ) colorMode(3);
            break;
        case 67:
            if( msg.velocity > thresh ) colorMode(4);
            break;
        case 69:
            if( msg.velocity > thresh ) colorMode(5);
            break;
        case 71:
            if( msg.velocity > thresh ) colorMode(6);
            break;
            
        default:
            break;
    }
    
}
