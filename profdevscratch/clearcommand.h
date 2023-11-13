#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
class clearcommand:public Commands
{
public:
	clearcommand();

	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

