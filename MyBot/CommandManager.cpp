#include "CommandManager.h"

CommandManager::CommandManager()
{
}

bool CommandManager::Init() {
	if (!InitCommands()) {
		std::cout << "Init command error" << std::endl;
		return false;
	}

	if (!InitInteractions()) {
		std::cout << "Init interactions error" << std::endl;
		return false;
	}
}

bool CommandManager::InitCommands() {
	dpp::slashcommand commandBlep;
	commandBlep.set_name(commands[CommandEnums::BLEP])
		.set_description("Send a random");

	dpp::slashcommand commandTest;
	commandTest.set_name(commands[CommandEnums::TEST])
		.set_description("just test 2");

	commandMap.insert({ CommandEnums::BLEP, commandBlep });
	commandMap.insert({ CommandEnums::TEST, commandTest });

	// check command count
	return true;
}

bool CommandManager::InitInteractions() {
	// check command count
	return true;
}