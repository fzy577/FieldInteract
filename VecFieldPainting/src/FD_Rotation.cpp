//
//  FD_Rotation.cpp
//  VecFieldPainting
//
//  Created by Bentley on 16/11/19.
//
//

#include "FD_Rotation.hpp"
#include "utilities.h"


FD_Rotation::FD_Rotation(
                         float radius, ofVec2f pos, float speed):
FieldDynamics(pos,radius),
_speed(speed)
{
}

void FD_Rotation::update(
    float dt,
    ofFloatPixels& VF,
    ofFbo& Field)
{
	// ʸ�����ߴ�
    int w = VF.getWidth();
    int h = VF.getHeight();
    
	// _img���ڱ��洦�������м���
	// ��_imgû�г�ʼ�������ʼ��
    int radius = (int)_radius;
    if(_img.getWidth()!=radius*2 || _img.getHeight()!=radius*2)
    {
        _img.allocate(2*radius,2*radius,OF_IMAGE_COLOR_ALPHA);
    }
    
	// �����ʸ�����ĸı䣬���������浽�м�洢����_img��
    int col(0),row(0);
    for(int i=_pos.x-_radius;i<_pos.x+_radius;i++)
    {
        row=0;
        for(int j=_pos.y-_radius;j<_pos.y+_radius;j++)
        {
            ofVec2f p(i,j);
			// ��õ�ǰ��������λ��p������ǿ��af
            float af = getAffectStrength(p);
            
			// ֻ������ǿ��af����0ʱ���Ž��д���
            if(af>0)
            {
				// ������λ�ó�����Ļ��Χ����
				// ����ת��Ϊ��Ļ��һͷ�Ķ�Ӧλ��
                int i2,j2;
                i2 = ofWrap(i,0,w);
                j2 = ofWrap(j,0,h);
                
				// ��VF�е�ǰλ�õ���ɫת��Ϊһ��ʸ��v
                ofFloatColor cr = VF.getColor(i2,j2);
                ofVec2f v = utils::floatColor2Vec2f(cr,0.5,1.0f);
                
				// ��תһ���Ƕ�
                v.rotate(dt*_speed);
                v.limit(300); // ���Ƴ���
				// ��ý����Ȼ�󱣴浽�ݴ�ռ�_img��
                ofFloatColor cr2(v.x+0.5f,v.y+0.5f,0.0f,1.0f);
                _img.setColor(col,row,cr2);
            }
			else
				// ��af������0�������ݴ�ռ��б���0ʸ������Ӧɫ��Ϊ��ɫ��
			{
				_img.setColor(col, row, ofFloatColor(0.5f, 0.5f, 0.5f, 1.0f));
			}            
            row++;
        }
        col++;
    }  
	// �ݴ�ͼ����
    _img.update();
    
	// ���ݴ�ͼ��Ŀ�����
    Field.begin();
    ofPushMatrix();
    ofPushStyle();
    int startX,startY;
    startX = _pos.x - _radius;
    startY = _pos.y - _radius;
    int diameter = 2*_radius;
    _img.draw(startX,startY,diameter,diameter);    
    ofPopStyle();
    ofPopMatrix();
    Field.end();
}
