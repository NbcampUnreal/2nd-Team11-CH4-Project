// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class SSBProject : ModuleRules
{
	public SSBProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "GameModes"),
			Path.Combine(ModuleDirectory, "GameStates"),
			Path.Combine(ModuleDirectory, "PlayerControllers"),
			Path.Combine(ModuleDirectory, "PlayerStates"),
			Path.Combine(ModuleDirectory, "UserWidgets"),
			Path.Combine(ModuleDirectory, "Global"),
			Path.Combine(ModuleDirectory, "Chracters"),
            Path.Combine(ModuleDirectory, "Actors"),
            Path.Combine(ModuleDirectory, "Instances"),
            Path.Combine(ModuleDirectory, "Combats"),
        });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "AIModule", "GameplayAbilities", "GameplayTasks", "GameplayTags" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
