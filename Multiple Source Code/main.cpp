#include "game.hpp"
#include "config.hpp"

int main()
{
	Game *g = Game__create(GRID_SIZE, LEVEL_WIDTH, LEVEL_HEIGHT);
	Game__run(g);
}
