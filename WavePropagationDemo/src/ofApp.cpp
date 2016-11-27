#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenW = ofGetWidth();
    screenH = ofGetHeight();
    
	// �ϰ���
    _FCoef.allocate(screenW, screenH, OF_IMAGE_GRAYSCALE);
    _FCoef.load("Coef.jpg");
    _FCoef.resize(screenW,screenH);
    _FCoef.update();    
    
	// ���γ�ʼ״̬
    _FWave.allocate(screenW, screenH, OF_IMAGE_GRAYSCALE);
    _FWave.load("Wave.jpg");
    _FWave.resize(screenW,screenH);
    _FWave.update();
    
	// �ٶȳ�ʼ��Ϊ0
    _FSpd.allocate(screenW, screenH, OF_IMAGE_GRAYSCALE);
    _FSpd.setColor(ofFloatColor(0,0,0,0));
    _FSpd.update();
    
	// ��ʾЧ����ʼ��Ϊ0
    _FWaveDisp.allocate(screenW,screenH,OF_IMAGE_GRAYSCALE);
	_FWaveDisp.setColor(ofFloatColor(0.5f,0.5f,0.5f,1.0f));
	_FWaveDisp.update();
    
	// ���Ʋ���
    _coef.set("Coef",0.8f,0.0f,5.0f);// �����񶯵Ĵ�������
    _dispOffset.set("DispOffset",0.3f,-1.0f,1.0f);
    _dispScale.set("DispScale",1.0f,0.1f,5.0f);
    _Control.setName("Control");
    _Control.add(_coef);
    _Control.add(_dispOffset);
    _Control.add(_dispScale);
    _GUI.setup("GUI");
    _GUI.add(_Control);
    _GUI.setPosition(0,0);
    _GUI.setShape(0,0,200,400);
}

//--------------------------------------------------------------
void ofApp::update(){
    float dt = ofGetLastFrameTime();
    
	// ÿ��update()�п����ò��μ�����
	int updateCount = 1;
    for(int mm=0;mm<updateCount;mm++)
    {
		for(int i=0;i<screenW;i++)
		{
			for(int j=0;j<screenH;j++)
			{
				// ��ÿ������i,j������
				ofVec2f Coord(i,j);
				ofFloatColor W = _FWave.getColor(i,j);
				float w = W.getBrightness();
            
				// ������ػ������ĸ��������ص�ƽ��ֵ�ƶ�
				// �ĸ��������ص�����ƫ����
				ofVec2f NB[4] = {ofVec2f(-1,0),ofVec2f(1,0),ofVec2f(0,-1),ofVec2f(0,1)};
				float deltaW = 0.0f; // �ĸ�����������������صĲ�ֵ
				for(int m=0;m<4;m++)
				{
					ofVec2f CoordN = Coord+NB[m];
					CoordN.x = ofWrap(CoordN.x,0,screenW);
					CoordN.y = ofWrap(CoordN.y,0,screenH);
					ofFloatColor WN = _FWave.getColor(CoordN.x,CoordN.y);
					float wn = WN.getBrightness();
					deltaW += wn-w;
				}
            
				ofFloatColor CCoef = _FCoef.getColor(i,j);
				float coef = CCoef.getBrightness();
				
				// �仯�ļ��ٶ������ڲ�ֵcoef
				float acc = _coef*coef*deltaW / 4.0f;
				acc = ofClamp(acc, -10, 10);

				// ����仯�ٶ�
				ofFloatColor CSpd = _FSpd.getColor(i, j);
				float spd = CSpd.getBrightness();
				spd = ofClamp(spd, -5, 5);				

				// �����ٶ�
				spd += acc*dt;
				spd = ofClamp(spd, -10, 10);
				_FSpd.setColor(i, j, ofFloatColor(spd, 1.0f));
            				
				// ���²���
				w += spd*dt;
				w = ofClamp(w, -10, 10);
				_FWave.setColor(i, j, ofFloatColor(w,1.0f));
            
				// ���²�����ʾЧ�����Բ��ν��г߶����ź�ƽ��
				float ds = pow(10.0f,-_dispScale);
				float spdDisp = spd*ds+ _dispOffset;
				_FWaveDisp.setColor(i,j,ofFloatColor(spdDisp,1.0f));
			}
		}
		_FSpd.update();
		_FWave.update();
        _FWaveDisp.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ��ʾ����
    _FWaveDisp.draw(0,0,ofGetWidth(),ofGetHeight());
    
	// ��ʾ����
    _GUI.draw();
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
    //ofSetWindowShape(screenW, screenH);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
