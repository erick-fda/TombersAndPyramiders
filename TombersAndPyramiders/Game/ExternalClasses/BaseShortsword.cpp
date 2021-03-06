/*===================================================================================*//**
	BaseShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShortsword.h"
#include "BoxCollider.h"

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
const float BaseShortsword::SHORTSWORD_COLLIDER_WIDTH = 1;
const float BaseShortsword::SHORTSWORD_COLLIDER_HEIGHT = 1;
const float BaseShortsword::SHORTSWORD_COLLIDER_SCALE = 10;
const float BaseShortsword::SHORTSWORD_X_OFFSET_FROM_HOLDER = 1;
const float BaseShortsword::SHORTSWORD_Y_OFFSET_FROM_HOLDER = 0;
const float BaseShortsword::SHORTSWORD_ATTACK_COOLDOWN_TIME = 5;

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseShortsword::BaseShortsword(string imageName) :
	BaseMeleeWeapon{ imageName, SHORTSWORD_COLLIDER_WIDTH, SHORTSWORD_COLLIDER_HEIGHT, 
	SHORTSWORD_X_OFFSET_FROM_HOLDER, SHORTSWORD_Y_OFFSET_FROM_HOLDER, SHORTSWORD_COLLIDER_SCALE }
{
	m_damagingRegion->getComponent<BoxCollider>()->setDisabled(true);
	m_damagingRegion->getTransform()->setScale(0);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseShortsword::use()
{
	if (!m_isAttacking)
	{
		onStart();
	}
}

void BaseShortsword::onStart()
{
	m_isAttacking = true;
	m_timeUntilNextAttack = SHORTSWORD_ATTACK_COOLDOWN_TIME;
	m_damagingRegion->getTransform()->setScale(1);
	m_damagingRegion->getComponent<BoxCollider>()->setDisabled(false);
}

void BaseShortsword::onUpdate(int ticks)
{
	BaseMeleeWeapon::updatePosition();
	updateAttack(ticks);
}

void BaseShortsword::onEnd()
{
	m_isAttacking = false;
	m_damagingRegion->getTransform()->setScale(0);
	m_damagingRegion->getComponent<BoxCollider>()->setDisabled(true);
}

void BaseShortsword::updateAttack(int ticks)
{
	if (m_isAttacking)
	{
		m_timeUntilNextAttack -= ticks / BaseItem::TICKS_PER_SECOND;

		if (m_timeUntilNextAttack <= 0)
		{
			onEnd();
		}
	}
}
