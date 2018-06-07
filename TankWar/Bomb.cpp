#include "Bomb.h"

CRB_TANK::Bomb::Bomb()
{
	this->m_bDisappear = false;
	this->m_color = YELLOW;
	this->m_dir = UP;
}

CRB_TANK::Bomb::Bomb(Point pos, BombType type) : Bomb()
{
	this->m_pos = pos;
	this->m_type = type;

	switch (m_type)
	{
	case LARGE:
		m_timer = 16;
		break;
	case SMALL:
		m_timer = 8;
		break;
	default:
		break;
	}
}

void CRB_TANK::Bomb::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(RED);

	switch (m_type)
	{
	case LARGE:
		fillcircle(m_pos.GetX(), m_pos.GetY(), 16 - m_timer);
		break;
	case SMALL:
		fillcircle(m_pos.GetX(), m_pos.GetY(), 8 - m_timer);
		break;
	default:
		break;
	}

	

	setcolor(color_save);
	setfillcolor(fill_color_save);

}

void CRB_TANK::Bomb::Move()
{
	m_timer -= 4;

	if (m_timer < 0)
	{
		m_bDisappear = true;
	}
}

void CRB_TANK::Bomb::Boom(list<Object*>& lstBombs)
{
}

bool CRB_TANK::Bomb::IsDisappear()
{
	return m_bDisappear;
}

void CRB_TANK::Bomb::CalculateSphere()
{
}
