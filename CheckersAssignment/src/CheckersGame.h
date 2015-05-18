#ifndef _CHECKERS_GAME_H_
#define _CHECKERS_GAME_H_

#include "Application.h"
#include "Camera.h"

#include "Pieces.h"

class CheckersGame : public Application
{
public:
	bool startup();
	void shutdown();
	bool update();
	void draw();


	bool TurnRed;

	FlyCamera* m_camera;
	float m_timer;
	unsigned int m_programID;

	PlayerManager* Players;

};

#endif // !_CHECKERS_GAME_H_
