#include "Point.h"

void CRB_TANK::Point::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CRB_TANK::Point::SetX(int x)
{
	m_x = x;
}

void CRB_TANK::Point::SetY(int y)
{
	m_y = y;
}

int CRB_TANK::Point::GetX() const
{
	return m_x;
}

int CRB_TANK::Point::GetY() const
{
	return m_y;
}
