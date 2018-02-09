/*===================================================================================*//**
	BaseMeleeWeapon
	
	Abstract class for a base melee weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseWeapon.h"

/*========================================================================================
	BaseWeapon	
========================================================================================*/
class BaseMeleeWeapon : public BaseWeapon
{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseMeleeWeapon(float colliderWidth, float colliderHeight);

		virtual ~BaseMeleeWeapon() {};
};
