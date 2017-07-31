// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AVA_WhitePuzzle_generated_h
#error "WhitePuzzle.generated.h already included, missing '#pragma once' in WhitePuzzle.h"
#endif
#define AVA_WhitePuzzle_generated_h

#define Ava_Source_Ava_WhitePuzzle_h_19_RPC_WRAPPERS
#define Ava_Source_Ava_WhitePuzzle_h_19_RPC_WRAPPERS_NO_PURE_DECLS
#define Ava_Source_Ava_WhitePuzzle_h_19_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAWhitePuzzle(); \
	friend AVA_API class UClass* Z_Construct_UClass_AWhitePuzzle(); \
	public: \
	DECLARE_CLASS(AWhitePuzzle, APuzzle, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ava"), NO_API) \
	DECLARE_SERIALIZER(AWhitePuzzle) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ava_Source_Ava_WhitePuzzle_h_19_INCLASS \
	private: \
	static void StaticRegisterNativesAWhitePuzzle(); \
	friend AVA_API class UClass* Z_Construct_UClass_AWhitePuzzle(); \
	public: \
	DECLARE_CLASS(AWhitePuzzle, APuzzle, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ava"), NO_API) \
	DECLARE_SERIALIZER(AWhitePuzzle) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ava_Source_Ava_WhitePuzzle_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWhitePuzzle(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWhitePuzzle) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWhitePuzzle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWhitePuzzle); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AWhitePuzzle(const AWhitePuzzle& InCopy); \
public:


#define Ava_Source_Ava_WhitePuzzle_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AWhitePuzzle(const AWhitePuzzle& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWhitePuzzle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWhitePuzzle); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWhitePuzzle)


#define Ava_Source_Ava_WhitePuzzle_h_16_PROLOG
#define Ava_Source_Ava_WhitePuzzle_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ava_Source_Ava_WhitePuzzle_h_19_RPC_WRAPPERS \
	Ava_Source_Ava_WhitePuzzle_h_19_INCLASS \
	Ava_Source_Ava_WhitePuzzle_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ava_Source_Ava_WhitePuzzle_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ava_Source_Ava_WhitePuzzle_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Ava_Source_Ava_WhitePuzzle_h_19_INCLASS_NO_PURE_DECLS \
	Ava_Source_Ava_WhitePuzzle_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ava_Source_Ava_WhitePuzzle_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS