/*===================================================================================*//**
	NullWeapon
	
	A null weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseWeapon.h"

/*========================================================================================
	NullWeapon	
========================================================================================*/
class NullWeapon : public BaseWeapon
{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit NullWeapon();

    /*----------------------------------------------------------------------------------------
		Instance Methods
    ----------------------------------------------------------------------------------------*/
	public:
		void onStart();
		void onUpdate(int ticks);
		void onEnd();
};
