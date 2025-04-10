#include "ModeCardUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UModeCardUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ClickButton)
    {
        ClickButton->OnClicked.AddDynamic(this, &UModeCardUserWidget::HandleClick);
    }
}

void UModeCardUserWidget::SetCardData(UTexture2D* InIcon, FText InTitle, FText InDesc, EGameModes InMode)
{
    ModeType = InMode;
    if (IconImage) IconImage->SetBrushFromTexture(InIcon);
    if (TitleText) TitleText->SetText(InTitle);
    if (DescText) DescText->SetText(InDesc);
}

void UModeCardUserWidget::HandleClick()
{
    OnCardClicked.Broadcast(ModeType);
}
