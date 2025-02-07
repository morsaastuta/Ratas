// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Ratas/RatasGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRatasGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
RATAS_API UClass* Z_Construct_UClass_ARatasGameMode();
RATAS_API UClass* Z_Construct_UClass_ARatasGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_Ratas();
// End Cross Module References

// Begin Class ARatasGameMode
void ARatasGameMode::StaticRegisterNativesARatasGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARatasGameMode);
UClass* Z_Construct_UClass_ARatasGameMode_NoRegister()
{
	return ARatasGameMode::StaticClass();
}
struct Z_Construct_UClass_ARatasGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RatasGameMode.h" },
		{ "ModuleRelativePath", "RatasGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARatasGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ARatasGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Ratas,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARatasGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARatasGameMode_Statics::ClassParams = {
	&ARatasGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARatasGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARatasGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARatasGameMode()
{
	if (!Z_Registration_Info_UClass_ARatasGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARatasGameMode.OuterSingleton, Z_Construct_UClass_ARatasGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARatasGameMode.OuterSingleton;
}
template<> RATAS_API UClass* StaticClass<ARatasGameMode>()
{
	return ARatasGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARatasGameMode);
ARatasGameMode::~ARatasGameMode() {}
// End Class ARatasGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARatasGameMode, ARatasGameMode::StaticClass, TEXT("ARatasGameMode"), &Z_Registration_Info_UClass_ARatasGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARatasGameMode), 2760394184U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_2893760228(TEXT("/Script/Ratas"),
	Z_CompiledInDeferFile_FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Ratas_Ratas_Source_Ratas_RatasGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
