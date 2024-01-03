int CircComTestAttr()
{
	circleCommand* myCircCommand = new circleCommand();
	std::vector<std::string> commandArgs;
	commandArgs.push_back("50");
	myCircCommand->setAttributes(commandArgs);
	return 0;
}