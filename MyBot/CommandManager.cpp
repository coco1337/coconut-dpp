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
	commandBlep.set_name(enumToCommand[CommandEnums::BLEP])
		.set_description("Send a random");

	dpp::slashcommand commandTest;
	commandTest.set_name(enumToCommand[CommandEnums::TEST])
		.set_description("just test 2");

	commandMap.emplace(CommandEnums::BLEP, commandBlep);
	commandMap.emplace(CommandEnums::TEST, commandTest);

	// check command count
	return true;
}

bool CommandManager::InitInteractions() {
	interactionMap.emplace(CommandEnums::BLEP, [](const dpp::interaction_create_t& evt) {
		evt.reply(dpp::ir_channel_message_with_source, fmt::format("this is blep"));
		});

	interactionMap.emplace(CommandEnums::TEST, [](const dpp::interaction_create_t& evt) {
		evt.reply(dpp::ir_channel_message_with_source, fmt::format("this is test"));
		});


	// check command count
	return true;
}