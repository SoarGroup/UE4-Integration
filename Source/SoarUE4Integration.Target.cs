// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SoarUE4IntegrationTarget : TargetRules
{
	public SoarUE4IntegrationTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "SoarUE4Integration" } );
	}
}
