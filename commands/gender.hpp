#pragma once
#include <dpp/dpp.h>
#include <string>

extern std::string currentGender;

void register_gender_command(dpp::cluster& bot);
void handle_gender_command(const dpp::slashcommand_t& event);

void register_update_gender(dpp::cluster& bot);
void handle_update_gender(const dpp::slashcommand_t& event);