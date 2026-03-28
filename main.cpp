#include <dpp/dpp.h>
#include "commands/description.hpp"

int main() {
    dpp::cluster bot(std::getenv("BOT_TOKEN"));
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        const auto& name = event.command.get_command_name();

        if (name == "description") {
            handle_description_command(event);
        }

        /*
         * TODO (nword detector - detects and timeouts the user for one minute)
         * TODO (ado gender - responds with the current gender of ado)
         */
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            register_description_command(bot);
        }
    });

    bot.start(dpp::st_wait);
}