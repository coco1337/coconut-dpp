#include <dpp/dpp.h>
#include <dpp/fmt/format.h>
#include <iostream>

int main(int argc, char**argv)
{
	dpp::cluster bot(argv[1]);

	bot.on_ready([&bot](const dpp::ready_t& event) {
		bot.log(dpp::ll_info, "Logged in as " + bot.me.username);

		dpp::slashcommand newCommand;

		newCommand.set_name("blep")
			.set_description("Send a random adorable animal photo")
			.set_application_id(bot.me.id)
			.add_option(
				dpp::command_option(dpp::co_string, "animal", "the type of animal", true)
				.add_choice(dpp::command_option_choice("Dog", std::string("animal_dog")))
				.add_choice(dpp::command_option_choice("Cat", std::string("animal_cat")))
				.add_choice(dpp::command_option_choice("Penguin", std::string("animal_penguin")))
			);

		dpp::slashcommand newCommand2;
		newCommand2.set_name("test")
			.set_description("Test dpp")
			.set_application_id(bot.me.id);

		bot.global_command_create(newCommand);
		bot.global_command_create(newCommand2);
		});

	bot.on_button_click([&bot](const dpp::button_click_t& event) {
		if (event.custom_id == "10") {
			event.reply(dpp::ir_channel_message_with_source, dpp::message("Correct").set_flags(dpp::m_ephemeral));
		}
		else {
			event.reply(dpp::ir_channel_message_with_source, dpp::message("Incorrect").set_flags(dpp::m_ephemeral));
		}
		});

	bot.on_message_create([&bot](const dpp::message_create_t& event) {
		if (event.msg->content == "!ping") {
			bot.message_create(dpp::message(event.msg->channel_id, "Pong!"));
		} else if (event.msg->content == "!ping2") {
			bot.message_create(
				dpp::message(event.msg->channel_id, "What is 5+5?").add_component(
					dpp::component().add_component(
						dpp::component().set_label("9").
						set_style(dpp::cos_primary).
						set_id("9")
					).add_component(
						dpp::component().set_label("10").
						set_style(dpp::cos_primary).
						set_id("10")
					).add_component(
						dpp::component().set_label("11").
						set_style(dpp::cos_primary).
						set_id("11")
					)
				)
			);
		}
		});

	bot.on_log([](const dpp::log_t& event) {
		if (event.severity > dpp::ll_trace) {
			std::cout << dpp::utility::loglevel(event.severity) << ": " << event.message << "\n";
		}
		});

	bot.on_interaction_create([&bot](const dpp::interaction_create_t& event) {
		if (event.command.type == dpp::it_application_command) {
			dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
			if (cmd_data.name == "blep") {
				std::string animal = std::get<std::string>(event.get_parameter("animal"));
				event.reply(dpp::ir_channel_message_with_source, fmt::format("Blep! you chose {}", animal));
			}
			else if (cmd_data.name == "test") {
				event.reply(dpp::ir_channel_message_with_source, fmt::format("test"));
			}
		}
		});

	bot.start(false);

	return 0;
}
