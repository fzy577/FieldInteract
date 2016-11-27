//
//  FieldDynamics.hpp
//  VecFieldPainting
//
//  Created by Bentley on 16/11/19.
//
//

#ifndef FieldDynamics_hpp
#define FieldDynamics_hpp

#include <stdio.h>
#include "ofMain.h"

class FieldDynamics
	// ������һ�����࣬����ʱ�޶�ʸ�����ֲ�����Ķ�̬������
{
public:
	// ���캯������ʼ����������λ��pos��Ӱ�췶Χ��Сradius
    FieldDynamics(ofVec2f pos, float radius);
	// ���£�����ʸ�������ж�̬����������Ϊ���麯������������ʵ����һ����
    virtual void update(float dt, ofFloatPixels& VF, ofFbo& Field) = 0;
	// ��ʾ����������Ļ����ʾ�Լ�������Ϊ�麯�����趨һ��Ĭ�ϵ���ʾЧ��������ʾ���÷�Χ
	// ��Ҳ���������Լ������������ʾЧ��
    virtual void draw();
    
protected:
	// ����һ��������������ɵ��õĺ��������ڼ���ĳ������λ�õ�ǿ��
    float getAffectStrength(ofVec2f _target);
    
	// �������������֣�λ�úͰ뾶
	// �������������������๲ͬ��Ҫ������
    ofVec2f _pos;
    float _radius;
    
};

#endif /* FieldDynamics_hpp */
