/*===================================================================================*//**
	BaseShortsword
	
	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseMeleeWeapon.h"

/*========================================================================================
	BaseWeapon	
========================================================================================*/
class BaseShortsword : public BaseMeleeWeapon
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	protected:
		static const float SHORTSWORD_COLLIDER_WIDTH;
		static const float SHORTSWORD_COLLIDER_HEIGHT;
		static const float SHORTSWORD_X_OFFSET_FROM_HOLDER;
		static const float SHORTSWORD_Y_OFFSET_FROM_HOLDER;
		static const float SHORTSWORD_ATTACK_COOLDOWN_TIME;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseShortsword();

		virtual ~BaseShortsword() {};
	
    /*----------------------------------------------------------------------------------------
		Instance Methods
    ----------------------------------------------------------------------------------------*/
	public:
		virtual void use();

		void onStart();
		void onUpdate(int ticks);
		void onEnd();

	private:
		void updateAttack(int ticks);
};
