#include "description.hpp"

void register_description_command(dpp::cluster& bot) {
    dpp::slashcommand cmd("description", "Description of the bot", bot.me.id);
    bot.global_command_create(cmd);
}

void handle_description_command(const dpp::slashcommand_t& event) {
    event.reply("Som skrizenec Ada a Hortenzie, teda som Ado Hortenziak. :heart:");
}