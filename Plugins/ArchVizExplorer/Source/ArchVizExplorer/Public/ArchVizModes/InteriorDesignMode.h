// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchVizModes/ArchVizMode.h"
#include "InputMappingContext.h"
#include "UObject/NoExportTypes.h"
#include "Actors/InteriorActor.h"
#include "InteriorDesignMode.generated.h"

UENUM(BlueprintType)
enum class EInteriorModeState : uint8 {
	Free,
    OldEntity,
    NewEntity
};

/**
 *
 */
UCLASS(Blueprintable)
class ARCHVIZEXPLORER_API UInteriorDesignMode : public UArchVizMode {
	GENERATED_BODY()

public:
	UInteriorDesignMode();

	virtual void Setup() override;
    virtual void Cleanup() override;
	virtual void SetupInputMapping() override;
	virtual void EnterMode() override;
	virtual void ExitMode() override;

    void BindWidgetDelegates();
    void SetCurrentInteriorActor(AInteriorActor* InInteriorActor);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    TSubclassOf<AInteriorActor> InteriorActorRef;

private:
    EInteriorModeState InteriorModeState;

    UPROPERTY()
    AInteriorActor* InteriorActor;

    UFUNCTION()
    void HandleInteriorAssetSelect(FInteriorAsset InteriorAsset);

    void HandleFreeState();
    void HandleOldEntityState();
    void HandleNewEntityState();

    void HandleLeftClickAction();
    void HandleRKeyPressAction();
    void HandleMKeyPressAction();
    void HandleDeleteKeyPressAction();

    UFUNCTION()
    void HandleNewButtonClick();

    UFUNCTION()
    void HandleDeleteButtonClick();

    UFUNCTION()
    void HandleClosePanelButtonClick();
};
