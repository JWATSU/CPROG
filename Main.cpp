#include <SDL.h>
#include <iostream>
#include "Session.h"
#include "PlayerComponent.h"
#include "EnemyComponent.h"

using namespace cprog;

int main(int argc, char *args[])
{
	session.setFPS(120);
	sys.enableMusic("c:/images/music.wav");
	session.setBackGroundFilePath("c:/images/backgroundsprite.jpg");
	session.setProjectileTextureFilePath("c:/images/lasersprite.png");
	session.setEnemyTexturePath("c:/images/enemysprite.png");
	session.setEnemyTravelSpeed(2);
	PlayerComponent* player = PlayerComponent::getInstance("c:/images/playersprite.png");
	session.add(player);

	session.run();


	return 0;
}