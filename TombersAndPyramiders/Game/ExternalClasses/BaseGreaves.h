/*===================================================================================*//**
	BaseGreaves
	
	Abstract class for a base pair of greaves (leg armor).

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Updateable.h"
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseGreaves	
========================================================================================*/
class BaseGreaves : public BaseEquippableItem, public Updateable, public std::enable_shared_from_this<BaseGreaves>

{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseGreaves() = default;

		virtual ~BaseGreaves() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		virtual void onStart() = 0;
		virtual void onUpdate(int ticks) = 0;
		virtual void onEnd() = 0;

	protected:
		std::shared_ptr<BaseItem> addSubclassToInventory();
};
