#pragma once
#include "Graphic.h"
#include <list>

using std::list;

namespace CRB_TANK{

enum Dir { UP, DOWN, LEFT, RIGHT };

class Object
{
public:
	// ��ͼ
	virtual void Display() = 0;

	// �ƶ�
	virtual void Move() = 0;

	// ��ը
	virtual void Boom(list<Object*>& lstBombs) = 0;

	// ������ʧ
	virtual void SetDisappear() = 0;

	// �ж��Ƿ���ʧ
	virtual bool IsDisappear() = 0;

	virtual Rect GetSphere() = 0;

protected:
	// ����������Χ
	virtual void CalculateSphere() = 0;

	// λ��
	Point m_pos;
	// ������Χ
	Rect m_rectSphere;
	// ��ɫ
	COLORREF m_color;
	// ����
	Dir m_dir;
	// ����״̬
	bool m_bDisappear;
	// ����ǰ������
	int m_step;
};

}