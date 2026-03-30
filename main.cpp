#include <dpp/dpp.h>
#include <fstream>
#include <string>
#include "commands/description.hpp"
#include "commands/gender.hpp"

std::string loadEnv() {
    std::ifstream file("../.env");
    if (!file) {
        std::cerr << "Failed to open .env file" << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, 9) == "BOT_TOKEN") {
            return line.erase(0, 10);
        }
    }
    return "kokot :3";
}

int main() {
    dpp::cluster bot(loadEnv());
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        const auto& name = event.command.get_command_name();

        if (name == "gender") {
            handle_gender_command(event);
        }
        if (name == "description") {
            handle_description_command(event);
        }
        if (name == "update-gender") {
            handle_update_gender(event);
        }

        /*
         * TODO (nword detector - detects and timeouts "738775610028982332" for one minute)
         */
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            register_description_command(bot);
            register_gender_command(bot);
            register_update_gender(bot);
        }
    });

    bot.start(dpp::st_wait);
}