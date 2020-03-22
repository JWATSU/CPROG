#pragma once
#include <vector>
#include "Component.h"
#include <string>
namespace cprog
{
	class Session
	{
	public:
		void add(Component *c);
		void run();
		Session();
		~Session();
		void remove(Component* component);
		void setBackGroundFilePath(std::string backGroundFilePath) { backgroundFilePath = backGroundFilePath; }
		void setFPS(int fps) { FPS = fps; }
		void setProjectileTextureFilePath(std::string texturePath) { projectileTextureFilePath = texturePath; }
		std::string getProjectileTextureFilePath() const { return projectileTextureFilePath; }

		void setEnemyTexturePath(std::string texturePath) { enemyTextureFilePath = texturePath; }
		std::string getEnemyTexturePath() const { return enemyTextureFilePath; }

		void setEnemyTravelSpeed(int speed) { enemyTravelSpeed = speed; }
		int getEnemyTravelSpeed() const { return enemyTravelSpeed; }


	private:
		std::vector<Component*> components, toBeAdded, toBeRemoved;
		std::string backgroundFilePath, projectileTextureFilePath, enemyTextureFilePath;
		int FPS, enemyTravelSpeed = 2, enemyLimiter = 0;
	};
	extern Session session;

}

