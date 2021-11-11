#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>

enum class CommandEnums {
	BLEP,
	TEST,
};

class CommandManager
{
public:
	CommandManager();
	~CommandManager() {}

	std::map<CommandEnums, dpp::slashcommand> GetCommandMap() { return commandMap; }
	std::map<CommandEnums, std::function<void(dpp::interaction_create_t&)>> GetInteractionMap() { return interactionMap; }
	std::unordered_map<std::string, CommandEnums> CommandToEnum() { return commandToEnum; }
	bool Init();

private:
	bool InitCommands();
	bool InitInteractions();

private:
	std::unordered_map<CommandEnums, std::string> enumToCommand{
		{CommandEnums::BLEP, "blepp"},
		{CommandEnums::TEST, "testt"}
	};

	std::unordered_map<std::string, CommandEnums> commandToEnum{
		{"blepp", CommandEnums::BLEP},
		{"testt", CommandEnums::TEST}
	};

	std::map<CommandEnums, dpp::slashcommand> commandMap;
	std::map<CommandEnums, std::function<void(dpp::interaction_create_t&)>> interactionMap;
};

