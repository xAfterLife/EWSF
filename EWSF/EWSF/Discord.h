#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include "Discord/discord_rpc.h"

class Discord
{
	inline static const char* applicationID_ = "Your Application ID";
	inline static time_t startTime_;
	inline static std::string rpcState_;
	inline static std::string rpcDetails_;
	inline static std::string rpcLargeImageKey;
	inline static std::string rpcLargeImageText;
	inline static std::string rpcSmallImageKey;
	inline static std::string rpcSmallImageText;
	inline static std::int32_t rpcPartySize;
	inline static std::int32_t rpcPartyMax;
public:
	static void UpdateThread();
	static void Initialize();
	static void Update();
	static void UpdateDetails(const std::string&);
};
