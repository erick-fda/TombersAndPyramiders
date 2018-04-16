#include "Corridor.h"
#include "SpawnManager.h"
#include "GeneratorManager.h"

Corridor::Corridor(int width, int height, int xPosition, int yPosition) : m_width(width), m_height(height), m_xCoord(xPosition), m_yCoord(yPosition)
{
	m_scale = 5;
}

void Corridor::draw()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (i == 0 && j == 0 && GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 9)
			{
				// top left corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallTopLeft_EdgeShift.png", true);
			}
			else if (i == 0 && j == m_width - 1 && GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 9)
			{
				//top right corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallTopRight_EdgeShift.png", true);
			}
			else if (i == m_height - 1 && j == 0 && GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 9)
			{
				//bottom left corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallBottomLeftShift.png", true);
			}
			else if (i == m_height - 1 && j == m_width - 1 && GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 9)
			{
				//bottom right corner
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallBottomRightShift.png", true);
			}
			else if (i == 0 && (GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 8
				|| GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 5))
			{
				//top wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "WallHorizontalU.png", true, m_scale, m_scale / 4.5);
			}
			else if (j == 0 && (GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 8
				|| GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 5))
			{
				//left wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallVerticalBothEdgeL.png", true, m_scale / 4.5, m_scale);
			}
			else if (i == m_height - 1 && (GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 8
				|| GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 5))
			{
				//bottom wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "WallHorizontalD.png", true, m_scale, m_scale / 4.5);
			}
			else if (j == m_width - 1 && (GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 8
				|| GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 5))
			{
				//right wall
				SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "wallVerticalBothEdgeR.png", true, m_scale / 4.5, m_scale);
			}
			else if (GeneratorManager::getInstance()->worldMatrix[m_xCoord + j + WORLD_WIDTH / 2][-(m_yCoord - WORLD_HEIGHT / 2) + i] == 7)
			{
				//floor
			//	SpawnManager::getInstance()->generateMiscSquare(m_xCoord * 5 + 2 + j * 5, m_yCoord * 5 - 2 - i * 5, -5, m_scale, "stoneTile_Edge.png", false);
			}

		}
	}
}