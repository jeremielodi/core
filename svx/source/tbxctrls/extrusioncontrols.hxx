/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#ifndef INCLUDED_SVX_SOURCE_TBXCTRLS_EXTRUSIONCONTROLS_HXX
#define INCLUDED_SVX_SOURCE_TBXCTRLS_EXTRUSIONCONTROLS_HXX

#include <svtools/toolbarmenu.hxx>
#include <svtools/popupwindowcontroller.hxx>

class ValueSet;

// enum to index light images
#define FROM_TOP_LEFT       0
#define FROM_TOP            1
#define FROM_TOP_RIGHT      2
#define FROM_LEFT           3
#define FROM_FRONT          4
#define FROM_RIGHT          5
#define FROM_BOTTOM_LEFT    6
#define FROM_BOTTOM         7
#define FROM_BOTTOM_RIGHT   8

#define DIRECTION_NW        0
#define DIRECTION_N         1
#define DIRECTION_NE        2
#define DIRECTION_W         3
#define DIRECTION_NONE      4
#define DIRECTION_E         5
#define DIRECTION_SW        6
#define DIRECTION_S         7
#define DIRECTION_SE        8

namespace svx
{
class ExtrusionDirectionWindow : public svtools::ToolbarMenu
{
public:
    ExtrusionDirectionWindow( svt::ToolboxController& rController, vcl::Window* pParentWindow );
    virtual ~ExtrusionDirectionWindow() override;
    virtual void dispose() override;

    virtual void statusChanged( const css::frame::FeatureStateEvent& Event ) override;
    virtual void DataChanged( const DataChangedEvent& rDCEvt ) override;

private:
    svt::ToolboxController& mrController;
    VclPtr<ValueSet>        mpDirectionSet;

    Image       maImgDirection[9];
    Image const       maImgPerspective;
    Image const       maImgParallel;

    DECL_LINK( SelectToolbarMenuHdl, ToolbarMenu*, void );
    DECL_LINK( SelectValueSetHdl, ValueSet*, void );
    void SelectHdl(void const *);

    void implSetDirection( sal_Int32 nSkew, bool bEnabled );
    void implSetProjection( sal_Int32 nProjection, bool bEnabled );

};


class ExtrusionDirectionControl : public svt::PopupWindowController
{
public:
    explicit ExtrusionDirectionControl( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    virtual VclPtr<vcl::Window> createVclPopupWindow( vcl::Window* pParent ) override;

    // XInitialization
    virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;
};

class ExtrusionDepthWindow : public svtools::ToolbarMenu
{
private:
    svt::ToolboxController& mrController;
    FieldUnit   meUnit;
    double      mfDepth;

    DECL_LINK( SelectHdl, ToolbarMenu*, void );

    void    implFillStrings( FieldUnit eUnit );
    void    implSetDepth( double fDepth );

public:
    ExtrusionDepthWindow( svt::ToolboxController& rController, vcl::Window* pParentWindow );

    virtual void statusChanged( const css::frame::FeatureStateEvent& Event ) override;
};

class ExtrusionDepthController : public svt::PopupWindowController
{
public:
    explicit ExtrusionDepthController( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    virtual VclPtr<vcl::Window> createVclPopupWindow( vcl::Window* pParent ) override;

    // XInitialization
    virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;
};

class ExtrusionLightingWindow : public svtools::ToolbarMenu
{
private:
    svt::ToolboxController& mrController;
    VclPtr<ValueSet>        mpLightingSet;

    Image maImgLightingOff[9];
    Image maImgLightingOn[9];
    Image maImgLightingPreview[9];

    Image const maImgBright;
    Image const maImgNormal;
    Image const maImgDim;

    int     mnDirection;
    bool    mbDirectionEnabled;

    void    implSetIntensity( int nLevel, bool bEnabled );
    void    implSetDirection( int nDirection, bool bEnabled );

    DECL_LINK( SelectToolbarMenuHdl, ToolbarMenu*, void );
    DECL_LINK( SelectValueSetHdl, ValueSet*, void );
    void SelectHdl(void const *);
public:
    ExtrusionLightingWindow( svt::ToolboxController& rController, vcl::Window* pParentWindow );
    virtual ~ExtrusionLightingWindow() override;
    virtual void dispose() override;

    virtual void statusChanged( const css::frame::FeatureStateEvent& Event ) override;
    virtual void DataChanged( const DataChangedEvent& rDCEvt ) override;
};


class ExtrusionLightingControl : public svt::PopupWindowController
{
public:
    explicit ExtrusionLightingControl( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    virtual VclPtr<vcl::Window> createVclPopupWindow( vcl::Window* pParent ) override;

    // XInitialization
    virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;
};

class ExtrusionSurfaceWindow : public svtools::ToolbarMenu
{
private:
    svt::ToolboxController& mrController;

    DECL_LINK( SelectHdl, ToolbarMenu*, void );

    void    implSetSurface( int nSurface, bool bEnabled );

public:
    ExtrusionSurfaceWindow( svt::ToolboxController& rController, vcl::Window* pParentWindow );

    virtual void statusChanged( const css::frame::FeatureStateEvent& Event ) override;
};


class ExtrusionSurfaceControl : public svt::PopupWindowController
{
public:
    explicit ExtrusionSurfaceControl( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    virtual VclPtr<vcl::Window> createVclPopupWindow( vcl::Window* pParent ) override;

    // XInitialization
    virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;
};

}
#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
