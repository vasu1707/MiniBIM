// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UMG/Public/Components/TextBlock.h"
#include "UMG/Public/Components/SizeBox.h"
#include "NotificationWidget.generated.h"

/**
 *
 */
UCLASS()
class ARCHVIZEXPLORER_API UNotificationWidget : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	USizeBox* NotificationSizeBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock*	NotificationText;

	virtual void NativeConstruct() override;
	void SetError(FText ErrorText, float Time);
	void SetSuccess(FText SuccessText, float Time);

	void ShowTextBox();
	void HideTextBox();

	void HideNotificationAfter(float Seconds);

	FTimerHandle TimerHandle;
};
