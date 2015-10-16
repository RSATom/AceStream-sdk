/*****************************************************************************
 * vlc.h: global header for libvlc
 *****************************************************************************
 * Copyright (C) 1998-2008 VLC authors and VideoLAN
 * $Id: 8f39094bd4b15c99288cecd001f76fcc10565daa $
 *
 * Authors: Vincent Seguin <seguin@via.ecp.fr>
 *          Samuel Hocevar <sam@zoy.org>
 *          Gildas Bazin <gbazin@netcourrier.com>
 *          Derk-Jan Hartman <hartman at videolan dot org>
 *          Pierre d'Herbemont <pdherbemont@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef VLC_VLC_H
#define VLC_VLC_H 1

/**
 * \file
 * This file defines libvlc new external API
 */

# ifdef __cplusplus
extern "C" {
# endif

#include <acestreamplayer/libvlc_structures.h>
#include <acestreamplayer/libvlc.h>
#include <acestreamplayer/libvlc_media.h>
#include <acestreamplayer/libvlc_media_player.h>
#include <acestreamplayer/libvlc_media_list.h>
#include <acestreamplayer/libvlc_media_list_player.h>
#include <acestreamplayer/libvlc_media_library.h>
#include <acestreamplayer/libvlc_media_discoverer.h>
#include <acestreamplayer/libvlc_acestream.h>
#include <acestreamplayer/libvlc_events.h>
#include <acestreamplayer/libvlc_vlm.h>
#include <acestreamplayer/deprecated.h>

# ifdef __cplusplus
}
# endif

#endif /* _VLC_VLC_H */
