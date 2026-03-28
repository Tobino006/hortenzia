#pragma once
#include <dpp/dpp.h>

void register_description_command(dpp::cluster& bot);

void handle_description_command(const dpp::slashcommand_t& event);