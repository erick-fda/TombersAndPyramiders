/*===================================================================================*//**
	BaseShortsword

	Abstract class for a base shortsword.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseShortsword.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
BaseShortsword::BaseShortsword(float colliderWidth, float colliderHeight) :
	BaseMeleeWeapon{colliderWidth, colliderHeight}
{}