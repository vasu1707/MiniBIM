// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NotificationWidget.h"

void UNotificationWidget::NativeConstruct() {
	Super::NativeConstruct();
}

void UNotificationWidget::SetError(FText ErrorText, float Time) {
	ShowTextBox();

	NotificationText->SetText(ErrorText);
	NotificationText->SetColorAndOpacity(FSlateColor{FLinearColor{1.f, 0.f, 0.f, 1.f}});

	HideNotificationAfter(Time);
}

void UNotificationWidget::SetSuccess(FText SuccessText, float Time) {
	ShowTextBox();

	NotificationText->SetText(SuccessText);
	NotificationText->SetColorAndOpacity(FSlateColor{ FLinearColor{0.f, 1.f, 0.f, 1.f} });

	HideNotificationAfter(Time);
}


void UNotificationWidget::ShowTextBox() {
	NotificationSizeBox->SetVisibility(ESlateVisibility::Visible);
}

void UNotificationWidget::HideTextBox() {
	NotificationSizeBox->SetVisibility(ESlateVisibility::Hidden);
}

void UNotificationWidget::HideNotificationAfter(float Seconds) {
	if (GetWorld()->GetTimerManager().GetTimerElapsed(TimerHandle) != -1.f) {
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UNotificationWidget::HideTextBox, Seconds, false);
}