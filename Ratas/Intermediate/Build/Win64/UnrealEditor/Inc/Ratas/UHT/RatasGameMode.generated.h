// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RatasGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RATAS_RatasGameMode_generated_h
#error "RatasGameMode.generated.h already included, missing '#pragma once' in RatasGameMode.h"
#endif
#define RATAS_RatasGameMode_generated_h

#define FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARatasGameMode(); \
	friend struct Z_Construct_UClass_ARatasGameMode_Statics; \
public: \
	DECLARE_CLASS(ARatasGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Ratas"), RATAS_API) \
	DECLARE_SERIALIZER(ARatasGameMode)


#define FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARatasGameMode(ARatasGameMode&&); \
	ARatasGameMode(const ARatasGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(RATAS_API, ARatasGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARatasGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARatasGameMode) \
	RATAS_API virtual ~ARatasGameMode();


#define FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_9_PROLOG
#define FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RATAS_API UClass* StaticClass<class ARatasGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
