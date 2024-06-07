// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ipv2 : ModuleRules
{
	public Ipv2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "OnlineSubsystemSteam", "OnlineSubsystem" });
	}
}
