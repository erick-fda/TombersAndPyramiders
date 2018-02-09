/*===================================================================================*//**
	Inventory
	
	A component representing a collection of items owned by a GameObject.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include "Inventory.h"
#include "BaseItem.h"
#include "BaseWeapon.h"
#include "BaseShield.h"
#include "BaseHelmet.h"
#include "BaseChestplate.h"
#include "BaseGreaves.h"
#include "NullChestplate.h"
#include "NullWeapon.h"
#include "NullShield.h"
#include "NullHelmet.h"
#include "NullGreaves.h"

/*----------------------------------------------------------------------------------------
	Resource Management
----------------------------------------------------------------------------------------*/
Inventory::Inventory(GameObject* gameobject) :
	Inventory(gameObject, nullptr, nullptr, nullptr, nullptr, nullptr)
{}

Inventory::Inventory(GameObject* gameobject, BaseWeapon* weapon, BaseShield* shield, BaseHelmet* helmet,
	BaseChestplate* chestplate, BaseGreaves* greaves) :
	Component(gameObject)
{
	setWeapon(weapon);
	setShield(shield);
	setHelmet(helmet);
	setChestplate(chestplate);
	setGreaves(greaves);
}

/*----------------------------------------------------------------------------------------
	Instance Getter Methods
----------------------------------------------------------------------------------------*/
BaseWeapon& Inventory::getWeapon()
{
	return *m_weapon;
}

BaseShield& Inventory::getShield()
{
	return *m_shield;
}

BaseHelmet& Inventory::getHelmet()
{
	return *m_helmet;
}

BaseChestplate& Inventory::getChestplate()
{
	return *m_chestplate;
}

BaseGreaves& Inventory::getGreaves()
{
	return *m_greaves;
}

/*----------------------------------------------------------------------------------------
	Instance Setter Methods
----------------------------------------------------------------------------------------*/
void Inventory::setWeapon(BaseWeapon* weapon)
{
	////
	//m_weapon.reset(weapon);
	//return;

	//
	m_weapon.reset(
		(weapon == nullptr) ?
		new NullWeapon() :
		weapon
	);
}

void Inventory::setShield(BaseShield* shield)
{
	m_shield = (shield == nullptr) ?
		std::unique_ptr<BaseShield>(new NullShield()) :
		std::unique_ptr<BaseShield>(shield);
}

void Inventory::setHelmet(BaseHelmet* helmet)
{
	m_helmet = (helmet == nullptr) ?
		std::unique_ptr<BaseHelmet>(new NullHelmet()) :
		std::unique_ptr<BaseHelmet>(helmet);
}

void Inventory::setChestplate(BaseChestplate* chestplate)
{
	m_chestplate = (chestplate == nullptr) ?
		std::unique_ptr<BaseChestplate>(new NullChestplate()) :
		std::unique_ptr<BaseChestplate>(chestplate);
}

void Inventory::setGreaves(BaseGreaves* greaves)
{
	m_greaves = (greaves == nullptr) ?
		std::unique_ptr<BaseGreaves>(new NullGreaves()) :
		std::unique_ptr<BaseGreaves>(greaves);
}

/*----------------------------------------------------------------------------------------
	Instance Methods
----------------------------------------------------------------------------------------*/
void Inventory::addItem(BaseItem* item)
{
	item->addToInventory(this);
}


void Inventory::onStart()
{};

void Inventory::onUpdate(int ticks)
{};

void Inventory::onEnd()
{};
