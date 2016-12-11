/*****************************************************************************
 * libvlc_events.h:  libvlc_events external API structure
 *****************************************************************************
 * Copyright (C) 1998-2010 VLC authors and VideoLAN
 * $Id $
 *
 * Authors: Filippo Carone <littlejohn@videolan.org>
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

#ifndef LIBVLC_EVENTS_H
#define LIBVLC_EVENTS_H 1

/**
 * \file
 * This file defines libvlc_event external API
 */

# ifdef __cplusplus
extern "C" {
# endif

/**
 * \ingroup libvlc_event
 * @{
 */

/**
 * Event types
 */
enum libvlc_event_e {
    /* Append new event types at the end of a category.
     * Do not remove, insert or re-order any entry.
     * Keep this in sync with lib/event.c:libvlc_event_type_name(). */
    libvlc_MediaMetaChanged=0,
    libvlc_MediaSubItemAdded,
    libvlc_MediaDurationChanged,
    libvlc_MediaParsedChanged,
    libvlc_MediaFreed,
    libvlc_MediaStateChanged,

    libvlc_MediaPlayerMediaChanged=0x100,
    libvlc_MediaPlayerNothingSpecial,
    libvlc_MediaPlayerOpening,
    libvlc_MediaPlayerBuffering,
    libvlc_MediaPlayerPlaying,
    libvlc_MediaPlayerPaused,
    libvlc_MediaPlayerStopped,
    libvlc_MediaPlayerForward,
    libvlc_MediaPlayerBackward,
    libvlc_MediaPlayerEndReached,
    libvlc_MediaPlayerEncounteredError,
    libvlc_MediaPlayerTimeChanged,
    libvlc_MediaPlayerPositionChanged,
    libvlc_MediaPlayerSeekableChanged,
    libvlc_MediaPlayerPausableChanged,
    libvlc_MediaPlayerTitleChanged,
    libvlc_MediaPlayerSnapshotTaken,
    libvlc_MediaPlayerLengthChanged,
    libvlc_MediaPlayerVout,
    libvlc_MediaPlayerLivePosChanged,           // generated for live broadcast (event description - u.media_player_livepos)
    libvlc_MediaPlayerHotkeyAction,             // event type for hotkey action after libvlc_emit_hotkey (event description - u.media_player_hotkey)

    libvlc_MediaListItemAdded=0x200,
    libvlc_MediaListWillAddItem,
    libvlc_MediaListItemDeleted,
    libvlc_MediaListWillDeleteItem,
    libvlc_MediaListItemSaveFormatChanged,      // generated if save type of acestream media changed (event description - u.media_list_item_saveformat_changed)
    libvlc_MediaListItemHlsStreamsChanged,      // generated if list of hls streams for acestream media is changed
    libvlc_MediaListItemMoved,                  // generated after libvlc_media_list_player_item_move if success (event description - u.media_list_item_moved)

    libvlc_MediaListViewItemAdded=0x300,
    libvlc_MediaListViewWillAddItem,
    libvlc_MediaListViewItemDeleted,
    libvlc_MediaListViewWillDeleteItem,

    libvlc_MediaListPlayerPlayed=0x400,
    libvlc_MediaListPlayerNextItemSet,
    libvlc_MediaListPlayerStopped,

    libvlc_MediaDiscovererStarted=0x500,
    libvlc_MediaDiscovererEnded,

    libvlc_VlmMediaAdded=0x600,
    libvlc_VlmMediaRemoved,
    libvlc_VlmMediaChanged,
    libvlc_VlmMediaInstanceStarted,
    libvlc_VlmMediaInstanceStopped,
    libvlc_VlmMediaInstanceStatusInit,
    libvlc_VlmMediaInstanceStatusOpening,
    libvlc_VlmMediaInstanceStatusPlaying,
    libvlc_VlmMediaInstanceStatusPause,
    libvlc_VlmMediaInstanceStatusEnd,
    libvlc_VlmMediaInstanceStatusError,

    libvlc_AcestreamAuth=0x700,                 // acestrean engine AUTH event (event description - u.acestream_auth)
    libvlc_AcestreamState,                      // acestrean engine STATE event (event description - u.acestream_state)
    libvlc_AcestreamInfo,                       // acestrean engine INFO event (event description - u.acestream_info)
    libvlc_AcestreamStatus,                     // acestrean engine STATUS event (event description - u.acestream_status)
    libvlc_AcestreamError,                      // acestrean engine ERROR event (event description - u.acestream_error)
    libvlc_AcestreamShowUrl,                    // deprecated
    libvlc_AcestreamShowUserDataDialog,         // acestrean engine USERDATA event (without description webplugin must show USERDATADIALOG)
    libvlc_AcestreamShowErrorDialog,            // show error dialog event (event description - u.acestream_showerrordialog)
    libvlc_AcestreamForceExitFullscreen,        // webplugin must close fullscreen window (unneeded)
    libvlc_AcestreamAdParams,                   // advertisements params (event description - u.acestream_adparams)
    libvlc_AcestreamShowPlaylist,               // web plugin must show playlist (for js extensions)
    libvlc_AcestreamStatusRaw,                  // acestream engine STATUS raw data (for js extensions)
    libvlc_AcestreamPreloadPauseUrl,            // preload context ads for pause
    libvlc_AcestreamPreloadNonLinearUrl,        // preload context ads for on video
    libvlc_AcestreamPreloadStopUrl,             // preload context ads for stop
    libvlc_AcestreamPreloadTopLineUrl,          // preload context ads for topline
    libvlc_AcestreamClearPreloadUrl,            //
    libvlc_AcestreamLoadUrl,                    //
    libvlc_AcestreamClearLoadUrl,               //
    libvlc_AcestreamShowInfoWindow,             //
    libvlc_AcestreamRawEngineEvent,             // raw event from acestream engine
};

typedef enum libvlc_hotkey_action_t {
    libvlc_hotkey_None = 0,
    libvlc_hotkey_PlayPause,
    libvlc_hotkey_Play,
    libvlc_hotkey_Pause,
    libvlc_hotkey_Stop,
    libvlc_hotkey_Prev,
    libvlc_hotkey_Next,
    libvlc_hotkey_Slower,
    libvlc_hotkey_Faster,
    libvlc_hotkey_ExitFullscreen,
    libvlc_hotkey_VolUp,
    libvlc_hotkey_VolDown,
    libvlc_hotkey_JumpBackExtraShort,
    libvlc_hotkey_JumpForwardExtraShort,
    libvlc_hotkey_JumpBackShort,
    libvlc_hotkey_JumpForwardShort,
    libvlc_hotkey_JumpBackMedium,
    libvlc_hotkey_JumpForwardMedium,
    libvlc_hotkey_JumpBackLong,
    libvlc_hotkey_JumpForwardLong,
    libvlc_hotkey_FrameNext,
    libvlc_hotkey_ShowPosition,
    libvlc_hotkey_VolMute,
    libvlc_hotkey_SubDelayUp,
    libvlc_hotkey_SubDelayDown,
    libvlc_hotkey_AudioTrack,
    libvlc_hotkey_SubTrack,
    libvlc_hotkey_AudioDelayUp,
    libvlc_hotkey_AudioDelayDown,
    libvlc_hotkey_Snapshot,
    libvlc_hotkey_Record,
    libvlc_hotkey_AspectRatio,
    libvlc_hotkey_Crop,
    libvlc_hotkey_Deinterlace,
    libvlc_hotkey_CropTop,
    libvlc_hotkey_UnCropTop,
    libvlc_hotkey_CropLeft,
    libvlc_hotkey_UnCropLeft,
    libvlc_hotkey_CropBottom,
    libvlc_hotkey_UnCropBottom,
    libvlc_hotkey_CropRight,
    libvlc_hotkey_UnCropRight,
    libvlc_hotkey_RateNormal,
    libvlc_hotkey_RateSlowerFine,
    libvlc_hotkey_RateFasterFine,
} libvlc_hotkey_action_t;
/**
 * A LibVLC event
 */
typedef struct libvlc_event_t
{
    int   type; /**< Event type (see @ref libvlc_event_e) */
    void *p_obj; /**< Object emitting the event */
    union
    {
        /* media descriptor */
        struct
        {
            libvlc_meta_t meta_type;
        } media_meta_changed;
        struct
        {
            libvlc_media_t * new_child;
        } media_subitem_added;
        struct
        {
            int64_t new_duration;
        } media_duration_changed;
        struct
        {
            int new_status;
        } media_parsed_changed;
        struct
        {
            libvlc_media_t * md;
        } media_freed;
        struct
        {
            libvlc_state_t new_state;
        } media_state_changed;

        /* media instance */
        struct
        {
            float new_cache;
        } media_player_buffering;
        struct
        {
            float new_position;
        } media_player_position_changed;
        struct
        {
            libvlc_time_t new_time;
        } media_player_time_changed;
        struct
        {
            int new_title;
        } media_player_title_changed;
        struct
        {
            int new_seekable;
        } media_player_seekable_changed;
        struct
        {
            int new_pausable;
        } media_player_pausable_changed;
        struct
        {
            int new_count;
        } media_player_vout;

        /* media list */
        struct
        {
            libvlc_media_t * item;
            int index;
        } media_list_item_added;
        struct
        {
            libvlc_media_t * item;
            int index;
        } media_list_will_add_item;
        struct
        {
            libvlc_media_t * item;
            int index;
        } media_list_item_deleted;
        struct
        {
            libvlc_media_t * item;
            int index;
        } media_list_will_delete_item;

        /* media list player */
        struct
        {
            libvlc_media_t * item;
        } media_list_player_next_item_set;

        /* snapshot taken */
        struct
        {
             char* psz_filename ;
        } media_player_snapshot_taken ;

        /* Length changed */
        struct
        {
            libvlc_time_t   new_length;
        } media_player_length_changed;

        /* VLM media */
        struct
        {
            const char * psz_media_name;
            const char * psz_instance_name;
        } vlm_media_event;

        /* Extra MediaPlayer */
        struct
        {
            libvlc_media_t * new_media;
        } media_player_media_changed;

        /* acestream */
        struct {
            int auth;           // 0 - user not auth
        } acestream_auth;
        struct {
            int state;          // libvlc_acestream_state_t from libvlc_acestream.h
        } acestream_state;
        struct {
            const char *status; // status message
        } acestream_status;
        struct {
            const char *status; // raw status message from engine (for js only)
        } acestream_status_raw;
        struct {
            const char *data; // raw engine event
        } acestream_raw_engine_event;
        struct {
            const char *info;   // info message
        } acestream_info;
        struct {
            const char *error;  // error message
        } acestream_error;
        struct {
            const char *url;
            const char *text;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;
            int type;
        } acestream_showurl;    // deprecated
        struct {
            const char *clickurl;       // url to show on visit button click
            const char *clicktext;      // text to place on visit button
            const char *skipoffset;     // "hh:mm:ss" or "xx%" time or position to ad can be skipped
            const char *noadsurl;       // url to show if user want diable advertisements
            const char *noadstext;
            const char *adinfotext;
        } acestream_adparams;
        struct {
            const char *title;          // dialog title
            const char *msg;            // dialog text
        } acestream_showerrordialog;
        struct {
            const char *url;
            const char *id;
            bool preload;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;

            bool allow_dialogs;
            bool enable_flash;
            int cookies;
            const char *embed_script;
        } acestream_preloadpauseurl;
        struct {
            const char *url;
            const char *id;
            const char *type;
            const char *creative_type;
            const char *click_url;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;

            bool allow_dialogs;
            bool enable_flash;
            int cookies;
            const char *embed_script;
        } acestream_preloadnonlinearurl;
        struct {
            const char *url;
            const char *id;
            bool preload;
            int fullscreen;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;

            bool allow_dialogs;
            bool enable_flash;
            int cookies;
            const char *embed_script;
        } acestream_preloadstopurl;
        struct {
            const char *url;
            const char *id;
            const char *type;
            const char *creative_type;
            const char *click_url;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;

            bool allow_dialogs;
            bool enable_flash;
            int cookies;
            const char *embed_script;
        } acestream_preloadtoplineurl;
        struct {
            int type;
        } acestream_clearpreloadurl;

        /* media list */
        struct
        {
            libvlc_media_t *item;           // libvlc_media_t descriptor
            int index;                      // index of media in media_list
        } media_list_item_saveformat_changed;
        struct
        {
            libvlc_media_t *item;           // libvlc_media_t descriptor
            int index;                      // index of media in media_list
        } media_list_item_hls_streams_changed;
        struct
        {
            libvlc_media_t *item;           // libvlc_media_t descriptor
            int from;                       // position from
            int to;                         // position to
        } media_list_item_moved;

        /* media player */
        struct {
            bool is_live;
            int live_first;
            int live_last;
            int pos;
            int first_ts;
            int last_ts;
            int last;
            int buffer_pieces;
        } media_player_livepos;             // live broadcast position event (to display input slider correctly)

        struct {
            libvlc_hotkey_action_t type;    // libvlc_hotkey_action_t
        } media_player_hotkey;

        struct {
            int type;
            const char *id;
            const char *url;
            int width;
            int height;
            int left;
            int top;
            int bottom;
            int right;
            bool allow_dialogs;
            bool allow_window_open;
            bool enable_flash;
            int cookies;
            const char *embed_scripts;
            const char *embed_code;

            bool preload;
            int fullscreen;

            const char *content_type;
            const char *creative_type;
            const char *click_url;

            int user_agent;
            int close_after_seconds;
            int show_time;

            bool start_hidden;
            bool url_filter;
            int group_id;
            bool useIE;
        } acestream_loadurl;
        struct {
            const char *type;
            const char *text;
            int height;
            int buttons;
            int btn1_action;
            const char *btn1_text;
            const char *btn1_url;
            int btn2_action;
            const char *btn2_text;
            const char *btn2_url;
        } acestream_showinfowindow;
        struct {
            int type;
        } acestream_clearloadurl;
    } u; /**< Type-dependent event description */
} libvlc_event_t;


/**@} */

# ifdef __cplusplus
}
# endif

#endif /* _LIBVLC_EVENTS_H */
