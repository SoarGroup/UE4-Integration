using UnrealBuildTool;
using System;
using System.IO;

public class Soar : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(System.IO.Path.Combine(ModulePath, "../../ThirdParty/Soar")); }
    }
   
    public Soar(TargetInfo target)
    {
        PrivateIncludePaths.AddRange(new[] { "Soar/Private" });
        PublicDelayLoadDLLs.Add("Soar.dll");

        PublicLibraryPaths.Add(ThirdPartyPath);
        PublicAdditionalLibraries.Add("Soar.lib");
        PrivateDependencyModuleNames.AddRange(
            new[]
            {
                "Engine",
                "InputCore",
                "Core",
                "CoreUObject"
            }
        );
    }
}