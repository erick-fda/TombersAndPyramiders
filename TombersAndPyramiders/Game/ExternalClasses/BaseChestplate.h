/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseChestplate	
========================================================================================*/
class BaseChestplate : public BaseEquippableItem, public std::enable_shared_from_this<BaseChestplate>
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	private:
		int m_durability;
		float m_absorptionPercent;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit BaseChestplate() = delete;

		explicit BaseChestplate(int durability, float absorptionPercent);

		virtual ~BaseChestplate() {};

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Returns the actual amount of damage the character should take after absorption 
			by the chestplate.
			
			Destroys the chestplate if it has taken too much damage.
		*/
		virtual int absorbDamage(int damage);

	protected:
		std::shared_ptr<BaseItem> addSubclassToInventory();

	private:
		/**
			Destroys the chestplate.
		*/
		virtual void destroy();
};
