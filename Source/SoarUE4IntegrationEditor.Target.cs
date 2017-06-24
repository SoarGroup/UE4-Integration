// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SoarUE4IntegrationEditorTarget : TargetRules
{
	public SoarUE4IntegrationEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "SoarUE4Integration" } );
	}
}
