#pragma once
#include "Component.h"
#include <SDL.h>
#include "System.h"
#include <string>
namespace cprog
{
	class EnemyComponent :public Component
	{
	public:
		static EnemyComponent* getInstance(std::string enemyTexturePath);
		void draw() const;
		void tick();
	protected:
		EnemyComponent(std::string enemyTexturePath);
	};
}

