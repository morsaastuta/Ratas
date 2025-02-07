// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RatasProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef RATAS_RatasProjectile_generated_h
#error "RatasProjectile.generated.h already included, missing '#pragma once' in RatasProjectile.h"
#endif
#define RATAS_RatasProjectile_generated_h

#define FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARatasProjectile(); \
	friend struct Z_Construct_UClass_ARatasProjectile_Statics; \
public: \
	DECLARE_CLASS(ARatasProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Ratas"), NO_API) \
	DECLARE_SERIALIZER(ARatasProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ARatasProjectile(ARatasProjectile&&); \
	ARatasProjectile(const ARatasProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARatasProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARatasProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARatasProjectile) \
	NO_API virtual ~ARatasProjectile();


#define FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_12_PROLOG
#define FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RATAS_API UClass* StaticClass<class ARatasProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Ratas_Ratas_Source_Ratas_RatasProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
