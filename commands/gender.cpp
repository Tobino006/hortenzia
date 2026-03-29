#include "gender.hpp"
#include <fstream>

const std::string path = "../resources/gender.txt";

std::string loadGender(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        return "unknown";
    }

    std::string gender;
    std::getline(file, gender);
    return gender;
}

std::string currentGender = loadGender(path);

bool saveGender(const std::string& path, const std::string& gender) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Failed to open gender file" << std::endl;
        return false;
    }

    file << gender;
    std::cout << "Saved gender to " << path << std::endl;
    return true;
}

void register_gender_command(dpp::cluster& bot) {
    dpp::slashcommand cmd("gender", "Ado's current gender", bot.me.id);
    bot.global_command_create(cmd);
}

void register_update_gender(dpp::cluster& bot) {
    dpp::slashcommand cmd("update-gender", "Update Ado's gender", bot.me.id);

    cmd.add_option(
        dpp::command_option(dpp::co_string, "text", "The new gender of Ado", true)
    );

    bot.global_command_create(cmd);
}

void handle_gender_command(const dpp::slashcommand_t& event) {
    event.reply("Ado sa momentalne citi ako " + currentGender + "!");
}

void handle_update_gender(const dpp::slashcommand_t &event) {
    if (event.command.usr.id != 886685359449210972 && event.command.usr.id != 668429481030975499) {
        event.reply (
            dpp::message("Na tento prikaz nemas opravnenie!")
            .set_flags(dpp::m_ephemeral)
        );
        return;
    }

    std::string newGender = std::get<std::string> (
        event.get_parameter("text")
    );

    currentGender = newGender;

    saveGender(path, newGender);

    event.reply(
        dpp::message("Ado sa od tohto momentu citi ako " + currentGender + "!")
        .set_flags(dpp::m_ephemeral)
    );
}
