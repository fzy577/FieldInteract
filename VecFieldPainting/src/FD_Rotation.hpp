//
//  FD_Rotation.hpp
//  VecFieldPainting
//
//  Created by Bentley on 16/11/19.
//
//

#ifndef FD_Rotation_hpp
#define FD_Rotation_hpp

#include <stdio.h>
#include "FieldDynamics.hpp"

class FD_Rotation: public FieldDynamics
	// �̳���FieldDynamics
{
public:
	// ���캯��
    FD_Rotation(float radius, ofVec2f pos, float speed);
    // ���£���ʱ��仯����ת������ʸ����������
	void update(
        float dt,
        ofFloatPixels& VF,
        ofFbo& Field) override; // ���麯������д
    
private:
    float _speed; // �ٶ�
    
    ofFloatImage _img; 
    
};

#endif /* FD_Rotation_hpp */
