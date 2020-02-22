//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef CONTROLLERMAP_H
#define CONTROLLERMAP_H
#ifdef _WIN32
#pragma once
#endif

#include "Panel.h"
#include "utlmap.h"
#include "utlsymbol.h"

class CControllerMap : public vgui2::Panel
{
	DECLARE_CLASS_SIMPLE( CControllerMap, vgui2::Panel )

	virtual void OnKeyCodeTyped( vgui2::KeyCode code );

public:
	CControllerMap( vgui2::Panel *parent, const char *name );

	virtual void ApplySettings( KeyValues *inResourceData );

	int NumButtons( void )
	{
		return m_buttonMap.Count();
	}

	const char *GetBindingText( int idx );
	const char *GetBindingIcon( int idx );

private:

	struct button_t
	{
		CUtlSymbol	cmd;
		CUtlSymbol	text;
		CUtlSymbol	icon;
	};
	CUtlMap< int, button_t > m_buttonMap;
};

#endif // CONTROLLERMAP_H