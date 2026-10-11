// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealChaos : ModuleRules
{
	public UnrealChaos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UnrealChaos",
			"UnrealChaos/Variant_Platforming",
			"UnrealChaos/Variant_Platforming/Animation",
			"UnrealChaos/Variant_Combat",
			"UnrealChaos/Variant_Combat/AI",
			"UnrealChaos/Variant_Combat/Animation",
			"UnrealChaos/Variant_Combat/Gameplay",
			"UnrealChaos/Variant_Combat/Interfaces",
			"UnrealChaos/Variant_Combat/UI",
			"UnrealChaos/Variant_SideScrolling",
			"UnrealChaos/Variant_SideScrolling/AI",
			"UnrealChaos/Variant_SideScrolling/Gameplay",
			"UnrealChaos/Variant_SideScrolling/Interfaces",
			"UnrealChaos/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
