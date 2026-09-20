#include "script.h"
#include "keyboard.h"
#include "log.h"
#include "config.h"

#include <format>

namespace
{
	bool g_enabled = false;
	ModConfig g_config;

	void DrawInWaterText(const char* text)
	{
		UIDEBUG::_BG_SET_TEXT_SCALE(0.55f, 0.55f);
		UIDEBUG::_BG_SET_TEXT_COLOR(245, 245, 245, 255);

		const char* varString = MISC::VAR_STRING(10, (char*)"LITERAL_STRING", (char*)text);
		UIDEBUG::_BG_DISPLAY_TEXT(varString, 100.0f / 1920.0f, 100.0f / 1080.0f);
	}

	void OnTick()
	{
		Ped player = PLAYER::PLAYER_PED_ID();

		if (ENTITY::IS_ENTITY_IN_WATER(player))
			DrawInWaterText("In Water");
	}
}

void ScriptMain()
{
	/* No config needed for this mod */
	/*
	g_config = LoadConfig();

	if (g_config.enableTextLogging) {
		Log::Init();
		Log::Write(std::format("ScriptMain started"));
	}
	*/
	while (true)
	{
		OnTick();
		WAIT(0);
	}
}

