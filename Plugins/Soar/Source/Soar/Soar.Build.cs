// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class Soar : ModuleRules
{
    public string GetUProjectPath(int depth)
    {
        //Change this according to your module's relative location to your project file. If there is any better way to do this I'm interested!
        //Assuming Source/ThirdParty/YourLib/
        string directory = ModuleDirectory;
        while (depth > 0)
        {
            directory = Directory.GetParent(directory).ToString();
            --depth;
        }
        return directory;
    }
    public string GetUProjectName(int depth)
    {
        //Change this according to your module's relative location to your project file. If there is any better way to do this I'm interested!
        //Assuming Source/ThirdParty/YourLib/
        string directory = ModuleDirectory;
        string directorySlashName = "";
        while (depth > 0)
        {
            directorySlashName = directory;
            directory = Directory.GetParent(directory).ToString();
            --depth;
        }
        return directorySlashName.Substring(directory.Length + 1);
    }

    private void CopyToBinaries(string Filepath, ReadOnlyTargetRules Target)
    {
        //System.IO.StreamWriter file = new System.IO.StreamWriter("C:\\Users\\bazald\\CloudStation\\Windows\\Documents\\repo\\UnrealSoar\\debug.txt");
        //file.WriteLine("ModuleDirectory: \"" + ModuleDirectory + "\"");
        //file.WriteLine("GetUProjectPath(4): \"" + GetUProjectPath(4) + "\"");
        //file.WriteLine("Filepath: \"" + Filepath + "\"");

        string binariesDir = Path.Combine(GetUProjectPath(4), "Binaries", Target.Platform.ToString());
        //file.WriteLine("binariesDir: " + binariesDir);
        string filename = Path.GetFileName(Filepath);
        //file.WriteLine("filename: " + filename);

        if (!Directory.Exists(binariesDir))
        {
            Directory.CreateDirectory(binariesDir);
            //file.WriteLine("CreateDirectory: \"" + Path.GetFullPath(binariesDir) + "\"");
        }
        else
        {
            //file.WriteLine("Directory.Exists: \"" + Path.GetFullPath(binariesDir) + "\"");
        }

        if (!File.Exists(Path.Combine(binariesDir, filename)))
        {
            File.Copy(Filepath, Path.Combine(binariesDir, filename), true);
            //file.WriteLine("File.Copy: \"" + Path.GetFullPath(Filepath) + " to " + Path.GetFullPath(Path.Combine(binariesDir, filename)) + "\"");
        }
        else
        {
            //file.WriteLine("File.Exists: \"" + Path.GetFullPath(Path.Combine(binariesDir, filename)) + "\"");
        }

        //file.Close();
    }

    public Soar(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Soar",
                "Projects"
				// ... add other public dependencies that you statically link with here ...
			}
        );

        PublicIncludePaths.AddRange(
            new string[] {
                ModuleDirectory + "/Core/ClientSML",
                ModuleDirectory + "/Core/ConnectionSML",
                ModuleDirectory + "/Core/ElementXML",
                ModuleDirectory + "/Core/KernelSML",
                ModuleDirectory + "/Core/shared"
            }
        );

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "Win64", "Release"));
			PublicAdditionalLibraries.Add("Soar.lib");
            
			PublicDelayLoadDLLs.Add("Soar.dll");
            
            CopyToBinaries(Path.Combine(ModuleDirectory, Target.Platform.ToString(), "Release", "Soar.dll"), Target);
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(GetUProjectPath(4), "Binaries", Target.Platform.ToString(), "Soar.dll")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicDelayLoadDLLs.Add("libSoar.dylib");

            CopyToBinaries(Path.Combine(ModuleDirectory, Target.Platform.ToString(), "Release", "libSoar.dylib"), Target);
            RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(GetUProjectPath(4), "Binaries", Target.Platform.ToString(), "libSoar.dylib")));
        }
    }
}
