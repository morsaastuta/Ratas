// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RatasCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RATAS_RatasCharacter_generated_h
#error "RatasCharacter.generated.h already included, missing '#pragma once' in RatasCharacter.h"
#endif
#define RATAS_RatasCharacter_generated_h

#define FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARatasCharacter(); \
	friend struct Z_Construct_UClass_ARatasCharacter_Statics; \
public: \
	DECLARE_CLASS(ARatasCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Ratas"), NO_API) \
	DECLARE_SERIALIZER(ARatasCharacter)


#define FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARatasCharacter(ARatasCharacter&&); \
	ARatasCharacter(const ARatasCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARatasCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARatasCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARatasCharacter) \
	NO_API virtual ~ARatasCharacter();


#define FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_19_PROLOG
#define FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RATAS_API UClass* StaticClass<class ARatasCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Ratas_Ratas_Source_Ratas_RatasCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
