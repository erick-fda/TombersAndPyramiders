/*===================================================================================*//**
	BaseLongbow
	
	Abstract class for a base longbow.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseProjectileWeapon.h"
#include <string>

/*========================================================================================
	BaseLongbow	
========================================================================================*/
class BaseLongbow : public BaseProjectileWeapon
{
    /*----------------------------------------------------------------------------------------
		Static Fields
    ----------------------------------------------------------------------------------------*/
	protected:
		static const float LONGBOW_ATTACK_COOLDOWN_TIME;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseLongbow() = default;

		virtual ~BaseLongbow() {};
		
    /*----------------------------------------------------------------------------------------
		Instance Methods
    ----------------------------------------------------------------------------------------*/
	public:
		void use();

		void onStart();
		void onUpdate(int ticks);
		void onEnd();

	protected:
		void updateAttack(int ticks);
};