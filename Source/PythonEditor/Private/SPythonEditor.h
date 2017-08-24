// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

class SPythonEditor : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPythonEditor) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, class UPythonProjectItem* InPythonProjectItem);

	bool Save() const;

	bool CanSave() const;

	void Execute() const;

	void ExecuteInSandbox() const;

	void GotoLineAndColumn(int32 LineNumber, int32 ColumnNumber);

private:
	void OnTextChanged(const FText& NewText);
	FText GetLineAndColumn() const;

protected:
	class UPythonProjectItem* PythonProjectItem;

	TSharedPtr<SScrollBar> HorizontalScrollbar;
	TSharedPtr<SScrollBar> VerticalScrollbar;

	TSharedPtr<class SPythonEditableText> PythonEditableText;

	mutable bool bDirty;
};