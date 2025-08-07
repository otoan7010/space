#include "ofApp.h"
ofVec3f addr, addt, t, lightPos;
ofVec2f preMousePos;




//--------------------------------------------------------------
void ofApp::setup() {
	//カメラの設定

	// cam の初期設定（任意）
	cam.setDistance(300); // 視点と対象の距離
	cam.setNearClip(0.5);
	cam.setFarClip(10000);
	cam.setFov(110); // 視野角（好みで調整）

	ofDisableArbTex(); //GL_TEXTURE_2D モードでテクスチュアを生成
	ofEnableDepthTest(); //深さ判定を有効に

	//tex1
	img_space.load("space.jpg"); //画像ファイルは bin の下の data フォルダに入れる
	tex_space.loadData(img_space);
	tex_space.setTextureWrap(GL_REPEAT, GL_REPEAT); //縦横とも繰り返し
	tex_space.setTextureMinMagFilter(GL_LINEAR, GL_LINEAR); //補間方法を線形補間に
	tex_space.texData.tex_t = 10; //横の繰り返し数
	tex_space.texData.tex_u = 10; //縦の繰り返し数

	//sun
	img_sun.load("sun.jpg");
	tex_sun.loadData(img_sun);
	//mercury
	img_mercury.load("mercury.jpg");
	tex_mercury.loadData(img_mercury);
	//venus
	img_venus.load("venus.jpg");
	tex_venus.loadData(img_venus);
	//earth
	img_earth.load("earth.jpg");
	tex_earth.loadData(img_earth);
	//moon
	img_moon.load("moon.jpg");
	tex_moon.loadData(img_moon);
	//mars
	img_mars.load("mars.jpg");
	tex_mars.loadData(img_mars);
	//jupiter
	img_jupiter.load("jupiter.jpg");
	tex_jupiter.loadData(img_jupiter);
	//saturn
	img_saturn.load("saturn.jpg");
	tex_saturn.loadData(img_saturn);
	//saturn2
	img_saturn2.load("saturn2.jpg");
	tex_saturn2.loadData(img_saturn2);
	//uranus
	img_uranus.load("uranus.jpg");
	tex_uranus.loadData(img_uranus);
	//uranus2
	img_uranus2.load("uranus2jpg");
	tex_uranus2.loadData(img_uranus2);
	//neptune
	img_neptune.load("neptune.jpg");
	tex_neptune.loadData(img_neptune);

	ofBackground(0);

	for (int i = 0; i < numStars; i++) {
		float x = ofRandom(-5000, 5000);
		float y = ofRandom(-5000, 5000);
		float z = ofRandom(-5000, 5000);
		stars.push_back(ofVec3f(x, y, z));
	}
}
//--------------------------------------------------------------
void ofApp::update(){
	// カメラを対象の惑星に移動させる（オフセットあり）
	ofVec3f targetPos = planetPositions[cameraTarget];
	ofVec3f camPos = targetPos + ofVec3f(0, 50, 200); // 惑星から少し離れた位置
	cam.setPosition(camPos);
	cam.lookAt(targetPos);


	a_mercury += 0.16;
	a_venus += 0.12;
	a_earth += 0.1;
	a_moon += 0.08;
	a_mars += 0.08;
	a_jupiter += 0.05;
	a_saturn += 0.04;
	a_uranus += 0.03;
	a_neptune += 0.02;

	r_mercury += 0.5;
	r_venus += -0.1;
	r_earth += 2;
	r_moon += 2;
	r_mars += 1.8;
	r_jupiter += 4;
	r_saturn += 3.5;
	r_uranus += -2;
	r_neptune += 1.5;
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();
	ofEnableDepthTest();
	ofEnableSmoothing();


	// 星
	ofSetColor(255); 
	for (auto & star : stars) {
		ofDrawSphere(star, 3); 
	}

	// 太陽
	ofPushMatrix();
	planetPositions[0].set(0, 0, 0);
	tex_sun.bind();
	ofDrawSphere(0, 0, 0, 100); 
	tex_sun.unbind();
	ofPopMatrix();

	// 水星
	ofPushMatrix();
	float mercuryDist = 150;
	float mercuryX = cos(ofDegToRad(a_mercury)) * mercuryDist;
	float mercuryZ = sin(ofDegToRad(a_mercury)) * mercuryDist;
	planetPositions[1].set(mercuryX, 0, mercuryZ);
	ofTranslate(mercuryX, 0, mercuryZ);
	ofRotateDeg(r_mercury, 0, 1, 0); 
	tex_mercury.bind();
	ofDrawSphere(4); 
	tex_mercury.unbind();
	ofPopMatrix();

	// 金星
	ofPushMatrix();
	float venusDist = 220;
	float venusX = cos(ofDegToRad(a_venus)) * venusDist;
	float venusZ = sin(ofDegToRad(a_venus)) * venusDist;
	planetPositions[2].set(venusX, 0, venusZ);
	ofTranslate(venusX, 0, venusZ);
	ofRotateDeg(r_venus, 0, 1, 0); 
	tex_venus.bind();
	ofDrawSphere(9);
	tex_venus.unbind();
	ofPopMatrix();

	// 地球
	ofPushMatrix();
	float earthDist = 300; 
	float earthX = cos(ofDegToRad(a_earth)) * earthDist;
	float earthZ = sin(ofDegToRad(a_earth)) * earthDist;
	planetPositions[3].set(earthX, 0, earthZ);
	ofTranslate(earthX, 0, earthZ); 
	ofRotateDeg(r_earth, 0, 1, 0); 
	tex_earth.bind();
	ofDrawSphere(0, 0, 0, 10); 
	tex_earth.unbind();
	ofPopMatrix();

	// 月（地球の周りに配置）
	ofPushMatrix();
	ofTranslate(earthX, 0, earthZ);
	float moonDist = 30;
	float moonX = cos(ofDegToRad(a_moon)) * moonDist;
	float moonZ = sin(ofDegToRad(a_moon)) * moonDist;
	ofTranslate(moonX, 0, moonZ);
	ofRotateDeg(r_moon, 0, 1, 0);
	tex_moon.bind();
	ofDrawSphere(3);
	tex_moon.unbind();
	ofPopMatrix();

	// 火星
	ofPushMatrix();
	float marsDist = 400;
	float marsX = cos(ofDegToRad(a_mars)) * marsDist;
	float marsZ = sin(ofDegToRad(a_mars)) * marsDist;
	planetPositions[4].set(marsX, 0, marsZ);
	ofTranslate(marsX, 0, marsZ);
	ofRotateDeg(r_mars, 0, 1, 0);
	tex_mars.bind();
	ofDrawSphere(5.3);
	tex_mars.unbind();
	ofPopMatrix();

	// 木星
	ofPushMatrix();
	float jupiterDist = 550;
	float jupiterX = cos(ofDegToRad(a_jupiter)) * jupiterDist;
	float jupiterZ = sin(ofDegToRad(a_jupiter)) * jupiterDist;
	planetPositions[5].set(jupiterX, 0, jupiterZ);
	ofTranslate(jupiterX, 0, jupiterZ);
	ofRotateDeg(r_jupiter, 0, 1, 0);
	tex_jupiter.bind();
	ofDrawSphere(30);
	tex_jupiter.unbind();
	ofPopMatrix();

	// 土星
	ofPushMatrix();
	float saturnDist = 700;
	float saturnX = cos(ofDegToRad(a_saturn)) * saturnDist;
	float saturnZ = sin(ofDegToRad(a_saturn)) * saturnDist;
	planetPositions[6].set(saturnX, 0, saturnZ);
	ofTranslate(saturnX, 0, saturnZ);
	ofRotateDeg(r_saturn, 0, 1, 0);
	tex_saturn.bind();
	ofDrawSphere(25);
	tex_saturn.unbind();
	ofPopMatrix();

	// 天王星
	ofPushMatrix();
	float uranusDist = 850;
	float uranusX = cos(ofDegToRad(a_uranus)) * uranusDist;
	float uranusZ = sin(ofDegToRad(a_uranus)) * uranusDist;
	planetPositions[7].set(uranusX, 0, uranusZ);
	ofTranslate(uranusX, 0, uranusZ);
	ofRotateDeg(r_uranus, 0, 1, 0);
	tex_uranus.bind();
	ofDrawSphere(15);
	tex_uranus.unbind();
	ofPopMatrix();

	// 海王星
	ofPushMatrix();
	float neptuneDist = 1000;
	float neptuneX = cos(ofDegToRad(a_neptune)) * neptuneDist;
	float neptuneZ = sin(ofDegToRad(a_neptune)) * neptuneDist;
	planetPositions[8].set(neptuneX, 0, neptuneZ);
	ofTranslate(neptuneX, 0, neptuneZ);
	ofRotateDeg(r_neptune, 0, 1, 0);
	tex_neptune.bind();
	ofDrawSphere(14);
	tex_neptune.unbind();
	ofPopMatrix();

	cam.end();
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key >= '0' && key <= '8') {
		cameraTarget = key - '0';
	}
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
