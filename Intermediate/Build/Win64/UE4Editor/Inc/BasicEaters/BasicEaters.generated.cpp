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
	ENGINE_API class UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API class UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UShapeComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USceneComponent_NoRegister();

	BASICEATERS_API class UClass* Z_Construct_UClass_ABasicEatersGameModeBase_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABasicEatersGameModeBase();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABonusFoodPellet_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_ABonusFoodPellet();
	BASICEATERS_API class UClass* Z_Construct_UClass_AEater1_NoRegister();
	BASICEATERS_API class UClass* Z_Construct_UClass_AEater1();
	BASICEATERS_API class UFunction* Z_Construct_UFunction_ANormalFoodPellets_OnPlayerEnterPickupBox();
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


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_OurCameraSpringArm = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OurCameraSpringArm"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OurCameraSpringArm, AEater1), 0x0020080000080009, Z_Construct_UClass_USpringArmComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<AEater1> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Eater1.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Eater1.h"));
				MetaData->SetValue(NewProp_OurCameraSpringArm, TEXT("Category"), TEXT("Eater1"));
				MetaData->SetValue(NewProp_OurCameraSpringArm, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_OurCameraSpringArm, TEXT("ModuleRelativePath"), TEXT("Eater1.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEater1, 2459211675);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEater1(Z_Construct_UClass_AEater1, &AEater1::StaticClass, TEXT("/Script/BasicEaters"), TEXT("AEater1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEater1);
	void ANormalFoodPellets::StaticRegisterNativesANormalFoodPellets()
	{
		UClass* Class = ANormalFoodPellets::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "OnPlayerEnterPickupBox", (Native)&ANormalFoodPellets::execOnPlayerEnterPickupBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_ANormalFoodPellets_OnPlayerEnterPickupBox()
	{
		struct NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		UObject* Outer=Z_Construct_UClass_ANormalFoodPellets();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnPlayerEnterPickupBox"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00420401, 65535, sizeof(NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms));
			UProperty* NewProp_SweepResult = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SweepResult"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(SweepResult, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010008008000182, Z_Construct_UScriptStruct_FHitResult());
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(bFromSweep, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms, bool);
			UProperty* NewProp_bFromSweep = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("bFromSweep"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bFromSweep, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(bFromSweep, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), sizeof(bool), true);
			UProperty* NewProp_OtherBodyIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherBodyIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(OtherBodyIndex, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010000000000080);
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010000000000080, Z_Construct_UClass_AActor_NoRegister());
			UProperty* NewProp_OverlappedComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OverlappedComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OverlappedComp, NormalFoodPellets_eventOnPlayerEnterPickupBox_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
			MetaData->SetValue(NewProp_SweepResult, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_OverlappedComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
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

				OuterClass->LinkChild(Z_Construct_UFunction_ANormalFoodPellets_OnPlayerEnterPickupBox());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_PickupBox = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PickupBox"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PickupBox, ANormalFoodPellets), 0x0010000000080009, Z_Construct_UClass_UShapeComponent_NoRegister());
				UProperty* NewProp_PickupMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PickupMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PickupMesh, ANormalFoodPellets), 0x0010000000080009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_PickupRoot = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("PickupRoot"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PickupRoot, ANormalFoodPellets), 0x0010000000080009, Z_Construct_UClass_USceneComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANormalFoodPellets_OnPlayerEnterPickupBox(), "OnPlayerEnterPickupBox"); // 1085148052
				static TCppClassTypeInfo<TCppClassTypeTraits<ANormalFoodPellets> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("NormalFoodPellets.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
				MetaData->SetValue(NewProp_PickupBox, TEXT("Category"), TEXT("NormalFoodPellets"));
				MetaData->SetValue(NewProp_PickupBox, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_PickupBox, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
				MetaData->SetValue(NewProp_PickupMesh, TEXT("Category"), TEXT("NormalFoodPellets"));
				MetaData->SetValue(NewProp_PickupMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_PickupMesh, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
				MetaData->SetValue(NewProp_PickupRoot, TEXT("Category"), TEXT("NormalFoodPellets"));
				MetaData->SetValue(NewProp_PickupRoot, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_PickupRoot, TEXT("ModuleRelativePath"), TEXT("NormalFoodPellets.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANormalFoodPellets, 1541969998);
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
			Guid.A = 0x0B73B465;
			Guid.B = 0xCC4899B9;
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
