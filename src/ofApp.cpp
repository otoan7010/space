#include "ofApp.h"
ofVec3f addr, addt, t, lightPos;
ofVec2f preMousePos;




//--------------------------------------------------------------
void ofApp::setup(){
	//カメラの設定

		// cam の初期設定（任意）
		cam.setDistance(300); // 視点と対象の距離
		cam.setNearClip(0.5);
		cam.setFarClip(10000);
		cam.setFov(110); // 視野角（好みで調整）

	ofDisableArbTex(); //GL_TEXTURE_2D モードでテクスチュアを生成
	ofEnableDepthTest(); //深さ判定を有効に
	
	//tex1
	img1.load("space.jpg"); //画像ファイルは bin の下の data フォルダに入れる
	tex1.loadData(img1);
	tex1.setTextureWrap(GL_REPEAT, GL_REPEAT); //縦横とも繰り返し
	tex1.setTextureMinMagFilter(GL_LINEAR, GL_LINEAR); //補間方法を線形補間に
	tex1.texData.tex_t = 10; //横の繰り返し数
	tex1.texData.tex_u = 10; //縦の繰り返し数
	//tex2
	img2.load("earth.jpg"); //画像ファイルは bin の下の data フォルダに入れる
	tex2.loadData(img2);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofEnableDepthTest(); //深さ判定を有効に
	ofEnableSmoothing(); //スムージング処理を有効に
	
	//テクスチャにも色の設定できる
	
	ofPushMatrix();
	tex1.bind();
	ofDrawBox(9000);
	ofRotateDeg(90, 0, 1, 0);
	tex1.unbind();
	ofPopMatrix();
	

	//tex2 をバインドする
	tex2.bind();
	ofDrawSphere(10);
	tex2.unbind();
	
	cam.end();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
