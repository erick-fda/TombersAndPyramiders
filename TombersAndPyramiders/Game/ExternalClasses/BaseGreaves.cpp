/*===================================================================================*//**
	BaseGreaves
	
	Abstract class for a base pair of greaves (leg armor).

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseGreaves.h"
#include "Inventory.h"

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void BaseGreaves::addToInventory(Inventory* inventory)
{
	inventory->setGreaves(this);
}
