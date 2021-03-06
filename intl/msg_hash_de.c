/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2017 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stddef.h>

#include <compat/strl.h>
#include <string/stdstring.h>

#include "../msg_hash.h"
#include "../configuration.h"
#include "../verbosity.h"

int menu_hash_get_help_de_enum(enum msg_hash_enums msg, char *s, size_t len)
{
   uint32_t driver_hash = 0;
   settings_t *settings = config_get_ptr();

   if (msg <= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_END &&
       msg >= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN) {
       unsigned idx = msg - MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN;

      switch (idx) {
         case RARCH_FAST_FORWARD_KEY:
            snprintf(s, len,
                  "Schaltet zwischen schnellem Vorlauf und \n"
                  "normaler Spielgeschwindigkeit um."
                  );
            break;
         case RARCH_FAST_FORWARD_HOLD_KEY:
            snprintf(s, len,
                  "Halte die Taste gedrückt, um vorzuspulen.\n"
                  " \n"
                  "Beim Loslassen wird der schnelle Vorlauf beendet."
                  );
            break;
         case RARCH_PAUSE_TOGGLE:
            snprintf(s, len,
                  "Inhalt pausieren und wieder fortsetzen.");
            break;
         case RARCH_FRAMEADVANCE:
            snprintf(s, len,
                  "Einzelbildvorlauf, wenn der Inhalt pausiert ist.");
            break;
         case RARCH_SHADER_NEXT:
            snprintf(s, len,
                  "Wendet den nächsten Shader im Verzeichnis an.");
            break;
         case RARCH_SHADER_PREV:
            snprintf(s, len,
                  "Wendet den vorherigen Shader im Verzeichnis an.");
            break;
         case RARCH_CHEAT_INDEX_PLUS:
         case RARCH_CHEAT_INDEX_MINUS:
         case RARCH_CHEAT_TOGGLE:
            snprintf(s, len,
                  "Cheats.");
            break;
         case RARCH_RESET:
            snprintf(s, len,
                  "Setzt den Inhalt zurück.");
            break;
         case RARCH_SCREENSHOT:
            snprintf(s, len,
                  "Bildschirmfoto anfertigen.");
            break;
         case RARCH_MUTE:
            snprintf(s, len,
                  "Tonwiedergabe stummschalten bzw. Stummschaltung aufheben.");
            break;
         case RARCH_OSK:
            snprintf(s, len,
                  "Bildschirmtastatur ein-/ausschalten.");
            break;
         case RARCH_NETPLAY_FLIP:
            snprintf(s, len,
                  "Netplay-Spieler tauschen.");
            break;
         case RARCH_NETPLAY_GAME_WATCH:
                snprintf(s, len,
                  "Im Netplay zwischen Spiel- und Beobachter-Modus wechseln.");
            break;
         case RARCH_SLOWMOTION:
            snprintf(s, len,
                  "Halte die Taste gedrückt, um die Zeitlupe einzuschalten.");
            break;
         case RARCH_ENABLE_HOTKEY:
            snprintf(s, len,
                  "Andere Hotkeys aktivieren. \n"
                  " \n"
                  "Wenn dieser Hotkey entweder einer\n"
                  "Tastatur, einer Joypad-Taste oder \n"
                  "Joypad-Achse zugeordnet ist, werden alle \n"
                  "anderen Hotkeys nur aktiviert, wenn dieser \n"
                  "Hotkey zur gleichen Zeit gehalten wird. \n"
                  " \n"
                  "Dies ist hilfreich für Implementierungen, die auf \n"
                  "RETRO_KEYBOARD ausgelegt sind und eine große \n"
                  "Fläche auf der Tastatur benötigen, wo es nicht \n"
                  "gewünscht ist, dass es zu Kollisionen mit Hotkeys kommt. \n"
                  " \n"
                  "Alternativ können auch alle Tastatur-Hotkeys durch \n"
                  "den Benutzer deaktiviert werden.");
            break;
         case RARCH_VOLUME_UP:
            snprintf(s, len,
                  "Erhöht die Lautstärke.");
            break;
         case RARCH_VOLUME_DOWN:
            snprintf(s, len,
                  "Verringert die Lautstärke.");
            break;
         case RARCH_OVERLAY_NEXT:
            snprintf(s, len,
                  "Wechselt zum nächsten Overlay.");
            break;
         case RARCH_DISK_EJECT_TOGGLE:
            snprintf(s, len,
                  "Datenträger einbinden/auswerfen. \n"
                  " \n"
                  "Wird für Inhalt verwendet, der auf mehreren Datenträgern ausgeliefert wird. ");
            break;
         case RARCH_DISK_NEXT:
         case RARCH_DISK_PREV:
            snprintf(s, len,
                  "Wechselt durch Datenträger-Abbilder. Nach dem Auswerfen verwenden. \n"
                  " \n"
                  "Zum Abschließen, Datenträger erneut einbinden.");
            break;
         case RARCH_GRAB_MOUSE_TOGGLE:
            snprintf(s, len,
                  "Maus einfangen/freilassen. \n"
                  " \n"
                  "Wenn die Maus eingefangen ist, versteckt RetroArch \n"
                  "die Maus und hält den Mauszeiger im RetroArch-Fenster, \n"
                  "um die Eingabe der Maus zu verbessern.");
            break;
         case RARCH_GAME_FOCUS_TOGGLE:
             snprintf(s, len,
                   "Spiel-Fokus umschalten.\n"
                   " \n"
                   "Wenn ein Spiel fokussiert ist, wird RetroArch die Hotkeys\n"
                   "deaktivieren und den Mauszeiger im RetroArch-Fenster halten.");
             break;
         case RARCH_MENU_TOGGLE:
            snprintf(s, len, "Menü aufrufen.");
            break;
         case RARCH_LOAD_STATE_KEY:
            snprintf(s, len,
                  "Spielstand laden.");
            break;
         case RARCH_FULLSCREEN_TOGGLE_KEY:
            snprintf(s, len,
                  "Vollbildmodus umschalten");
            break;
         case RARCH_QUIT_KEY:
            snprintf(s, len,
                  "Taste zum Beenden von RetroArch. \n"
                  " \n"
                  "Wenn Du RetroArch unsanft beendest (SIGKILL, etc.) wird \n"
                  "RetroArch beendet, ohne Arbeitsspeicher oder ähnliches zu speichern."
#ifdef __unix__
                  "\nAuf unixoiden Systemen erlaubt SIGINT/SIGTERM ein sauberes \n"
                  "Beenden von RetroArch."
#endif
                  "");
            break;
         case RARCH_STATE_SLOT_PLUS:
         case RARCH_STATE_SLOT_MINUS:
            snprintf(s, len,
                  "Speicherplätze. \n"
                  " \n"
                  "Wenn der Speicherplatz 0 ausgewählt wird, ist der Name des Spielstands \n"
                  "*.state (oder was entsprechend auf der Kommandozeile definiert wurde). \n"
                  " \n"
                  "Wenn ein anderer Speicherplatz als 0 gewählt wird, wird das Verzeichnis <path><d> \n"
                  "verwendet, wobei <d> die Nummer des Speicherplatzes ist.");
            break;
         case RARCH_SAVE_STATE_KEY:
            snprintf(s, len,
                  "Spielstand abspeichern.");
            break;
         case RARCH_REWIND:
            snprintf(s, len,
                  "Halte die Taste zum Zurückspulen gedrückt. \n"
                  " \n"
                  "Die Zurückspulfunktion muss eingeschaltet sein.");
            break;
         case RARCH_MOVIE_RECORD_TOGGLE:
            snprintf(s, len,
                  "Aufnahme starten/beenden");
            break;
         default:
            if (string_is_empty(s))
               strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
            break;
      }

      return 0;
   }

   switch (msg)
   {
      case MENU_ENUM_LABEL_ACCOUNTS_RETRO_ACHIEVEMENTS:
         snprintf(s, len, "Anmelde-Daten für dein \n"
               "Retro Achievements-Konto. \n"
               " \n"
               "Besuche retroachievements.org und eröffne \n"
               "ein kostenloses Konto. \n"
               " \n"
               "Nach der Registrierung musst Du deinen \n"
               "Benutzernamen und dein Passwort in RetroArch \n"
               "angeben.");
         break;
      case MENU_ENUM_LABEL_CHEEVOS_USERNAME:
         snprintf(s, len, "Benutzernahme für dein Retro Achievements-Konto.");
         break;
      case MENU_ENUM_LABEL_CHEEVOS_PASSWORD:
         snprintf(s, len, "Passwort für dein Retro Achievements-Konto.");
         break;
      case MENU_ENUM_LABEL_USER_LANGUAGE:
         snprintf(s, len, "Übersetzt das Menü und alle Bildschirm-Meldungen \n"
               "in die Sprache, die Du hier ausgewählt hast. \n"
               " \n"
               "Ein Neustart wird benötigt, um die geänderten \n"
               "Einstellungen zu aktivieren. \n"
               " \n"
               "Hinweis: möglicherweise sind nicht alle Sprachen \n"
               "implementiert. \n"
               " \n"
               "Wenn die gewählte Sprache nicht implementiert ist, \n"
               "wird Englisch als Sprache ausgewählt.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FONT_PATH:
         snprintf(s, len, "Wählt die Schriftart, \n"
               "die für Bildschirm-Meldungen verwendet wird.");
         break;
      case MENU_ENUM_LABEL_GAME_SPECIFIC_OPTIONS:
         snprintf(s, len, "Inhaltsspezifische Core-Einstellungen automatisch laden.");
         break;
      case MENU_ENUM_LABEL_AUTO_OVERRIDES_ENABLE:
         snprintf(s, len, "Überschreibende Konfigurationen automatisch laden.");
         break;
      case MENU_ENUM_LABEL_AUTO_REMAPS_ENABLE:
         snprintf(s, len, "Eingabebelegungsdateien automatisch laden.");
         break;
      case MENU_ENUM_LABEL_SORT_SAVESTATES_ENABLE:
         snprintf(s, len, "Speichert Spielstand-Dateien in Ordnern, \n"
               "die nach dem verwendeten libretro-Core benannt sind.");
         break;
      case MENU_ENUM_LABEL_SORT_SAVEFILES_ENABLE:
         snprintf(s, len, "Speichert Speicherdaten in Ordnern, \n"
               "die nach dem verwendeten libretro-Core benannt sind.");
         break;
      case MENU_ENUM_LABEL_RESUME_CONTENT:
         snprintf(s, len, "Verlässt das Menü und kehrt \n"
               "zum Inhalt zurück.");
         break;
      case MENU_ENUM_LABEL_RESTART_CONTENT:
         snprintf(s, len, "Startet den Inhalt vom Beginn an neu.");
         break;
      case MENU_ENUM_LABEL_CLOSE_CONTENT:
         snprintf(s, len, "Schließt den Inhalt und entlädt ihn aus dem \n"
               "Speicher.");
         break;
      case MENU_ENUM_LABEL_UNDO_LOAD_STATE:
         snprintf(s, len, "Wenn ein Spielstand geladen war, wird der Inhalt \n"
               "zum Status vor dem Laden des Spielstands zurückkehren.");
         break;
      case MENU_ENUM_LABEL_UNDO_SAVE_STATE:
         snprintf(s, len, "Wenn ein Spielstand überschrieben wurde, wird \n"
               "der Inhalt zum vorherigen Spielstand zurückkehren.");
         break;
      case MENU_ENUM_LABEL_TAKE_SCREENSHOT:
         snprintf(s, len, "Fertigt ein Bildschirmfoto an. \n"
               " \n"
               "Das Bildschirmfoto wird im Bildschirmfoto-Verzeichnis \n"
               "gespeichert.");
         break;
      case MENU_ENUM_LABEL_RUN:
         snprintf(s, len, "Startet den Inhalt.");
         break;
      case MENU_ENUM_LABEL_INFORMATION:
         snprintf(s, len, "Zeige zusätzliche Metadaten \n"
               "über den Inhalt an.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_CONFIG:
         snprintf(s, len, "Konfigurationsdatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_COMPRESSED_ARCHIVE:
         snprintf(s, len, "Komprimierte Archivdatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_RECORD_CONFIG:
         snprintf(s, len, "Aufzeichnungs-Konfigurationsdatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_CURSOR:
         snprintf(s, len, "Vorherige Datenbank-Suchanfragen."); /*Maybe a FIXME*/
         break;
      case MENU_ENUM_LABEL_FILE_CONFIG:
         snprintf(s, len, "Konfigurationsdatei.");
         break;
      case MENU_ENUM_LABEL_SCAN_THIS_DIRECTORY:
         snprintf(s, len,
               "Auswählen, um das gewählte Verzeichnis nach Inhalten \n"
               "zu durchsuchen.");
         break;
      case MENU_ENUM_LABEL_USE_THIS_DIRECTORY:
         snprintf(s, len,
               "Dieses Verzeichnis auswählen.");
         break;
      case MENU_ENUM_LABEL_CONTENT_DATABASE_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis für Inhaltsdatenbanken. \n"
               " \n"
               "Verzeichnis, in welchem die Inhaltsdatenbanken \n"
               "gespeichert werden.");
         break;
      case MENU_ENUM_LABEL_THUMBNAILS_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis für Vorschaubilder. \n"
               " \n"
               "Verzeichnis, in welchem die Vorschaubilder \n"
			   "gespeichert werden.");
         break;
      case MENU_ENUM_LABEL_LIBRETRO_INFO_PATH:
         snprintf(s, len,
               "Verzeichnis für Core-Informationsdateien. \n"
               " \n"
               "Ein Verzeichnis, in dem nach \n"
               "libretro-Core-Informationen gesucht wird.");
         break;
      case MENU_ENUM_LABEL_PLAYLIST_DIRECTORY:
         snprintf(s, len,
               "Wiedergabelisten-Verzeichnis. \n"
               " \n"
               "Speichere alle Wiedergabelisten in diesem \n"
               "Verzeichnis.");
         break;
      case MENU_ENUM_LABEL_DUMMY_ON_CORE_SHUTDOWN:
         snprintf(s, len,
               "Einige Cores haben eine \n"
               "Abschalt-Funktion. \n"
               " \n"
               "Wenn diese Option deaktiviert bleibt, \n"
               "wird RetroArch beendet, wenn die Abschalt-Funktion \n"
               "ausgelöst wird. \n"
               " \n"
               "Wenn diese Option aktiviert ist, wird stattdessen \n"
               "ein 'leerer' Core geladen, sodass wir im Menü bleiben \n"
               "und RetroArch nicht beendet wird.");
         break;
      case MENU_ENUM_LABEL_CHECK_FOR_MISSING_FIRMWARE:
         snprintf(s, len,
               "Einige Cores benötigen spezielle \n"
               "Firmware- oder BIOS-Dateien. \n"
               " \n"
               "Wenn diese Option deaktiviert ist, \n"
               "wird versucht, den Core auch zu laden, \n"
               "wenn die Firmware fehlt. \n");
         break;
      case MENU_ENUM_LABEL_PARENT_DIRECTORY:
         snprintf(s, len,
               "Kehre zum übergeordneten Verzeichnis zurück.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_SHADER_PRESET:
         snprintf(s, len,
               "Datei mit Shader-Voreinstellungen.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_SHADER:
         snprintf(s, len,
               "Shader-Datei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_REMAP:
         snprintf(s, len,
               "Eingabebelegungsdatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_CHEAT:
         snprintf(s, len,
               "Cheat-Datei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_OVERLAY:
         snprintf(s, len,
               "Overlay-Datei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_RDB:
         snprintf(s, len,
               "Datenbankdatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_FONT:
         snprintf(s, len,
               "TrueType-Schriftartendatei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_PLAIN_FILE:
         snprintf(s, len,
               "Einfache Datei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_MOVIE_OPEN:
         snprintf(s, len,
               "Video. \n"
               " \n"
               "Auswählen, um diese Datei mit dem \n"
               "Video-Player abzuspielen.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_MUSIC_OPEN:
         snprintf(s, len,
               "Musik. \n"
               " \n"
               "Auswählen, um diese Datei mit dem \n"
               "Musik-Player abzuspielen.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_IMAGE:
         snprintf(s, len,
               "Bild-Datei.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_IMAGE_OPEN_WITH_VIEWER:
         snprintf(s, len,
               "Bild. \n"
               " \n"
               "Auswählen, um diese Datei mit dem \n"
               "Bildbetrachter zu öffnen.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_CORE_SELECT_FROM_COLLECTION:
         snprintf(s, len,
               "libretro-Core. \n"
               " \n"
               "Auswählen, um diesen Core dem Spiel zuzuordnen.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_CORE:
         snprintf(s, len,
               "libretro-Core. \n"
               " \n"
               "Auswählen, um diesen Core in RetroArch zu laden.");
         break;
      case MENU_ENUM_LABEL_FILE_BROWSER_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis. \n"
               " \n"
               "Auswählen, um dieses Verzeichnis zu öffnen.");
         break;
      case MENU_ENUM_LABEL_CACHE_DIRECTORY:
         snprintf(s, len,
               "Zwischenspeicher-Verzeichnis. \n"
               " \n"
               "Von RetroArch entpackter Inhalt wird \n"
               "temporär in diesem Verzeichnis gespeichert.");
         break;
      case MENU_ENUM_LABEL_HISTORY_LIST_ENABLE:
         snprintf(s, len,
               "Wenn aktiviert, wird jeder Inhalt, der in RetroArch \n"
               "geöffnet wird, automatisch in \n"
               "die Verlaufsliste aufgenommen.");
         break;
      case MENU_ENUM_LABEL_RGUI_BROWSER_DIRECTORY:
         snprintf(s, len,
               "Dateibrowser-Verzeichnis. \n"
               " \n"
               "Legt das Verzeichnis fest, in dem der Dateibrowser startet.");
         break;
      case MENU_ENUM_LABEL_INPUT_POLL_TYPE_BEHAVIOR:
         snprintf(s, len,
               "Beeinflusst, wie die Eingabe-Abfrage in \n"
               "RetroArch gehandhabt wird. \n"
               " \n"
               "Früh  - Eingabe wird abgefragt, bevor \n"
               "das aktuelle Frame verarbeitet wird. \n"
               "Normal - Eingabe wird abgefragt, wenn \n"
               "eine Abfrage angefordert wird. \n"
               "Spät   - Eingabe wird abgefragt, wenn \n"
               "die erste Eingabe-Abfrage im Frame angefordert wird.\n"
               " \n"
               "Diese Option auf 'Früh' oder 'Spät' zu setzen kann \n"
               "eine verringerte Latenz bewirken, \n"
               "abhängig von deiner Konfiguration.\n\n"
               "Wenn Netplay aktiviert ist, wird das Standard-Abfrageverhalten \n"
               "(Normal) verwendet. Dieser Wert wird dann nicht berücksichtigt."
               );
         break;
      case MENU_ENUM_LABEL_INPUT_DESCRIPTOR_HIDE_UNBOUND:
         snprintf(s, len,
               "Verstecke Eingabe-Beschreibungen, die nicht vom \n"
               "Core festgelegt werden.");
         break;
      case MENU_ENUM_LABEL_VIDEO_REFRESH_RATE:
         snprintf(s, len,
               "Bildwiederholrate deines Bildschirms. \n"
               "Wird verwendet, um eine geeignete Audio-Eingaberate zu finden.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FORCE_SRGB_DISABLE:
         snprintf(s, len,
               "Unterstützung für sRGB FBO zwangsweise deaktivieren. Einige Intel \n"
               "OpenGL-Treiber unter Windows haben Bildprobleme bei aktivierter \n"
               "sRGB FBO-Unterstützung.");
         break;
      case MENU_ENUM_LABEL_AUDIO_ENABLE:
         snprintf(s, len,
               "Tonausgabe aktivieren.");
         break;
      case MENU_ENUM_LABEL_AUDIO_SYNC:
         snprintf(s, len,
               "Ton synchronisieren (empfohlen).");
         break;
      case MENU_ENUM_LABEL_AUDIO_LATENCY:
         snprintf(s, len,
               "Gewünschte Ton-Latenz in Millisekunden. \n"
               "Wird evtl. nicht berücksichtigt, wenn der Audiotreiber \n"
               "die Latenz nicht zurückmelden kann.");
         break;
      case MENU_ENUM_LABEL_VIDEO_ALLOW_ROTATE:
         snprintf(s, len,
               "Erlaube Core, die Drehung festzulegen. Wenn deaktiviert, \n"
               "werden Dreh-Anfragen angenommen, aber ignoriert. \n\n"
               "Wird in Setups verwendet, in denen der Benutzer den \n"
               "Monitor manuell dreht.");
         break;
      case MENU_ENUM_LABEL_INPUT_DESCRIPTOR_LABEL_SHOW:
         snprintf(s, len,
               "Zeige vom Core festgelegte Eingabe-Beschreibungen anstelle \n"
               "der standardmäßigen an.");
         break;
      case MENU_ENUM_LABEL_CONTENT_HISTORY_SIZE:
         snprintf(s, len,
               "Anzahl der Elemente, die in der \n"
               "Verlaufsliste gespeichert werden.");
         break;
      case MENU_ENUM_LABEL_VIDEO_WINDOWED_FULLSCREEN:
         snprintf(s, len,
               "Legt fest, ob der Fenstermodus verwendet wird oder nicht, \n"
               "wenn das Bild in Vollbild angezeigt werden soll.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FONT_SIZE:
         snprintf(s, len,
               "Schriftgröße für Bildschirm-Meldungen.");
         break;
      case MENU_ENUM_LABEL_SAVESTATE_AUTO_INDEX:
         snprintf(s, len,
               "Erhöht den Speicherplatz-Index bei jedem Speichervorgang, \n"
               "sodass mehrere Spielstand-Dateien erzeugt werden. \n"
               "Wenn der Inhalt geladen ist, wird der Speicherplatz-Index \n"
               "auf den höchsten existierenden Wert gesetzt (neuester Spielstand).");
         break;
      case MENU_ENUM_LABEL_FPS_SHOW:
         snprintf(s, len,
               "Aktiviert die Anzeige der aktuellen Bilder \n"
               "pro Sekunde.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FONT_ENABLE:
         snprintf(s, len,
               "Zeige und/oder verstecke Bildschirm-Meldungen.");
         break;
      case MENU_ENUM_LABEL_VIDEO_MESSAGE_POS_X:
      case MENU_ENUM_LABEL_VIDEO_MESSAGE_POS_Y:
         snprintf(s, len,
               "Legt den Versatz für die Anzeige von Bildschirm-Meldungen \n"
               "fest. Gültige Werte liegen im Bereich [0.0 bis 1.0].");
         break;
      case MENU_ENUM_LABEL_INPUT_OVERLAY_ENABLE:
         snprintf(s, len,
               "Aktiviert oder deaktiviert das aktuelle Overlay.");
         break;
      case MENU_ENUM_LABEL_INPUT_OVERLAY_HIDE_IN_MENU:
         snprintf(s, len,
               "Verhindert, dass das aktuelle Overlay im \n"
               "Menü angezeigt wird.");
         break;
      case MENU_ENUM_LABEL_OVERLAY_PRESET:
         snprintf(s, len,
               "Pfad zum Eingabe-Overlay.");
         break;
      case MENU_ENUM_LABEL_OVERLAY_OPACITY:
         snprintf(s, len,
               "Overlay-Deckkraft");
         break;
      case MENU_ENUM_LABEL_INPUT_BIND_TIMEOUT:
         snprintf(s, len,
               "Zeitlimit für Eingabe-Belegungen (in Sekunden). \n"
               "Anzahl der Sekunden, die gewartet werden soll, \n"
               "bis zur nächsten Belegung gewechselt wird.");
         break;
      case MENU_ENUM_LABEL_OVERLAY_SCALE:
         snprintf(s, len,
               "Overlay-Skalierung.");
         break;
      case MENU_ENUM_LABEL_AUDIO_OUTPUT_RATE:
         snprintf(s, len,
               "Audio-Abtastrate.");
         break;
      case MENU_ENUM_LABEL_VIDEO_SHARED_CONTEXT:
         snprintf(s, len,
               "Aktivieren, wenn Hardware-beschleunigte Cores \n"
               "ihren eigenen privaten Kontext bekommen sollen. \n"
               "Dies verhindert, dass Änderungen des Geräte-Status \n"
               "zwischen den Einzelbildern geschätzt werden müssen."
               );
         break;
      case MENU_ENUM_LABEL_CORE_LIST:
         snprintf(s, len,
               "Lade Core. \n"
               " \n"
               "Suche nach einer libretro-Core-Implementierung. \n"
               "In welchem Verzeichnis der Browser beginnt, \n"
               "hängt von deinem Core-Verzeichnispfad \n"
               "ab. Ist dieser nicht eingestellt, wird im Wurzelverzeichnis begonnen. \n"
               " \n"
               "Ist als Core-Verzeichnis ein Ordner ausgewählt, wird \n"
               "das Menü diesen als Startverzeichnis nutzen. \n"
               "Ist das Core-Verzeichnis ein vollständiger Pfad, wird \n"
               "es in dem Ordner beginnen, in welchem sich die Datei befindet.");
         break;
      case MENU_ENUM_LABEL_VALUE_MENU_ENUM_CONTROLS_PROLOG:
         snprintf(s, len,
               "Du kannst folgende Steuerelemente mit\n"
               "deinem Controller oder deiner Tastatur verwenden\n"
               "um durch das Menü zu navigieren: \n"
               " \n"
               );
         break;
      case MENU_ENUM_LABEL_WELCOME_TO_RETROARCH:
         snprintf(s, len,
               "Willkommen bei RetroArch\n"
               );
         break;
      case MENU_ENUM_LABEL_VALUE_HELP_AUDIO_VIDEO_TROUBLESHOOTING_DESC:
         {
            /* Work around C89 limitations */
            char u[501];
            const char * t =
                  "RetroArch verwendet eine einzigartige Form der\n"
                  "Audio/Video-Synchronisierung. Diese muss\n"
                  "an die Bildwiederholrate deines Bildschirms angepasst werden,\n"
                  "um die bestmögliche Leistung zu erhalten.\n"
                  " \n"
                  "Treten Probleme wie eine knackende Ton-Wiedergabe oder\n"
                  "eine unregelmäßige Bildwiedergabe auf, bedeutet dies in der Regel,\n"
                  "dass Du die Einstellungen kalibrieren musst. Du hast folgende Möglichkeiten:\n"
                  " \n";
            snprintf(u, sizeof(u), /* can't inline this due to the printf arguments */
                  "a) Gehe zu '%s' -> '%s', und aktiviere\n"
                  "'Threaded Video'. Die Bildwiederholrate wird in diesem\n"
                  "Modus nicht berücksichtigt. Die Bildwiederholrate wird höher,\n"
                  "aber die Video-Darstellung wird eventuell weniger flüssig.\n"
                  "b) Gehe zu '%s' -> '%s', und schaue nach\n"
                  "'%s'. Lass' es für \n"
                  "2048 Frames laufen, dann drücke auf 'OK'.",
                  msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
                  msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_SETTINGS),
                  msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
                  msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_SETTINGS),
                  msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_REFRESH_RATE_AUTO));
            strlcpy(s, t, len);
            strlcat(s, u, len);
         }
         break;
      case MENU_ENUM_LABEL_VALUE_HELP_SCANNING_CONTENT_DESC:
         snprintf(s, len,
               "Um nach Inhalten zu suchen, gehe zu '%s' und\n"
               "wähle '%s' oder %s'.\n"
               " \n"
               "Die Dateien werden werden mit einer Datenbank abgeglichen.\n"
               "Bei einem Treffer wird die Datei zu einer Sammlung\n"
               "hinzugefügt.\n"
               " \n"
               "Du kannst diese Inhalte einfach aufrufen, indem Du\n"
               "zu'%s' ->\n"
               "'%s'\n gehst,"
               "anstatt jedes Mal den Dateibrowser\n"
               "verwenden zu müssen.\n"
               " \n"
               "HINWEIS: Inhalte für einige Cores können möglicherweise\n"
               "noch nicht durchsucht werden."
               ,
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_ADD_CONTENT_LIST),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SCAN_DIRECTORY),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SCAN_FILE),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LOAD_CONTENT_LIST),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_CONTENT_COLLECTION_LIST)
               );
         break;
      case MENU_ENUM_LABEL_VALUE_EXTRACTING_PLEASE_WAIT:
         snprintf(s, len,
               "Willkommen bei RetroArch \n"
               "\n"
               "Extrahiere Assets, bitte warten.\n"
               "Dies kann eine Weile dauern...\n"
               );
         break;
      case MENU_ENUM_LABEL_INPUT_DRIVER:
         if (settings)
            driver_hash = msg_hash_calculate(settings->input.driver);

         switch (driver_hash)
         {
            case MENU_LABEL_INPUT_DRIVER_UDEV:
               snprintf(s, len,
                     "udev-Eingabetreiber. \n"
                     " \n"
                     "Dieser Treiber kann ohne X ausgeführt werden. \n"
                     " \n"
                     "Er verwende die neue evdev-Joypad-API \n"
                     "für die Joystick-Unterstützung und unterstützt \n"
                     "auch Hotplugging und Force-Feedback (wenn das \n"
                     "Gerät dies unterstützt). \n"
                     " \n"
                     "Der Treiber liest evdev-Ereignisse für die Tastatur- \n"
                     "Unterstützung und kann auch mit Tastatur-Callbacks, \n"
                     "Mäusen und Touchpads umgehen. \n"
                     " \n"
                     "Standardmäßig sind die /dev/input-Dateien in den \n"
                     "meisten Linux-Distribution nur vom Root- \n"
                     "Benutzer lesbar (mode 600). Sie können eine udev- \n"
                     "Regel erstellen, die auch den Zugriff für andere \n"
                     "Benutzer erlaubt."
                     );
               break;
            case MENU_LABEL_INPUT_DRIVER_LINUXRAW:
               snprintf(s, len,
                     "linuxraw-Eingabetreiber. \n"
                     " \n"
                     "Dieser Treiber erfordert eine aktive TTY-Schnittstelle. \n"
                     "Tastatur-Ereignisse werden direkt von der TTY gelesen, \n"
                     "was es einfacher, aber weniger flexibel als udev macht. \n"
                     "Mäuse und ähnliche Geräte werden nicht unterstützt. \n"
                     " \n"
                     "Dieser Treiber verwendet die alte Joystick-API \n"
                     "(/dev/input/js*).");
               break;
            default:
               snprintf(s, len,
                     "Eingabetreiber.\n"
                     " \n"
                     "Abhängig vom Grafiktreiber kann ein anderer Eingabe- \n"
                     "treiber erzwungen werden.");
               break;
         }
         break;
      case MENU_ENUM_LABEL_LOAD_CONTENT_LIST:
         snprintf(s, len,
               "Lade Inhalt. \n"
               "Suche nach Inhalten. \n"
               " \n"
               "Um Inhalte zu laden benötigst Du den passenden \n"
               "libretro-Core und die Inhalts-Datei. \n"
               " \n"
               "Um einzustellen, welcher Ordner standardmäßig \n"
               "geöffnet wird, um nach Inhalten zu suchen, solltest \n"
               "Du das Inhalts-Verzeichnis setzen. Wenn es nicht \n"
               "gesetzt ist, wird es im Hauptverzeichen starten. \n"
               " \n"
               "Der Browser wird nur Dateierweiterungen des \n"
               "zuletzt geladenen Cores zeigen und diesen Core \n"
               "nutzen, wenn Inhalt geladen wird."
               );
         break;
      case MENU_ENUM_LABEL_LOAD_CONTENT_HISTORY:
         snprintf(s, len,
               "Lade Inhalt aus dem Verlauf. \n"
               " \n"
               "Wenn Inhalt geladen wird, wird der Inhalt \n"
               "sowie der dazugehörige Core im Verlauf gespeichert. \n"
               " \n"
               "Der Verlauf wird im selben Verzeichnis wie die \n"
               "RetroArch-Konfigurationsdatei gespeichert. Wenn \n"
               "beim Start keine Konfigurationsdatei geladen wurde, \n"
               "wird keine Verlauf geladen oder gespeichert und nicht \n"
               "im Hauptmenü angezeigt."
               );
         break;
      case MENU_ENUM_LABEL_VIDEO_DRIVER:
         snprintf(s, len,
               "Aktueller Grafiktreiber");

         if (string_is_equal(settings->video.driver, "gl"))
         {
            snprintf(s, len,
                  "OpenGL-Grafiktreiber. \n"
                  " \n"
                  "Dieser Treiber erlaubt es, neben software- \n"
                  "gerenderten Cores auch libretro-GL-Cores zu \n"
                  "verwenden. \n"
                  " \n"
                  "Die Leistung, sowohl bei software-gerenderten, \n"
                  "als auch bei libretro-GL-Cores, hängt von dem \n"
                  "GL-Treiber deiner Grafikkarte ab.");
         }
         else if (string_is_equal(settings->video.driver, "sdl2"))
         {
            snprintf(s, len,
                  "SDL2-Grafiktreiber.\n"
                  " \n"
                  "Dies ist ein SDL2-Grafiktreiber \n"
                  "mit Software-Rendering."
                  " \n"
                  "Die Leistung hängt von der SDL- \n"
                  "Implementierung deiner Plattform ab.");
         }
         else if (string_is_equal(settings->video.driver, "sdl1"))
         {
            snprintf(s, len,
                  "SDL-Grafiktreiber.\n"
                  " \n"
                  "Dies ist ein SDL1.2-Grafiktreiber \n"
                  "mit Software-Rendering."
                  " \n"
                  "Die Leistung ist suboptimal und Du \n"
                  "solltest diesen Treiber nur als letzte \n"
                  "Möglichkeit verwenden.");
         }
         else if (string_is_equal(settings->video.driver, "d3d"))
         {
             snprintf(s, len,
                  "Direct3D-Grafiktreiber. \n"
                  " \n"
                  "Die Leistung bei software-gerenderten \n"
                  "Cores hängt von dem D3D-Treiber deiner \n"
                  "Grafikkarte ab.");
         }
         else if (string_is_equal(settings->video.driver, "exynos"))
         {
            snprintf(s, len,
                  "Exynos-G2D-Grafiktreiber. \n"
                  " \n"
                  "Dies ist ein Low-Level-Exynos-Grafiktreiber. \n"
                  "Er verwendet den G2D-Block in Samsung-Exynos-SoCs \n"
                  "für Blitting-Operationen. \n"
                  " \n"
                  "Die Leistung bei software-gerendeten Cores sollte \n"
                  "optimal sein.");
         }
         else if (string_is_equal(settings->video.driver, "drm"))
         {
            snprintf(s, len,
                  "DRM-Grafiktreiber \n"
                  " \n"
                  "Dies ist ein Low-Level DRM-Grafiktreiber.\n"
                  "Er verwendet libdrm für Hardware-Skalierung und \n"
                  "GPU-Overlays.");
         }
         else if (string_is_equal(settings->video.driver, "sunxi"))
         {
            snprintf(s, len,
                  "Sunxi-G2D-Grafiktreiber\n"
                  " \n"
                  "Dies ist ein Low-Level-Sunxi-Grafiktreiber. \n"
                  "Er verwendet den G2D-Block in Allwinner-SoCs.");
         }
         break;
      case MENU_ENUM_LABEL_AUDIO_DSP_PLUGIN:
         snprintf(s, len,
               "Audio-DSP-Plugin.\n"
               " Verarbeitet Audiodaten, bevor \n"
               "sie zum Treiber gesendet werden."
               );
         break;
      case MENU_ENUM_LABEL_AUDIO_RESAMPLER_DRIVER:
         if (settings)
            driver_hash = msg_hash_calculate(settings->audio.resampler);

         switch (driver_hash)
         {
            case MENU_LABEL_AUDIO_RESAMPLER_DRIVER_SINC:
               snprintf(s, len,
                     "Windowed-SINC-Implementierung.");
               break;
            case MENU_LABEL_AUDIO_RESAMPLER_DRIVER_CC:
               snprintf(s, len,
                     "Convoluted-Kosinus-Implementierung.");
               break;
            default:
               if (string_is_empty(s))
                  strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
               break;
         }
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_PRESET:
         snprintf(s, len,
               "Lade Shader-Voreinstellung. \n"
               " \n"
               " Lade eine Shader-Voreinstellung direkt. \n"
               "Das Shader-Menü wird entsprechend angepasst. \n"
               " \n"
               "Wenn der CGP Skalierungsmethoden verwendet, die nicht \n"
               "einfach sind, (z.B. Quellen-Skalierung, gleicher \n"
               "Skalierungsfaktor für X/Y), ist der angezeigte Skalierungsfaktor \n"
               "im Menü möglicherweise nicht korrekt."
               );
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_SCALE_PASS:
         snprintf(s, len,
               "Für diesen Durchgang skalieren. \n"
               " \n"
               "Der Skalierungsfaktor wird multipliziert, \n"
               "d.h. 2x im ersten Durchgang und 2x im \n"
               "zweiten Durchgang bedeute eine 4x Gesamt- \n"
               "Skalierung."
               " \n"
               "Wenn es im letzten Durchgang einen \n"
               "Skalierungsfaktor gibt, wird das Ergebnis \n"
               "mit dem als 'Standardfilter' eingestellten \n"
               "Filter auf die Bildschirmgröße gestreckt. \n"
               " \n"
               "Wenn 'Ignorieren' eingestellt ist, wird \n"
               "entweder einfache Skalierung oder Vollbild- \n"
               "Streckung verwendet - abhängig davon, ob \n"
               "es der letzte Durchgang ist oder nicht."
               );
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_NUM_PASSES:
         snprintf(s, len,
               "Shader-Durchgänge. \n"
               " \n"
               "RetroArch erlaubt es, verschiedene Shader \n"
               "in verschiedenen Durchgängen miteinander zu \n"
               "kombinieren. \n"
               " \n"
               "Diese Option legt die Anzahl der Shader- \n"
               "Durchgänge fest. Wenn Du die Anzahl auf 0 setzt, \n"
               "verwendest Du einen 'leeren' Shader."
               " \n"
               "Die 'Standardfilter'-Option beeinflusst den \n"
               "Streckungsfilter");
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_PARAMETERS:
         snprintf(s, len,
               "Shader-Parameter. \n"
               " \n"
               "Verändert den momentanen Shader. Wird nicht in \n"
               "der CGP/GLSLP-Voreinstellungs-Datei gespeichert.");
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_PRESET_PARAMETERS:
         snprintf(s, len,
               "Parameter der Shader-Voreinstellung. \n"
               " \n"
               "Verändert die Shader-Voreinstellung, die aktuell \n"
               "im Menü aktiv ist."
               );
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_PASS:
         snprintf(s, len,
               "Pfad zum Shader. \n"
               " \n"
               "Alle Shader mmüssen vom selben Typ sein \n"
               "(z.B. CG, GLSL oder HLSL). \n"
               " \n"
               "Durch das Setzen des Shader-Verzeichnisses \n"
               "legst Du fest, in welchem Verzeichnis der Browser \n"
               "nach Shadern sucht."
               );
         break;
      case MENU_ENUM_LABEL_CONFIG_SAVE_ON_EXIT:
         snprintf(s, len,
               "Speichert die Konfiguration beim Beenden. \n"
               "Hilfreich für das Menü, da Einstellungen geändert \n"
               "werden können. Überschreibt die Konfiguration. \n"
               " \n"
               "#include-Einträge und Kommentare bleiben nicht erhalten. \n"
               " \n"
               "Die Konfigurationsdatei sollte als 'unantastbar' \n"
               "angesehen werden, da es wahrscheinlich ist, \n"
               "dass der Benutzer Änderungen vornimmt \n"
               "und diese nicht ohne Wissen des \n"
               "Benutzers überschrieben werden sollten."
#if defined(RARCH_CONSOLE) || defined(RARCH_MOBILE)
               "\nDies gilt nicht für \n"
               "Konsolen, bei denen eine manuelle \n"
               "Konfiguration keine sinnvolle Option ist. \n"
#endif
               );
         break;
      case MENU_ENUM_LABEL_CONFIRM_ON_EXIT:
         snprintf(s, len, "Bist Du sicher, dass Du RetroArch verlassen möchtest?");
         break;
      case MENU_ENUM_LABEL_SHOW_HIDDEN_FILES:
         snprintf(s, len, "Zeige versteckte Dateien \n"
               "und Ordner.");
         break;
      case MENU_ENUM_LABEL_VIDEO_SHADER_FILTER_PASS:
         snprintf(s, len,
               "Hardware-Filter für diesen Durchgang. \n"
               " \n"
               "Wenn 'Ignorieren' gewählt ist, wird der \n"
               "Standard-Filter verwendet."
               );
         break;
      case MENU_ENUM_LABEL_AUTOSAVE_INTERVAL:
         snprintf(s, len,
               "Speichert den nichtflüchtigen SRAM-Speicher \n"
               "in regelmäßigen Abständen.\n"
               " \n"
               "Sofern nicht anders festgelegt, ist das automatische \n"
               "Speichern standardmäßig deaktiviert. Das Intervall wird \n"
               "in Sekunden angegeben. \n"
               " \n"
               "Ein Wert von 0 deaktiviert das automatische Speichern.");
         break;
      case MENU_ENUM_LABEL_INPUT_BIND_DEVICE_TYPE:
         snprintf(s, len,
               "Typ des Eingabe-Gerätes. \n"
               " \n"
               "Wählt aus, welcher Eingabe-Gerätetyp verwendet wird. \n"
               "Dies ist für den libretro-Core selbst relevat."
               );
         break;
      case MENU_ENUM_LABEL_LIBRETRO_LOG_LEVEL:
         snprintf(s, len,
               "Legt das Log-Level für das \n"
               "(GET_LOG_INTERFACE) der Cores fest. \n"
               " \n"
               " Wenn ein libretro-Core ein Log-Level unterhalb \n"
               " des eingestellten Log-Levels ausgibt, wird \n"
               " dies ignoriert.\n"
               " \n"
               " DEBUG-Logs werden immer ignoriert, außer der \n"
               " ausführliche Ausgabemodus (--verbose) ist aktiviert.\n"
               " \n"
               " DEBUG = 0\n"
               " INFO  = 1\n"
               " WARN  = 2\n"
               " ERROR = 3"
               );
         break;
      case MENU_ENUM_LABEL_STATE_SLOT_INCREASE:
      case MENU_ENUM_LABEL_STATE_SLOT_DECREASE:
         snprintf(s, len,
                  "Speicherplätze. \n"
                  " \n"
                  "Wenn der Speicherplatz auf 0 gesetzt wird, ist der Name des Spielstands \n"
                  "*.state (oder was auf der Kommandozeile definiert wurde). \n"
                  " \n"
                  "Wenn der Speicherplatz nicht auf 0 gesetzt wird, wird das Verzeichnis <path><d>, \n"
                  "gewählt, wobei <d> die Nummer des Speicherplatzes ist.");
         break;
      case MENU_ENUM_LABEL_SHADER_APPLY_CHANGES:
         snprintf(s, len,
               "Shader-Einstellungen übernehmen. \n"
               " \n"
               "Verwende diese Option, um Änderungen an den \n"
               "Shader-Einstellungen zu übernehmen. \n"
               " \n"
               "Da das Ändern der Shader-Optionen \n"
               "einiges an Rechenleistung erfordert, \n"
               "musst Du die Option manuell auslösen. \n"
               " \n"
               "Wenn Du Shader anwendest, werden die Menüeinstellungen \n"
               "in einer temporären Datei gespeichert (entweder \n"
               "menu.cgp oder menu.glslp) und geladen. Die Datei \n"
               "bleibt nach dem Beenden von RetroArch bestehen. Die Datei \n"
               "wird im Shader-Verzeichnis gespeichert."
               );
         break;
      case MENU_ENUM_LABEL_MENU_TOGGLE:
         snprintf(s, len,
               "Menü aufrufen.");
         break;
      case MENU_ENUM_LABEL_GRAB_MOUSE_TOGGLE:
         snprintf(s, len,
                  "Maus einfangen/freilassen. \n"
                  " \n"
                  "Wenn die Maus eingefangen ist, versteckt RetroArch \n"
                  "die Maus und hält den Mauszeiger im RetroArch-Fenster, \n"
                  "um die Eingabe der Maus zu verbessern.");
         break;
      case MENU_ENUM_LABEL_GAME_FOCUS_TOGGLE:
         snprintf(s, len,
                   "Spiel-Fokus umschalten.\n"
                   " \n"
                   "Wenn ein Spiel fokussiert ist, wird RetroArch die Hotkeys\n"
                   "deaktivieren and und den Mauszeiger im RetroArch-Fenster halten.");
         break;
      case MENU_ENUM_LABEL_DISK_NEXT:
         snprintf(s, len,
                  "Wechselt durch Datenträger-Abbilder. Nach dem Auswerfen verwenden. \n"
                  " \n"
                  "Zum Abschließen, Datenträger erneut einbinden.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FILTER:
#ifdef HAVE_FILTERS_BUILTIN
         snprintf(s, len,
               "CPU-basierte Grafikfilter.");
#else
         snprintf(s, len,
               "CPU-basierte Grafikfilter.\n"
               " \n"
               "Pfad zu einer dynamischen Bibliothek.");
#endif
         break;
      case MENU_ENUM_LABEL_AUDIO_DEVICE:
         snprintf(s, len,
               "Überschreibt das Standard-Audiogerät, welches \n"
               "der Audiotreiber verwendet.\n"
               "Dies ist treiberabhängig. z.B.\n"
#ifdef HAVE_ALSA
               " \n"
               "benötigt ALSA ein PCM-Gerät."
#endif
#ifdef HAVE_OSS
               " \n"
               "benötigt OSS einen Pfad (z.B. /dev/dsp)."
#endif
#ifdef HAVE_JACK
               " \n"
               "benötigt JACK Portnamen (z.B. system:playback1\n"
               ",system:playback_2)."
#endif
#ifdef HAVE_RSOUND
               " \n"
               "benötigt RSound eine IP-Adresse zu einem RSound-Server \n"
               " \n"
#endif
               );
         break;
      case MENU_ENUM_LABEL_DISK_EJECT_TOGGLE:
         snprintf(s, len,
                  "Datenträger einbinden/auswerfen. \n"
                  " \n"
                  "Verwendet für Inhalt, der auf mehreren Datenträgern ausgeliefert wird. ");
         break;
      case MENU_ENUM_LABEL_ENABLE_HOTKEY:
         snprintf(s, len,
                  "Andere Hotkeys aktivieren. \n"
                  " \n"
                  "Wenn dieser Hotkey entweder einer\n"
                  "Tastatur, einem Joypad-Taste oder \n"
                  "Joypad-Achse zugeordnet ist, werden alle \n"
                  "anderen Hotkeys nur aktiviert, wenn dieser \n"
                  "Hotkey zur gleichen Zeit gehalten wird. \n"
                  " \n"
                  "Dies ist hilfreich für Implementierungen, die auf \n"
                  "RETRO_KEYBOARD ausgelegt sind und eine große \n"
                  "Fläche auf der Tastatur benötigen, wo es nicht \n"
                  "gewünscht ist, dass es zu Kollisionen mit Hotkeys kommt \n."
                  " \n"
                  "Alternativ können auch alle Tastatur-Hotkeys durch \n"
                  "den Benutzer deaktiviert werden.");
         break;
      case MENU_ENUM_LABEL_REWIND_ENABLE:
         snprintf(s, len,
               "Zurückspulen aktivieren.\n"
               " \n"
               "Dies wird die Leistung negativ beeinflussen, \n"
               "weshalb es standardmäßig deaktiviert ist.");
         break;
      case MENU_ENUM_LABEL_LIBRETRO_DIR_PATH:
         snprintf(s, len,
               "Core-Verzeichnis. \n"
               " \n"
               "Ein Verzeichnis, in welchem nach \n"
               "libretro-Core-Implementierungen gesucht wird.");
         break;
      case MENU_ENUM_LABEL_VIDEO_REFRESH_RATE_AUTO:
         snprintf(s, len,
               "Bildwiederholrate.\n"
               " \n"
               "Die genaue Bildwiederholrate Deines Bildschirms (Hz).\n"
               "Diese wird verwendet, um die Audio-Eingaberate mithilfe \n"
               "der folgenden Formel zu berechnen: \n"
               " \n"
               "audio_input_rate = Spiel-Eingaberate * Bildschirm- \n"
               "Wiederholrate / Spiel-Wiederholrate\n"
               " \n"
               "Wenn die Implementierung keinen Wert liefert, \n"
               "werden aus Kompatiblitätsgründen die Werte für NTSC \n"
               "angenommen.\n"
               " \n"
               "Dieser Wert sollte nahe 60Hz liegen, um Tonsprünge zu vermeiden. \n"
               "Wenn Dein Bildschirm nicht auf 60Hz oder einem ähnlichen Wert läuft, \n"
               "deaktiviere VSync und lasse diese Einstellung unverändert. \n");
         break;
      case MENU_ENUM_LABEL_VIDEO_ROTATION:
         snprintf(s, len,
               "Erzwinge eine bestimmte \n"
               "Bildschirm-Rotation.\n"
               " \n"
               "Diese Drehung wird zu den Drehungen hinzugefügt, \n"
               "die durch den libretro-Core festgelegt werden. (siehe 'Erlaube \n"
               "Bild-Drehung').");
         break;
      case MENU_ENUM_LABEL_VIDEO_SCALE:
         snprintf(s, len,
               "Vollbild-Auflösung.\n"
               " \n"
               "Auflösung von 0 verwendet die \n"
               "Auflösung der Umgebung. \n");
         break;
      case MENU_ENUM_LABEL_FASTFORWARD_RATIO:
         snprintf(s, len,
               "Vorspul-Verhältnis."
               " \n"
               "Die maximale Geschwindigkeit, mit der Inhalt \n"
               "wiedergegeben wird, wenn der schnelle Vorlauf aktiviert ist.\n"
               " \n"
               " (z.B. 5.0 für Inhalt mit 60 FPS => auf 300 FPS \n"
               "begrenzt).\n"
               " \n"
               "RetroArch wird pausieren, um sicherzustellen, \n"
               "dass die maximale Geschwindigkeit nicht überschritten wird.\n"
               "Verlasse dich nicht darauf, dass diese Begrenzung \n"
               "vollkommen zuverlässig ist.");
         break;
      case MENU_ENUM_LABEL_VIDEO_MONITOR_INDEX:
         snprintf(s, len,
               "Legt fest, welcher Bildschirm bevorzugt wird.\n"
               " \n"
               "0 (Standard) bedeutet, dass kein bestimmter Bildschirm \n"
               "bevorzugt wird, 1 und größer (1 stellt den ersten \n"
               "Bildschirm dar), bewirkt, dass RetroArch diesen \n"
               "bestimmten Bildschirm verwenden.");
         break;
      case MENU_ENUM_LABEL_VIDEO_CROP_OVERSCAN:
         snprintf(s, len,
               "Erzwingt das Beschneiden von übertasteten \n"
               "Frames.\n"
               " \n"
               "Das exakte Verhalten dieser Option ist von der \n"
               "Core-Implementierung abhängig.");
         break;
      case MENU_ENUM_LABEL_VIDEO_SCALE_INTEGER:
         snprintf(s, len,
               "Skaliere die Bildwiedergabe nur in ganzzahligen \n"
               "Schritten.\n"
               " \n"
               "Die Basis-Größe hängt von der vom System gemeldeten \n"
               "Geometrie und Seitenverhältnis ab.\n"
               " \n"
               "Wenn 'Seitenverhältnis erzwingen' nicht aktiv ist, wird X/Y \n"
               "unabhängig voneinander ganzzahlig skaliert.");
         break;
      case MENU_ENUM_LABEL_AUDIO_VOLUME:
         snprintf(s, len,
               "Audio-Lautstärke, ausgedrückt in dB.\n"
               " \n"
               " 0 dB ist die normale Lautstärke. Keine Verstärkung wird angewendet.\n"
               "Die Verstärkung kann zur Laufzeit mit 'Lautstärke erhöhen' \n"
               "und 'Lautstärke verringern' angepasst werden.");
         break;
      case MENU_ENUM_LABEL_AUDIO_RATE_CONTROL_DELTA:
         snprintf(s, len,
               "Audioratenkontrolle.\n"
               " \n"
               "Ist dieser Wert 0, wird Ratenkontrolle deaktiviert.\n"
               "Jeder andere Wert steuert die Änderung der \n"
               "Audiorate.\n"
               " \n"
               "Beschreibt, wie weit die Audiorate dynamisch \n"
               "verändert werden kann.\n"
               " \n"
               " Eingaberate ist definiert als: \n"
               " Eingaberate * (1.0 +/- (Ratenkontroll-Wert))");
         break;
      case MENU_ENUM_LABEL_AUDIO_MAX_TIMING_SKEW:
         snprintf(s, len,
               "Maximaler Audioversatz.\n"
               " \n"
               "Definiert die maximale Änderung der Eingaberate.\n"
               "Aktivieren Sie diese Option, wenn Sie \n"
               "umfangreiche Änderungen im Timing wünschen, zum Beispiel\n"
               "um PAL-Cores auf NTSC-Bildschirmen zu spielen.\n"
               "Die Tonhöhe ist dann nicht korrekt.\n"
               " \n"
               " Eingaberate ist definiert als: \n"
               " Eingaberate * (1.0 +/- (Max. Audioversatz))");
         break;
      case MENU_ENUM_LABEL_OVERLAY_NEXT:
         snprintf(s, len,
               "Wechselt zum nächsten Overlay.\n"
               " \n"
               // Translation unclear, disabled for now. Some context would be really helpful.
               // "Wraps around."
               );
         break;
      case MENU_ENUM_LABEL_LOG_VERBOSITY:
         snprintf(s, len,
               "Aktiviert oder deaktiviert ausführliche Ausgabe \n"
               "des Frontends.");
         break;
      case MENU_ENUM_LABEL_VOLUME_UP:
         snprintf(s, len,
               "Erhöht die Lautstärke.");
         break;
      case MENU_ENUM_LABEL_VOLUME_DOWN:
         snprintf(s, len,
               "Verringert die Lautstärke.");
         break;
      case MENU_ENUM_LABEL_VIDEO_DISABLE_COMPOSITION:
         snprintf(s, len,
               "Abschaltung der Desktop-Gestaltung erzwingen.\n"
               "Nur gültig für Windows Vista/7.");
         break;
      case MENU_ENUM_LABEL_PERFCNT_ENABLE:
         snprintf(s, len,
               "Leistungs-Zähler im Frontend aktivieren \n"
               "und deaktivieren.");
         break;
      case MENU_ENUM_LABEL_SYSTEM_DIRECTORY:
         snprintf(s, len,
               "Systemverzeichnis. \n"
               " \n"
               "Bestimmt das 'system'-Verzeichnis. \n"
               "Cores können dieses Verzeichnis verwenden, \n"
               "um BIOS-Dateien, systemspezifische \n"
               "Konfigurationen etc. zu laden. ");
         break;
      case MENU_ENUM_LABEL_SAVESTATE_AUTO_SAVE:
      case MENU_ENUM_LABEL_SAVESTATE_AUTO_LOAD:
         snprintf(s, len,
               "Erstellt einen Spielstand automatisch, \n"
               "wenn RetroArch beendet wird .\n"
               " \n"
               "RetroArch wird Spielstände in diesem Pfad automatisch \n"
               "nach dem Starten laden, wenn 'Spielstand automatisch laden' \n"
               "aktiviert ist.");
         break;
      case MENU_ENUM_LABEL_VIDEO_THREADED:
         snprintf(s, len,
               "Video-Treiber in separatem Thread ausführen.\n"
               " \n"
               "Diese Option kann die Leistung verbessern, \n"
               "verursacht jedoch möglicherweise eine erhöhte Latenz \n"
               "und eine weniger flüssige Video-Ausgabe.");
         break;
      case MENU_ENUM_LABEL_VIDEO_VSYNC:
         snprintf(s, len,
               "Vertikale Synchronisation (VSync).\n");
         break;
      case MENU_ENUM_LABEL_VIDEO_HARD_SYNC:
         snprintf(s, len,
               "Versucht, die CPU und GPU \n"
               "'hart' zu synchronisieren.\n"
               " \n"
               "Dies kann die Latenz verringern, \n"
               "reduziert jedoch möglicherweise die Leistung.");
         break;
      case MENU_ENUM_LABEL_REWIND_GRANULARITY:
         snprintf(s, len,
               "Rückspul-Genauigkeit.\n"
               " \n"
               "Wenn eine festgelegte Anzahl von Frames zurückgespult \n"
               "wird, kannst Du mehrere Frames auf einmal \n"
               "zurückspulen, was die Rückspul-Geschwindigkeit \n"
               "erhöht.");
         break;
      case MENU_ENUM_LABEL_SCREENSHOT:
         snprintf(s, len,
               "Bildschirmfoto anfertigen.");
         break;
      case MENU_ENUM_LABEL_VIDEO_FRAME_DELAY:
         snprintf(s, len,
               "Legt fest, wie viele Millisekunden nach \n"
               "VSync gewartet wird, bevor der Core gestartet wird.\n"
               "\n"
               "Dies kann die Latenz verringern, birgt jedoch\n"
               "ein erhöhtes Risiko für stotternde Videoausgabe.\n"
               " \n"
               "Maximum ist 15.");
         break;
      case MENU_ENUM_LABEL_VIDEO_HARD_SYNC_FRAMES:
         snprintf(s, len,
               "Legt fest, wie viele Frames die CPU \n"
               "vor der GPU bearbeitet, wenn 'GPU-Hardsync' \n"
               "aktiviert ist.\n"
               " \n"
               "Maximum ist 3.\n"
               " \n"
               " 0: Synchronisiert direkt mit der GPU.\n"
               " 1: Synchronisiert zum vorherigen Frame.\n"
               " 2: Etc ...");
         break;
      case MENU_ENUM_LABEL_VIDEO_BLACK_FRAME_INSERTION:
         snprintf(s, len,
               "Fügt ein schwarzes Bild zwischen den einzelnen \n"
               "Frames ein.\n"
               " \n"
               "Hilfreich für 120 Hz-Monitore, wenn \n"
               "60 Hz-Material ohne Ghosting dargestellt \n"
               "werden soll.\n"
               " \n"
               "Die Bildwiederholrate sollte so eingestellt \n"
               "werden, dass sie einem 60 Hz-Monitor entspricht. \n"
               "(Bildwiederholrate durch 2 teilen).");
         break;
      case MENU_ENUM_LABEL_RGUI_SHOW_START_SCREEN:
         snprintf(s, len,
               "Startbildschirm im Menü anzeigen.\n"
               "Wird automatisch deaktiviert, wenn er zum\n"
               "ersten Mal dargestellt wurde.\n"
               " \n"
               "Dies wird nur in die Konfiguration übernommen, wenn\n"
               "'Konfiguration beim Beenden speichern' aktiviert ist.\n");
         break;
      case MENU_ENUM_LABEL_VIDEO_FULLSCREEN:
         snprintf(s, len, "Vollbildmodus umschalten");
         break;
      case MENU_ENUM_LABEL_BLOCK_SRAM_OVERWRITE:
         snprintf(s, len,
               "Verhindert, dass SRAM überschrieben wird, \n"
               "wenn Spielstände geladen werden.\n"
               " \n"
               "Kann zu fehlerhaften Spielen führen.");
         break;
      case MENU_ENUM_LABEL_PAUSE_NONACTIVE:
         snprintf(s, len,
               "Spiel pausieren, wenn Fenster-Fokus \n"
               "verloren ist.");
         break;
      case MENU_ENUM_LABEL_VIDEO_GPU_SCREENSHOT:
         snprintf(s, len,
               "Sofern verfügbar, werden Screenshots \n"
               "aus Bildmaterial nach Shader-Durchgängen erzeugt.");
         break;
      case MENU_ENUM_LABEL_SCREENSHOT_DIRECTORY:
         snprintf(s, len,
               "Bildschirmfoto-Verzeichnis. \n"
               " \n"
               "Verzeichnis, in welchem Bildschirmfotos abgelegt werden."
               );
         break;
      case MENU_ENUM_LABEL_VIDEO_SWAP_INTERVAL:
         snprintf(s, len,
               "Benutzerdefiniertes VSync-Intervall.\n"
               " \n"
               "Verwendet ein benutzerdefiniertes Intervall für VSync. \n"
               "Aktiviert halbiert diese Einstellung die Bildwiederholrate.");
         break;
      case MENU_ENUM_LABEL_SAVEFILE_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis für Speicherdaten. \n"
               " \n"
               "Speichert alle Speicherdaten (*.srm) in diesem \n"
               "Verzeichnis. Dies beinhaltet verwandte Dateitypen wie \n"
               ".bsv, .rt, .psrm, etc...\n"
               " \n"
               "Explizite Optionen über die Kommandozeile überschreiben \n"
               "diese Einstellung.");
         break;
      case MENU_ENUM_LABEL_SAVESTATE_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis für Spielstände. \n"
               " \n"
               "Speichert alle Spielstände (*.state) in diesem \n"
               "Verzeichnis.\n"
               " \n"
               "Explizite Optionen über die Kommandozeile überschreiben \n"
               "diese Einstellung.");
         break;
      case MENU_ENUM_LABEL_ASSETS_DIRECTORY:
         snprintf(s, len,
               "Assets-Verzeichnis. \n"
               " \n"
               "Dieses Verzeichnis wird standardmäßig vom Menü \n"
               "verwendet, um dort nach ladbaren Inhalten wie Assets \n"
               "etc. zu suchen.");
         break;
      case MENU_ENUM_LABEL_DYNAMIC_WALLPAPERS_DIRECTORY:
         snprintf(s, len,
               "Verzeichnis für dynamische Hintergrundbilder. \n"
               " \n"
               "In diesem Verzeichnis werden Hintergrundbilder \n"
               "abgelegt, die vom Menü dynamisch abhängig vom \n"
               "Kontext geladen werden.");
         break;
      case MENU_ENUM_LABEL_SLOWMOTION_RATIO:
         snprintf(s, len,
               "Verhältnis für Zeitlupe. \n"
               " \n"
               "Ist die Zeitlupe eingeschaltet, wird das Spiel \n"
               "um diesen Faktor verlangsamt.");
         break;
      case MENU_ENUM_LABEL_INPUT_AXIS_THRESHOLD:
         snprintf(s, len,
               "Definiert Achsen-Grenzwert.\n"
               " \n"
               "Wie weit eine Achse bewegt werden muss, um einen \n"
               "Tastendruck auszulösen .\n"
               "Mögliche Werte liegen im Bereich [0.0, 1.0].");
         break;
      case MENU_ENUM_LABEL_INPUT_TURBO_PERIOD:
         snprintf(s, len,
               "Turbo-Frequenz.\n"
               " \n"
               "Beschreibt, wie oft Tasten, für die der Turbo \n"
               "aktiviert ist, ausgelöst werden.\n"
               " \n"
               "Dieser Wert wird in der Anzahl der Einzelbilder angegeben."
               );
         break;
      case MENU_ENUM_LABEL_INPUT_DUTY_CYCLE:
         snprintf(s, len,
               "Turbo-Dauer.\n"
               " \n"
               "Beschreibt, wie lange Tasten, für die der Turbo \n"
               "aktiviert ist, gehalten werden sollen.\n"
               " \n"
               "Dieser Wert wird in der Anzahl der Einzelbilder angegeben."
               );
         break;
      case MENU_ENUM_LABEL_INPUT_TOUCH_ENABLE:
         snprintf(s, len, "Touch-Unterstützung aktivieren.");
         break;
      case MENU_ENUM_LABEL_INPUT_PREFER_FRONT_TOUCH:
         snprintf(s, len, "Touch-Eingabe auf der Vorderseite bevorzugen.");
         break;
      case MENU_ENUM_LABEL_MOUSE_ENABLE:
         snprintf(s, len, "Maussteuerung im Menü aktivieren.");
         break;
      case MENU_ENUM_LABEL_POINTER_ENABLE:
         snprintf(s, len, "Touch-Steuerung im Menü aktivieren.");
         break;
      case MENU_ENUM_LABEL_MENU_WALLPAPER:
         snprintf(s, len, "Pfad zu einem Bild, welches als Hintergrundbild verwendet werden soll.");
         break;
      case MENU_ENUM_LABEL_NAVIGATION_WRAPAROUND:
         snprintf(s, len,
               "Am Anfang und/oder dem Ende einer Liste umbrechen, \n"
               "wenn die Grenzen der Liste horizontal und/oder \n"
               "vertikal erreicht werden.");
         break;
      case MENU_ENUM_LABEL_PAUSE_LIBRETRO:
         snprintf(s, len,
               "Wenn deaktiviert wird der libretro-Core im \n"
               "Hintergrund weiter laufen, wenn wir uns \n"
               "im Menü befinden.");
         break;
      case MENU_ENUM_LABEL_SUSPEND_SCREENSAVER_ENABLE:
         snprintf(s, len,
               "Deaktiviert den Bildschirmschoner. Diese Einstellung \n"
               "wird möglicherweise vom Video-Treiber nicht \n"
               "berücksichtigt.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_MODE:
         snprintf(s, len,
               "Netplay-Client-Modus für den aktuellen Benutzer. \n"
               "Wird zu 'Server'-Modus, wenn deaktiviert.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_DELAY_FRAMES:
         snprintf(s, len,
               "Anzahl der Verzögerungs-Frames für Netplay. \n"
               " \n"
               "Wird dieser Wert erhöht, verbessert sich \n"
               "die Leistung, die Latenz erhöht sich jedoch.");
        case MENU_ENUM_LABEL_NETPLAY_STATELESS_MODE: /* Maybe FIXME*/
            snprintf(s, len,
                     "Legt fest, ob Netplay in einem Modus laufen soll, der keine\n"
                             "Savestates benötigt. \n"
                             " \n"
                             "Wenn diese Option eingeschaltet wird, wird ein sehr \n"
                             "schnelles Netzwerk benötigt. Da kein Rücklauf benötigt wird, \n"
                             "tritt keine Netplay-Verzögerung auf.\n");
            break;
         break;
      case MENU_ENUM_LABEL_NETPLAY_CHECK_FRAMES:
         snprintf(s, len,
               "Die Frequenz in Einzelbildern, mit der Netplay \n"
               "sicherstellen wird, dass Host und Clients \n"
               "synchronisiert sind. \n"
               " \n"
               "Bei den meisten Cores wird diese Einstellungen \n"
               "keine sichtbaren Auswirkungen haben und kann ignoriert werden. \n"
               "Bei nichtdeterministischen Cores legt dieser Wert fest, \n"
               "wie oft die Netplay-Mitglieder miteinander synchronisiert \n"
               "werden. Bei fehlerhaften Cores wird ein \n"
               "anderer Wert als 0 für diese Einstellung erhebliche \n"
               "Leistungsprobleme verursachen. Auf 0 setzen, um keine \n"
               "Überprüfungen durchzuführen. Diese Einstellung wird nur \n"
               "auf dem Netplay-Host verwendet. \n");
         break;
        case MENU_ENUM_LABEL_NETPLAY_INPUT_LATENCY_FRAMES_MIN:
            snprintf(s, len,
                     "Legt die Eingabeverzögerung in Einzelbildern fest, \n"
                     "die Netplay verwendet, um die Netzwerklatenz zu verstecken. \n"
                     " \n"
                     "In einem Multiplayer-Spiel verzögert diese Option die lokale \n"
                     "Eingabe, sodass das aktuelle Einzelbild \n"
                     "näher an dem Einzelbild liegt, welches vom Netzwerk \n"
                     "empfangen wird. Dies verbessert die Netplay-Performance \n"
                     "und  benötigt weniger CPU-Leistung, verursacht \n"
                     "jedoch eine spürbare Eingabe-Verzögerung. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_INPUT_LATENCY_FRAMES_RANGE:
            snprintf(s, len,
                     "Legt den Bereich in Einzelbildern fest, die von \n"
                     "Netplay für die Eingabeverzögerung verwendet werden, \n"
                     "um die Netzwerklatenz zu verstecken. \n"
                     "\n"
                     "Wenn aktiviert, wird Netplay die Eingabeverzögerung \n"
                     "in Einzelbildern dynamisch anpassen, um \n"
                     "die CPU-Zeit, Eingabeverzögerung und \n"
                     "Netzwerklatenz auszubalancieren. Dies verbessert \n"
                     "die Netplay-Performance und benötigt weniger CPU-Leistung, \n"
                     "verursacht jedoch eine Eingabe-Verzögerung, die nicht vorhergesagt werden kann. \n");
            break;
      case MENU_ENUM_LABEL_NETPLAY_NAT_TRAVERSAL:
         snprintf(s, len,
               "Versuche, beim Hosten eines Spiels auf eingehende \n"
               "Verbindungen aus dem öffentlichen Internet zu hören. \n"
               "Dabei werden UPnP oder ähnliche Techniken verwendet, \n"
               "um das eigene LAN zu verlassen. \n");
         break;
      case MENU_ENUM_LABEL_VIDEO_MAX_SWAPCHAIN_IMAGES:
         snprintf(s, len,
               "Maximale Zahl von Zwischenbildern. Diese Einstellung \n"
               "kann dem Video-Treiber vorschreiben, einen bestimmten \n"
               "Videopuffer-Modus zu verwenden. \n"
               " \n"
               "Einfache Pufferung - 1\n"
               "Doppelte Pufferung - 2\n"
               "Dreifache Pufferung - 3\n"
               " \n"
               "Den richtigen Puffer-Modus auzuwählen \n"
               "kann einen großen Einfluss auf die Leistung nehmen.");
         break;
      case MENU_ENUM_LABEL_VIDEO_SMOOTH:
         snprintf(s, len,
               "Bild mit bilinearer Filterung glätten. \n"
               "Sollte deaktiviert werden, wenn Shader verwendet werden.");
         break;
      case MENU_ENUM_LABEL_TIMEDATE_ENABLE:
         snprintf(s, len,
               "Zeigt das aktuelle Datum/die aktuelle Zeit im Menü an.");
         break;
        case MENU_ENUM_LABEL_BATTERY_LEVEL_ENABLE:
            snprintf(s, len,
                "Zeigt den aktuellen Ladezustand des Akkus im Menü an.");
            break;
      case MENU_ENUM_LABEL_CORE_ENABLE:
         snprintf(s, len,
               "Zeigt den aktuellen Core im Menü an.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_ENABLE_HOST:
         snprintf(s, len,
               "Aktiviert Netplay im Host-(Server)-Modus.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_ENABLE_CLIENT:
         snprintf(s, len,
               "Aktiviert Netplay im Client-Modus.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_DISCONNECT:
         snprintf(s, len,
               "Bestehende Netplay-Verbindung beenden.");
         break;
        case MENU_ENUM_LABEL_NETPLAY_LAN_SCAN_SETTINGS:
            snprintf(s, len,
               "Suche nach einem Netplay-Host im lokalen Netzwerk und stelle eine Verbindung zu diesem her.");
            break;
      case MENU_ENUM_LABEL_NETPLAY_SETTINGS:
         snprintf(s, len,
               "Netplay-bezogene Einstellungen.");
         break;
      case MENU_ENUM_LABEL_DYNAMIC_WALLPAPER:
         snprintf(s, len,
               "Lade ein neues Hintergrundbild dynamisch, \n"
               "abhängig vom aktuellen Kontext.");
         break;
      case MENU_ENUM_LABEL_CORE_UPDATER_BUILDBOT_URL:
         snprintf(s, len,
               "URL zum Core-Verzeichnis auf dem \n"
               "libretro-Server.");
         break;
      case MENU_ENUM_LABEL_BUILDBOT_ASSETS_URL:
         snprintf(s, len,
               "URL zum Assets-Verzeichnis auf dem \n"
               "libretro-Server.");
         break;
      case MENU_ENUM_LABEL_INPUT_REMAP_BINDS_ENABLE:
         snprintf(s, len,
               "Wenn aktiviert, werden die aktuellen Tastenbelegungen \n"
               "mit den neu zugewiesenen Belegungen für den \n"
               "aktuellen Core überschrieben.");
         break;
      case MENU_ENUM_LABEL_OVERLAY_DIRECTORY:
         snprintf(s, len,
               "Overlay-Verzeichnis. \n"
               " \n"
               "Definiert ein Verzeichnis, in dem alle Overlays \n"
               "aufbewahrt werden.");
         break;
      case MENU_ENUM_LABEL_INPUT_MAX_USERS:
         snprintf(s, len,
               "Maximale Anzahl von Benutzern, die in \n"
               "RetroArch unterstützt werden.");
         break;
      case MENU_ENUM_LABEL_CORE_UPDATER_AUTO_EXTRACT_ARCHIVE:
         snprintf(s, len,
               "Entpacke Archive, die heruntergeladenen Inhalt \n"
               "enthalten, nach dem Herunterladen \n"
               "automatisch.");
         break;
      case MENU_ENUM_LABEL_NAVIGATION_BROWSER_FILTER_SUPPORTED_EXTENSIONS_ENABLE:
         snprintf(s, len,
               "Filtere die angezeigten Dateien nach \n"
               "unterstützten Dateierweiterungen.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_NICKNAME:
         snprintf(s, len,
               "Der Benutzername der Person, die RetroArch verwendet. \n"
               "Wird in Online-Spielen verwendet.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_CLIENT_SWAP_INPUT:
         snprintf(s, len,
               "Verwende Tastenbelegung für Spieler 1, \n"
               "wenn Du Teilnehmer an einem Netplay-Spiel bist.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_TCP_UDP_PORT:
         snprintf(s, len,
               "Der Port der Host-IP-Adresse. \n"
               "Kann entweder ein TCP- oder ein UDP-Port sein.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_SPECTATOR_MODE_ENABLE:
         snprintf(s, len,
               "Aktiviere oder deaktiviere Beobachter-Modus\n"
               "für den Benutzer im Netplay-Spiel.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_IP_ADDRESS:
         snprintf(s, len,
               "Die Addresse des Hosts, zu dem verbunden werden soll.");
         break;
        case MENU_ENUM_LABEL_NETPLAY_PASSWORD:
            snprintf(s, len,
                     "Das Passwort, welches für die Verbindung mit dem Netplay-Host \n"
                             "verwendet wird. Wird nur im Host-Modus verwendet.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_SPECTATE_PASSWORD:
            snprintf(s, len,
                     "Das Passwort, welches für die Verbindung mit dem Netplay-Host \n"
                             "und ausschließlich mit Beobachter-Privilegien verwendet wird. \n"
                             "Wird nur im Host-Modus verwendet.");
            break;
      case MENU_ENUM_LABEL_STDIN_CMD_ENABLE:
         snprintf(s, len,
               "Aktiviere stdin-Kommandozeile.");
         break;
      case MENU_ENUM_LABEL_UI_COMPANION_START_ON_BOOT:
         snprintf(s, len,
               "Starte begleitenden Treiber für Benutzeroberfläche \n"
               "während des Bootens (wenn verfügbar).");
         break;
      case MENU_ENUM_LABEL_MENU_DRIVER:
         snprintf(s, len, "Menü-Treiber, der verwendet werden soll.");
         break;
      case MENU_ENUM_LABEL_INPUT_MENU_ENUM_TOGGLE_GAMEPAD_COMBO:
         snprintf(s, len,
               "Gamepad-Tastenkombination, um Menü aufzurufen. \n"
               " \n"
               "0 - Keine \n"
               "1 - Drücke L + R + Y + D-Pad nach unten \n"
               "gleichzeitig. \n"
               "2 - Drücke L3 + R3 gleichzeitig. \n"
               "3 - Drücke Start + Select gleichzeitig.");
         break;
      case MENU_ENUM_LABEL_INPUT_ALL_USERS_CONTROL_MENU:
         snprintf(s, len, "Erlaubt jedem Benutzer, das Menü zu steuern. \n"
               " \n"
               "Wenn deaktiviert, kann nur Benutzer 1 das Menü steuern.");
         break;
      case MENU_ENUM_LABEL_INPUT_AUTODETECT_ENABLE:
         snprintf(s, len,
               "Aktiviere automatische Eingabe-Erkennung.\n"
               " \n"
               "Wird versuchen, Joypads automatisch zu konfigurieren. \n"
               "(Plug-and-Play).");
         break;
      case MENU_ENUM_LABEL_CAMERA_ALLOW:
         snprintf(s, len,
               "Erlaubt oder verbietet den Cores Zugriff auf \n"
               "die Kamera.");
         break;
      case MENU_ENUM_LABEL_LOCATION_ALLOW:
         snprintf(s, len,
               "Erlaubt oder verbietet den Cores Zugriff \n"
               "auf Ortungsdienste.");
         break;
      case MENU_ENUM_LABEL_TURBO:
         snprintf(s, len,
               "Aktiviert den Turbo.\n"
               " \n"
               "Wird die Turbo-Taste gedrückt, während eine andere Taste \n"
               "gedrückt wird, wird für diese Taste der Turbo-Modus aktiviert. \n"
               "Im Turbo-Modus wird die Taste innerhalb der Emulation \n"
               "automatisch wiederholt gedrückt und wieder losgelassen. \n"
               " \n"
               "Der Turbo-Modus wird beendet, wenn die Taste \n"
               "selbst (nicht die Turbo-Taste) losgelassen wird.");
         break;
      case MENU_ENUM_LABEL_OSK_ENABLE:
         snprintf(s, len,
               "Bildschirmtastatur ein/ausschalten.");
         break;
      case MENU_ENUM_LABEL_AUDIO_MUTE:
         snprintf(s, len,
               "Ton stumm/lautschalten.");
         break;
      case MENU_ENUM_LABEL_REWIND:
         snprintf(s, len,
               "Taste zum Zurückspulen gedrückt halten.\n"
               " \n"
               "Die Rücklauf-Funktion muss aktiviert sein.");
         break;
      case MENU_ENUM_LABEL_EXIT_EMULATOR:
         snprintf(s, len,
               "Taste zum sauberen Beenden von RetroArch."
#if !defined(RARCH_MOBILE) && !defined(RARCH_CONSOLE)
               "\nWenn Du RetroArch 'unsanft' beendest (SIGKILL, \n"
               "etc), werden RAM-Speicher etc. nicht gespeichert.\n"
               "Auf Unix-ähnlichen Systemen erlaubt\n"
               "SIGINT/SIGTERM ein sauberes\n"
               "Beenden."
#endif
               );
         break;
      case MENU_ENUM_LABEL_LOAD_STATE:
         snprintf(s, len,
               "Lädt Save-State.");
         break;
      case MENU_ENUM_LABEL_SAVE_STATE:
         snprintf(s, len,
               "Speichert Save-State.");
         break;
      case MENU_ENUM_LABEL_NETPLAY_FLIP_PLAYERS:
         snprintf(s, len,
               "Netplay-Benutzer vertauschen.");
         break;
      case MENU_ENUM_LABEL_CHEAT_INDEX_PLUS:
         snprintf(s, len,
               "Cheat-Index erhöhen.\n");
         break;
      case MENU_ENUM_LABEL_CHEAT_INDEX_MINUS:
         snprintf(s, len,
               "Cheat-Index verringern.\n");
         break;
      case MENU_ENUM_LABEL_SHADER_PREV:
         snprintf(s, len,
               "Wendet den vorherigen Shader im Verzeichnis an.");
         break;
      case MENU_ENUM_LABEL_SHADER_NEXT:
         snprintf(s, len,
               "Wendet den nächsten Shader im Verzeichnis an.");
         break;
      case MENU_ENUM_LABEL_RESET:
         snprintf(s, len,
               "Inhalt zurücksetzen.\n");
         break;
      case MENU_ENUM_LABEL_PAUSE_TOGGLE:
         snprintf(s, len,
               "Inhalt pausieren und wieder fortsetzen.");
         break;
      case MENU_ENUM_LABEL_CHEAT_TOGGLE:
         snprintf(s, len,
               "Cheat-Index ein-/ausschalten.\n");
         break;
      case MENU_ENUM_LABEL_HOLD_FAST_FORWARD:
         snprintf(s, len,
               "Zum Vorspulen gedrückt halten. Wird die Taste \n"
               "losgelassen, wird der schnelle Vorlauf beendet.");
         break;
      case MENU_ENUM_LABEL_SLOWMOTION:
         snprintf(s, len,
               "Gedrückt halten für Zeitlupe.");
         break;
      case MENU_ENUM_LABEL_FRAME_ADVANCE:
         snprintf(s, len,
               "Einzelbild-Vorlauf, wenn Inhalt pausiert ist.");
         break;
      case MENU_ENUM_LABEL_MOVIE_RECORD_TOGGLE:
         snprintf(s, len,
               "Aufnahme starten/beenden.");
         break;
      case MENU_ENUM_LABEL_L_X_PLUS:
      case MENU_ENUM_LABEL_L_X_MINUS:
      case MENU_ENUM_LABEL_L_Y_PLUS:
      case MENU_ENUM_LABEL_L_Y_MINUS:
      case MENU_ENUM_LABEL_R_X_PLUS:
      case MENU_ENUM_LABEL_R_X_MINUS:
      case MENU_ENUM_LABEL_R_Y_PLUS:
      case MENU_ENUM_LABEL_R_Y_MINUS:
         snprintf(s, len,
               "Achse für Analog-Stick (DualShock-artig).\n"
               " \n"
               "Zugewiesen wie gewöhnlich, wenn jedoch eine echte \n"
               "Analogachse zugewiesen wird, kann sie auch wirklich \n"
               "analog gelesen werden.\n"
               " \n"
               "Positive X-Achse ist rechts. \n"
               "Positive Y-Achse ist unten.");
         break;
      case MENU_ENUM_LABEL_VALUE_WHAT_IS_A_CORE_DESC:
         snprintf(s, len,
               "RetroArch selbst tut nichts. \n"
               " \n"
               "Damit RetroArch etwas tut, musst \n"
               "Du ein Programm hineinladen. \n"
               "\n"
               "Wir nennen diese Programme 'libretro-Core', \n"
               "oder einfach nur 'Core'. \n"
               " \n"
               "Um einen Core zu laden, verwende \n"
               "'Core laden'.\n"
               " \n"
#ifdef HAVE_NETWORKING
               "Du kannst die Cores auf mehreren Wegen beziehen: \n"
               "* Herunterladen, indem Du\n"
               "'%s' -> '%s' verwendest. \n"
               "* Manuell ins Verzeichnis \n"
               "'%s' kopieren.",
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_ONLINE_UPDATER),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_CORE_UPDATER_LIST),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LIBRETRO_DIR_PATH)
#else
               "Du kannst die Cores beziehen, indem\n"
               "du sie manuell ins Verzeichnis \n"
               "'%s' kopierst.",
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LIBRETRO_DIR_PATH)
#endif
               );
         break;
      case MENU_ENUM_LABEL_VALUE_HELP_CHANGE_VIRTUAL_GAMEPAD_DESC:
         snprintf(s, len,
               "Du kannst das virtuelle Gamepad-Overlay ändern, indem Du \n"
               "zu '%s' -> '%s' gehst."
               " \n"
               "Hier kannst du das Overlay ändern,\n"
               "die Größe und Transparenz der Tasten verändern, etc.\n"
               " \n"
               "HINWEIS: Standardmäßig werden virtuelle Gamepad-Overlays \n"
               "versteckt, wenn Du dich im Menü befindest.\n"
               "Wenn Du dieses Verhalten ändern möchtest,\n"
               "kannst Du '%s' auf 'aus' setzen.",
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_OVERLAY_SETTINGS),
               msg_hash_to_str(MENU_ENUM_LABEL_VALUE_INPUT_OVERLAY_HIDE_IN_MENU)
               );
         break;
      default:
         if (string_is_empty(s))
            strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
         return -1;
   }

   return 0;
}

#ifdef HAVE_MENU
static const char *menu_hash_to_str_de_label_enum(enum msg_hash_enums msg)
{
   if (msg <= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_END &&
         msg >= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN)
   {
      static char hotkey_lbl[128] = {0};
      unsigned idx = msg - MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN;
      snprintf(hotkey_lbl, sizeof(hotkey_lbl), "input_hotkey_binds_%d", idx);
      return hotkey_lbl;
   }

   switch (msg)
   {
      #include "msg_hash_lbl.h"
      default:
#if 0
         RARCH_LOG("Unimplemented: [%d]\n", msg);
#endif
         break;
   }

   return "null";
}
#endif

const char *msg_hash_to_str_de(enum msg_hash_enums msg)
{
#ifdef HAVE_MENU
   const char *ret = menu_hash_to_str_de_label_enum(msg);

   if (ret && !string_is_equal(ret, "null"))
      return ret;
#endif

   switch (msg)
   {
      #include "msg_hash_de.h"
      default:
#if 0
         RARCH_LOG("Unimplemented: [%d]\n", msg);
         {
            RARCH_LOG("[%d] : %s\n", msg - 1, msg_hash_to_str(((enum msg_hash_enums)(msg - 1))));
         }
#endif
         break;
   }

   return "null";
}
