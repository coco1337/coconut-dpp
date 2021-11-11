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

	bool Init();

private:
	bool InitCommands();
	bool InitInteractions();

private:
	std::unordered_map<CommandEnums, std::string> commands{
		{CommandEnums::BLEP, "blepp"},
		{CommandEnums::TEST, "testt"}
	};

	std::map<CommandEnums, dpp::slashcommand> commandMap;
	std::map<CommandEnums, void*> interactionMap;
};

