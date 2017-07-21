// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BASICEATERS_Wall_generated_h
#error "Wall.generated.h already included, missing '#pragma once' in Wall.h"
#endif
#define BASICEATERS_Wall_generated_h

#define BasicEaters_Source_BasicEaters_Wall_h_12_RPC_WRAPPERS
#define BasicEaters_Source_BasicEaters_Wall_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define BasicEaters_Source_BasicEaters_Wall_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWall(); \
	friend BASICEATERS_API class UClass* Z_Construct_UClass_AWall(); \
public: \
	DECLARE_CLASS(AWall, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BasicEaters"), NO_API) \
	DECLARE_SERIALIZER(AWall) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BasicEaters_Source_BasicEaters_Wall_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAWall(); \
	friend BASICEATERS_API class UClass* Z_Construct_UClass_AWall(); \
public: \
	DECLARE_CLASS(AWall, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BasicEaters"), NO_API) \
	DECLARE_SERIALIZER(AWall) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BasicEaters_Source_BasicEaters_Wall_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWall(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWall) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWall); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWall(AWall&&); \
	NO_API AWall(const AWall&); \
public:


#define BasicEaters_Source_BasicEaters_Wall_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWall(AWall&&); \
	NO_API AWall(const AWall&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWall); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWall); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWall)


#define BasicEaters_Source_BasicEaters_Wall_h_12_PRIVATE_PROPERTY_OFFSET
#define BasicEaters_Source_BasicEaters_Wall_h_9_PROLOG
#define BasicEaters_Source_BasicEaters_Wall_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BasicEaters_Source_BasicEaters_Wall_h_12_PRIVATE_PROPERTY_OFFSET \
	BasicEaters_Source_BasicEaters_Wall_h_12_RPC_WRAPPERS \
	BasicEaters_Source_BasicEaters_Wall_h_12_INCLASS \
	BasicEaters_Source_BasicEaters_Wall_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BasicEaters_Source_BasicEaters_Wall_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BasicEaters_Source_BasicEaters_Wall_h_12_PRIVATE_PROPERTY_OFFSET \
	BasicEaters_Source_BasicEaters_Wall_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	BasicEaters_Source_BasicEaters_Wall_h_12_INCLASS_NO_PURE_DECLS \
	BasicEaters_Source_BasicEaters_Wall_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BasicEaters_Source_BasicEaters_Wall_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
