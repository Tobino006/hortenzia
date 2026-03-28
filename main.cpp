#include <dpp/dpp.h>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    dpp::cluster bot(std::getenv("BOT_TOKEN"));

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "description") {
            event.reply("Som skrizenec Ada a Hortenzie, teda som Ado Hortenziak. :heart:");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("description", "Description of the bot", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
}