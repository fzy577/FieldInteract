//
//  DrawingParticle.cpp
//  VecFieldPainting
//
//  Created by Bentley on 16/11/19.
//
//

#include "DrawingParticle.hpp" // �����ͷ�ļ�
#include "Utilities.h" // ���ߺ������������ͷ�ļ���

void DrawingParticle::updatePosition(
    float dt,
    ofFloatPixels& VecField)
{
	// ��ʸ����VecField��õ�ǰλ��pos����ɫ
    ofFloatColor vecCr =
        VecField.getColor(_pos.x, _pos.y);
	// ����ɫת��Ϊһ��ʸ������Ϊ�ٶ�vecʹ��
    ofVec2f vec =
        utils::floatColor2Vec2f(vecCr, 0.5f, _speed);
    
	// ���ٶ�vec�ƶ���move
    ofVec2f move =dt * vec / (0.01f*_radius*_radius);

	// ����Լ���ɫ��ɫ��Hue
    float hue = 360.0f*(float)_color.getHue()/255.0f;

	// �ƶ�����תһ���Ƕȣ���ɫ��hue
    move.rotate(hue);
    
	// �ƶ�����λ��
    _pos += move;
    
	// ��������Ļ��Χ������ת����Ļ��һ��
    ofRectangle R(0,0,ofGetWidth(),ofGetHeight());
    if(!R.inside(_pos))
    {
        _pos.x = ofWrap(_pos.x,0,ofGetWidth());
        _pos.y = ofWrap(_pos.y,0,ofGetHeight());
    }
    
	// ��ԾǨ�����漴ԾǨ
    float rvalue = ofRandom(1.0f);
    if(rvalue<_wrapProb*dt)
    {
        _pos.x = ofRandom(0,VecField.getWidth());
        _pos.y = ofRandom(0,VecField.getHeight());
    }
}

void DrawingParticle::draw()
{
	// ����Բ��
    ofPushStyle();
    ofSetColor(_color);
    ofDrawCircle(_pos, _radius);
    ofPopStyle();
}

void DrawingParticle::drawVisualAids()
{
    // ������Ķ�������ɫ����
    ofPushStyle();
    ofNoFill();
    ofSetColor(0,0,0,255);
    ofDrawCircle(_pos, _radius);
    ofPopStyle();
}
// ���캯������ʼ������
DrawingParticle::DrawingParticle(
                float radius,
                ofColor cr,
                ofVec2f pos,
                float spd,
                float wrapProb):
_radius(radius),
_color(cr),
_pos(pos),
_speed(spd),
_wrapProb(wrapProb)
{}
