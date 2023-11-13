#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
/**
 * .the clear command acts as a bridge between user and renderer to clear
 */
class clearcommand:public Commands
{
public:
	/**
	 * .sets parameters no 
	 * 
	 */
	clearcommand();
	/**
	 * .runs clear command
	 * 
	 * \param renderer to use to clear
	 * \param Pen kept for possible inheritance from command
	 * \return sdl error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

