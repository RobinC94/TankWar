#include "EnemyTank.h"
#include "Bullet.h"

void CRB_TANK::EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetStartPoint().GetY() + 4);
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());

	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void CRB_TANK::EnemyTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() + m_step);
			this->RandomDir(1);
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() - m_step);
			this->RandomDir(1);
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() + m_step);
			this->RandomDir(1);
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() - m_step);
			this->RandomDir(1);
		}
		break;
	default:
		break;
	}

	CalculateSphere();

	m_stepCnt++;
	if (m_stepCnt % MAX_STEP_TURN == 0)
	{
		this->RandomDir(0);
	}
	else
	{
		if (rand() % (MAX_STEP_TURN * 2) == 0)
			this->RandomDir(0);
	}

	if (m_stepCnt % MAX_STEP_SHOOT == 0)
	{
		m_bNeedShoot = true;
	}
	else
	{
		if (rand() % (MAX_STEP_SHOOT * 2) == 0)
			m_bNeedShoot = true;
	}
}

void CRB_TANK::EnemyTank::Shoot(list<Object*>& lstBullets)
{
	Bullet* pBullet = new Bullet(m_pos, m_dir, m_color);

	lstBullets.push_back(pBullet);

	m_bNeedShoot = false;
}

void CRB_TANK::EnemyTank::CalculateSphere()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}

void CRB_TANK::EnemyTank::RandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleGround().GetWidth());
	m_pos.SetY(rand() % Graphic::GetBattleGround().GetHeight());
	m_color = WHITE;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step = 2;
	m_stepCnt = rand();
}

void CRB_TANK::EnemyTank::RandomDir(int type)
{
	if (type == 1)
	{
		switch (m_dir)
		{
		case UP:
		case DOWN:
			switch (rand() % 5) 
			{
			case 0:
			case 1:
				m_dir = LEFT;
				break;
			case 2:
			case 3:
				m_dir = RIGHT;
				break;
			case 4:
				m_dir = (m_dir == UP ? DOWN : UP);
				break;
			default:
				break;
			}
			break;
		case LEFT:
		case RIGHT:
			switch (rand() % 5)
			{
			case 0:
			case 1:
				m_dir = UP;
				break;
			case 2:
			case 3:
				m_dir = DOWN;
				break;
			case 4:
				m_dir = (m_dir == LEFT ? RIGHT : LEFT);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (m_dir)
		{
		case UP:
		case DOWN:
			switch (rand() % 6)
			{
			case 0:
			case 1:
				m_dir = LEFT;
				break;
			case 2:
			case 3:
				m_dir = RIGHT;
				break;
			case 4:
				m_dir = UP;
				break;
			case 5:
				m_dir = DOWN;
			default:
				break;
			}
			break;
		case LEFT:
		case RIGHT:
			switch (rand() % 6)
			{
			case 0:
			case 1:
				m_dir = UP;
				break;
			case 2:
			case 3:
				m_dir = DOWN;
				break;
			case 4:
				m_dir = LEFT;
				break;
			case 5:
				m_dir = RIGHT;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
