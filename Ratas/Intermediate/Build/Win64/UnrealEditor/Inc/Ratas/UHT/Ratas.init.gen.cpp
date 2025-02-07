// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRatas_init() {}
	RATAS_API UFunction* Z_Construct_UDelegateFunction_Ratas_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Ratas;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Ratas()
	{
		if (!Z_Registration_Info_UPackage__Script_Ratas.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Ratas_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Ratas",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x95F9B08A,
				0xA7538C72,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Ratas.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Ratas.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Ratas(Z_Construct_UPackage__Script_Ratas, TEXT("/Script/Ratas"), Z_Registration_Info_UPackage__Script_Ratas, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x95F9B08A, 0xA7538C72));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
