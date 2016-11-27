//
//  DrawingParticle.hpp
//  VecFieldPainting
//
//  Created by Bentley on 16/11/19.
//
//

// #ifndef ... #def ...   #endif
// ���ڷ��ñ�ͷ�ļ����ظ�����
#ifndef DrawingParticle_hpp
#define DrawingParticle_hpp

#include <stdio.h>
#include "ofMain.h" // �õ�OF�Ĺ��ܣ����������ͷ�ļ�

class DrawingParticle
// ���������������������ɫ���������ڵ�ʸ�����ƶ����������ƶ������У��򻭲�����
{
public:
	// ���캯��
    DrawingParticle(
        float radius=10.0f,
        ofColor cr= ofColor::green,
        ofVec2f pos = ofVec2f(0,0),
                    float spd=100.0f,
        float wrapProb = 0.03f);
    
	// ���ݾ�����ʱ��dt����ʸ����VecField�������λ�õ�ʸ��������
	// ��Ϊ��ǰ���ٶȣ��ƶ�����λ��
    void updatePosition(float dt, ofFloatPixels& VecField);

	// ���Լ���λ��/��ɫ/�ߴ续һ��Բ��
    void draw();

	// ��������Ϣ
    void drawVisualAids();
    
private:
    float _radius; // �뾶
    ofColor _color;// ��ɫ
    ofVec2f _pos;// λ��
    float _speed; // �ٶ�
    float _wrapProb; // ԾǨ��˲���ƶ�����������
    
};

#endif /* DrawingParticle_hpp */
