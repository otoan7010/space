#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofEasyCam cam; //ofCamera クラスのインスタンス cam を生成
		ofLight light; //ofLight クラスのインスタンス light0 を作成
		ofMaterial material[3]; //ofMateial クラスのインスタンスを作成
		ofVec3f r;
		ofVec3f preMousePos;
		ofImage img1, img2, img3;
		ofTexture tex1, tex2, tex3;
		
};
