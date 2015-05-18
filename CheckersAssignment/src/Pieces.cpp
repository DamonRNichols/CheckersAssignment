#include "Pieces.h"
#include <vector>


#include "Gizmos.h" //for visualisation


PlayerManager::PlayerManager()
{
	IsMouseDown = false;
	lineToDrawEnd = vec3(0, 0, 0);
	lineToDrawStart = vec3(0, 0, 0);
}
PlayerManager::~PlayerManager(){}

void PlayerManager::Update(GLFWwindow* window, Camera* camera)
{
	//if mouse clicked
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
	{
		if (!IsMouseDown)
		{
			IsMouseDown = true;
			SelectPiece(window, camera);
		}
	}
	else
	{
		if (IsMouseDown)
		{
			IsMouseDown = false;
		}
	}

	Gizmos::addLine(lineToDrawStart, lineToDrawEnd, vec4(1, 1, 1, 1));
	
}


///////PLAYER FUNCTIONS/////////

void PlayerManager::SelectPiece(GLFWwindow* window, Camera* camera)
{
	//cast a ray from the camera through mouse pos
	vec4 camPos = camera->m_world[3];

	double mouseXpos;
	double mouseYpos;
	glfwGetCursorPos(window, &mouseXpos, &mouseYpos);

	vec3 rayDirection = glm::normalize(camPos.xyz - vec3(mouseXpos, mouseYpos, 0));

	float adjacent = glm::length(0 - camPos.y);

	//find the cos
	float cos = glm::dot(rayDirection, vec3(0, -1, 0)); 
	
	float hypotenuse = adjacent / cos;

	vec3 pointOnBoard = rayDirection * hypotenuse;

	//VISUALISATION
	lineToDrawStart = camPos.xyz;
	lineToDrawEnd = pointOnBoard;
	//if it has gone through a piece pos



	//piece is selected
}

bool PlayerManager::CanMovePiece(int wanted_pos)
{
	bool result = false;

	int pos_row = SelectedPiecePos / 8;
	int pos_col = SelectedPiecePos % 8;


	if (SelectedPieceValue == 1 || SelectedPieceValue == 2 || SelectedPieceValue == 4) //the piece can move up
	{
		if (pos_row != 7) //not at the top
		{
			if (pos_col == 0 && pos_row != 7) //if on the left side
			{
				if (SelectedPiecePos + 9 == wanted_pos)
				{

				}
			}
			else if (pos_col == 7) //if on the right side
			{

			}
			else
			{

			}
		}
		
	}
	if (SelectedPieceValue == 2 || SelectedPieceValue == 3 || SelectedPieceValue == 4) //the piece can move down
	{
		if (pos_col == 0) //if on the left side
		{

		}
		else if (pos_col == 7) //if on the right side
		{

		}
		else
		{

		}
	}

	

	return result;
}





///////AI FUNCTIONS/////////

int PlayerManager::AvailablePiecesToMove()
{
	char piece_id;
	switch (gameState)
	{
	case TURN_RED :
		piece_id = 1;
		break;
	case TURN_BLACK:
		piece_id = 3;
		break;
	default:
		printf("Looking to move piece on invalid turn. Has a player won?");
		return 0;
		break;
	}
	

	// loop through the pieces until you find one that is theirs
	std::vector<unsigned char> available_pieces;
	for (int i = 0; i < 64; ++i)
	{
		//if (Pieces[i] == piece_id || Pieces[i] == piece_id + 1) //if it's a normal or king
		//{
		//	available_pieces.push_back(i);
		//}
	}
	
	//if no more pieces then the game is over
	if (available_pieces.size() == 0)
	{
		switch (gameState)
		{
		case TURN_RED:
			gameState = BLACK_WON;
			break;
		case TURN_BLACK:
			gameState = RED_WON;
			break;
		default:
			break;
		}
	}
	else //need to find the ones that can move
	{
		for (int i = 0; i < available_pieces.size(); ++i)
		{
			int pos_row = available_pieces[i] / 8;
			int pos_col = available_pieces[i] % 8;

			//check if the piece is on the left of the board
			if (pos_col == 0)
			{
				
			}
			else if (pos_col == 7) //check if on the right
			{
				
			}
			else //else if it is in the middle enough
			{

			}

		}


	}




}

int PlayerManager::AvailablePiecesToJump()
{
	return 0;
}

bool PlayerManager::CheckAvailablePositions(int col, int row, char value)
{
	return 0;
}