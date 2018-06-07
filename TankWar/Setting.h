#pragma once
#include <list>

using std::list;

namespace CRB_TANK
{
	class Setting
	{
	public:
		static void NewGameLevel();
		static void TankDamaged();

		static int GetLife()
		{
			return m_nLife;
		}

		static void Die()
		{
			m_nLife -= 1;
		}

		static int GetGameLevel()
		{
			return m_nGameLevel;
		}

		static int GetTankLevel()
		{
			return m_nTankLevel;
		}

		static int GetTankNum()
		{
			return m_nTankNum;
		}

		static int GetSumScore()
		{
			return m_nSumScore;
		}

		static int GetTankSum()
		{
			return m_nTankSum;
		}

		static bool m_bNewLevel;

	private:
		static int m_nLife; // ����ֵ

		static int m_nGameLevel;	// ��ǰ��Ϸ�ؿ�
		static int m_nTankLevel;	// ��ǰ̹�˼���

		static int m_nTankNum;		// ��ǰ̹����

		static int m_nSumScore;		// �ܷ�

		static int m_nTankScore;	// ����̹�˵÷�

		static int m_nTankSum;		// ������̹����
	};
}
