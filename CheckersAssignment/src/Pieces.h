#ifndef _PIECES_H_
#define _PIECES_H_

#include "Camera.h"

#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"


enum GameState
{
	TURN_RED,
	TURN_BLACK,
	RED_WON,
	BLACK_WON
};

enum Movement
{
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void Update(GLFWwindow* window, Camera* camera); //need camera for ray casting

	//AI Functions
	int AvailablePiecesToMove(); //will return an array of all pieces able to move
	int AvailablePiecesToJump(); //will return an array of all pieces able to jump an opposing piece
	bool CheckAvailablePositions(int col, int row, char value);

	//Player Functions
	void SelectPiece(GLFWwindow* window, Camera* camera);
	bool CanMovePiece(int wanted_pos);


	//64 bits = 8 by 8 board
	//unsigned long long m_red_board = 0x55AA550000AA55AA;
	//unsigned long long m_black_board = 0xAA55AA;


	//0 = empty
	//1 = red
	//2 = red king
	//3 = black
	//4 = black king
	/*unsigned char Pieces[64] =
	{
		0, 3, 0, 3, 0, 3, 0, 3,
		3, 0, 3, 0, 3, 0, 3, 0,
		0, 3, 0, 3, 0, 3, 0, 3,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0
	};*/

	int SelectedPiecePos;
	unsigned char SelectedPieceValue;

	GameState gameState;
	


private:
	bool IsMouseDown;
	vec3 lineToDrawStart;
	vec3 lineToDrawEnd;
};




#endif // !_Pieces_h_