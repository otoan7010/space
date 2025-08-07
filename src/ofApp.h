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
		vector<ofVec3f> stars;
		int numStars = 1000;
		ofVec3f preMousePos;
		ofImage img_space, img_sun, img_mercury,
			    img_venus, img_earth,  img_moon, img_mars,
			    img_jupiter, img_saturn, img_saturn2,
			    img_uranus, img_uranus2, img_neptune;

		ofTexture tex_space, tex_sun, tex_mercury,
			      tex_venus, tex_earth, tex_moon, tex_mars,
			      tex_jupiter, tex_saturn, tex_saturn2,
			      tex_uranus, tex_uranus2, tex_neptune;

		float r_space, r_sun, r_mercury,
			    r_venus, r_earth, r_moon, r_mars,
			    r_jupiter, r_saturn, r_saturn2,
			    r_uranus, r_uranus2, r_neptune;

		float a_space, a_sun, a_mercury,
			a_venus, a_earth, a_moon, a_mars,
			a_jupiter, a_saturn, a_saturn2,
			a_uranus, a_uranus2, a_neptune;

		int cameraTarget = 0; // 0: 太陽, 1: 水星, ..., 8: 海王星
		ofVec3f planetPositions[9];
};
