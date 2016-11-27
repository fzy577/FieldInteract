#pragma once

#include "ofMain.h"
// Ҫ�õ�ͼ�ν��棬���ò��ofxGui
#include "ofxGui.h"

// ��Ҫ�õ����������ࣺ
class DrawingParticle;
class FieldDynamics;

// ������Ķ���
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
    
	//_VField�� ʸ������
		//��ofFbo������ʸ����
		// �ô������ڶ�����б༭
		// �����������ڷ��ʵ��������ص���ֵ
    ofFbo _VField;
	// _VFPx: ��_VField�������ػ�ȡ��ֵ
    ofFloatPixels _VFPx;
    // _Canvas��ɫ�ʳ��������˶����ӻ��ƵĶ���
	ofFbo _Canvas;
    
	// ��ˢ
	// _BrushImg: ��ˢ����Ϊһ��ͼ��������ʸ����_VField����
    ofFloatImage _BrushImg; 
	// ����һϵ�ж��ǿ��Ʊ�ˢ�Ĳ���������ʾ��ͼ�ν�����
    ofParameter<bool> _BrushOn;
    ofParameter<float> _BrScale;
    ofParameter<float> _BrCentric;
    ofParameter<float> _BrYXRatio;
    ofParameter<float> _BrRotation;
    ofParameter<float> _BrStrength;
    ofParameter<float> _BrBiasDir;
    ofParameter<float> _BrBiasStr;
    ofParameter<float> _BrRandomBias;
    ofParameter<bool> _BrPreview;
    ofParameter<float> _BrPreviewSize;
	// ������ˢ���������ڲ�����_BrushControl��
    ofParameterGroup _BrushControl;
	// BrParamChange(float &v)��������ˢ�����Ļص�������
	// �����ǵ���ֵ�ı�ʱ����������������
    void BrParamChange(float &v);
	// drawBrushPreview()�� ���Ʊ�ˢ��Ԥ��ͼ
    void drawBrushPreview();
	// updateBrushImg()����������ˢ�����ı䣬����±�ˢͼ��
    void updateBrushImg();
	// BrushDrawToVecField(): ��ˢͼ��ʸ����_VField����
    void BrushDrawToVecField();
	// drawBrushShape()������Ļ�ϻ��Ʊ�ˢ��״������ʾһ������ԲȦ
    void drawBrushShape();
    
	// �˶����ӣ�����ʸ����_VField�˶������򻭲�_Canvas����
	// ������vector���������ɱ�����Ӷ���
	// ���Ӷ���������ָ��������
    vector<ofPtr<DrawingParticle> > _Particles;
	// ����һϵ�ж������������˶����ӵĲ���
	// _AddParticle���Ƿ�������ӣ���Ϊ�棬������Ļ�����һ������
    ofParameter<bool> _AddParticle; 
	// ��������ֱ�Ϊ���������ӵ�����
    ofParameter<float> _Radius;
    ofParameter<ofColor> _Color;
    ofParameter<float> _Speed;
	// �������ӱ�Ǻͻص�����
    ofParameter<bool> _ClearParticles;	
	void clearParticles(bool& bClear);
	// �����˶����ӵĲ��������ڲ�����_ParticleControl��
    ofParameterGroup _ParticleControl;
	// ��ʾ�����˶�����
    void drawParticles(bool bVisualAid=false);	
    
	// һϵ��ʸ������̬Դ
    vector<ofPtr<FieldDynamics> > _FDynamics;
	// ���ƴ���������ʸ������̬Դ�Ĳ���
    ofParameter<bool> _AddDynamic;
    ofParameter<int> _DynamicType;
    ofParameter<float> _DynamicRadius;
    ofParameter<float> _DynamicSpeed;
	// �����̬Դ�ı�Ǻͻص�����
    ofParameter<bool> _ClearDynamics;
    void clearDynamics(bool& bClear);
	// ��̬Դ�����в��������ڲ�����_Dynamics��
    ofParameterGroup _Dynamics;
    
	// ʸ��������ʾЧ������
    ofParameter<bool> _bDrawVField;
    ofParameter<int> _VecDispRes;
    ofParameter<ofFloatColor> _VecDispColor;
    ofParameterGroup _DisplayControl;
    void drawVField();
    
    bool bDrawGUI;// �Ƿ���ʾͼ�ν��棬�ð���f1����
    ofxPanel GUI; // ͼ�ν���
    
	// ���ڳߴ�
    int screenw,screenh;

};
