// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BasicEaters.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1BasicEaters() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();

	BASICEATERS_API class UClass* Z_Construct_UClass_ABasicEatersGameModeBase_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABasicEatersGameModeBase();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABonusFoodPellet_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABonusFoodPellet();
	BASICEATERS_API class UClass* Z_Construct_UClass_AEater1_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_AEater1();
	BASICEATERS_API class UClass* Z_Construct_UClass_ANormalFoodPellets_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_ANormalFoodPellets();
	BASICEATERS_API class UClass* Z_Construct_UClass_AWall_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_AWall();
	BASICEATERS_API class UPackage* Z_Construct_UPackage__Script_BasicEaters();
	void ABasicEatersGameModeBase::StaticRegisterNativesABasicEatersGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABasicEatersGameModeBase_NoRegister()
	{
		return ABasicEatersGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ABasicEatersGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_BasicEaters();
			OuterClass = ABasicEatersGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900288;


				static TCppClassTypeInfo<TCppClassTypeTraits<ABasicEatersGameModeBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BasicEatersGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BasicEatersGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABasicEatersGameModeBase, 1964799188);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasicEatersGameModeBase(Z_Construct_UClass_ABasicEatersGameModeBase, &ABasicEatersGameModeBase::StaticClass, TEXT("/Script/BasicEaters"), TEXT("ABasicEatersGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasicEatersGameModeBase);
	void ABonusFoodPellet::StaticRegisterNativesABonusFoodPellet()
	{
	}
	UClass* Z_Construct_UClass_ABonusFoodPellet_NoRegister()
	{
		return ABonusFoodPellet::StaticClass();
	}
	UClass* Z_Construct_UClass_ABonusFoodPellet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_BasicEaters();
			OuterClass = ABonusFoodPellet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ABonusFoodPellet> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BonusFoodPellet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BonusFoodPellet.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABonusFoodPellet, 4011318966);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABonusFoodPellet(Z_Construct_UClass_ABonusFoodPellet, &ABonusFoodPellet::StaticClass, TEXT("/Script/BasicEaters"), TEXT("ABonusFoodPellet"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABonusFoodPellet);
	void AEater1::StaticRegisterNativesAEater1()
	{
	}
	UClass* Z_Construct_UClass_AEater1_NoRegister()
	{
		return AEater1::StaticClass();
	}
	UClass* Z_Construct_UClass_AEater1()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_BasicEaters();
			OuterClass = AEater1::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AEater1> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Eater1.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Eater1.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEater1, 951933139);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEater1(Z_Construct_UClass_AEater1, &AEater1::StaticClass, TEXT("/Script/BasicEaters"), TEXT("AEater1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEater1);
	void ANormalFoodPellets::StaticRegisterNativesANormalFoodPellets()
	{
	}
	UClass* Z_Construct_UClass_ANormalFoodPellets_NoRegister()
	{
		return ANormalFoodPellets::StaticClass();
	}
	UClass* Z_Construct_UClass_ANormalFoodPellets()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_BasicEaters();
			OuterClass = ANormalFoodPellets::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<ANormalFoodPellets> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("NormalFoodPellets.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANormalFoodPellets, 618788294);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANormalFoodPellets(Z_Construct_UClass_ANormalFoodPellets, &ANormalFoodPellets::StaticClass, TEXT("/Script/BasicEaters"), TEXT("ANormalFoodPellets"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANormalFoodPellets);
	void AWall::StaticRegisterNativesAWall()
	{
	}
	UClass* Z_Construct_UClass_AWall_NoRegister()
	{
		return AWall::StaticClass();
	}
	UClass* Z_Construct_UClass_AWall()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_BasicEaters();
			OuterClass = AWall::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				static TCppClassTypeInfo<TCppClassTypeTraits<AWall> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Wall.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Wall.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWall, 2117763102);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWall(Z_Construct_UClass_AWall, &AWall::StaticClass, TEXT("/Script/BasicEaters"), TEXT("AWall"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWall);
	UPackage* Z_Construct_UPackage__Script_BasicEaters()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/BasicEaters")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xD3E283BA;
			Guid.B = 0x8306ACCF;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
