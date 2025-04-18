#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleUserWidget.generated.h"

class UCircularThrobber;

UCLASS()
class SSBPROJECT_API UTitleUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UTitleUserWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UPROPERTY(meta = (BindWidget))
	UCircularThrobber* Loading;
};