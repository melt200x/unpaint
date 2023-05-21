﻿#pragma once
#include "InferenceView.g.h"
#include "SizeToStringConverter.h"
#include "IsNanToBooleanConverter.h"
#include "NanToZeroConverter.h"
#include "StringToImageSourceConverter.h"
#include "BooleanInverter.h"
#include "EqualsConverter.h"

namespace winrt::Unpaint::implementation
{
  struct InferenceView : InferenceViewT<InferenceView>
  {
    InferenceView();

    InferenceViewModel ViewModel();

    bool IsStatusVisible();

    void ToggleSettingsLock();

    void OnOutputImageDragStarting(Windows::UI::Xaml::UIElement const& sender, Windows::UI::Xaml::DragStartingEventArgs const& eventArgs);
    void OnOutputImageDragOver(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::DragEventArgs const& eventArgs);
    fire_and_forget OnOutputImageDrop(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::DragEventArgs const& eventArgs);

    event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
    void PropertyChanged(event_token const& token);

  private:
    event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> _propertyChanged;
    INavigationService _navigationService;

    Windows::ApplicationModel::Core::CoreApplicationViewTitleBar::LayoutMetricsChanged_revoker _titleBarLayoutMetricsChangedRevoker;
    INavigationService::IsPointerOverTitleBarChanged_revoker _isPointerOverTitleBarChangedRevoker;
    Windows::UI::Xaml::Data::INotifyPropertyChanged::PropertyChanged_revoker _viewModelPropertyChangedRevoker;

    bool _isPointerOverStatusBar;
    InferenceViewModel _viewModel;

    void UpdateStatusVisibility();
  };
}

namespace winrt::Unpaint::factory_implementation
{
  struct InferenceView : InferenceViewT<InferenceView, implementation::InferenceView>
  {
  };
}
