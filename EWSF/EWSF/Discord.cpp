#include "Discord.h"

void Discord::UpdateThread()
{
	while (true)
	{
		Update();
		Discord_RunCallbacks();
		Sleep(15000); //DiscordRPC is limited to Updates every 15 Seconds
	}
}

void Discord::Initialize()
{
	DiscordEventHandlers handle;
	startTime_ = time(nullptr);

	memset(&handle, 0, sizeof handle);
	Discord_Initialize(applicationID_, &handle, 1, nullptr);
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)UpdateThread, nullptr, 0, nullptr);
}

void Discord::Update()
{
	DiscordRichPresence discord_presence;
	memset(&discord_presence, 0, sizeof discord_presence);

	discord_presence.state = rpcState_.c_str(); 
	discord_presence.details = rpcDetails_.c_str(); 
	discord_presence.startTimestamp = startTime_;
	discord_presence.endTimestamp = 0; 
	discord_presence.largeImageKey = rpcLargeImageKey.c_str(); 
	discord_presence.largeImageText = rpcLargeImageText.c_str(); 
	discord_presence.smallImageKey = rpcSmallImageKey.c_str(); 
	discord_presence.smallImageText = rpcSmallImageText.c_str(); 
	discord_presence.partyId = nullptr; 
	discord_presence.partySize = rpcPartySize; 
	discord_presence.partyMax = rpcPartyMax;
	discord_presence.partyPrivacy = NULL;

	Discord_UpdatePresence(&discord_presence);
}

void Discord::UpdateDetails(const std::string& s)
{
	//Fill these with Values from an incoming string- like an PacketLogger f.E. that get's send a packet from the Server for the RPC Informations
	rpcState_ = "Your State";
	rpcDetails_ = "Your Details";
	rpcLargeImageKey = "Your LargeImageKey";
	rpcLargeImageText = "Your LargeImageText";
	rpcSmallImageKey = "Your SmallImageKey";
	rpcSmallImageText = "Your SmallImageText";
	rpcPartySize = atoi("Your PartySize");
	rpcPartyMax = atoi("Your PartyMax");
}
